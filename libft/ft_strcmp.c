/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:46:48 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/24 15:47:16 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	int					i;

	i = 0;
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (ss1[i] != '\0' && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}