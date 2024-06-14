# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagea <lagea@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 16:07:15 by lagea             #+#    #+#              #
#    Updated: 2024/05/21 13:10:25 by lagea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = libft.a

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIB_DIR = ../lib/
LIBNAME = $(LIB_DIR)$(NAME)

SRC = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c \
		src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_memchr.c \
		src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_strchr.c \
		src/ft_strdup.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c \
		src/ft_strnstr.c src/ft_strrchr.c src/ft_tolower.c src/ft_toupper.c \
		src/ft_substr.c src/ft_strjoin.c src/ft_split.c src/ft_itoa.c \
		src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c src/ft_strtrim.c src/ft_striteri.c src/ft_strmapi.c \
		src/ft_lstnew_bonus.c src/ft_lstadd_front_bonus.c src/ft_lstadd_back_bonus.c \
		src/ft_lstlast_bonus.c src/ft_lstclear_bonus.c src/ft_lstdelone_bonus.c \
		src/ft_lstmap_bonus.c src/ft_lstsize_bonus.c src/ft_lstiter_bonus.c \
		src/printf.c src/parse.c src/print_elements.c \
		src/print_elements_2.c src/utils_len.c src/ft_putunbr_fd.c src/ft_atol.c \
		src/dll_insert_head.c src/dll_insert_tail.c src/dll_new_node.c \
		src/dll_print_forward.c src/dll_size.c src/dll_clear.c \
		src/dll_delete_head.c src/dll_delete_tail.c src/dll_print_backward.c \
		src/get_next_line.c src/get_next_line_utils.c 

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC = gcc
RM	= rm -rf
CFLAGS = -Wall -Wextra -Werror
INCS = -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling Libft... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -g -c $< -o $@
	$(call progress_bar_push_swap)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating libft library $(LIBNAME)...$(NC)"
	@mkdir -p $(LIB_DIR)
	@ar rc $(LIBNAME) $(OBJ)
	@echo "$(BLUE)Library libft created!$(NC)"
	
clean:
	@echo "$(ORANGE)Cleaning objects libft...$(NC)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Cleaned objects libft!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning libft...$(NC)"
	@$(RM) $(LIBNAME)
	@rm -rf $(LIB_DIR)
	@echo "$(BLUE)Fully cleaned libft!$(NC)"

re: fclean all

.PHONY: all clean fclean re