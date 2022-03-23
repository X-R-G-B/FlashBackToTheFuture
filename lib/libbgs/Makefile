##
## EPITECH PROJECT, 2022
## LIB_CONVERSION
## File description:
## make the conversion lib
##

# ----------------------------------------------------------------------------
# TARGET
NAME			=	libbgs.a
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# COLOUR
CYAN			=	'\033[1;36m'
BLUE			=	'\033[1;34m'
GREEN	 		= 	'\033[1;32m'

RESET			=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# IN-MAKEFILE SETTINGS
CURR_RULE		=	all
# ----------------------------------------------------------------------------

SRCDIR			=	src/

# ----------------------------------------------------------------------------
# SRC
SRC_COMPONENTS	:= 	add_components.c					\
					create_event.c						\
					object_add_collision_components.c	\
					object_add_set_sprite_components.c	\
					object_check_event.c				\
					object_set_event.c					\
					object_check_health.c				\
					object_update_mouse_event.c
SRC_COMPONENTS	:= $(addprefix components/,$(SRC_COMPONENTS))

SRC_CORE		:=	add.c					\
					create_object.c			\
					create_scene.c			\
					event.c					\
					scene_reload_lists.c	\
					check_click_prev_call.c	\
					object_set_origin.c		\
					loop.c					\
					object_update.c			\
					remove.c				\
					start.c
SRC_CORE		:=	$(addprefix core/,$(SRC_CORE))

SRC_PRESET		:=	preset_display.c			\
					set_unset_bigdata_display.c
SRC_PRESET		:=	$(addprefix preset/,$(SRC_PRESET))

SRC_UTILS		:=	cast.c			\
					id_generator.c	\
					set_window_style.c
SRC_UTILS		:=	$(addprefix utils/,$(SRC_UTILS))

SRC_HITBOX		:=	check_image_pixel.c			\
					squares_gestion.c			\
					get_right_checkbox.c		\
					find_higher_pixels_group.c	\
					check_collision.c			\
					get_rect_arr.c
SRC_HITBOX		:=	$(addprefix hitbox/,$(SRC_HITBOX))

SRC		:=	$(SRC_COMPONENTS) $(SRC_CORE) $(SRC_PRESET) $(SRC_UTILS)	\
			$(SRC_HITBOX)
SRC		:=	$(addprefix $(SRCDIR),$(SRC))

OBJ		=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# FLAGS
CFLAGS		=	-I../include -Iinclude/ -Wall -Wextra -Wpedantic
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# DEPENDANCES
LIBS_DEP	=	../libdico/libdico.a ../libstr/libstr.a ../liblist/liblist.a
# ----------------------------------------------------------------------------

%.o:	%.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e $(BLUE)'[compil]: $(notdir $^) -> $(notdir $@)'$(RESET)

all: 	CURR_RULE = all
all: 	init
	@$(MAKE) $(NAME) -s

$(NAME): CURR_RULE = $(NAME)
$(NAME): init $(LIBS_DEP) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e $(GREEN)'[finished]: $(NAME): $(CURR_RULE)'$(RESET)

$(LIBS_DEP):
	$(foreach LIB,$(LIBS_DEP),$(MAKE) -C $(dir $(LIB)) $(RULE);)

debug: RULE = debug
debug: CFLAGS += -g3
debug: fclean $(NAME)

clean:	CURR_RULE = clean
clean:	init
	@$(RM) $(OBJ)
	@echo -e $(GREEN)'[finished]: $(NAME): $(CURR_RULE)'$(RESET)

fclean:	CURR_RULE = fclean
fclean:	init
	@$(MAKE) clean -s
	@$(RM) $(NAME)
	@echo -e $(GREEN)'[finished]: $(NAME): $(CURR_RULE)'$(RESET)

re:	CURR_RULE = re
re:	init
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@echo -e $(GREEN)'[finished]: $(NAME): $(CURR_RULE)'$(RESET)

.PHONY: init
init:
	@echo -e $(CYAN)'[starting]: $(NAME): $(CURR_RULE)'$(RESET)
