/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:10 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/01 14:46:58 by pleroux          ###   ########.fr       */
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

static int		vpf_14_(char *e, ...)
{
	wint_t		t[5] = {536,537,538,539,0};
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %S, finish", t);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_14()
{
	int		p;
	wint_t		t[5] = {536,537,538,539,0};
	return (vpf_14_("test x %S, finish", t));
}

static int		vpf_15_(char *e, ...)
{
	wint_t		t[5] = {536,537,538,539,0};
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %15.2S, finish", t);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_15()
{
	int		p;
	wint_t		t[5] = {536,537,538,539,0};
	return (vpf_15_("test x %15.2S, finish", t));
}

static int		vpf_16_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %p, finish", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_16()
{
	return (vpf_16_("test x %p, finish", NULL));
}

static int		vpf_17_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %-10.5%, finish");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_17()
{
	return (vpf_17_("test x %-10.5%, finish"));
}

static int		vpf_18_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%dtest x %-10.5%, finish%d", 15, 42);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_18()
{
	return (vpf_18_("%dtest x %-10.5%, finish%d", 15, 42));
}

static int		vpf_19_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%20p", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_19()
{
	return (vpf_19_("%20p", NULL));
}

static int		vpf_20_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%d", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_20()
{
	return (vpf_20_("%d", 0));
}

static int		vpf_21_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "% d", 0xff11ff);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_21()
{
	return (vpf_21_("% d", 0xff11ff));
}

static int		vpf_22_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "\ntoto et %00009Uallo%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_22()
{
	return (vpf_22_("\ntoto et %00009Uallo%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200));
}

static int		vpf_23_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%#o", 1000);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_23()
{
	return (vpf_23_("%#o", 1000));
}

static int		vpf_24_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_24()
{
	return (vpf_24_("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
}

static int		vpf_25_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%#X", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_25()
{
	return (vpf_25_("%d", 0));
}

static int		vpf_26_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%p", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_26()
{
	return (vpf_26_("%p", 0));
}

static int		vpf_27_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%c", '\0');
	ft_print_memory(vp, 5);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_27()
{
	return (vpf_27_("%c", '\0'));
}

static int		vpf_28_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%.2s", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_28()
{
	return (vpf_28_("%.2s", NULL));
}

static int		vpf_29_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%C", 0xd800);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_29()
{
	return (vpf_29_("%C", 0xd800));
}

static int		vpf_30_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%C", (wint_t)-2);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_30()
{
	return (vpf_30_("%C", (wint_t)-2));
}

static int		vpf_31_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_31()
{
	return (vpf_31_("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));
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
	_verify(vpf_14);
	_verify(vpf_15);
	_verify(vpf_16);
	_verify(vpf_17);
	_verify(vpf_18);
	_verify(vpf_19);
	_verify(vpf_20);
	_verify(vpf_21);
	_verify(vpf_22);
	_verify(vpf_23);
	_verify(vpf_24);
	_verify(vpf_25);
	_verify(vpf_26);
	_verify(vpf_27);
	_verify(vpf_28);
	_verify(vpf_29);
	_verify(vpf_30);
	_verify(vpf_31);
	return (0);
}
