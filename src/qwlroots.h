#pragma once

#include "interfaces/qwbackendinterface.h"
#include "interfaces/qwbufferinterface.h"
#include "interfaces/qwinterface.h"
#include "interfaces/qwkeyboardinterface.h"
#include "interfaces/qwoutputinterface.h"
#include "interfaces/qwpointerinterface.h"
#include "interfaces/qwrendererinterface.h"
#include "interfaces/qwswitchinterface.h"
#include "interfaces/qwtabletpadinterface.h"
#include "qwbackend.h"
#include "qwdisplay.h"
#include "qwglobal.h"
#include "qwlroots.h"
#include "qwobject.h"
#include "render/qwallocator.h"
#include "render/qwcolor.h"
#include "render/qwdmabuf.h"
#include "render/qwdrmformatset.h"
#include "render/qwdrmsyncobj.h"
#include "render/qwegl.h"
#include "render/qwrenderer.h"
#include "render/qwswapchain.h"
#include "render/qwtexture.h"
#include "types/qwalphamodifierv1.h"
#include "types/qwbuffer.h"
#include "types/qwcolormanagerv1.h"
#include "types/qwcompositor.h"
#include "types/qwcontenttypev1.h"
#include "types/qwcursor.h"
#include "types/qwcursorshapev1.h"
#include "types/qwdamagering.h"
#include "types/qwdatacontrolv1.h"
#include "types/qwdatadevice.h"
#include "types/qwdrm.h"
#include "types/qwdrmleasev1.h"
#include "types/qwexportdmabufv1.h"
#include "types/qwextforeigntoplevellistv1.h"
#include "types/qwextimagecopycapturev1.h"
#include "types/qwforeigntoplevelhandlev1.h"
#include "types/qwfractionalscalemanagerv1.h"
#include "types/qwfullscreenshellv1.h"
#include "types/qwgammacontorlv1.h"
#include "types/qwidleinhibitv1.h"
#include "types/qwidlenotifyv1.h"
#include "types/qwinputdevice.h"
#include "types/qwinputmethodv2.h"
#include "types/qwkeyboard.h"
#include "types/qwkeyboardgroup.h"
#include "types/qwkeyboardshortcutsinhibitv1.h"
#include "types/qwlayershellv1.h"
#include "types/qwlinuxdmabufv1.h"
#include "types/qwlinuxdrmsyncobjv1.h"
#include "types/qwoutput.h"
#include "types/qwoutputlayer.h"
#include "types/qwoutputlayout.h"
#include "types/qwoutputmanagementv1.h"
#include "types/qwoutputpowermanagementv1.h"
#include "types/qwpointer.h"
#include "types/qwpointerconstraintsv1.h"
#include "types/qwpointergesturesv1.h"
#include "types/qwpresentation.h"
#include "types/qwprimaryselection.h"
#include "types/qwprimaryselectionv1.h"
#include "types/qwrelativepointerv1.h"
#include "types/qwscene.h"
#include "types/qwscreencopyv1.h"
#include "types/qwseat.h"
#include "types/qwsecuritycontextmanagerv1.h"
#include "types/qwsessionlockv1.h"
#include "types/qwshm.h"
#include "types/qwsinglepixelbufferv1.h"
#include "types/qwsubcompositor.h"
#include "types/qwswitch.h"
#include "types/qwtablet.h"
#include "types/qwtabletpad.h"
#include "types/qwtabletv2.h"
#include "types/qwtearingcontrolv1.h"
#include "types/qwtextinputv3.h"
#include "types/qwtouch.h"
#include "types/qwtransientseatv1.h"
#include "types/qwviewporter.h"
#include "types/qwvirtualkeyboardv1.h"
#include "types/qwvirtualpointerv1.h"
#include "types/qwxcursormanager.h"
#include "types/qwxdgactivationv1.h"
#include "types/qwxdgdecorationmanagerv1.h"
#include "types/qwxdgforeignregistry.h"
#include "types/qwxdgforeignv1.h"
#include "types/qwxdgforeignv2.h"
#include "types/qwxdgoutputv1.h"
#include "types/qwxdgshell.h"
#include "types/qwxwayland.h"
#include "types/qwxwaylandserver.h"
#include "types/qwxwaylandshellv1.h"
#include "types/qwxwaylandsurface.h"
#include "util/qwbox.h"
#include "util/qwlogging.h"
#include "util/qwsignalconnector.h"

using QwBasic = qw_basic;
using QwBox = qw_box;
template <typename Handle, typename Derive>
using QwClassBox = qw_class_box<Handle, Derive>;
using QwDisplay = qw_display;
using QwDrmBackend = qw_drm_backend;
using QwFbox = qw_fbox;
using QwHeadlessBackend = qw_headless_backend;
template <typename Handle, typename Impl>
using QwInterface = qw_interface<Handle, Impl>;
using QwInterfaceBasic = qw_interface_basic;
using QwKeyboard = qw_keyboard;
using QwLibinputBackend = qw_libinput_backend;
using QwLog = qw_log;
using QwMultiBackend = qw_multi_backend;
template <typename Handle, typename Derive>
using QwObject = qw_object<Handle, Derive>;
using QwObjectBasic = qw_object_basic;
using QwPointer = qw_pointer;
template <typename Handle, typename Derive>
using QwReinterpretCast = qw_reinterpret_cast<Handle, Derive>;
using QwScene = qw_scene;
using QwSceneBuffer = qw_scene_buffer;
using QwSceneRect = qw_scene_rect;
using QwSceneTimer = qw_scene_timer;
using QwSceneTree = qw_scene_tree;
using QwSignalConnector = qw_signal_connector;
using QwSwitch = qw_switch;
using QwTablet = qw_tablet;
using QwTabletPad = qw_tablet_pad;
using QwTouch = qw_touch;
using QwWaylandBackend = qw_wayland_backend;
using QwX11Backend = qw_x11_backend;
using QwXdgExportedV1 = qw_xdg_exported_v1;
using QwXdgExportedV2 = qw_xdg_exported_v2;
