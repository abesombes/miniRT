/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:57:30 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/15 18:16:38 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_olst.h"

void	ft_display_vec(t_vector *v)
{
	printf("\nv->x: %f - v->y: %f - v->z: %f\n", v->x, v->y, v->z);
}

void	ft_display_sc(t_scene *sc)
{
	printf("\n-----------------------------------------");
	printf("\n----------------SCENE--------------------");
	printf("\n-----------------------------------------");
	printf("\ni: [%i]", sc->i);
	printf("\nj: [%i]", sc->j);	
	printf("\nk: [%i]", sc->k);
	printf("\ncur_cam: [%i]", sc->cur_cam);
	printf("\npix_int:");
	ft_display_vec(&sc->pix_int);
	printf("\npix_color: [%i]", sc->pix_color);
	printf("\nray->orig:");
	ft_display_vec(&sc->ray.orig);
	printf("\nray->dir:");
	ft_display_vec(&sc->ray.dir);
	printf("\nray_light->orig:");
	ft_display_vec(&sc->ray_light.orig);
	printf("\nray_light->dir:");
	ft_display_vec(&sc->ray_light.dir);
	printf("\nolst:");
	ft_print_olst(sc);
}

void	ft_print_olst(t_scene *sc)
{
	t_olst *tmp;
	
	tmp = sc->olst;
	while (tmp)
	{
		printf("\n--------------------------------------");
		printf("\nolst->obj_type: [%c]", tmp->obj_type);
		printf("\n--------------------------------------\n");
		printf("\nobj_id: [%i]", tmp->id);
		if (tmp->obj_type == 'l')
		{
			printf("\nlight_intst: [%f]", tmp->light.intst);
			ft_display_vec(&tmp->light.pos);
		}
		if (tmp->obj_type == 'm')
		{
			printf("\ncam_fov: [%f]", tmp->cam.fov);
			ft_display_vec(&tmp->cam.pos);
			ft_display_vec(&tmp->cam.orient);
		}
		if (tmp->obj_type == 's')
		{
			printf("\nsphere_radius: [%f]", tmp->sp.radius);
			ft_display_vec(&tmp->sp.orig);
		}
		tmp = tmp->next;
	}
}
/*
void    ft_display_sp(t_sphere *s)
{
    printf("\ns->x: %f - s->y: %f - s->z: %f - s->radius: %f", s->origin->x, s->origin->y, s->origin->z, s->radius);
}

void    ft_display_tr(t_triangle *t)
{
    printf("\nt->a: [%f, %f, %f] - t->b: [%f, %f, %f] - t->c: [%f, %f, %f]", t->a->x, t->a->y, t->a->z, t->b->x, t->b->y, t->b->z, t->c->x, t->c->y, t->c->z);
}
*/
void    ft_display_ray(t_ray *r)
{
    printf("\nr->origin->x: %f - r->origin->y: %f - r->origin->z: %f - r->direction->x: %f - r->direction->y: %f - r->direction->z: %f", r->orig.x, r->orig.y, r->orig.z, r->dir.x, r->dir.y, r->dir.z);
}
/*
void    ft_display_light(t_light *light)
{
    printf("\nlight->light_pos->x: %f - light->light_pos->y: %f - light->light_pos->z: %f - light->light_int: %f", light->light_pos->x, light->light_pos->y, light->light_pos->z, light->light_int);
}

void ft_sc_print(t_scene *sc)
{
    t_scene *tmp;
    tmp = sc;
    while (tmp)
    {
        if (tmp->obj_type == 's')
        {
            printf("\nsphere %i: ", tmp->id);
            ft_display_sp(tmp->sp);
        }
		else if (tmp->obj_type == 't')
		{
            printf("\ntriangle %i: ", tmp->id);
            ft_display_tr(tmp->tr);
        }
        tmp = tmp->next;
    }
}*/