/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:03:56 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/06 12:47:19 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
	|| c == '\f')
		return (1);
	return (0);
}
