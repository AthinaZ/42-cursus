/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:48:50 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:48:52 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H
# include "../libutils/libutils.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# define MAP_SPACE_VAL 0

# define W_CODE 13
# define A_CODE 0
# define S_CODE 1
# define D_CODE 2
# define L_A_CODE 123
# define R_A_CODE 124
# define SHIFT_CODE 257
# define ESC_CODE 53
# define L_BUTTON 1
# define R_BUTTON 2
# define R_VEL 0.07
# define MI_P
# define NORMAL_SPEED 0.1
# define RUNNING_SPEED 0.2
# define U_C unsigned char

/*
** Structures
*/

typedef struct s_color
{
	char		*red;
	char		*blue;
	char		*green;
	int			n_color;
}				t_color;

typedef struct s_size
{
	int			size_x;
	int			size_y;
}				t_size;

/*
**Structures mlx
*/

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_mouse_ck
{
	int			button;
	int			pos_x;
	int			pos_y;
}				t_mouse_ck;

typedef struct s_mouse_pos
{
	int			pos_x;
	int			pos_y;
}				t_mouse_pos;

typedef struct s_keys
{
	int			w_key;
	int			a_key;
	int			s_key;
	int			d_key;
	int			left_arrow;
	int			right_arrow;
	int			shift;
	int			esc;
}				t_keys;

/*
**Player_structs
*/

typedef struct s_plane
{
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
}				t_plane;

typedef struct s_s_caster
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			d;
	int			tex_y;
}				t_s_caster;

typedef struct s_caster
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	float		*z_buffer;
	t_s_caster	sprite_caster[1];
}				t_caster;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		tilt;
	float		speed;
	t_plane		plane[1];
	t_caster	caster[1];
}				t_player;
/*
**texture
*/
typedef struct s_texture
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			img_w;
	int			img_h;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_textures
{
	t_texture	n_texture[1];
	t_texture	s_textture[1];
	t_texture	e_texture[1];
	t_texture	w_texture[1];
	t_texture	sprite_texture[1];
	t_texture	skybox[1];
}				t_textures;

typedef struct s_coords
{
	float			x;
	float			y;
}				t_coords;

/*
**ALLTHEFREAINGWINDOWISHERE_____________________________________________
*/

typedef struct s_game
{
	char		*res_w;
	char		*res_h;
	int			res_w_nu;
	int			res_h_nu;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*sprite_texture;
	char		*skybox;
	t_color		fcolor[1];
	t_color		ccolr[1];
	t_coords	*s_cords;
	int			s_count;
	char		**map;
	t_size		map_size[1];
	int			bonus;
	int			save;
}				t_game;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	t_data		curr_img[1];
	t_mouse_ck	click[1];
	t_mouse_pos	mouse_pos[1];
	t_keys		keys[1];
	int			close;
	t_game		*game;
	t_player	plr[1];
	t_textures	textuures[1];
}				t_window;

/*
**figures_structs
*/

/*
** String_utilities
*/

int				ft_numlen(char **str);
void			ft_jump_spaces(char **str);
char			*ft_strjoin_new_line(char const *s1, char const *s2);
void			change_char_in_s(char *str, char dest, char substitute);
int				is_in_cset(char c, char *c_set);
int				check_string(char *to_check, char *checker);

/*
**Gen_utils
*/

void			initialize_vars(int vars_number, ...);
void			free_if_exists(void **var);
void			free_mat(void **mat);
int				check_suffix(char *str, char *suffix);

/*
** game_utils_functions
*/

char			*take_value_s_cub_parser(char **str, int offset);
void			fill_color(char **str, int offset, t_color *color);
void			free_game(t_game *game);
void			resize_to_screen_size(t_game *game, t_window *window);

/*
** game_checks
*/

int				is_color_filled(t_color *color);
int				is_map_moment(t_game *game);
int				is_texture_valid(char *text_name);
int				validator(t_game *game);
int				are_game_ok(t_game *game);

/*
** Map_filler
*/

void			print_mat(char **mat);
void			copy_mat(char **dest, char **src);
size_t			mat_len(char **mat);
void			add_string_to_mat(char ***mat, char *str);
void			mat_size(t_game *game);

/*
**Player_checks
*/

int				just_one_player(char **map);
void			player_positioner(t_player *player, int pos_x, int pos_y,
					char dir);
void			where_is_the_player(char **map, t_player *player);

/*
**Map_c
*/

int				check_around_walkables(int index, char *prev, char *curr,
					char *next);
int				intermidiate_row(char *prev, char *curr, char *next);
int				is_map_valid(char **map);

/*
**Sprites_funcs
*/

void			sprites_filler(t_game *game);
void			sprite_sorter(t_coords *s_cords, t_player *player,
					t_game *game);

/*
** game_reader_functions
*/

int				game_filler(t_game *game, char *file_path);

/*
**Win_func
*/

void			start_win(t_window *window, t_game *game);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			new_image(t_data *image, t_window *window, int width,
					int height);
int				close_game(t_window *window);

/*
**Mouse funks
*/

int				mouse_click(int button, int pos_x, int pos_y, t_window *window);
int				mouse_pos_mov(int x, int y, t_window *window);

/*
**Struct_cleaners
*/

void			clean_data(t_data *data);
void			clean_mouse_pos(t_mouse_pos *mouse_pos);
void			clean_mouse_click(t_mouse_ck *click);
void			clean_window_struct(t_window *window);
void			clean_keys(t_keys *keys);
void			plane_cleaner(t_plane *plane);
void			game_cleaner(t_game *game);
void			color_cleaner(t_color *color);
void			zero_caster(t_caster *caster);
void			zero_s_caster(t_s_caster *s_caster);
/*
**Keyboard_funcs
*/

int				key_hook_in(int keycode, t_window *window);
int				key_hook_out(int keycode, t_window *window);

/*
**Player_movement
*/

void			increment_degree(float *tilt, float degree,
					t_plane *plane);
void			decrement_degree(float *tilt, float degree,
					t_plane *plane);
void			player_movement(t_keys *keys, t_player *player, char **map);

/*
**Minimap
*/

void			minimap_img(t_data *img, t_window *window, t_player *player,
					int min_fract);

/*
**RAYCASTER
*/

void			sprite_positioner(t_player *player, t_game *game, int i);
void			sprite_dimensioner(t_player *player, t_game *game);
void			sprite_painting_coords_y(t_player *player, t_game *game);
void			sprite_painting_coords_x(t_player *player, t_game *game);
void			sprite_ver_line(int stripe, t_game *game, t_data *img,
					t_window *window);
void			sprite_print(t_player *player, t_game *game, t_data *img,
					t_window *window);
void			sprite_caster(t_player *player, t_game *game, t_data *img,
					t_window *window);
void			ray_pos_and_dir(t_caster *caster, t_game *game, t_player
					*player, int x);
void			ray_collider(t_caster *caster, t_player *player);
void			ray_dda(t_caster *caster, t_game *game);
void			line_measure_dist(t_caster *caster, t_game *game,
					t_player *player);
t_texture		*texture_selector(t_window *window, t_caster *caster);
void			texturer(t_caster *caster, t_player *player, t_game *game,
					t_window *window);
void			ver_line(int x, t_caster *caster, t_window *window,
					t_data *img);
void			cast_ray(t_player *player, t_game *game, t_data *img,
					t_window *window);
void			cast_ray(t_player *player, t_game *game, t_data *img,
					t_window *window);

/*
**textures
*/

void			textures_filler(t_window *window);

/*
**--save
*/

void			screenshot(t_window *window, t_data *img);

#endif
