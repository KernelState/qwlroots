// Copyright (C) 2025 UnionTech Software Technology Co., Ltd.
// SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <qwglobal.h>

#include "qwbuffer.h"

extern "C" {
#include <wlr/types/wlr_buffer.h>
#include <wlr/types/wlr_linux_drm_syncobj_v1.h>
}

QW_BEGIN_NAMESPACE

class QW_CLASS_REINTERPRET_CAST(linux_drm_syncobj_manager_v1)
{
public:
    QW_FUNC_STATIC(linux_drm_syncobj_manager_v1, create, qw_linux_drm_syncobj_manager_v1 *, wl_display *display,
        uint32_t version, int drm_fd)
};

class QW_CLASS_REINTERPRET_CAST(linux_drm_syncobj_surface_v1_state)
{
public:
#if WLR_VERSION_MINOR >= 19
    template<typename ...Args>
    QW_ALWAYS_INLINE bool
    signal_release_with_buffer(Args &&... args) const requires std::is_invocable_v<decltype(wlr_linux_drm_syncobj_v1_state_signal_release_with_buffer), decltype(*this), Args...>
    {
        return wlr_linux_drm_syncobj_v1_state_signal_release_with_buffer(*this, std::forward<Args>(args)...);
    }
#endif
};

QW_END_NAMESPACE
