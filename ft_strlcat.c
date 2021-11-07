/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:15 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:21:16 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = 0;
	len_src = 0;
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	while (src[len_src] != '\0')
		len_src++;
	while (src[i] != '\0' && (len_dst + i < dstsize - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (len_dst < dstsize)
		dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}
