/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:38:12 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:34:41 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static t_tex	*ft_add_tex(t_tex **head)
{
	t_tex	*curr;

	if (!*head)
	{
		*head = malloc(sizeof(t_tex));
		return (*head);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = malloc(sizeof(t_tex));
	return (curr->next);
}

static size_t	ft_tex_length(char *el)
{
	size_t	tex_len;

	tex_len = 0;
	while (el[tex_len] && el[tex_len] != ' ')
		tex_len++;
	return (tex_len);
}

static char	*ft_get_tex_path(char *el)
{
	char	*tex_path;
	size_t	tex_len;

	tex_len = ft_tex_length(el);
	tex_path = malloc(tex_len + 1);
	if (!tex_path)
		return (NULL);
	ft_strlcpy(tex_path, el, tex_len + 1);
	return (tex_path);
}

int	ft_new_tex(t_tex **head, char *el, int el_id)
{
	t_tex	*new_tex;
	char	*tex_path;

	tex_path = ft_get_tex_path(el);
	if (!tex_path)
		return (ft_error(EMALLOC, NULL));
	new_tex = ft_add_tex(head);
	if (!new_tex)
	{
		free(tex_path);
		return (ft_error(EMALLOC, NULL));
	}
	new_tex->next = NULL;
	new_tex->id = el_id;
	new_tex->tex_path = tex_path;
	return (1);
}
