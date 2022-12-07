/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:35:27 by yettabaa          #+#    #+#             */
/*   Updated: 2022/11/03 22:52:38 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	len_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static	char	*stock_str(char **stock, int fd)
{
	char	*new_s;

	if (ft_strchr(stock[fd], '\n'))
	{
		new_s = ft_strdup(ft_strchr(stock[fd], '\n') + 1);
		free(stock[fd]);
		return (new_s);
	}
	new_s = NULL;
	return (new_s);
}

static	char	*stop_at_nel(char **stock, int fd)
{
	char	*gnl;

	if (!stock[fd])
		return (NULL);
	if (stock[fd][0] == '\0')
		return (free(stock[fd]), NULL);
	if (ft_strchr(stock[fd], '\n'))
	{
		gnl = ft_substr(stock[fd], 0, len_new(stock[fd]) + 1);
		return (gnl);
	}
	else
	{
		gnl = ft_strdup(stock[fd]);
		free(stock[fd]);
		stock[fd] = NULL;
	}
	return (gnl);
}

char	*get_next_line(int fd)
{
	int			t;
	char		*gnl;
	char		*temp;
	char *baf; 
	static char	*stock[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	baf = malloc(BUFFER_SIZE + 1);
	if (!baf)
		return NULL;
	t = BUFFER_SIZE;
	while (t > 0 && !ft_strchr(stock[fd], '\n'))
	{
		t = read(fd, baf, BUFFER_SIZE);
		if (t <= 0)
			break ;
		baf[t] = '\0';
		temp = ft_strjoin(stock[fd], baf);
		free(stock[fd]);
		stock[fd] = temp;
	}
	gnl = stop_at_nel(stock, fd);
	stock[fd] = stock_str(stock, fd);
	return (free(baf), gnl);
}
// #include <sys/types.h>
// #include<sys/uio.h>
#include<limits.h>
int main()
{
	int fd = open("test", O_RDONLY);
	// close(fd);
	// int fd1 = open("test1", O_RDONLY );
	// printf("fd %d fd1 %d\n",fd, fd1);
	char *line;
	int i=0;

	// printf("%d", _SC_OPEN_MAX);
	// printf("line 1; %s\n", get_next_line(fd));
	// printf("line 2; %s\n", get_next_line(fd));
	// printf("line 3; %s\n", get_next_line(fd));
	// printf("line 4; %s\n", get_next_line(fd));
	// printf("line 5; %s\n", get_next_line(fd));
	// printf("line 6; %s\n", get_next_line(fd));
	// printf("line 6; %s\n", get_next_line(fd));
	printf("%d", OPEN_MAX);
}
