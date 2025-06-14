cmake_minimum_required(VERSION 3.15)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/include
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    # bgs components
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/add_components.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/add_window_component.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/create_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_add_collision_components.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_add_set_sprite_components.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_check_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_check_health.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_check_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/components/object_update_mouse_event.c
    # bgs core
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/add.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/check_click_prev_call.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/check_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/create_object.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/create_scene.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/loop.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/object_change_scene.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/object_set_origin.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/object_set_sound.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/object_set_type.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/object_update.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/remove.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/remove_object.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/scene_loading.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/scene_loop.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/start.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/core/window_remove.c
    # bgs create_button
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/check_layer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/check_set_color.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/create_button.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/destroy_pos_array.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/fill_obj_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/set_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/create_button/toggle_pop_up.c
    # bgs particle
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/add_circle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/add_elem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/add_line.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/add_rect.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/clear_framebuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/create_framebuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/destroy_framebuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/draw_framebuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/update_framebuffer.c
    # bgs particle pixels
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/pixels/circle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/pixels/line.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/pixels/put_pixel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/particle/pixels/rect.c
    # bgs preset
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/preset/preset_display.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/preset/set_unset_bigdata_display.c
    # bgs utils
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/utils/cast.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/utils/id_generator.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libbgs/src/utils/set_window_style.c
    # conv
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atodf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atodf_err.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atof.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atof_err.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atoi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_atoi_err.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_compute_power_rec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_itoa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_itoa_base.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_itoa_base_err.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libconv/src/my_itoa_err.c
    # dico
    ${CMAKE_CURRENT_SOURCE_DIR}/libdico/src/add.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libdico/src/destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libdico/src/get.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libdico/src/pop.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libdico/src/rem.c
    # fs
    ${CMAKE_CURRENT_SOURCE_DIR}/libfs/src/fs_get_content.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libfs/src/fs_get_size.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libfs/src/fs_open_ronly.c
    # json get
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/get/get.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/get/get_from_array.c
    # json parser
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/any_dup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/create_any.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/fill_data.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/fill_dico.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/parse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/pop_data.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/parser/remove_space.c
    # json printer
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/printer/prety_print.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/printer/print_dico.c
    # json writer
    ${CMAKE_CURRENT_SOURCE_DIR}/libjson/src/writer/write_json.c
    # list
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/cast_from_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/free.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/get.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/list_add.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/list_create.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/rm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/str_to_word_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/liblist/src/swap.c
    # puts
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_printf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_putchar.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_putnbr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_putnbr_base.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_putstr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/my_putunbr_base.c
    # puts myprintf_dependencies
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_b.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_d.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_mod.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_o.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_s.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_u.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libputs/src/myprintf_dependencies/print_x.c
    # str
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_calloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_revstr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strcat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strcmp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strcontainc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strcontains.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strcpy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strdup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strealloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strlen.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libstr/src/my_strstartswith.c
    # wa
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_free.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_from_str.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_from_wordarray.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_index_startswith.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_len.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libwa/src/my_wordarray_show.c
)
