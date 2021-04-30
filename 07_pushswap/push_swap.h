/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:12:24 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:12:26 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	int				content;
	int				moving;
	struct s_list	*next;
	struct s_list	*prev;
	int				flag;
	int				lis;
	int				pa;
	int				pb;
}				t_list;

typedef struct s_heads
{
	t_list	*head_a;
	t_list	*head_b;
}				t_heads;

int		ft_many_args(char **argv);
int		ft_one_arg(char **argv, int j);
int		ft_after_spaces(char **argv);
int		ft_isalpha(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_push_convenience(t_heads *heads, t_list *node);
int		ft_findpos(t_heads *heads, t_list *node);
int		ft_node_pos(t_list *head, t_list *node);
int		ft_get_next_line(int fd, char **line);
int		ft_renewbuffer(char *buff);
int		ft_emptybuffer(char *buff);
int		ft_largest(t_heads *heads);
int		ft_findmin(t_list *head);
int		ft_atoi(const char *str);
int		ft_position(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_isc(char c, char *s);
int		ft_issorted(t_list *lst);
int		ft_strlen2(char *s);
int		ft_isdigit(char c);
int		ft_numlen(int num);
char	*ft_itoa(int n);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_pushflags(t_heads *heads, char *ret);
char	*ft_idealmove_values(t_heads *heads, char *ret);
void	ft_argparsing(int argc, char **argv, t_list **head, int j);
void	ft_lstadd_front(t_list *lst, t_list *new);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	ft_parseline(char *line, t_heads *heads);
void	ft_rotation(t_heads *heads, char **ret);
void	ft_printalo2(t_list *tmp, t_list *tmp1);
void	ft_empty_a(t_heads *heads, char **ret);
void	ft_subsequence2(t_list *tmp2, int i);
void	ft_push(t_list **dst, t_list **src);
void	ft_checkargs(int argc, char **argv);
void	ft_checkduplicates(t_list *head);
void	ft_reverse_r(t_list **head);
void	ft_subsequence(t_list *lst);
void	ft_rotate(t_list **head);
void	ft_swap(t_list **head);
void	ft_error(void);
void	ft_printalo(t_heads *heads, int flag);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy2(char *dst, char *src, size_t dstsize);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_strcmp(char *s1, char *s2);
void	ft_two(t_heads *heads, char **ret);
void	ft_three(t_heads *heads, char **ret);
void	ft_five2(t_heads *heads, char **ret);
void	ft_five(t_heads *heads, char **ret);
void	ft_argparsing2(char **arr, t_list **head, int j, t_list *tmp);
int		ft_argparsing3(char **arr, int j);
void	ft_printzero(t_list *tmp);
void	ft_is_sorted(t_heads heads);
int		ft_sortedlist(t_heads heads);
int		ft_check2(char **argv, int i, int j);

#endif
