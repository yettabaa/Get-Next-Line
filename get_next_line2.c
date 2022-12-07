/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:29:36 by yettabaa          #+#    #+#             */
/*   Updated: 2022/11/05 00:57:01 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	len_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static	char	*opti_fonction(char **stock)
{
	char	*str;
	char	*temp;

	if (!*stock)
		return (NULL);
	if (*stock[0] == '\0')
		return (free(*stock), NULL);
	if (ft_strchr(*stock, '\n') != NULL)
	{
		str = ft_substr(*stock, 0, len_new(*stock) + 1);
		temp = ft_strdup(ft_strchr(*stock, '\n') + 1);
		free(*stock);
		*stock = temp;
	}
	else
	{
		str = ft_strdup(*stock);
		free(*stock);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	int			t;
	char		*gnl;
	char		*temp;
	char		*baf;
	static char	*stock;  // data segment // struct needs all variables to be stocked in one segment 

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	baf = malloc(BUFFER_SIZE +1);
	if (!baf)
		return (NULL);
	t = BUFFER_SIZE;
	while (t > 0 && !ft_strchr(stock, '\n'))
	{
		t = read(fd, baf, BUFFER_SIZE);
		if (t <= 0)
			break ;
		baf[t] = '\0';
		temp = ft_strjoin(stock, baf);
		free(stock);
		stock = temp;
	}
	gnl = opti_fonction(&stock);
	return (free(baf), gnl);
}
int main()
{
	int fd = open("/dev/urandom", O_RDONLY | O_CREAT, 0777);
	// close(fd);
	// int fd1 = open("test1", O_RDONLY );
	// printf("fd %d fd1 %d\n",fd, fd1);
	char *line;
	int i=0;
	while (1)
	{
	    line =  get_next_line(fd);
	    if(line == NULL)
	        break;
	    printf("%s", line);
	    free(line);
	}
// 	// printf("%d", _SC_OPEN_MAX);
// 	// printf("line 1; %s\n", get_next_line(fd));
// 	// printf("line 2; %s\n", get_next_line(fd1));
// 	// printf("line 3; %s\n", get_next_line(fd));
// 	// printf("line 4; %s\n", get_next_line(fd));
// 	// printf("line 5; %s\n", get_next_line(fd1));
// 	// printf("line 6; %s\n", get_next_line(fd1));
// 	// printf("line 6; %s\n", get_next_line(fd));
// }