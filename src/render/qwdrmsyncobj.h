// Copyright (C) 2025 UnionTech Software Technology Co., Ltd.
// SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <qwglobal.h>

extern "C" {
#include <wlr/render/drm_syncobj.h>
}

QW_BEGIN_NAMESPACE

class QW_CLASS_REINTERPRET_CAST(drm_syncobj_timeline)
{
public:
    QW_FUNC_STATIC(drm_syncobj_timeline, create, qw_drm_syncobj_timeline *, int drm_fd)
    QW_FUNC_STATIC(drm_syncobj_timeline, import, qw_drm_syncobj_timeline *, int drm_fd, int drm_syncobj_fd)

    QW_FUNC_MEMBER(drm_syncobj_timeline, ref, wlr_drm_syncobj_timeline *, void)
    QW_FUNC_MEMBER(drm_syncobj_timeline, unref, void)
#if WLR_VERSION_MINOR >= 19
    template<typename ...Args>
    QW_ALWAYS_INLINE void
    export_(Args &&... args) const requires std::is_invocable_v<decltype(wlr_drm_syncobj_timeline_export), decltype(*this), Args...>
    {
        return wlr_drm_syncobj_timeline_export(*this, std::forward<Args>(args)...);
    }

    QW_FUNC_STATIC(drm_syncobj_timeline, transfer, bool, wlr_drm_syncobj_timeline *dst, uint64_t dst_point, wlr_drm_syncobj_timeline *src, uint64_t src_point)
#endif
    QW_FUNC_MEMBER(drm_syncobj_timeline, check, bool, uint64_t point, uint32_t flags, bool *result)
    QW_FUNC_MEMBER(drm_syncobj_timeline, export_sync_file, int, uint64_t)
    QW_FUNC_MEMBER(drm_syncobj_timeline, import_sync_file, bool, uint64_t, int)
};

class QW_CLASS_REINTERPRET_CAST(drm_syncobj_timeline_waiter)
{
public:
    QW_FUNC_MEMBER(drm_syncobj_timeline_waiter, init, bool, wlr_drm_syncobj_timeline *timeline, uint64_t point,
        uint32_t flags, wl_event_loop *loop, wlr_drm_syncobj_timeline_ready_callback callback)
    QW_FUNC_MEMBER(drm_syncobj_timeline_waiter, finish, void)
};

QW_END_NAMESPACE
