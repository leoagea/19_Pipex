/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:11 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 17:19:57 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>  //errno
# include <fcntl.h>  //open
# include <limits.h> //Macro INT_MAX
# include <stdarg.h>
# include <stdbool.h> //boolean
# include <stddef.h>  //NULL
# include <stdio.h>   //perror
# include <stdlib.h>  //free
# include <string.h>  //strerror
# include <unistd.h>  //read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_dll
{
	struct s_node	*head;
	struct s_node	*tail;
}					t_dll;

/*------------------------------LIBFT-----------------------------------*/
/*Libc functions*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);

void				ft_bzero(void *str, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*Fonctions additionnelles*/

char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*Partie bonus*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_lstsize(t_list *lst);

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*------------------------------PRINTF----------------------------------*/
/* Printf */

int					ft_print_char(char c);
int					ft_print_string(char *s);
int					ft_print_decimal(int n);
int					ft_print_udecimal(unsigned int n);
int					ft_print_hex(unsigned int n, char *base);

/* Utils_2 */
int					ft_print_udecimal(unsigned int n);
int					ft_print_add(unsigned long add);
int					ft_print_hex_add(unsigned long n);

/* Utils_len */
int					ft_int_len(long n);
int					ft_add_len(unsigned long add);
int					ft_hex_len(unsigned int hex);

/* Parse */
int					ft_check_next_char(const char *s, int index);
int					ft_parse_printf(const char *s, int index, va_list *par);

/* Printf */
int					ft_printf(const char *s, ...);

/*---------------------------ADDED FUNCTIONS------------------------------*/

void				ft_putunbr_fd(unsigned int n, int fd);
long				ft_atol(const char *str);

/*---------------------------DOUBLE LIMKED LIST-------------------------------*/

void				dll_init(t_dll *dll);
t_node				*dll_new_node(int data);
size_t				dll_size(t_dll *dll);
void				dll_insert_head(int data, t_dll *dll);
void				dll_insert_tail(int data, t_dll *dll);
void				dll_delete_head(t_dll *dll);
void				dll_delete_tail(t_dll *dll);
void				dll_print_forward(t_dll *dll);
void				dll_clear(t_dll *dll);

/*-----------------------------GET NEXT LINE----------------------------------*/

/* get_next_line */
char				*get_next_line(int fd);
char				*ft_set_line(char *line_buffer);
char				*ft_fill_line_buffer(int fd, char *stash, char *buffer);

/* get_next_line_utils */
int					my_strlen(const char *str);
char				*strchr_index(char *str);
char				*my_strdup(char *s1);
char				*strjoin(char *s1, char *s2);
char				*substr(char *s, int start, int len);

#endif
