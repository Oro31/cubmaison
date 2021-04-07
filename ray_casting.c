#include "header.h"
#include <math.h>

float	vert_intersect(t_vars *vars, float a, int signe)
{
	int	y;
	int	x;
	float 	len;
	float	tmp;

	y = vars->ninja[0].posy;
	x = vars->ninja[0].posx + 16 + (signe * (16 * (sin(a) / cos(a))));
	while (vars->monde.map[x / 32][(y / 32) - 1] != 0)
	{
		y = y - 32;
		x = x + (signe * (32 * (sin(a) / cos(a))));
	}
	tmp = pow(vars->ninja[0].posx + 16 - x, 2) + pow(vars->ninja[0].posy + 16 - y, 2);
	len = sqrt(tmp);
	return (len);
}

float	horiz_intersect(t_vars *vars, float a, int signe)
{
	int     y;
        int     x;
	float	tmp;
	float	len;

        x = vars->ninja[0].posx + ((32 + (signe * 32)) / 2);
        y = vars->ninja[0].posy + 16 - (16 / (sin(a) / cos(a)));
        while (vars->monde.map[(x + signe) / 32][y / 32] != 0)
        {
                x = x + (signe * 32);
                y = y - (32 / (sin(a) / cos(a)));
        }
	tmp = pow(vars->ninja[0].posx + 16 - x, 2) + pow(vars->ninja[0].posy + 16 - y, 2);
	len = sqrt(tmp); 
        return (len);
}

float	len_closest_wall(t_vars *vars, float a, int signe)
{
	float	x;
	float	y;

	x = horiz_intersect(vars, a, signe);
	y = vert_intersect(vars, a, signe);
	if (x >= y)
		return (y);
	else
		return (x);
}

void	findalloc_walls(t_vars *vars, float walls[640])
{
	int	i;
	float	a;

	a = 1.047 / 640;
	printf("a = %f \n", a);
	i = 0;
	while (i < 320)
	{
		walls[i] = len_closest_wall(vars, 0.5236 - (i * a), -1);
		i++;
	}
	i++;
	while (i < 640)
	{
		walls[i] = len_closest_wall(vars, (i - 320) * a, 1);
		i++;
	}
}
