# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 02:38:16 by ikawamuk          #+#    #+#              #
#    Updated: 2025/07/29 14:06:21 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BONUS_NAME)
BONUS_NAME = philo_bonus

CC = cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))
AR = ar
ARFLAGS = rcs
RM = rm -f
RMDIR = rm -rf

# SRCDIR = src
BONUS_SRCDIR = src
# OBJDIR = obj
BONUS_OBJDIR = obj
INCDIR = include
LIBFTDIR = ../libft
TMPDIR = ar_tmp

# SRCFILES =	

BONUS_SRCFILES =	main_bonus.c\
					perse_arg_bonus.c\
					validate_bonus.c\
					philo_bonus.c\
					set_philo_bonus.c\
					philo_loop_bonus.c\
					monitor_loop_bonus.c\
					thinking_bonus.c\
					eating_bonus.c\
					sleeping_bonus.c\
					$(addprefix utils/, \
					digits_to_uint_bonus.c\
					ft_calloc_bonus.c\
					get_ms_bonus.c\
					get_timestamp_bonus.c\
					is_finished_bonus.c\
					print_state_bonus.c\
					)

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
BONUS_SRCS = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUS_SRCDIR)/%.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRCS))

INCLUDES = $(INCDIR) $(LIBFTDIR)/include

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

all: $(NAME) 
	
$(NAME):

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIR) $(BONUS_OBJDIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@	

# test: all
# 	$(VALGRIND) $(VALGRIND_FLAGS) ./test.sh

.PHONY:all clean fclean re test bonus
