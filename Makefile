# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2023/09/11 18:48:20 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	$(addsuffix .c, 			\
		$(addprefix srcs/,			\
		main 						\
		error						\
		parsing						\
		get_files					\
			$(addprefix tree/,		\
			new_tree				\
			tree_manipulation		\
			tree_utils				\
			tree_nodes				\
			delete_tree				\
			)						\
		))

SHELL	= /bin/zsh

OBJ		= ${SRC:srcs/%.c=obj/%.o}

CC		= gcc

LIBFT	= libft/libft.a

INCLUDE = -Iinclude/

CFLAGS	= -Wall -Werror -Wextra ${INCLUDE} -g -fsanitize=address

NAME	= ft_ls

MAKE	= --silent --jobs

MY_MAKE	= make --silent --jobs

total	:= $(shell echo ${SRC} | wc -w)

percent	:= 0

current	:= 1

save_percent ?= 0

len := $(shell echo ${NAME} | wc -c)

all:
	@${MY_MAKE} setup
	@${MY_MAKE} libft_rule
	@echo -ne "\033[7;3H\033[1;32mObjets deja compilés!\033[m";
	@make --silent ${OBJ}
	@echo -ne "\033[12;3H\033[1;32m${NAME} deja compilé!\033[m";
	@echo -ne "\033[14;H"
	@make --silent ${NAME}
	@${MY_MAKE} end_make

obj/%.o: srcs/%.c
	@printf "\033[7;2H                                                  \033[7;3H%s" $< ${<:.c=⠀⠀}
	@echo -ne "\033[14;H"
	@${CC} ${CFLAGS} -c $< -o ${<:srcs/%.c=obj/%.o}	
	@$(eval percent=$(shell expr ${current} "*" 100 / ${total}))
	@echo -ne "\033[8;3H"
	@printf "%d/%d:   \t\t%d%%" ${current} ${total} ${percent}
	$(call loading,${percent})
	@$(eval current=$(shell expr ${current} + 1))

${NAME}: ${OBJ}
	@${CC} ${OBJ} ${LIBFT} ${CFLAGS} -o ${NAME}
	@printf "\033[12;3H\033[1mCompilation de ${NAME} \033[32mterminee\033[1;37m!";
	@${MY_MAKE} end_make

setup:
	@echo -ne "\033[0;0H\033[J"
#	@echo -ne "\033[?25l"
	@echo -ne "\033[1;38;5;57m"
	@echo "╔══════════════════════════════════════════════════╗"
	@echo "╟────────────────┤ \033[3mTURBO MAKEFILE ├────────────────╢"
	@echo "║ Libft:                                           ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ Objets:                                          ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ Executable:                                      ║"
	@echo "║                                                  ║"
	@echo "╚══════════════════════════════════════════════════╝"
	@echo -ne "\033[m"

define loading
	@$(eval save_percent=$(shell expr ${percent}))
	@echo -ne "\033[9;13H"
	@save_percent=$(shell expr ${save_percent} "*" 2); \
	while (( $${save_percent} > 7)) ; do \
		echo -ne "\033[47;32m█"; \
		((save_percent-=7)); \
	done;	\
	echo "\u`printf '%x' $(expr 9608 + $$save_percent)`"		
	@echo -ne "\033[0m"
	@true
endef

libft_rule:
	@if [[ -f ${LIBFT} ]] ;	\
			then;	\
				echo -ne "\033[4;3H\033[1;32mLibft deja compilée!\033[m";	\
			else; \
				echo -ne "\033[4;3HCompilation de la libft: \033[33mEn cours...\033[m"; \
				${MY_MAKE} -C libft >/dev/null; \
				if [[ $$? -eq 0 ]] ; \
				then; \
					echo "\033[11D\033[1;32mOK!        \033[m"; \
			fi; \
		fi;

end_make:
	echo -ne "\033[14;H\033[?25h\033[0m"

re: fclean all

fclean:
	@make -C libft fclean 
	@rm -rf ${NAME} ${OBJ} 

clean:
	@make -C libft clean
	@rm -rf ${OBJ}

.PHONY: clean fclean re end_make all setup libft_rule
