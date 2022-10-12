/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:23:54 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 17:03:36 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef	struct		s_var_printf
{
	int						i;
	int						t;
	int						first;
	int						ret;
	int						sharp;
	int						zero;
	int						minus;
	int						plus;
	int						space;
	int						h;
	int						hh;
	int						l;
	int						ll;
	int						j;
	int						z;
	int						have_pres;
	int						neg;
	int						signed_conv;
	int						base;
	int						conv;
	size_t					size;
	size_t					size_temp;
	size_t					pres;
	size_t					size_min;
	size_t					pres_zero;
	char					spec;
	char					conv_char;
	char					*conv_wspace;
	char					*conv_wzero;
	char					*str;
	char					*temp;
	char					*temp2;
	char					*conv_temp;
	char					*conv_str;
	char					*str_base;
	wchar_t					wchar;
	wchar_t					*wstr;
	int						ret_s;
	unsigned int			ubase;
	long long int			conv_llong;
	unsigned long long int	conv_ullong;
}					t_var_printf;

typedef	struct		s_funct
{
	void					(*function)(t_var_printf *var, va_list ap);
	char					key;
}					t_funct;

int					ft_printf(const char *format, ...);
void				ft_printf_var_init(t_var_printf *var);
void				ft_printf_var_raz(t_var_printf *var);
void				ft_printf_format(const char *format, t_var_printf *var,
		va_list ap);
int					ft_printf_is_flag(char c);
void				ft_printf_find_flag(t_var_printf *var);
int					ft_printf_flag_zero(t_var_printf *var);
void				ft_printf_spec_id(t_var_printf *var, va_list ap);
void				ft_printf_no_conv(t_var_printf *var);
void				ft_printf_conv_min_s_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_s(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_s_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_p(t_var_printf *var, va_list ap);
void				ft_printf_conv_d(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_d_h(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_d_hh(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_d_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_d_ll(t_var_printf *var, va_list ap);
void				ft_printf_conv_o(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_o_h(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_o_hh(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_o_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_o_ll(t_var_printf *var, va_list ap);
void				ft_printf_conv_u(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_u_h(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_u_hh(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_u_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_u_ll(t_var_printf *var, va_list ap);
void				ft_printf_conv_x_1(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_x_h(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_x_hh(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_x_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_x_ll(t_var_printf *var, va_list ap);
void				ft_printf_conv_x_2(t_var_printf *var, va_list ap);
void				ft_printf_conv_maj_x_h(t_var_printf *var, va_list ap);
void				ft_printf_conv_maj_x_hh(t_var_printf *var, va_list ap);
void				ft_printf_conv_maj_x_l(t_var_printf *var, va_list ap);
void				ft_printf_conv_maj_x_ll(t_var_printf *var, va_list ap);
void				ft_printf_conv_c(t_var_printf *var, va_list ap);
void				ft_printf_conv_min_c_l(t_var_printf *var, va_list ap);
void				ft_printf_print(t_var_printf *var);
void				ft_printf_putchar_ret(char c, t_var_printf *var);
void				ft_printf_putstr_conv_char(t_var_printf *var);
void				ft_printf_putstr_ret(char *str, t_var_printf *var);
void				ft_printf_putnbr_ret(t_var_printf *var);
void				ft_printf_conv_wspace(t_var_printf *var);
void				ft_printf_conv_wzero(t_var_printf *var);
void				ft_printf_space_before(t_var_printf *var);
void				ft_printf_signe(t_var_printf *var);
void				ft_printf_sharp_before(t_var_printf *var);
void				ft_printf_zero_before(t_var_printf *var);
void				ft_printf_space_after(t_var_printf *var);
void				ft_printf_conv_unicode(t_var_printf *var);

#endif
