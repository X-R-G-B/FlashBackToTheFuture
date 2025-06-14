cmake_minimum_required(VERSION 3.22)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    # audio
    ${CMAKE_CURRENT_SOURCE_DIR}/audio/audio_static.c
    ${CMAKE_CURRENT_SOURCE_DIR}/audio/init_music.c
    ${CMAKE_CURRENT_SOURCE_DIR}/audio/init_sound.c
    ${CMAKE_CURRENT_SOURCE_DIR}/audio/play_audio.c
    # ennemy
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/add_to_ennemy_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/check_drop.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/create_ennemy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/destroy_ennemy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/drop_right_item.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/ennemy_check_hurt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/ennemy_get_view_dir.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/ennemy_static.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/is_player_in_range.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/sprite_set_change.c
    # ennemy update
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/check_wall.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/ennemy_check_is_dashing.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/ennemy_update.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/hurt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/update_ennemy_attack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ennemy/update/update_ennemy_move.c
    # hud
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/add_main_menu_elements_to_hud_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/check_evolution_stat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/hud_apply_right_pos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/increment_hud_pos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/init_energy_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/init_hud_elements.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/init_life_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/init_text_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/init_xp_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/manage_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/update_text_hud.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hud/update_xp_bar.c
    # launch
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/init_credits.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/init_pause_button.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/launch_game.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/launch_next_stage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/launch_stage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/launch_static.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/launch_story_mode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/move_object_between_scene.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/replace_objects_in_next_stage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/launch/scene_loading_basic.c
    # map
    ${CMAKE_CURRENT_SOURCE_DIR}/map/change_meteo_json.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/check_collision.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/check_player_pos_in_map.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/create_map.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_set_components.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/stage_map_to_collision_array.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/wordarray_free_cast.c
    # map square_updates
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/activate_dash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/activate_player_down_scale.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/activate_player_up_scale.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/is_player_on_square.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/knockback.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/next_stage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/npc_spawner.c
    ${CMAKE_CURRENT_SOURCE_DIR}/map/square_updates/spawner.c
    # math
    ${CMAKE_CURRENT_SOURCE_DIR}/math/check_circle_col.c
    ${CMAKE_CURRENT_SOURCE_DIR}/math/get_distance.c
    ${CMAKE_CURRENT_SOURCE_DIR}/math/get_rand_number.c
    ${CMAKE_CURRENT_SOURCE_DIR}/math/get_vector_dir.c
    ${CMAKE_CURRENT_SOURCE_DIR}/math/gore_effect.c
    ${CMAKE_CURRENT_SOURCE_DIR}/math/rect_contains_segment.c
    # menu
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/button_event_array.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/menu_static.c
    # menu dead
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/dead/configure_dead_screen.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/dead/event_dead_screen.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/dead/update_dead_message.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/dead/update_dead_screen.c
    # menu main
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/event_menu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/exit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/init_menu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/init_music.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/making_of.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/on_click_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/pop_up_management.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/sandbox_button.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/main/set_overlay.c
    # menu pause
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/check_restart_end_magician.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/create_pause_menu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/home_button_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/pause_button_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/pressed_button_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/pause/restart_button.c
    # menu settings_menu
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/add_new_audio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/bar_update.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/button_hover_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/drag_button_off.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/drag_button_on.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/init_audio_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/replace_button.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/set_drag_objects.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/set_frame.c
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/settings_menu/toggle_music_in_scene.c
    # meteo
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/add_leaf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/add_movement.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/add_snow.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/add_sunshine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/change_meteo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/init_movement.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/meteo_handler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/meteo/meteo_handler_init.c
    # npc
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/add_text_dialog.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/add_text_dialog_json.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/aplly_rect_npc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/create_npc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/init_dialog.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/pretyprint.c
    # npc event
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/event/press_to_continue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/event/press_to_quit_dialogues.c
    # npc npc
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/npc/callback_npc.c
    # npc npc chest_npc
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/npc/chest_npc/dropping_infinity_86.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/npc/chest_npc/reset_86_number.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/npc/chest_npc/update_chest.c
    # npc update
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/event_skip_tp_magi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/magician_view_rotation.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_dialog_text.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_dialogue_box.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_elder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_end_magician.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_grandpa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_intro_magician.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_magician.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_ninho.c
    ${CMAKE_CURRENT_SOURCE_DIR}/npc/update/update_npc.c
    # pathfind
    ${CMAKE_CURRENT_SOURCE_DIR}/pathfind/destroy_pathfind.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pathfind/get_new_pos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pathfind/init_find.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pathfind/init_path.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pathfind/pathfind_add_to_scene.c
    # player
    ${CMAKE_CURRENT_SOURCE_DIR}/player/create_player.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/destroy_player.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/init_player_scale_handling.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/player_check_hurt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/player_check_hurt_during_attack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/player_static.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/set_player_default_stats.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/set_stop.c
    # player event
    ${CMAKE_CURRENT_SOURCE_DIR}/player/event/attack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/event/move.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/event/roulade.c
    # player inventory
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/create_inventory.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/create_nbr_potions_text.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/heal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/inventory_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/toggle_key_obj.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/inventory/update_data_json_inv.c
    # player stat_upgrade
    ${CMAKE_CURRENT_SOURCE_DIR}/player/stat_upgrade/gain_xp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/stat_upgrade/stats_component.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/stat_upgrade/upgrade_dammage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/stat_upgrade/upgrade_stat.c
    # player update
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/handle_player_down_scaling.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/handle_player_up_scaling.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_attack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_hurt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_movement.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_player.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_roulade.c
    ${CMAKE_CURRENT_SOURCE_DIR}/player/update/update_scale_with_height.c
    # pop_text_generator
    ${CMAKE_CURRENT_SOURCE_DIR}/pop_text_generator/create_pop_text.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pop_text_generator/create_stat_pop_text.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pop_text_generator/update_text.c
)
