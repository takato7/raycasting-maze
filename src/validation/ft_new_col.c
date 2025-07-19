/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:38:12 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:34:34 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static t_col	*ft_add_col(t_col **head)
{
	t_col	*curr;

	if (!*head)
	{
		*head = malloc(sizeof(t_col));
		return (*head);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = malloc(sizeof(t_col));
	return (curr->next);
}

static int	ft_get_rgb(t_col *new_col, char *el, int color)
{
	int	error;

	if (*el < '0' || *el > '9')
		return (0);
	error = 0;
	if (color == RED)
		new_col->r = ft_colortoi(&el, &error);
	else if (color == GREEN)
		new_col->g = ft_colortoi(&el, &error);
	else if (color == BLUE)
		new_col->b = ft_colortoi(&el, &error);
	if (error)
		return (0);
	if (color != BLUE)
	{
		if (*el == ',')
			return (ft_get_rgb(new_col, el + 1, color + 1));
		return (0);
	}
	if (*el && !ft_only_trailing_spaces(el))
		return (0);
	return (1);
}

int	ft_new_col(t_col **head, char *el, int el_id)
{
	t_col	*new_col;

	new_col = ft_add_col(head);
	if (!new_col)
		return (ft_error(EMALLOC, NULL));
	new_col->id = el_id;
	new_col->next = NULL;
	if (!ft_get_rgb(new_col, el, RED))
		return (ft_error(ECOLORFORMAT, NULL));
	return (1);
}
