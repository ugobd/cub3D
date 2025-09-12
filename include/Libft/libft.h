/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:51:26 by thphilip          #+#    #+#             */
/*   Updated: 2025/05/23 17:44:20 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/***	Libft	***/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/***	Libft Bonus	***/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *));

/***	My fuction	***/

int		ft_iswhitespace(int c);
void	ft_free_array(char **strs);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoinf(char *s1, char *s2);
int		ft_strlenc(char *str, char c);
char	*ft_strndup(const char *s, size_t n);

/***	Ft_printf	***/

int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbrdec(int num);
int		ft_putnbrhex(unsigned int num, char x);
int		ft_putnbruns(unsigned int num);
int		ft_putpointer(unsigned long num);
int		ft_printf(const char *str, ...);

/***	Ft_printf_fd	***/

int		ft_putnbrdec_fd(int num, int fd);
int		ft_putnbrhex_fd(unsigned int num, char x, int fd);
int		ft_putnbruns_fd(unsigned int num, int fd);
int		ft_putpointer_fd(unsigned long num, int fd);
int		ft_printf_fd(const char *str, int fd, ...);

/***	Get_nest_line	***/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);

#endif
