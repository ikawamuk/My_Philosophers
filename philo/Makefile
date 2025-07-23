# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:17:32 by ikawamuk          #+#    #+#              #
#    Updated: 2025/07/23 11:58:28 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
# BONUS_NAME = 

CC = cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))
AR = ar
ARFLAGS = rcs
RM = rm -f
RMDIR = rm -rf

SRCDIR = src
# BONUS_SRCDIR = src/bonus
OBJDIR = obj
# BONUS_OBJDIR = obj/bonus
INCDIR = include
TMPDIR = ar_tmp

SRCFILES =	main.c\
			validate.c\
			perse_arg.c\
			philo.c\
			set_ctx.c\
			set_philosophers.c\
			create_threads.c\
			monitor_loop.c\
			philo_loop.c\
			$(addprefix utils/, \
			digits_to_uint.c\
			ft_calloc.c\
			get_ms.c\
			get_timestamp.c\
			)

# BONUS_SRCFILES = $(patsubst %.c, %_bonus.c, $(SRCFILES))

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
# BONUS_SRCS = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
# BONUS_OBJS = $(patsubst $(BONUS_SRCDIR)/%.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRCS))

INCLUDES = $(INCDIR)

# LIBFT = $(LIBFTDIR)/libft.a

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

all: $(NAME) 
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@	

test: all
	@$(CC) $(CFLAGS) test.c $(LIBFT) -o test
	$(VALGRIND) $(VALGRIND_FLAGS) ./test

.PHONY:all clean fclean re test bonus
