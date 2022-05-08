##
## EPITECH PROJECT, 2021
## defender
## File description:
## make the defender
##

# ----------------------------------------------------------------------------
# TARGET
NAME		=	my_rpg
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# COLOUR
CYAN		=	'\033[1;36m'
BLUE		=	'\033[1;34m'
GREEN 		= 	'\033[1;32m'
RED			=	'\033[1;31m'

RESET		=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# SRC

CFLAGS				=	-Iinclude/ -Ilib/include/ -Wall -Wextra	\
						-Wpedantic -Wno-pointer-to-int-cast		\
						-Wno-int-to-pointer-cast
# -------- SRC_METEO ---------------------------------------------------------
SRC_METEO			:=	add_leaf.c								\
						add_snow.c								\
						add_sunshine.c							\
						add_movement.c							\
						change_meteo.c							\
						meteo_handler.c							\
						meteo_handler_init.c					\
						init_movement.c
SRC_METEO			:=	$(addprefix meteo/,$(SRC_METEO))
# ----------------------------------------------------------------------------
# --------- SRC_ENNEMY -------------------------------------------------------

SRC_ENNEMY_UPDATE	:=	check_wall.c							\
						ennemy_check_is_dashing.c				\
						ennemy_update.c							\
						hurt.c									\
						update_ennemy_attack.c					\
						update_ennemy_move.c
SRC_ENNEMY_UPDATE	:=	$(addprefix update/,$(SRC_ENNEMY_UPDATE))

SRC_ENNEMY			:=	create_ennemy.c							\
						drop_right_item.c						\
						ennemy_get_view_dir.c					\
						check_drop.c							\
						sprite_set_change.c						\
						add_to_ennemy_list.c					\
						ennemy_check_hurt.c						\
						destroy_ennemy.c						\
						$(SRC_ENNEMY_UPDATE)					\
						is_player_in_range.c
SRC_ENNEMY			:=	$(addprefix ennemy/,$(SRC_ENNEMY))
# ----------------------------------------------------------------------------
# -------- SRC_LAUNCH --------------------------------------------------------
SRC_LAUNCH			:=	launch_game.c							\
						launch_stage.c							\
						move_object_between_scene.c				\
						launch_story_mode.c						\
						replace_objects_in_next_stage.c			\
						launch_next_stage.c						\
						scene_loading_basic.c					\
						init_credits.c							\
						init_pause_button.c
SRC_LAUNCH			:=	$(addprefix launch/,$(SRC_LAUNCH))
# ----------------------------------------------------------------------------
# -------------- SRC_MAP -----------------------------------------------------
SRC_SQUARE_UPDATES	:=	is_player_on_square.c					\
						next_stage.c							\
						knockback.c								\
						activate_player_down_scale.c			\
						activate_player_up_scale.c				\
						activate_dash.c							\
						spawner.c								\
						npc_spawner.c
SRC_SQUARE_UPDATES	:=	$(addprefix square_updates/,$(SRC_SQUARE_UPDATES))

SRC_MAP				:=	stage_map_to_collision_array.c			\
						wordarray_free_cast.c					\
						check_player_pos_in_map.c				\
						square_set_components.c					\
						check_collision.c						\
						create_map.c							\
						create_collision_map.c					\
						$(SRC_SQUARE_UPDATES)
SRC_MAP				:=	$(addprefix map/,$(SRC_MAP))
# ----------------------------------------------------------------------------
# ------- SRC_PLAYER ---------------------------------------------------------
SRC_EVENT			:=	attack.c								\
						roulade.c								\
						move.c
SRC_EVENT			:=	$(addprefix event/,$(SRC_EVENT))

SRC_UPDATE			:=	update_player.c							\
						update_roulade.c						\
						update_hurt.c							\
						update_movement.c						\
						update_attack.c							\
						update_scale_with_height.c				\
						handle_player_down_scaling.c			\
						handle_player_up_scaling.c
SRC_UPDATE			:=	$(addprefix update/,$(SRC_UPDATE))

SRC_STAT_UPGRADE	:=	upgrade_stat.c							\
						stats_component.c						\
						gain_xp.c								\
						upgrade_dammage.c
SRC_STAT_UPGRADE	:=	$(addprefix stat_upgrade/,$(SRC_STAT_UPGRADE))

SRC_INVENTORY		:=	create_inventory.c						\
						inventory_event.c						\
						update_data_json_inv.c					\
						toggle_key_obj.c						\
						heal.c									\
						create_nbr_potions_text.c
SRC_INVENTORY		:=	$(addprefix inventory/, $(SRC_INVENTORY))

SRC_PLAYER			:=	set_stop.c								\
						create_player.c							\
						player_check_hurt_during_attack.c		\
						player_check_hurt.c						\
						destroy_player.c						\
						set_player_default_stats.c				\
						init_player_scale_handling.c			\
						$(SRC_EVENT)							\
						$(SRC_UPDATE)							\
						$(SRC_STAT_UPGRADE)						\
						$(SRC_INVENTORY)
SRC_PLAYER			:=	$(addprefix player/,$(SRC_PLAYER))
# ----------------------------------------------------------------------------
# -------- SRC_HUD ----------------------------------------------------------
SRC_HUD				:=	manage_hud.c							\
						add_main_menu_elements_to_hud_list.c	\
						hud_apply_right_pos.c					\
						init_hud_elements.c						\
						increment_hud_pos.c						\
						init_life_hud.c							\
						init_energy_hud.c						\
						check_evolution_stat.c					\
						init_xp_hud.c							\
						update_xp_bar.c							\
						init_text_hud.c							\
						update_text_hud.c
SRC_HUD				:=	$(addprefix hud/,$(SRC_HUD))
# ----------------------------------------------------------------------------
# -------- SRC_MENU ----------------------------------------------------------
SRC_MAIN			:=	event_menu.c							\
						init_menu.c								\
						init_music.c							\
						sandbox_button.c						\
						pop_up_management.c 					\
						on_click_event.c						\
						exit.c									\
						making_of.c								\
						set_overlay.c
SRC_MAIN			:=	$(addprefix main/,$(SRC_MAIN))

SRC_SETTINGS_MENU	:=	add_new_audio.c							\
						set_drag_objects.c						\
						set_frame.c								\
						toggle_music_in_scene.c					\
						bar_update.c							\
						replace_button.c						\
						button_hover_event.c					\
						drag_button_on.c						\
						drag_button_off.c						\
						init_audio_list.c
SRC_SETTINGS_MENU	:=	$(addprefix settings_menu/,$(SRC_SETTINGS_MENU))

SRC_PAUSE			:=	create_pause_menu.c						\
						home_button_event.c						\
						restart_button.c						\
						pressed_button_event.c					\
						pause_button_event.c
SRC_PAUSE			:=	$(addprefix pause/,$(SRC_PAUSE))

SRC_DEAD			:=	configure_dead_screen.c					\
						event_dead_screen.c						\
						update_dead_screen.c					\
						update_dead_message.c
SRC_DEAD			:=	$(addprefix dead/,$(SRC_DEAD))

SRC_MENU			:=	$(SRC_PAUSE)							\
						$(SRC_MAIN)								\
						$(SRC_SETTINGS_MENU)					\
						$(SRC_DEAD)								\
						button_event_array.c
SRC_MENU			:=	$(addprefix menu/,$(SRC_MENU))
# ----------------------------------------------------------------------------
# ------- SRC_PATHFIND -------------------------------------------------------
SRC_PATH			:=	init_find.c								\
						init_path.c								\
						get_new_pos.c							\
						destroy_pathfind.c						\
						pathfind_add_to_scene.c
SRC_PATH			:=	$(addprefix pathfind/,$(SRC_PATH))
# ----------------------------------------------------------------------------
# -------- SRC_MATH ----------------------------------------------------------
SRC_MATH			:=	check_circle_col.c						\
						get_distance.c							\
						rect_contains_segment.c					\
						get_rand_number.c						\
						get_vector_dir.c						\
						gore_effect.c
SRC_MATH			:=	$(addprefix math/,$(SRC_MATH))
# ----------------------------------------------------------------------------
# --------- SRC_NPC ----------------------------------------------------------
SRC_NPC_EVENT		:=	press_to_continue.c						\
						press_to_quit_dialogues.c
SRC_NPC_EVENT		:=	$(addprefix event/,$(SRC_NPC_EVENT))

SRC_NPC_UPDATE		:=	update_dialog_text.c					\
						update_grandpa.c						\
						magician_view_rotation.c				\
						update_magician.c						\
						update_intro_magician.c					\
						update_dialogue_box.c					\
						update_npc.c							\
						update_elder.c
SRC_NPC_UPDATE		:=	$(addprefix update/,$(SRC_NPC_UPDATE))

SRC_NPC_NPC			:=	callback_npc.c
SRC_NPC_NPC			:=	$(addprefix npc/,$(SRC_NPC_NPC))

SRC_NPC				:=	add_text_dialog.c						\
						add_text_dialog_json.c					\
						aplly_rect_npc.c						\
						create_npc.c							\
						init_dialog.c							\
						pretyprint.c							\
						$(SRC_NPC_EVENT)						\
						$(SRC_NPC_UPDATE)						\
						$(SRC_NPC_NPC)
SRC_NPC				:=	$(addprefix npc/,$(SRC_NPC))
# ----------------------------------------------------------------------------
# --------- SRC_AUDIO ----------------------------------------------------------
SRC_AUDIO			:=	init_sound.c						\
						play_audio.c
SRC_AUDIO			:=	$(addprefix audio/,$(SRC_AUDIO))
# ----------------------------------------------------------------------------
# ------ POP_TEXT_GENERATOR --------------------------------------------------
SRC_POP_TEXT_GENERATOR	:=	create_pop_text.c		\
							create_stat_pop_text.c	\
							update_text.c
SRC_POP_TEXT_GENERATOR	:=	\
					$(addprefix pop_text_generator/,$(SRC_POP_TEXT_GENERATOR))
# ----------------------------------------------------------------------------
# ------ SRC -----------------------------------------------------------------
SRC					:=	main.c									\
						$(SRC_LAUNCH)							\
						$(SRC_POP_TEXT_GENERATOR)				\
						$(SRC_PATH)								\
						$(SRC_MAP)								\
        				$(SRC_MENU)								\
						$(SRC_PLAYER)							\
						$(SRC_ENNEMY)							\
						$(SRC_METEO)							\
						$(SRC_MATH)								\
						$(SRC_HUD)								\
						$(SRC_NPC)								\
						$(SRC_AUDIO)
SRC					:= 	$(addprefix src/,$(SRC))
# ----------------------------------------------------------------------------
# ----- OBJ ------------------------------------------------------------------
OBJ						:=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------
# ****************************************************************************

# ****************************************************************************
# ----------------------------------------------------------------------------
# LIB
LIB_TARGET			=	lib/libmy.a

LDFLAGS				=	-L$(dir $(LIB_TARGET)) -lmy -lcsfml-graphics \
						-lcsfml-audio -lcsfml-system -lcsfml-window -lm
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# TEST
TFLAGS				=	-fprofile-arcs -ftest-coverage -Ilib/libbgs/include/
CR_TEST_LDFLAGS		=	-lcriterion -lgcov
FN_TEST_LDFLAGS		=	-lgcov

TSRCDIR				:=	./tests/crit_test/

TSRC				:=	rect_contains_segment.c
TSRC				:=	$(addprefix $(TSRCDIR),$(TSRC))
TSRC				:= 	$(filter-out src/main.c,$(SRC)) $(TSRC)

TOBJ				:=	$(TSRC:%.c=%.o)
# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e $(BLUE)'[builded]'$(RESET)': $(notdir $^) -> $(notdir $@)'

# ----------------------------------------------------------------------------
# Make the rpg
.PHONY: 		all
all:			RULE = all
all:			$(LIB_TARGET) $(NAME)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

$(NAME):		RULE = $(NAME)
$(NAME): 		$(OBJ)
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

$(LIB_TARGET):
	@$(MAKE) -s -C $(dir $(LIB_TARGET)) $(RULE)

.PHONY: 		debug
debug:			RULE = debug
debug:			CFLAGS += -g3
debug:			fclean $(LIB_TARGET) $(NAME)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Mr. lean
.PHONY: 		clean
clean:
	@$(RM) $(OBJ) $(TOBJ)
	@$(RM) $(TOBJ:.o=.gcno) $(TOBJ:.o=.gcda) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	@$(RM) vgcore.*

.PHONY: 		fclean
fclean:			RULE = fclean
fclean:			clean
	@$(MAKE) -C $(dir $(LIB_TARGET)) fclean -s
	@$(RM) $(NAME)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Re
.PHONY: 		 re
re:				RULE = re
re:				fclean all
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(RULE)'$(RESET)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Test
.PHONY: 		tests_run
tests_run:		cr_tests_run

.PHONY: 		cr_tests_run
cr_tests_run:	LDFLAGS += $(CR_TEST_LDFLAGS)
cr_tests_run:	CFLAGS += $(TFLAGS)
cr_tests_run:	fclean $(LIB_TARGET) $(TOBJ)
	@$(CC) $(TOBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)
	@./$(NAME)
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branch

.PHONY:		 	fn_tests_run
fn_tests_run:	LDFLAGS += $(FN_TEST_LDFLAGS)
fn_tests_run:	CFLAGS += $(TFLAGS)
fn_tests_run:	fclean $(LIB_TARGET) $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)
	@./tests/fn_tests.sh ./$(NAME)
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branch
# ----------------------------------------------------------------------------
