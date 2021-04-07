#include "header.h"

int	mouse_hook_edit(int button, int x, int y, t_vars *vars)
{
	int	item;

	item = 1;
	if (button == 1)
	{
		item = 0;
	}
	else if (button == 3)
	{
		if (vars->monde.map[x / 32][y / 32] == 1)
			item = 2;
		else if (vars->monde.map[x / 32][y / 32] == 2)
			item = 3;
		else
			item = 1;
	}
	vars->monde.map[x / 32][y / 32] = item;
	if (item > 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[item - 2].img, (x / 32) * 32, (y / 32) * 32);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[item], (x / 32) * 32, (y / 32) * 32);
	return (0);
}

int	edit_key_hook(int keycode, t_vars *vars)
{
	mlx_mouse_hook(vars->win, mouse_hook_edit, vars);
	if (keycode == 97)
	{
		saveNiveau(vars->monde.map);
		jexit(vars);
	}
	else if (keycode == 65307)
		jexit(vars);
	return (0);
}

void	editeur(t_vars *vars)
{
	refresh_map(vars);
	mlx_hook(vars->win, 2, (1L<<0 | 1L<<2), edit_key_hook, vars);
}
