/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:41:37 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/23 12:38:42 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif
# define MAX_FD 1024

char	*get_next_line(int fd);
char	*update_queue(char *s, int start, size_t len);
char	*add_buffer_to_queue(char *queue, char *buff, int bytes_read);
char	*check_queue(int *nl_index, char **queue, char *line, int bytes_read);
int		read_fd(int fd, int *bytes_read, char *buff, char **queue);
char	*ft_fill_line(char *queue, int *eol_index, int bytes_read);
void	free_str(char **str);
int		find_char_index(char *str, int searchedChar);
#endif