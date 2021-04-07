#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "header.h"

void	byimg_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	else if (keycode == 97)
	{
		init_monde(vars);
		jouer(vars);
	}
	else if (keycode == 122)
		editeur(vars);
	printf("hello from key_hook ! keycode : %d \n", keycode);
	return (0);
}

/*int		mouse_hook(int button, int x, int y, t_vars *vars)
{
	byimg_mlx_pixel_put(&vars->img, x, y, 0x00FF0000);
	if (button == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites[0], (x / 32) * 32, (y / 32) * 32);
	else if (button == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites[1], (x / 32) * 32, (y / 32) * 32);
	printf("hello from mouse_hook ! button : %d, x : %d, y : %d \n", button, x, y);
	return (0);
}*/

int	main(void)
{
	t_vars	vars;

	if (!(vars.mlx = mlx_init()))
		return (0);
	if (!(vars.win = mlx_new_window(vars.mlx, 640, 480, "test1")))
		return (0);
	vars.monde.width = 32;
	vars.monde.height = 32;
	/*if (!(vars.monde.sprites = (void**) malloc(2 * sizeof(void *))))
		return (0);
	if(!(vars.ninja = (t_ninja*) malloc(2 * sizeof(t_ninja *))))
		return (0);
	if (!(vars.ninja[0].ability = (void**) malloc(5 * sizeof(void *))))
		return (0);*/
	/*if (!(vars.img.img = mlx_new_image(vars.mlx, 640, 480)))
	{
		printf("xpm failed \n");
		return (0);
	}*/
	/*vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);*/
	printf("malloc ok ! \n");
	fill_sprites(&vars);
	printf("sprites filled ok ! \n");
	if (!(chargerNiveau(vars.monde.map)))
		return (0);
	printf("niveau chargé \n");
	mlx_hook(vars.win, 2, (1L<<0 | 1L<<2), key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
