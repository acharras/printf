/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:35:01 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:30:07 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_free_init(t_printf *st)
{
	if (st->malloc_zero == 1)
		ft_memdel((void *)&st->zero);
	if (st->no_malloc_str == 0)
		ft_memdel((void *)&st->str_convert);
	ft_memdel((void *)&st->str_convert_2);
	ft_memdel((void *)&st->flag);
	ft_memdel((void *)&st->flag_2);
	ft_memdel((void *)&st->flag_pt_s);
	ft_memdel((void *)&st->flag_sp_l);
	ft_memdel((void *)&st->space);
	ft_memdel((void *)&st->flag_zero);
}

static void	ft_re_init_2(t_printf *st)
{
	st->dash = 0;
	st->dash_field = 0;
	st->null = 0;
	st->check_pt = 0;
	st->check_int_min = 0;
	st->uns_int_converter = 0;
	st->long_converter = 0;
	st->ll_converter = 0;
	st->dash_d = 0;
	st->l = 1;
	st->flag_dash_i = 0;
	st->malloc_zero = 0;
	st->no_malloc_str = 0;
	st->malloc_space = 0;
}

void		ft_re_init(t_printf *st)
{
	st->char_converter = 0;
	st->int_converter = 0;
	st->flag_star_i = 0;
	st->len_star = 0;
	st->len_star_2 = 0;
	st->star_pt_star = 0;
	st->len_star_3 = 0;
	st->verif = 0;
	st->verif2 = 0;
	st->int_neg = 0;
	st->dash_star = 0;
	ft_free_init(st);
	ft_re_init_2(st);
}

static void	ft_init_2(t_printf *st)
{
	st->dash = 0;
	st->space = NULL;
	st->dash_field = 0;
	st->null = 0;
	st->flag_2 = NULL;
	st->check_pt = 0;
	st->zero = NULL;
	st->dash_zero = NULL;
	st->check_int_min = 0;
	st->uns_int_converter = 0;
	st->long_converter = 0;
	st->flag_zero = NULL;
	st->ll_converter = 0;
	st->dash_d = 0;
	st->no_malloc_str = 0;
	st->malloc_zero = 0;
	st->dash_star = 0;
}

void		ft_init(t_printf *st)
{
	st->i = 0;
	st->k = 0;
	st->l = 1;
	st->str_convert = NULL;
	st->str_convert_2 = NULL;
	st->char_converter = 0;
	st->int_converter = 0;
	st->flag = NULL;
	st->flag_star_i = 0;
	st->flag_pt_s = NULL;
	st->flag_sp_l = NULL;
	st->len_star = 0;
	st->len_star_2 = 0;
	st->star_pt_star = 0;
	st->len_star_3 = 0;
	st->verif = 0;
	st->verif2 = 0;
	st->flag_dash_i = 0;
	st->int_neg = 0;
	ft_init_2(st);
}
