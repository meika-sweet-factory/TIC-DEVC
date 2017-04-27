WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
		-Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
		-Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
		-Wuninitialized -Wconversion -Wstrict-prototypes

CFLAGS ?= -std=gnu99 -g $(WARNINGS) -fpic

OBJDIR := Objects
OUTDIR := Outputs
SRCDIR := Sources

NAME := snake_$(shell uname -m)-$(shell uname -s)

ifeq ($(VERBOSE), 1)
    SILENCER := 
else
    SILENCER := @
endif

ifeq ($(DEBUG_BUILD), 1)
    CFLAGS +=-DDEBUG_BUILD
endif

SRCF := chain/file.c 			\
		chain/pile.c 		\
		helpers/type.c 		\
		helpers/print.c 	\
		helpers/string.c 	\
		helpers/random.c	\
		file.c 			\
		map.c 			\
		memory.c 		\
		game.c 			\
		player.c 		\
		main.c

SRCS := $(patsubst %, $(SRCDIR)/%, $(SRCF))
OBJS := $(patsubst %, $(OBJDIR)/%, $(SRCF:c=o))

CFLAGS += -MMD -MP
DEPS := $(patsubst %, $(OBJDIR)/%, $(SRCF:c=d))

all: $(NAME)

objectdir:
	$(SILENCER)mkdir -p $(OBJDIR)

outputdir:
	$(SILENCER)mkdir -p $(OUTDIR)

$(NAME): $(OBJS) | outputdir
	$(SILENCER)$(CC) $(CFLAGS) -o $(OUTDIR)/$(NAME) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | objectdir
	$(SILENCER)$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(SILENCER)find . -name "*.o" -type f -delete
	$(SILENCER)find . -name "*.d" -type f -delete

fclean: clean
	$(SILENCER)$(RM) -rf $(OUTDIR)

re: fclean all

.PHONY: re fclean clean all

-include $(DEPS)
