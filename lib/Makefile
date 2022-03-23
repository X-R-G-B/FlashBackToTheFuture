##
## EPITECH PROJECT, 2021
## LIBMY
## File description:
## make the libmy
##

# ----------------------------------------------------------------------------
# TARGET
NAME		:=	libmy.a
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# COLOUR
CYAN		:=	'\033[0;36m'
GREEN 		:= 	'\033[0;32m'

RESET		:=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# IN-MAKEFILE SETTINGS
CURR_RULE	=	all
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# SUBMODULE LIB
LBGS		:=	libbgs/libbgs.a

LCONV		:=	libconv/libconv.a

LDICO		:=	libdico/libdico.a

LLIST		:=	liblist/liblist.a

LPUTS		:=	libputs/libputs.a

LSTR		:=	libstr/libstr.a

LWA			:=	libwa/libwa.a

LJSON		:= libjson/libjson.a

LFS			:= libfs/libfs.a

ALL_SUB_LIB	:=	$(LBGS) $(LCONV) $(LDICO) $(LLIST) $(LPUTS) $(LSTR) $(LWA)\
	$(LJSON) $(LFS)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Make big libmy
.PHONY: all
all:	CURR_RULE = all
all:	init $(NAME)
	@echo -e $(GREEN)' -> [finished]: $(NAME): make all'$(RESET)

$(NAME): $(ALL_SUB_LIB)
	ar rcT $(NAME) $(ALL_SUB_LIB)
	ranlib $(NAME)

debug: CURR_RULE = debug
debug: fclean $(NAME)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Call Make of sub-lib

%.a:
	@$(MAKE) -C $(dir $@) $(CURR_RULE) -s
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
.PHONY: clean
clean: 	CURR_RULE = clean
clean:	init
	@echo -e $(GREEN)' -> [finished]: $(NAME): make $(CURR_RULE)'$(RESET)

.PHONY: fclean
fclean: CURR_RULE = fclean
fclean:	init
	@$(MAKE) clean -s
	@$(foreach LIB,$(ALL_SUB_LIB),$(MAKE) -s -C $(dir $(LIB)) fclean;)
	@$(RM) $(NAME)
	@echo -e $(GREEN)' -> [finished]: $(NAME): make $(CURR_RULE)'$(RESET)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
.PHONY: re
re:
	@$(MAKE) fclean -s
	@$(MAKE) all -s
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
.PHONY: init
init:
	@echo -e $(CYAN)' -> [starting]: $(NAME): make $(CURR_RULE)'$(RESET)
# ----------------------------------------------------------------------------
