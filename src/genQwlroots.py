#!/usr/bin/env python3
"""
generate_qwlroots_header.py

Scans .h files in a directory and writes qwlroots.h containing:
  - #include "..." for every header found
  - using QwName = qw_name;                  for plain classes/enums
  - template <typename T>
    using QwName = qw_name<T>;               for templated classes/enums

Usage:
    ./generate_qwlroots_header.py [dir] [-r/--recursive] [-o/--output qwlroots.h]
"""
import argparse
import re
import sys
from pathlib import Path

NAME = r"qw_[a-zA-Z0-9_]+"
EXPORT = r"(?:[A-Z_][A-Z0-9_]*\s+)?"          # optional ALL_CAPS export macro
KEYWORD = r"(?:class|enum(?:\s+class)?)"

# template <params> [newline/space] class|enum [EXPORT_MACRO] qw_name
TEMPLATE_RE = re.compile(
    rf"^[ \t]*template[ \t]*<(?P<params>(?:[^<>]|<[^<>]*>)*)>[ \t\r\n]*"
    rf"{KEYWORD}\s+{EXPORT}(?P<name>{NAME})",
    re.MULTILINE,
)

# plain: class|enum [EXPORT_MACRO] qw_name, at start of its own line
PLAIN_RE = re.compile(
    rf"^[ \t]*{KEYWORD}\s+{EXPORT}(?P<name>{NAME})",
    re.MULTILINE,
)


def to_pascal(name: str) -> str:
    """qw_output_power_management_v1 -> QwOutputPowerManagementV1"""
    return "".join(part.capitalize() for part in name.split("_"))


def split_top_level(params: str):
    """Split a template parameter list on top-level commas (ignores commas
    nested inside a single level of <...>, e.g. std::allocator<T>)."""
    parts, depth, cur = [], 0, ""
    for ch in params:
        if ch == "<":
            depth += 1
            cur += ch
        elif ch == ">":
            depth -= 1
            cur += ch
        elif ch == "," and depth == 0:
            parts.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        parts.append(cur)
    return parts


def param_names(params: str) -> str:
    """'typename T, typename... Args, int N = 4' -> 'T, Args..., N'"""
    names = []
    for raw in split_top_level(params):
        p = raw.split("=")[0].strip()          # drop default argument
        variadic = "..." in p
        p = p.replace("...", "").strip()
        tok = p.split()
        n = tok[-1] if tok else ""
        names.append(n + ("..." if variadic else ""))
    return ", ".join(names)


def collect(text: str):
    """Returns {qw_name: params_str_or_None} for one file's contents."""
    entries = {}
    covered = []  # name spans already claimed by a template match

    for m in TEMPLATE_RE.finditer(text):
        entries[m.group("name")] = m.group("params").strip()
        covered.append(m.span("name"))

    for m in PLAIN_RE.finditer(text):
        start = m.start("name")
        if any(cs <= start < ce for cs, ce in covered):
            continue  # already handled as a template above
        entries.setdefault(m.group("name"), None)

    return entries


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir", nargs="?", default=".", help="directory to scan (default: .)")
    ap.add_argument("-r", "--recursive", action="store_true", help="scan subdirectories recursively")
    ap.add_argument("-o", "--output", default="qwlroots.h", help="output filename")
    args = ap.parse_args()

    root = Path(args.dir)
    pattern = "**/*.h" if args.recursive else "*.h"
    headers = sorted(
        p for p in root.glob(pattern)
        if p.is_file() and p.name != args.output
    )

    if not headers:
        print(f"No .h files found in {root}", file=sys.stderr)
        sys.exit(1)

    all_entries = {}
    for h in headers:
        text = h.read_text(encoding="utf-8", errors="replace")
        for name, params in collect(text).items():
            if name not in all_entries or all_entries[name] is None:
                all_entries[name] = params

    lines = ["#pragma once", ""]
    for h in headers:
        rel = h.relative_to(root) if args.recursive else h.name
        lines.append(f'#include "{Path(rel).as_posix()}"')
    lines.append("")

    for name in sorted(all_entries):
        params = all_entries[name]
        alias = to_pascal(name)
        if params is None:
            lines.append(f"using {alias} = {name};")
        else:
            lines.append(f"template <{params}>")
            lines.append(f"using {alias} = {name}<{param_names(params)}>;")

    out_path = root / args.output
    out_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {out_path} ({len(headers)} headers, {len(all_entries)} aliases)")


if __name__ == "__main__":
    main()
