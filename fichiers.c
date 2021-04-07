#include "header.h"

int	chargerNiveau(int map[][15])
{
	FILE*	fichier;
	char	ligneFichier[20 * 15 + 1];
	int	i;
	int	j;

	if (!(fichier = fopen("niveau.txt", "r")))
			return (0);
	fgets(ligneFichier, 20 * 15 + 1, fichier);
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 15)
		{
			if (ligneFichier[(i * 15) + j] == '0')
				map[i][j] = 0;
			else if (ligneFichier[(i * 15) + j] == '1')
				map[i][j] = 1;
			else if (ligneFichier[(i * 15) + j] == '2')
				map[i][j] = 2;
			else if (ligneFichier[(i * 15) + j] == '3')
				map[i][j] = 3;
			j++;
		}
		i++;
	}
	fclose(fichier);
	return (1);
}

int	saveNiveau(int map[][15])
{
	FILE*	fichier;
	int	i;
	int	j;

	if (!(fichier = fopen("niveau.txt", "w")))
		return (0);
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 15)
		{
			printf("%d \n", fprintf(fichier, "%d", map[i][j]));
			j++;
		}
		i++;
	}
	fclose(fichier);
	return (1);
}

void	fill_sprites(t_vars *vars)
{
	vars->monde.sprites[0] = mlx_xpm_file_to_image(vars->mlx, "../murnoir.XPM", &vars->monde.width, &vars->monde.height);
        vars->monde.sprites[1] = mlx_xpm_file_to_image(vars->mlx, "../vide.XPM", &vars->monde.width, &vars->monde.height);
	vars->monde.sprites[2] = mlx_xpm_file_to_image(vars->mlx, "../sky.XPM", &vars->monde.width, &vars->monde.height);
	printf("mondesprite ok \n");
        vars->ninja[0].img = mlx_xpm_file_to_image(vars->mlx, "../yosume.XPM", &vars->monde.width, &vars->monde.height);
	vars->ninja[1].img = mlx_xpm_file_to_image(vars->mlx, "../orotachiri.XPM", &vars->monde.width, &vars->monde.height);
	printf("ninja sprite ok");
	vars->ninja[0].ability[0] = mlx_xpm_file_to_image(vars->mlx, "../attaqueAdownleft.XPM", &vars->monde.width, &vars->monde.height);
	vars->ninja[0].ability[1] = mlx_xpm_file_to_image(vars->mlx, "../attaqueAdownright.XPM", &vars->monde.width, &vars->monde.height);
	vars->ninja[0].ability[2] = mlx_xpm_file_to_image(vars->mlx, "../attaqueAupleft.XPM", &vars->monde.width, &vars->monde.height);
	vars->ninja[0].ability[3] = mlx_xpm_file_to_image(vars->mlx, "../attaqueAupright.XPM", &vars->monde.width, &vars->monde.height);
	vars->ninja[0].ability[4] = mlx_xpm_file_to_image(vars->mlx, "../attaqueE.XPM", &vars->monde.width, &vars->monde.height);
}
