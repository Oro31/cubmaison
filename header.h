#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	posx;
	int	posy;
}		t_data;

typedef	struct	s_ninja {
	void	*img;
	int	posx;
	int	posy;
	int	pv;
	void	*ability[5];
}		t_ninja;

typedef	struct	s_monde {
	void	*sprites[3];
	int	width;
	int	height;
	int	posx;
	int	posy;
	int	map[][15];
}		t_monde;

typedef	struct	s_vars {
	void	*mlx;
	void	*win;
	clock_t	before;
	t_data	img;
	t_ninja	ninja[2];
	t_monde	monde;
}		t_vars;

float	vert_intersect(t_vars *vars, float a, int signe);
float	horiz_intersect(t_vars *vars, float a, int signe);
float	len_closest_wall(t_vars *vars, float a, int signe);
void	findalloc_walls(t_vars *vars, float walls[640]);
void	init_monde(t_vars *vars);
void	show_ability(char a, t_vars *vars);
void	refresh_map(t_vars *vars);
int	close_win(t_vars *vars);
int	key_hook_exit(int keycode, t_vars *vars);
void	jexit(t_vars *vars);
void	attaquerJ(char a, t_vars *vars);
void	deplacerJ(char d, t_vars *vars);
int	jeu_key_hook(int keycode, t_vars *vars);
void	jouer(t_vars *vars);
int	mouse_hook_edit(int button, int x, int y, t_vars *vars);
int	edit_key_hook(int keycode, t_vars *vars);
void	editeur(t_vars *vars);
int	key_hook_menu(int keycode, t_vars *vars);
int	mlx_keypress_hook(t_win_list *win, int (*funct)(), void *param);
void	fill_sprites(t_vars *vars);
int	chargerNiveau(int map[][15]);
int	saveNiveau(int map[][15]);
