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
CFLAGS		= 	-Iinclude/ -Ilib/include/ -Wall -Wextra -Wpedantic

SRC			:=	src/main.c	\
				./src/ennemy/amongus.c \
				./src/ennemy/amongus_change_rect.c

OBJ			:=	$(SRC:%.c=%.o)
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

TSRC		:=	...
TSRC		:=	$(addprefix $(TSRCDIR),$(TSRC))
TSRC		:= 	$(filter-out $(SRCDIR)main.c,$(SRC)) $(TSRC)

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
