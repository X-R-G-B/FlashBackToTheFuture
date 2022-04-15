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
CFLAGS			=	-Iinclude/ -Ilib/include/ -Wall -Wextra -Wpedantic

SRC_ENNEMY	:=	amongus.c				\
				amongus_change_rect.c
SRC_ENNEMY	:=	$(addprefix ennemy/,$(SRC_ENNEMY))

SRC_LAUNCH	:=	launch_game.c							\
				launch_stage.c							\
				move_object_between_scene.c				\
				launch_story_mode.c						\
				add_main_menu_elements_to_uid_list.c	\
				uid_apply_right_pos.c					\
				scene_loading_basic.c					\
				temp_file_temp_pause_button.c
SRC_LAUNCH	:=	$(addprefix launch/,$(SRC_LAUNCH))

SRC_SQUARE_UPDATES	:=	is_player_on_square.c	\
						knockback.c
SRC_SQUARE_UPDATES	:=	$(addprefix square_updates/,$(SRC_SQUARE_UPDATES))

SRC_MAP		:=	stage_map_to_collision_array.c	\
				wordarray_free_cast.c			\
				check_player_pos_in_map.c		\
				check_collision.c				\
				create_map.c					\
				create_collision_map.c			\
				$(SRC_SQUARE_UPDATES)
SRC_MAP		:= $(addprefix map/,$(SRC_MAP))

SRC_EVENT	:=	attack.c	\
				move.c
SRC_EVENT	:= $(addprefix event/,$(SRC_EVENT))

SRC_UPDATE		:=	update_player.c		\
					increment_uid_pos.c	\
					update_movement.c	\
					update_attack.c
SRC_UPDATE		:=	$(addprefix update/,$(SRC_UPDATE))

SRC_PLAYER	:=	set_stop.c			\
				create_player.c		\
				destroy_player.c	\
				$(SRC_EVENT)		\
				$(SRC_UPDATE)
SRC_PLAYER	:=	$(addprefix player/,$(SRC_PLAYER))

SRC_MAIN	:=	event_menu.c	\
				init_menu.c		\
				pop_up_management.c
SRC_MAIN	:=	$(addprefix main/,$(SRC_MAIN))

SRC_PAUSE	:=	create_pause_menu.c		\
				home_button_event.c		\
				pressed_button_event.c	\
				pause_button_event.c
SRC_PAUSE	:=	$(addprefix pause/,$(SRC_PAUSE))

SRC_DEAD	:=	configure_dead_screen.c	\
				dead_screen.c
SRC_DEAD	:=	$(addprefix dead/,$(SRC_DEAD))

SRC_MENU	:=	$(SRC_PAUSE)	\
				$(SRC_MAIN)		\
				$(SRC_DEAD)		\
				button_event_array.c
SRC_MENU	:=	$(addprefix menu/,$(SRC_MENU))

SRC_PATH	:=	init_find.c			\
				init_path.c			\
				get_new_pos.c		\
				destroy_pathfind.c
SRC_PATH	:=	$(addprefix pathfind/,$(SRC_PATH))

SRC			:=	main.c				\
				$(SRC_LAUNCH)		\
				$(SRC_PATH)			\
				$(SRC_MAP)			\
        		$(SRC_MENU)			\
				$(SRC_PLAYER)		\
				$(SRC_ENNEMY)
SRC			:= 	$(addprefix src/,$(SRC))

OBJ				:=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# LIB
LIB_TARGET		=	lib/libmy.a

LDFLAGS			=	-L$(dir $(LIB_TARGET)) -lmy -lcsfml-graphics \
					-lcsfml-audio -lcsfml-system -lcsfml-window -lm
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# TEST
TFLAGS			=	-fprofile-arcs -ftest-coverage -Ilib/libbgs/include/
CR_TEST_LDFLAGS	=	-lcriterion -lgcov
FN_TEST_LDFLAGS	=	-lgcov

TSRCDIR		:=	tests/

TSRC		:=	pathfind.c
TSRC		:=	$(addprefix $(TSRCDIR),$(TSRC))
TSRC		:= 	$(filter-out src/main.c,$(SRC)) $(TSRC)

TOBJ		:=	$(TSRC:%.c=%.o)
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
tests_run:		fn_tests_run

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
