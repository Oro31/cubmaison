#include "header.h"

void	init_monde(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
        {
                j = 0;
                while (j < 15)
                {
                        if (vars->monde.map[i][j] == 0)
                                mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[0], i * 32, j * 32);
                        else if (vars->monde.map[i][j] == 1)
                                mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[1], i * 32, j * 32);
                        else if (vars->monde.map[i][j] == 2)
                        {
				vars->ninja[0].pv = 20;
                                vars->ninja[0].posx = i * 32;
                                vars->ninja[0].posy = j * 32;
                                mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].img, i * 32, j * 32);
			}
                        else if (vars->monde.map[i][j] == 3)
                        {
				vars->ninja[1].pv = 20;
                                vars->ninja[1].posx = i * 32;
                                vars->ninja[1].posy = j * 32;
                                mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[1].img, i * 32, j * 32);
                        }
                        j++;
		}
                i++;
        }
}

void	refresh_map(t_vars *vars)
{
	float	walls[640];
	int	i;
	int	j;
	int	e;

	printf("hello from refresh_map \n");
	findalloc_walls(vars, walls);
	printf("hello findalloc succed \n");
	i = 0;
	while (i < 640)
        {
		j = 0;
		e = (480 - ((32 * 500) / walls[i])) / 2;
		while (j < e)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[2], i, j);
			j++;
		}
		while (j < 480 - e)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[0], i, j);
			j++;
		}
		while (j < 480)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[1], i, j);
			j++;
		}
		i++;
	}
	if (vars->ninja[0].pv > 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].img, vars->ninja[0].posx, vars->ninja[0].posy);
	if (vars->ninja[1].pv > 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[1].img, vars->ninja[1].posx, vars->ninja[1].posy);
}

void	show_ability(char a, t_vars *vars)
{
	if (a == 'a')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[0], vars->ninja[0].posx - 16, vars->ninja[0].posy + 16);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[1], vars->ninja[0].posx + 16, vars->ninja[0].posy + 16);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[2], vars->ninja[0].posx - 16, vars->ninja[0].posy - 16);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[3], vars->ninja[0].posx + 16, vars->ninja[0].posy - 16);
	}
	else if (a == 'e')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[4], vars->ninja[0].posx - 16, vars->ninja[0].posy);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[4], vars->ninja[0].posx, vars->ninja[0].posy);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].ability[4], vars->ninja[0].posx + 16, vars->ninja[0].posy);
	}
}
