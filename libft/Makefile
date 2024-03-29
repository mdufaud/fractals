# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:45:20 by mdufaud           #+#    #+#              #
#    Updated: 2015/10/01 16:23:57 by mdufaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname)
ifeq ($(OS),Linux)
SHELL := /bin/bash
else
SHELL := /bin/sh
endif

ifeq ($(OS),Linux)
ECHO = echo -e
else
ECHO = echo
endif

NAME = libft.a
CFLAGS = cc -Wall -Wextra -Werror
IFLAGS = -I includes
PATH_SRC = src
PATH_OBJ = obj
FIRST_SRC = $(addprefix $(PATH_SRC)/, $(shell ls -1 $(PATH_SRC) | head -n 1))
SRC = ft_atoi.c\
	  ft_putcnbr.c\
	  ft_putcnbrendl.c\
	  ft_putcnbr_fd.c\
	  ft_putcnbrendl_fd.c\
	  ft_put_color.c\
	  ft_put_color_fd.c\
	  ft_end_color.c\
	  ft_end_color_fd.c\
	  ft_putlong.c\
	  ft_putlongendl.c\
	  ft_putnbrendl.c\
	  ft_error.c\
	  ft_error_verbose.c\
	  ft_error_file.c\
	  ft_projname.c\
	  ft_hashfind.c\
	  ft_hashdebug.c\
	  ft_hashnew.c\
	  ft_hashadd.c\
	  ft_hashprint_all.c\
	  ft_hashprint.c\
	  ft_hashprintendl.c\
	  ft_hashfree.c\
	  ft_hashdel.c\
	  ft_print_t_type.c\
	  ft_retint_free.c\
	  ft_retptr_free.c\
	  ft_tabprint.c\
	  ft_tabprint_fd.c\
	  ft_tabnew.c\
	  ft_tabinit.c\
	  ft_tabadd.c\
	  ft_tabdel.c\
	  ft_tabfind.c\
	  ft_tabreplace.c\
	  ft_tabcount.c\
	  ft_tabfree.c\
	  ft_tabslip.c\
	  ft_csend.c\
	  ft_send.c\
	  ft_sendendl.c\
	  ft_putbin.c\
	  ft_byteswap.c\
	  ft_printaddr.c\
	  ft_debugaddr.c\
	  ft_bzero.c\
	  ft_debugc.c\
	  ft_strlcat.c\
	  ft_debugchar.c\
	  ft_debugfun.c\
	  ft_debugnbr.c\
	  ft_debugn.c\
	  ft_debugs.c\
	  ft_debugstr.c\
	  ft_debugstrn.c\
	  ft_epur.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_isdigit.c\
	  ft_isspace.c\
	  ft_itoa.c\
	  ft_lstadd.c\
	  ft_lstnew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memdel.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_printlist.c\
	  ft_printtab.c\
	  ft_printtab_fd.c\
	  ft_putcendl.c\
	  ft_putcendl_fd.c\
	  ft_putendltab.c\
	  ft_putdendl.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putdendl_fd.c\
	  ft_putchar.c\
	  ft_putstr_fd.c\
	  ft_strclen.c\
	  ft_strequ.c\
	  ft_strjoin_free.c\
	  ft_strlen.c\
	  ft_strtjoin.c\
	  ft_tabdup.c\
	  ft_tablen.c\
	  ft_putchar_fd.c\
	  ft_putdstr.c\
	  ft_putdstr_fd.c\
	  ft_putcstr.c\
	  ft_putcstr_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdigit.c\
	  ft_strdup.c\
	  ft_strdup_free.c\
	  ft_strncat.c\
	  ft_strnchar.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strfsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strsub_free.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_sub.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c
OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))
INCLUDES = includes/libft.h\
		   includes/debug.h\
		   includes/ermac.h

all: $(NAME)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c) $(INCLUDES)
	@mkdir -p $(PATH_OBJ)
	@$(CFLAGS) $(IFLAGS) -o $@ -c $<
	@ if [ $< == $(FIRST_SRC) ]; then \
			$(ECHO) "\033[32;01mLibft : [ \033[00m\c"; \
		fi
	@$(ECHO) "\033[32;01m.\033[00m\c"

$(NAME): $(OBJ)
	@$(ECHO) "\033[32;01m ]\033[00m"
	@$(ECHO) "\033[32m[ Objects done ]\033[00m"
	@ar rcs $@ $^
	@$(ECHO) "\033[32m[ Library done ]\033[00m"

clean:
	@rm -f $(OBJ)
	@$(ECHO) "\033[31m[ Objects deleted ]\033[00m"

fclean: clean
	@rm -rf $(NAME)
	@$(ECHO) "\033[31m[ $(NAME) deleted ]\033[00m"

re: fclean all

.PHONY: all clean fclean re
