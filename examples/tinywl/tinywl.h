#include <qwlroots.h>

class Q_DECL_HIDDEN TinywlServer : public QObject
{
    Q_OBJECT
public:
    TinywlServer();
    ~TinywlServer();

    bool start();

private Q_SLOTS:
    void onNewOutput(wlr_output *output);
#if WLR_VERSION_MINOR < 18
    void onNewXdgSurface(wlr_xdg_surface *surface);
#endif
    void onNewXdgToplevel(wlr_xdg_toplevel *surface);
    void onNewXdgPopup(wlr_xdg_popup *surface);

    void onMap();
    void onUnmap();
    void onXdgToplevelRequestMove(wlr_xdg_toplevel_move_event *);
    void onXdgToplevelRequestResize(wlr_xdg_toplevel_resize_event *event);
    void onXdgToplevelRequestMaximize();
    void onXdgToplevelRequestRequestFullscreen();

    void onCursorMotion(wlr_pointer_motion_event *event);
    void onCursorMotionAbsolute(wlr_pointer_motion_absolute_event *event);
    void onCursorButton(wlr_pointer_button_event *event);
    void onCursorAxis(wlr_pointer_axis_event *event);
    void onCursorFrame();

    void onNewInput(wlr_input_device *device);
    void onRequestSetCursor(wlr_seat_pointer_request_set_cursor_event *event);
    void onRequestSetSelection(wlr_seat_request_set_selection_event *event);

    void onKeyboardModifiers();
    void onKeyboardKey(wlr_keyboard_key_event *event);
    void onKeyboardDestroy();

    void onOutputFrame();

private:
    struct View
    {
        TinywlServer *server;
        qw_xdg_toplevel *xdgToplevel;
        qw_scene_tree *sceneTree;
        QPointF pos;
    };

    enum class CursorState {
        Normal,
        MovingWindow,
        ResizingWindow,
    };

    static inline View *getView(const qw_xdg_surface *surface);
    View *viewAt(const QPointF &pos, wlr_surface **surface, QPointF *spos) const;
    void processCursorMotion(uint32_t time);
    void focusView(View *view, wlr_surface *surface);
    void beginInteractive(View *view, CursorState state, uint32_t edges);
    bool handleKeybinding(xkb_keysym_t sym);

    qw_display *display;
    qw_backend *backend;
    qw_renderer *renderer;
    qw_allocator *allocator;

    qw_compositor *compositor;
    qw_subcompositor *subcompositor;
    qw_data_device_manager *dataDeviceManager;

    qw_output_layout *outputLayout;
    QList<qw_output*> outputs;

    qw_scene *scene;
    qw_scene_output_layout *scene_layout;

    qw_xdg_shell *xdgShell;
    QList<View*> views;
    View *grabbedView = nullptr;
    QPointF grabCursorPos;
    QRectF grabGeoBox;

    qw_cursor *cursor;
    qw_xcursor_manager *cursorManager;
    CursorState cursorState = CursorState::Normal;
    uint32_t resizingEdges = 0;

    QList<qw_keyboard*> keyboards;
    qw_seat *seat;
};
