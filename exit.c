#include "header.h"

int	close_win(t_vars *vars)
{
	/*int	i;*/

	/*i = 0;
	while (i < 5)
	{
		free(vars->ninja[0].ability[i]);
		i++;
	}*/
	/*free(vars->ninja[0].ability);*/
	/*i = 0
	while (i < 2)
	{
		free(->vars.monde.sprites[i]);
		free(vars->ninja[i].img);
		i++;
	}*/
	/*free(vars->ninja);
	free(vars->monde.sprites);*/
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook_exit(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	return (0);
}

void	jexit(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_hook(vars->win, 2, (1L<<0 | 1L<<3), key_hook_exit, vars);
}
