WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
		-Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
		-Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
		-Wuninitialized -Wconversion -Wstrict-prototypes

CFLAGS ?= -std=gnu99 -g $(WARNINGS) -fpic

OBJDIR := Objects
SRCDIR := Sources

NAME := snake_$(shell uname -m)-$(shell uname -s)

EXEC := $(NAME)

ifeq ($(VERBOSE), 1)
    SILENCER := 
else
    SILENCER := @
endif

ifeq ($(DEBUG_BUILD), 1)
    CFLAGS +=-DDEBUG_BUILD
endif

SRCF := chain/file.c \
		chain/pile.c \
		game.c \
		player.c \
		type.c \
		print.c \
		string.c \
		main.c

SRCS := $(wildcard %, $(SRCDIR)/%, $(SRCF))
OBJS := $(patsubst %, $(OBJDIR)/%, $(SRCF:c=o))

CFLAGS += -MMD -MP
DEPS := $(patsubst %, $(OBJDIR)/%, $(SRCF:c=d))

all: $(EXEC)

createdir:
	$(SILENCER)mkdir -p $(OBJDIR)

$(EXEC): $(OBJS)
	$(SILENCER)$(CC) $(CFLAGS) -o $(NAME) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | createdir
	$(SILENCER)$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(SILENCER)find . -name "*.o" -type f -delete
	$(SILENCER)find . -name "*.d" -type f -delete
	$(SILENCER)$(RM) -f $(NAME)

fclean: clean
	$(SILENCER)$(RM) -f $(NAME)

re: fclean $(LIBS) $(LIBD)

.PHONY: re fclean clean all

-include $(DEPS)
