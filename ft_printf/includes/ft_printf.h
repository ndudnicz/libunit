/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:21:24 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/22 10:13:23 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>

# define ERR_MALLOC "\nft_printf error: Can't allocate memory.\n"
# define ERR_BADFLAG "\nft_printf error: Invalid flag.\n"

typedef struct		s_flag
{
	int				len;
	char			attribut[6];
	int				field_width;
	int				precision;
	char			modifier[3];
	char			conversion;
	char			*p_format;
	int				total;
}					t_flag;

t_flag				*init_flag(void);
int					get_attribut(char *fmt, t_flag *flag);
void				reset_flag(t_flag *flag);

void				flag_is_valid(t_flag *flag);
int					valid_format(char *fmt);
void				valid_args(t_flag *flag, va_list ap);
int					valid_wstr(wchar_t *wstr);

void				ft_free_exit(t_flag *flag, char *msg);
int					ft_free_return(t_flag *flag, char *msg, int ret);

int					treat_flag(t_flag *flag, va_list ap);
void				treat_char(t_flag *flag, int c);
int					treat_wchar(t_flag *flag, wint_t wc);
int					treat_str(t_flag *flag, char *str);
int					treat_wstr(t_flag *flag, wchar_t *wstr);
void				treat_decimal(t_flag *flag, long long int number);
void				treat_hexa(t_flag *flag, long long int number);
void				treat_pointer(t_flag *flag, unsigned long int number);
void				treat_octal(t_flag *flag, long long int number);
void				treat_base(t_flag *flag, long long int number, int base);
void				treat_unsigned(t_flag *flag, unsigned long long int number);
char				*treat_color(char *fmt);

void				lld_putbase(long long int n, int base);
void				ld_putbase(long int n, int base);
void				uld_putbase(unsigned long int n, int base,
		char upper);
void				ulld_putbase(unsigned long long int n, int base,
		char upper);
void				z_putbase(size_t n, int base, char upper);
void				j_putbase(intmax_t n, int base, char upper);
void				uj_putbase(uintmax_t n, int base, char upper);
void				ft_putchar(char c);
int					ft_putnchar(char c, int n);
int					ft_putwchar(wint_t wc);
void				ft_putstr(char *str);
int					ft_putnstr(char *str, int n);
int					ft_putnwstr(wchar_t *wstr, int n);
int					ft_wstrlen(wchar_t *wstr);
int					ft_long_numberlen(long long int n, int base);
int					ft_ulong_numberlen(unsigned long long int n, int base);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
int					ft_isprint(int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlenchr(const char *s, int c);
char				*ft_strdupchr(const char *s1, int c);
int					ft_strcmp(const char *s1, const char *s2);

#endif
