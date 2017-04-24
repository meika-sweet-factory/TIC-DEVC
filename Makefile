WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
		-Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
		-Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
		-Wuninitialized -Wconversion -Wstrict-prototypes

CFLAGS ?= -std=gnu99 -g $(WARNINGS) -fpic

OBJDIR := obj
SRCDIR := src

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

SRCF := file.c \
		game.c \
		helper.c \
		pile.c \
		player.c \
		main.c

SRCS := $(patsubst %, $(SRCDIR)/%, $(SRCF))
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
	$(SILENCER)$(RM) -r $(OBJDIR)

fclean: clean
	$(SILENCER)$(RM) -f *~ $(NAME) $(NAME).so $(NAME).a

re: fclean $(LIBS) $(LIBD)

.PHONY: re fclean clean all

-include $(DEPS)
