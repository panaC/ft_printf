/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:10 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 19:24:16 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int		vpf_01_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("allo42 : sinon -42, finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_01()
{
	return (vpf_01_("allo%d : sinon %d, finish", 42, -42));
}

static int		vpf_02_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("allo42 : sinon -42, finish420000000000", s);
	va_end(ap);
	return (0);
}

static int		vpf_02()
{
	return (vpf_02_("allo%d : sinon %d, finish%D", 42, -42, 420000000000));
}

static int		vpf_03_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("alloalloollaallo\nallllllllllllo\tollllllllla", s);
	va_end(ap);
	return (0);
}

static int		vpf_03()
{
	return (vpf_03_("alloalloollaallo\nallllllllllllo\tollllllllla"));
}

static int		vpf_04_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 0x2a, finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_04()
{
	return (vpf_04_("test x %#x, finish", 42));
}

static int		vpf_05_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 0X0002A   , finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_05()
{
	return (vpf_05_("test x %#0+- 10.5X, finish", 42));
}

static int		vpf_06_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 00052     , finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_06()
{
	return (vpf_06_("test x %#0+- 10.5o, finish", 42));
}

static int		vpf_07_(int *p, char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %p, finish", p);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_07()
{
	int		p;
	return (vpf_07_(&p, "test x %p, finish", &p));
}

static int		vpf_08_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %c, finish", 'h');
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_08()
{
	int		p;
	return (vpf_08_("test x %c, finish", 'h'));
}

#include <wchar.h>
#include <unistd.h>
#include <locale.h>

static int		vpf_09_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %C, finish", (wint_t)536);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_09()
{
	int		p;
	return (vpf_09_("test x %C, finish", (wint_t)536));
}

static int		vpf_10_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %-10C, finish", (wint_t)536);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_10()
{
	int		p;
	return (vpf_10_("test x %-10C, finish", (wint_t)536));
}

static int		vpf_11_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %s, finish", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_11()
{
	int		p;
	return (vpf_11_("test x %s, finish", NULL));
}

static int		vpf_12_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %10.3s, finish", "Hello");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_12()
{
	int		p;
	return (vpf_12_("test x %10.3s, finish", "Hello"));
}

static int		vpf_13_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %s, finish", "Hello");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_13()
{
	int		p;
	return (vpf_13_("test x %s, finish", "Hello"));
}


int ft_vasprintf_test()
{
	PT;
	_verify(vpf_01);
	_verify(vpf_02);
	_verify(vpf_03);
	_verify(vpf_04);
	_verify(vpf_05);
	_verify(vpf_06);
	_verify(vpf_07);
	_verify(vpf_08);
	_verify(vpf_09);
	_verify(vpf_10);
	_verify(vpf_11);
	_verify(vpf_12);
	_verify(vpf_13);
	return (0);
}
