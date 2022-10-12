/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:46:07 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/28 15:56:18 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFF_SIZE 	1
# define TRUE		1
# define FALSE		0

typedef unsigned long long int	t_ulong;
typedef long long int			t_long;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_string
{
	char			*content;
	int				size;
	int				alloc_size;
}					t_string;

char				*ft_strndup(const char *src, size_t n);
long int			ft_latoi(const char *str);
char				*ft_litoa(long int n);
void				*ft_realloc(void *ptr, size_t size);
void				ft_intdel(int **array, int nb_of_array);
int					ft_arrlen(char **array);
void				ft_arrdel(char **array);
void				ft_putstr(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_str_replace(char *s, char *add);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
int					ft_strchri(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_long				ft_atoi(const char *str);
int					ft_atoin(const char *str, int len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isdigit_str(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_safe(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_remove_lspace(char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(t_ulong nb, const char *base);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_strsplit_lst(char const *s, char c);
void				**ft_memalloc_2d(size_t x, size_t y);
void				ft_memfree_2d(char **map);
char				*ft_strrev(char *str);
size_t				ft_filelen(char *file);
char				*ft_file_to_char(char *file);
char				**ft_file_to_tab(char *file);
void				ft_putnbr_base(int nbr, char *base);
int					ft_getnbr(char const *s);
int					get_next_line(int const fd, char **line);
int					ft_nb_of_word(char const *s, char c);
int					ft_nb_of_char(char const *s, char c);
char				*ft_putchar_str(char *str, char c);
void				ft_strupper(char *str);
void				ft_strlower(char *str);
void				ft_error(char *preface, char *str);
size_t				ft_strtablen(char **tab);

void				ft_stringinit(t_string *string);
void				ft_stringaddc(t_string *string, char c);
void				ft_stringadd(t_string *string, char *str, int n);
void				ft_stringaddnl(t_string *string, char *str, int n);
int					ft_stringext(t_string *string, int need);
void				ft_stringdelete(t_string *string);
void				ft_stringaddnbr(t_string *string, int nb);

#endif
