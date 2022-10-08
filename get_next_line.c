/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:25:47 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/19 20:25:55 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char	*box; //no leak untill char
    char	    *new_box;
    char	    *that_line;
    int	        index;
    int	        read_re; //is the vlue that rad can read of **also is len that it do**

    while (read_re >= 0)
    {
        if (!box)
        {
            box = malloc(BUFFER_SIZE);
            if (!box)
                return (NULL);
        }
        else
        {
            index = ft_len(box);
            new_box = malloc(BUFFER_SIZE); // may be calloc with '1'
            box = boxjoin(new_box,box);
            free(new_box);
        }

        read_re = read(fd, (box + index), BUFFER_SIZE);

        if (lemme_see(box) == 1) // found /n or eof
        {
            that_line = find_line(box);
            box = move_line(box);
            return (that_line);
        }
    }
}