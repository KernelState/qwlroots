// Copyright (C) 2025 UnionTech Software Technology Co., Ltd.
// SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <qwglobal.h>

extern "C" {
#include <wlr/types/wlr_ext_image_copy_capture_v1.h>
}

QW_BEGIN_NAMESPACE

class QW_CLASS_REINTERPRET_CAST(ext_image_copy_capture_manager_v1)
{
public:
    QW_FUNC_STATIC(ext_image_copy_capture_manager_v1, create, qw_ext_image_copy_capture_manager_v1 *, wl_display *display,
        uint32_t version)
};

class QW_CLASS_REINTERPRET_CAST(ext_image_copy_capture_frame_v1)
{
public:
    QW_FUNC_MEMBER(ext_image_copy_capture_frame_v1, ready, void, enum wl_output_transform, const timespec *)
    QW_FUNC_MEMBER(ext_image_copy_capture_frame_v1, fail, void, enum ext_image_copy_capture_frame_v1_failure_reason)
    QW_FUNC_MEMBER(ext_image_copy_capture_frame_v1, copy_buffer, bool, wlr_buffer *, wlr_renderer *)
};

QW_END_NAMESPACE
