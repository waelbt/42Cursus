/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 08:31:26 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/05 15:55:59 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define IMG_SIZE 50
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct assets{
	void	*pla;
	void	*wall;
	void	*col;
	void	*exit;
	void	*bg;
}	t_assets;
typedef struct s_vars {
	void	*mlx;
	void	*win;

	char	**matrix;

	t_assets assets;

	int		width;
	int		height;
	int		moves;

	int		e;
	int		c;
	int		p;
	int		posx;
	int		posy;
}				t_vars;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_beta(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strldup(const char *s1, int len);
int		wall_check(char *str, t_vars *dim);
int		stranger_check(char *str);
void	content_counter(char *str, t_vars *a);
int		ft_check(t_vars *dim);
void	ft_dimension(char *str, t_vars *dim);
void	ft_matrix(char *str, t_vars *dim);
void	free_matrix(char **ptr, int len);
int		check_end_of_file(char *str, t_vars *dim);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	error(char *str);
int		ft_putstr(char *s);
void	ft_render(t_vars *vars);
void	find_player(t_vars *data);
void	moves(t_vars *data, int keycode);
void	initialise_images(t_vars *v, char *e);
int		count_c(t_vars *data);
int		find_exit(t_vars *data);
int		ft_putnbr(int nb);
int		charcmp(char c, char i, char j);
void	norm(t_vars *v, int i, int j);
#endif