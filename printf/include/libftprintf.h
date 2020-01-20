/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 11:38:54 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 08:31:04 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct		s_printf
{
	char			char_converter;
	char			*str_convert;
	char			*str_convert_2;
	int				int_converter;
	long			long_converter;
	unsigned int	uns_int_converter;
	char			*flag;
	char			*flag_2;
	char			cp;
	int				flag_pt;
	char			*flag_pt_s;
	int				flag_sp_len;
	char			*flag_sp_l;
	int				i;
	int				j;
	int				k;
	size_t			l;
	int				len_star_2;
	int				flag_dash_i;
	int				flag_star_i;
	int				len_star;
	int				star_pt_star;
	int				len_star_3;
	int				verif;
	int				verif2;
	int				dash;
	char			*space;
	int				dash_field;
	int				null;
	int				check_pt;
	char			*zero;
	int				dash_d;
	char			*dash_zero;
	int				check_int_min;
	char			*flag_zero;
	long long		ll_converter;
	int				int_neg;
	int				no_malloc_str;
	int				malloc_zero;
	int				malloc_space;
	int				dash_star;
}					t_printf;

void				ft_init(t_printf *st);
void				ft_re_init(t_printf *st);
char				*ft_fill_space(int len);
char				*ft_strjoin_free(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
int					ft_check_dash(t_printf *st);
int					ft_printf(const char *fmt, ...);
void				ft_putchar(char c, t_printf *st);
void				ft_putstr(char *s, t_printf *st);
void				ft_putnbr(int n, t_printf *st);
void				ft_check_c(va_list ap, t_printf *st, char *fmt);
void				ft_check_s(va_list ap, t_printf *st, char *fmt);
void				ft_check_d_i(va_list ap, t_printf *st, char *fmt);
void				ft_check_x(va_list ap, t_printf *st, char *fmt);
void				ft_check_u(va_list ap, t_printf *st, char *fmt);
void				ft_star_flag_c(va_list ap, t_printf *st);
void				ft_dash_star_flag_c(va_list ap, t_printf *st);
void				ft_field_size_c(t_printf *st, va_list ap);
void				ft_star_flag_s(va_list ap, t_printf *st);
void				ft_dash_star_flag_s(va_list ap, t_printf *st);
void				ft_point_flag_s(t_printf *st, va_list ap);
void				ft_field_size_s(t_printf *st, va_list ap);
void				ft_two_star_neg_s(t_printf *st, int final_len);
void				ft_star_flag_d_i(va_list ap, t_printf *st);
void				ft_dash_star_flag_d_i(va_list ap, t_printf *st);
char				*ft_itoa_base(long nbr, char *set);
void				ft_star_flag_u(va_list ap, t_printf *st);
void				ft_dash_star_flag_u(va_list ap, t_printf *st);
void				ft_putnbr_u(unsigned int n, t_printf *st);
void				ft_star_flag_x(char *fmt, va_list ap, t_printf *st);
void				ft_dash_star_flag_x(char *fmt, va_list ap, t_printf *st);
void				ft_check_p(va_list ap, t_printf *st, char *fmt);
void				ft_check_percent(va_list ap, t_printf *st, char *fmt);
void				ft_dash_star_flag_percent(va_list ap, t_printf *st);
void				ft_star_flag_percent(va_list ap, t_printf *st);
void				ft_field_size_d_i(t_printf *st, va_list ap);
int					ft_two_star_neg_d_i(t_printf *st, int final_len);
void				ft_point_flag_d_i(t_printf *st, va_list ap);
char				*ft_fill_zero(int len);
char				*ft_strjoin_free(char *s1, char *s2);
void				ft_print_space(t_printf *st, int final_len);
void				ft_star_pt_no_star_d_i(t_printf *st);
void				ft_no_star_pt_star_d_i(t_printf *st, int len_zero);
void				ft_star_pt_star_d_i(t_printf *st, int len_zero);
void				ft_no_star_pt_no_star_d_i(t_printf *st, int len_zero);
void				ft_flag_null_d_i(t_printf *st);
void				ft_star_pt_no_star_u(t_printf *st, char *uns_char);
void				ft_no_star_pt_star_u(t_printf *st, int len_zero,
						char *uns_char);
void				ft_star_pt_star_u(t_printf *st, int len_zero,
						char *uns_char);
void				ft_no_star_pt_no_star_u(t_printf *st, int len_zero,
						char *uns_char);
void				ft_flag_null_u(t_printf *st);
void				ft_field_size_u(t_printf *st, va_list ap);
void				ft_two_star_neg_u(t_printf *st, int final_len);
void				ft_point_flag_u(t_printf *st, va_list ap);
char				*ft_uns_itoa(unsigned int n);
void				ft_two_star_neg_x(char *fmt, t_printf *st, int final_len);
void				ft_field_size_x(char *fmt, t_printf *st, va_list ap);
void				ft_point_flag_x(char *fmt, t_printf *st, va_list ap);
void				ft_flag_null_x(char *fmt, t_printf *st);
void				ft_no_star_pt_no_star_x(char *fmt, t_printf *st,
						int len_zero);
void				ft_star_pt_star_x(char *fmt, t_printf *st, int len_zero);
void				ft_no_star_pt_star_x(char *fmt, t_printf *st, int len_zero);
void				ft_star_pt_no_star_x(char *fmt, t_printf *st);
void				ft_two_star_neg_percent(t_printf *st, int final_len);
void				ft_field_size_percent(t_printf *st, va_list ap);
void				ft_point_flag_percent(t_printf *st, va_list ap);
void				ft_flag_null_percent(t_printf *st);
void				ft_no_star_pt_no_star_percent(t_printf *st, int len_zero);
void				ft_star_pt_star_percent(t_printf *st, int len_zero);
void				ft_no_star_pt_star_percent(t_printf *st, int len_zero);
void				ft_star_pt_no_star_percent(t_printf *st);
void				ft_star_flag_p(va_list ap, t_printf *st);
void				ft_dash_star_flag_p(va_list ap, t_printf *st);
void				ft_field_size_p(t_printf *st, va_list ap);
void				ft_two_star_neg_p(t_printf *st, int final_len);
void				ft_point_flag_p(t_printf *st, va_list ap);
char				*ft_itoa_base_ul(unsigned long nbr, char *set);
void				ft_memdel(void **str);
void				ft_free_init(t_printf *st);
int					ft_int_len(int nbr);
char				*ft_strjoin_2_free(char *s1, char *s2);
char				*ft_strdup_free(const char *s1);
int					ft_u_int_len(unsigned int nbr);
char				*ft_strjoin_r_free(char *s1, char *s2);
char				*ft_int_min(char *str);
void				ft_no_zero(t_printf *st, int final_len);
void				ft_no_zero_percent_or_d_i(t_printf *st, int final_len);
void				ft_no_point_x(char *fmt, t_printf *st, int final_len);
void				ft_two_star_sup_x(char *fmt, t_printf *st, int final_len);
void				ft_know_x_or_maj_x(char *fmt, t_printf *st);
void				ft_print_x_no_dash(char *fmt, t_printf *st);
void				ft_replace_x_or_maj_x(char *fmt, t_printf *st);
void				ft_print_u_no_point(t_printf *st, int final_len);
void				ft_two_star_sup_u(t_printf *st, int final_len);
void				ft_two_star_sup_percent(t_printf *st, int final_len);
void				ft_print_d_i_no_point(t_printf *st, int final_len);
void				ft_neg_d_i(t_printf *st);
int					ft_two_star_sup_d_i(t_printf *st, int final_len);
void				ft_two_star_sup_p(t_printf *st, int final_len);
void				ft_point_neg_d_i(t_printf *st);
void				ft_print_dash_star_neg_d_i(t_printf *st, int final_len);
void				ft_resolve_algo_point(t_printf *st, char *fmt);
void				ft_algo_point(t_printf *st, char *fmt);
void				ft_algo_field_zero_or_star(t_printf *st, char *fmt);
void				ft_algo_field_size(t_printf *st, char *fmt);
void				ft_algo_star(t_printf *st, int j, int k, char *fmt);
void				ft_zero_d_i(t_printf *st, int final_len);
void				ft_print_no_point_percent(t_printf *st);
void				ft_print_no_point_p(t_printf *st);
void				ft_fill_str_zero(t_printf *st, int len_zero);

#endif
