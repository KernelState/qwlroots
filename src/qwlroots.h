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

using QwAllocator = qw_allocator;
using QwAlphaModifierV1 = qw_alpha_modifier_v1;
using QwBackend = qw_backend;
using QwBasic = qw_basic;
using QwBox = qw_box;
using QwBuffer = qw_buffer;
template <typename Handle, typename Derive>
using QwClassBox = qw_class_box<Handle, Derive>;
using QwClientBuffer = qw_client_buffer;
using QwColorManagerV1 = qw_color_manager_v1;
using QwColorTransform = qw_color_transform;
using QwCompositor = qw_compositor;
using QwContentTypeManagerV1 = qw_content_type_manager_v1;
using QwCursor = qw_cursor;
using QwCursorShapeManagerV1 = qw_cursor_shape_manager_v1;
using QwDamageRing = qw_damage_ring;
using QwDataControlDeviceV1 = qw_data_control_device_v1;
using QwDataControlManagerV1 = qw_data_control_manager_v1;
using QwDataDeviceManager = qw_data_device_manager;
using QwDataSource = qw_data_source;
using QwDisplay = qw_display;
using QwDmabufAttributes = qw_dmabuf_attributes;
using QwDrag = qw_drag;
using QwDrm = qw_drm;
using QwDrmBackend = qw_drm_backend;
using QwDrmBuffer = qw_drm_buffer;
using QwDrmFormat = qw_drm_format;
using QwDrmFormatSet = qw_drm_format_set;
using QwDrmLeaseRequestV1 = qw_drm_lease_request_v1;
using QwDrmLeaseV1 = qw_drm_lease_v1;
using QwDrmLeaseV1Manager = qw_drm_lease_v1_manager;
using QwDrmSyncobjTimeline = qw_drm_syncobj_timeline;
using QwDrmSyncobjTimelineWaiter = qw_drm_syncobj_timeline_waiter;
using QwEgl = qw_egl;
using QwExportDmabufManagerV1 = qw_export_dmabuf_manager_v1;
using QwExtForeignToplevelHandleV1 = qw_ext_foreign_toplevel_handle_v1;
using QwExtForeignToplevelListV1 = qw_ext_foreign_toplevel_list_v1;
using QwExtImageCopyCaptureFrameV1 = qw_ext_image_copy_capture_frame_v1;
using QwExtImageCopyCaptureManagerV1 = qw_ext_image_copy_capture_manager_v1;
using QwFbox = qw_fbox;
using QwForeignToplevelHandleV1 = qw_foreign_toplevel_handle_v1;
using QwForeignToplevelManagerV1 = qw_foreign_toplevel_manager_v1;
using QwFractionalScaleManagerV1 = qw_fractional_scale_manager_v1;
using QwGammaControlManagerV1 = qw_gamma_control_manager_v1;
using QwGammaControlV1 = qw_gamma_control_v1;
using QwHeadlessBackend = qw_headless_backend;
using QwIdleInhibitManagerV1 = qw_idle_inhibit_manager_v1;
using QwIdleInhibitorV1 = qw_idle_inhibitor_v1;
using QwIdleNotifierV1 = qw_idle_notifier_v1;
using QwInputDevice = qw_input_device;
using QwInputMethodKeyboardGrabV2 = qw_input_method_keyboard_grab_v2;
using QwInputMethodManagerV2 = qw_input_method_manager_v2;
using QwInputMethodV2 = qw_input_method_v2;
using QwInputPopupSurfaceV2 = qw_input_popup_surface_v2;
template <typename Handle, typename Impl>
using QwInterface = qw_interface<Handle, Impl>;
using QwInterfaceBasic = qw_interface_basic;
using QwKeyboard = qw_keyboard;
using QwKeyboardGroup = qw_keyboard_group;
using QwKeyboardShortcutsInhibitManagerV1 = qw_keyboard_shortcuts_inhibit_manager_v1;
using QwKeyboardShortcutsInhibitorV1 = qw_keyboard_shortcuts_inhibitor_v1;
using QwLayerShellV1 = qw_layer_shell_v1;
using QwLayerSurfaceV1 = qw_layer_surface_v1;
using QwLibinputBackend = qw_libinput_backend;
using QwLinuxDmabufFeedbackV1 = qw_linux_dmabuf_feedback_v1;
using QwLinuxDmabufV1 = qw_linux_dmabuf_v1;
using QwLinuxDrmSyncobjManagerV1 = qw_linux_drm_syncobj_manager_v1;
using QwLinuxDrmSyncobjSurfaceV1State = qw_linux_drm_syncobj_surface_v1_state;
using QwLog = qw_log;
using QwMultiBackend = qw_multi_backend;
template <typename Handle, typename Derive>
using QwObject = qw_object<Handle, Derive>;
using QwObjectBasic = qw_object_basic;
using QwOutput = qw_output;
using QwOutputConfigurationHeadV1 = qw_output_configuration_head_v1;
using QwOutputConfigurationV1 = qw_output_configuration_v1;
using QwOutputCursor = qw_output_cursor;
using QwOutputLayer = qw_output_layer;
using QwOutputLayout = qw_output_layout;
using QwOutputManagerV1 = qw_output_manager_v1;
using QwOutputPowerManagerV1 = qw_output_power_manager_v1;
using QwOutputState = qw_output_state;
using QwPointer = qw_pointer;
using QwPointerConstraintV1 = qw_pointer_constraint_v1;
using QwPointerConstraintsV1 = qw_pointer_constraints_v1;
using QwPointerGesturesV1 = qw_pointer_gestures_v1;
using QwPresentation = qw_presentation;
using QwPresentationEvent = qw_presentation_event;
using QwPresentationFeedback = qw_presentation_feedback;
using QwPrimarySelectionSource = qw_primary_selection_source;
using QwPrimarySelectionV1DeviceManager = qw_primary_selection_v1_device_manager;
template <typename Handle, typename Derive>
using QwReinterpretCast = qw_reinterpret_cast<Handle, Derive>;
using QwRelativePointerManagerV1 = qw_relative_pointer_manager_v1;
using QwRelativePointerV1 = qw_relative_pointer_v1;
using QwRenderer = qw_renderer;
using QwScene = qw_scene;
using QwSceneBuffer = qw_scene_buffer;
using QwSceneLayerSurfaceV1 = qw_scene_layer_surface_v1;
using QwSceneNode = qw_scene_node;
using QwSceneOutput = qw_scene_output;
using QwSceneOutputLayout = qw_scene_output_layout;
using QwSceneRect = qw_scene_rect;
using QwSceneSurface = qw_scene_surface;
using QwSceneTimer = qw_scene_timer;
using QwSceneTree = qw_scene_tree;
using QwScreencopyManagerV1 = qw_screencopy_manager_v1;
using QwSeat = qw_seat;
using QwSeatClient = qw_seat_client;
using QwSecurityContextManagerV1 = qw_security_context_manager_v1;
using QwSessionLockManagerV1 = qw_session_lock_manager_v1;
using QwSessionLockSurfaceV1 = qw_session_lock_surface_v1;
using QwSessionLockV1 = qw_session_lock_v1;
using QwShm = qw_shm;
using QwSignalConnector = qw_signal_connector;
using QwSinglePixelBufferManagerV1 = qw_single_pixel_buffer_manager_v1;
using QwSubcompositor = qw_subcompositor;
using QwSubsurface = qw_subsurface;
using QwSurface = qw_surface;
using QwSwapchain = qw_swapchain;
using QwSwitch = qw_switch;
using QwTablet = qw_tablet;
using QwTabletManagerV2 = qw_tablet_manager_v2;
using QwTabletPad = qw_tablet_pad;
using QwTabletV2Tablet = qw_tablet_v2_tablet;
using QwTabletV2TabletPad = qw_tablet_v2_tablet_pad;
using QwTabletV2TabletTool = qw_tablet_v2_tablet_tool;
using QwTearingControlManagerV1 = qw_tearing_control_manager_v1;
using QwTextInputManagerV3 = qw_text_input_manager_v3;
using QwTextInputV3 = qw_text_input_v3;
using QwTexture = qw_texture;
using QwTouch = qw_touch;
using QwTransientSeatManagerV1 = qw_transient_seat_manager_v1;
using QwTransientSeatV1 = qw_transient_seat_v1;
using QwViewporter = qw_viewporter;
using QwVirtualKeyboardManagerV1 = qw_virtual_keyboard_manager_v1;
using QwVirtualPointerManagerV1 = qw_virtual_pointer_manager_v1;
using QwWaylandBackend = qw_wayland_backend;
using QwX11Backend = qw_x11_backend;
using QwXcursorManager = qw_xcursor_manager;
using QwXdgActivationTokenV1 = qw_xdg_activation_token_v1;
using QwXdgActivationV1 = qw_xdg_activation_v1;
using QwXdgDecorationManagerV1 = qw_xdg_decoration_manager_v1;
using QwXdgExportedV1 = qw_xdg_exported_v1;
using QwXdgExportedV2 = qw_xdg_exported_v2;
using QwXdgForeignExported = qw_xdg_foreign_exported;
using QwXdgForeignRegistry = qw_xdg_foreign_registry;
using QwXdgForeignV1 = qw_xdg_foreign_v1;
using QwXdgForeignV2 = qw_xdg_foreign_v2;
using QwXdgOutputManagerV1 = qw_xdg_output_manager_v1;
using QwXdgPopup = qw_xdg_popup;
using QwXdgShell = qw_xdg_shell;
using QwXdgSurface = qw_xdg_surface;
using QwXdgToplevel = qw_xdg_toplevel;
using QwXdgToplevelDecorationV1 = qw_xdg_toplevel_decoration_v1;
using QwXwayland = qw_xwayland;
using QwXwaylandServer = qw_xwayland_server;
using QwXwaylandShellV1 = qw_xwayland_shell_v1;
using QwXwaylandSurface = qw_xwayland_surface;
