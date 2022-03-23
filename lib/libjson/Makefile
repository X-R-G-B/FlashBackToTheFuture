##
## EPITECH PROJECT, 2022
## LIBPUTS
## File description:
## make the puts lib
##

# ----------------------------------------------------------------------------
# TARGET
NAME		=	libjson.a
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# COLOUR
CYAN		=	'\033[1;36m'
BLUE		=	'\033[1;34m'
GREEN 		= 	'\033[1;32m'

RESET		=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# IN-MAKEFILE SETTINGS
CURR_RULE	=	all
# ----------------------------------------------------------------------------

SRCDIR		=	src/
PARSERDIR 	= 	parser/
WRITERDIR 	= 	writer/
PRINTERDIR 	= 	printer/
GETDIR 		= 	get/

# ----------------------------------------------------------------------------
# SRC
SRC_GET			:= 	get_from_array.c	\
					get.c
SRC_GET			:=	$(addprefix $(GETDIR),$(SRC_GET))

SRC_PARSER		:=	any_dup.c		\
					destroy.c		\
					create_any.c	\
					pop_data.c		\
					fill_dico.c		\
					remove_space.c	\
					fill_data.c		\
					parse.c
SRC_PARSER		:=	$(addprefix $(PARSERDIR),$(SRC_PARSER))

SRC_PRINTER		:= 	prety_print.c	\
					print_dico.c
SRC_PRINTER		:=	$(addprefix $(PRINTERDIR),$(SRC_PRINTER))

SRC_WRITER		:= 	write_json.c
SRC_WRITER		:=	$(addprefix $(WRITERDIR),$(SRC_WRITER))

SRC				:=	$(SRC_PARSER) $(SRC_WRITER) $(SRC_PRINTER) $(SRC_GET)
SRC				:=	$(addprefix $(SRCDIR),$(SRC))

OBJ				=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# FLAGS
CFLAGS		:=	-I../include -Wall -Wextra -Wpedantic \
				-Wno-implicit-fallthrough -Wno-switch
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# DEPENDANCES
LIBS_DEP	=	../libdico/libdico.a ../liblist/liblist.a ../libfs/libfs.a
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
