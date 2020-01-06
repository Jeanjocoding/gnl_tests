#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*cat_writer(char *file)
{
	char	*command;

	command = ft_strjoin("cat ", file);
	return (command);
}

char	*echo_writer(char *line, char *file)
{
	char	*command;
	char	*first_str;
	char	*second_str;

	first_str = ft_strjoin("echo \"", line);
	second_str = ft_strjoin(first_str, "\" >> ");
	ft_strdel(&first_str);
	command = ft_strjoin(second_str, file);
	ft_strdel(&second_str);
	return (command);
}

char	*diff_writer(char *file1, char *file2)
{
	char	*command;
	char	*first_str;
	char	*second_str;

	first_str = ft_strjoin("diff -s ", file1);
	second_str = ft_strjoin(first_str, " ");
	ft_strdel(&first_str);
	command = ft_strjoin(second_str, file2);
	ft_strdel(&second_str);
	return (command);
}

int	main(int ac, char **av)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	i;
	char	*line;
//	char	*command;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open("multi_1", O_RDONLY);
	fd3 = open("multi_2", O_RDONLY);
	fd4 = open("multi_3", O_RDONLY);

	printf("%s\n\n", "début des tests...");
	printf("%s\n\n", "contenu du premier fichier : ");
	system(cat_writer(av[1]));
	printf("%s\n\n", "--------------");
	printf("%s\n\n", "resultat gnl : ");
	while (get_next_line(fd1, &line))
	{
		printf("%s\n", line);
//		return (0);
		system(echo_writer(line, "log_test1"));
		free(line);
	}
	close(fd1);
	printf("%s\n\n", "--------------");
	printf("%s\n\n", "diff test: ");
	system(diff_writer(av[1], "log_test1"));
	i = 0;
	printf("%s\n\n", "multi_fd: ");
	while (i < 10)
	{
		printf("ret : %d line : ", get_next_line(fd2, &line));
		printf("multi 1 : %s\n", line);
//		free(line);
		printf("ret : %d line : ", get_next_line(fd3, &line));
		printf("multi 2 %s\n", line);
//		free(line);
		printf("ret : %d line : ", get_next_line(fd4, &line));
		printf("multi 3 %s\n", line);
//		free(line);
		i++;
	}
	/*printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);*/
	return (0);
}
