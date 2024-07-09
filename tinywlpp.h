#pragma once

#include <wayland-server-core.h>

#define class     _class
#define namespace _namespace
#define static
#define delete delete_

extern "C" {
#include <wlr/backend.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_keyboard.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_pointer.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_subcompositor.h>
#include <wlr/types/wlr_xcursor_manager.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/util/log.h>
}

#undef delete
#undef class
#undef namespace
#undef static

#include <xkbcommon/xkbcommon.h>

namespace tinywlpp {
    enum cursor_mode {
        CURSOR_PASSTHROUGH,
	    CURSOR_MOVE,
	    CURSOR_RESIZE,
    };

    class server {
    private:
        struct wl_display *wl_display;
        struct wlr_backend *backend;
        struct wlr_renderer *renderer;
        struct wlr_allocator *allocator;
        struct wlr_scene *scene;
        struct wlr_scene_output_layout *scene_layout;
        struct wlr_xdg_shell *xdg_shell;
        struct wl_listener new_xdg_surface;
        struct wl_list toplevels;
        struct wlr_cursor *cursor;
        struct wlr_xcursor_manager *cursor_mgr;
        struct wl_listener cursor_motion;
        struct wl_listener cursor_motion_absolute;
        struct wl_listener cursor_button;
        struct wl_listener cursor_axis;
        struct wl_listener cursor_frame;
        struct wlr_seat *seat;
        struct wl_listener new_input;
        struct wl_listener request_cursor;
        struct wl_listener request_set_selection;
        struct wl_list keyboards;
        enum cursor_mode cursor_mode;
        toplevel *grabbed_toplevel;
        double grab_x, grab_y;
        struct wlr_box grab_geobox;
        uint32_t resize_edges;
        struct wlr_output_layout *output_layout;
        struct wl_list outputs;
        struct wl_listener new_output;

    public:
        
    };

    class output {
    private:
        struct wl_list link;
        server *server;
        struct wlr_output *wlr_output;
        struct wl_listener frame;
        struct wl_listener request_state;
        struct wl_listener destroy;

    public:

    };

    class toplevel {
    private:
        struct wl_list link;
        server *server;
        struct wlr_xdg_toplevel *xdg_toplevel;
        struct wlr_scene_tree *scene_tree;
        struct wl_listener map;
        struct wl_listener unmap;
        struct wl_listener destroy;
        struct wl_listener request_move;
        struct wl_listener request_resize;
        struct wl_listener request_maximize;
        struct wl_listener request_fullscreen;

    public:
        
    };

    class keyboard {
    private:
        struct wl_list link;
        server *server;
        struct wlr_keyboard *wlr_keyboard;
        struct wl_listener modifiers;
        struct wl_listener key;
        struct wl_listener destroy;

    public:

    };
}