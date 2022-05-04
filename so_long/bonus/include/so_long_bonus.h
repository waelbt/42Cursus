/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:14:19 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/04 00:50:33 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

# define IMG_SIZE 50

typedef struct frames {
	void	*frame1;
	void	*frame2;
	void	*frame3;
}				t_frames;

typedef struct s_vars {
	char		**matrix;

	void		*mlx;
	void		*win;
	void		*bg;

	t_frames	enemy;
	t_frames	angry;
	t_frames	wall;
	t_frames	count;
	t_frames	assests;

	int			width;
	int			height;
	int			moves;
	int			posx;
	int			posy;
	int			exit_counter;
	int			enemy_counter;
	int			collects_counter;
	int			player_counter;
	int			counter;

}				t_vars;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_beta(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strldup(const char *s1, int len);
int		ft_check(t_vars *dim);
void	ft_dimension(char *str, t_vars *dim);
void	ft_matrix(char *str, t_vars *dim);
int		check_end_of_file(char *str, t_vars *dim);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	error(char *str);
int		ft_putstr(char *s);
void	ft_render(t_vars *v, void *s, void *c);
void	moves(t_vars *data, int keycode);
void	initialise_images(t_vars *v, char *e);
int		count_char(t_vars *data, char c);
int		ft_putnbr(int nb);
int		charcmp(char c, char i, char j);
void	end_game(t_vars *vars, char *str);
char	*ft_itoa(int n);
int		animation(t_vars *vars);
void	norm54(t_vars *v, int i, int j);
int		target_near(t_vars *v,	int x,	int y);
void	angry_enmey(t_vars *v, t_frames f, int i, int j);
int		one_field(t_vars *v, int x, int y);
#endif
