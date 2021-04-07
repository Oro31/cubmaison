#include "header.h"

void	attaquerJ(char a, t_vars *vars)
{
	int	i;
	int	j;

	if (a == 'a')
	{
		i = (vars->ninja[0].posx / 32) - 1;
		while (i < (vars->ninja[0].posx / 32) + 2)
		{
			j = (vars->ninja[0].posy / 32) - 1;
			while (j < (vars->ninja[0].posy / 32) + 2)
			{
				if ((vars->ninja[1].posx / 32) == i && (vars->ninja[1].posy / 32) == j)
					vars->ninja[1].pv -= 1;
				j++;
			}
			i++;
		}
	}
	else if (a == 'e' && vars->ninja[1].posy == vars->ninja[0].posy && vars->ninja[1].posx >= vars->ninja[0].posx - 32 && vars->ninja[1].posx <= vars->ninja[0].posx + 32)
	{
		printf("attaquerE \n");
		vars->ninja[1].pv -= 2;
	}
	show_ability(a, vars);
	if (vars->ninja[1].pv <= 0)
	{
		vars->monde.map[vars->ninja[1].posx / 32][vars->ninja[1].posy / 32] = 1;
	}
}

void	deplacerJ(char d, t_vars *vars)
{
	int	sprite;

	sprite = vars->monde.map[vars->ninja[0].posx / 32][vars->ninja[0].posy / 32];
	if (sprite == 3 || sprite == 2)
		sprite = 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->monde.sprites[sprite], vars->ninja[0].posx, vars->ninja[0].posy);
	if (d == 'z' && vars->monde.map[vars->ninja[0].posx / 32][(vars->ninja[0].posy / 32) - 1] != 0)
		vars->ninja[0].posy -= 32;
	else if (d == 's' && vars->monde.map[vars->ninja[0].posx / 32][(vars->ninja[0].posy / 32) + 1] != 0)
		vars->ninja[0].posy += 32;
	else if (d == 'd' && vars->monde.map[(vars->ninja[0].posx / 32) + 1][vars->ninja[0].posy / 32] != 0)
		vars->ninja[0].posx += 32;
	else if (d == 'q' && vars->monde.map[(vars->ninja[0].posx / 32) - 1][vars->ninja[0].posy / 32] != 0)
		vars->ninja[0].posx -= 32;
	printf("ninja0 posx : %d, ninja0 posy : %d \n", vars->ninja[0].posx, vars->ninja[0].posy);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->ninja[0].img, vars->ninja[0].posx, vars->ninja[0].posy);
}

int	jeu_key_hook(int keycode, t_vars *vars)
{
	clock_t	actual;

	if (keycode == 65307)
		jexit(vars);
	else if (keycode == 122)
		deplacerJ('z', vars);
	else if (keycode == 115)
		deplacerJ('s', vars);
	else if (keycode == 100)
		deplacerJ('d', vars);
	else if (keycode == 113)
		deplacerJ('q', vars);
	else if (keycode == 97)
		attaquerJ('a', vars);
	else if (keycode == 101)
		attaquerJ('e', vars);
	refresh_map(vars);
	return (0);
}

void	jouer(t_vars *vars)
{
	usleep(100000);
	printf("hello from jouer \n");
	mlx_hook(vars->win, 2, (1L<<0 | 1L<<3), jeu_key_hook, vars);
}
