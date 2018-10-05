/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 03:15:41 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/05 05:06:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "test42f.h"
#include <stdlib.h>
#include <stdio.h>

int	g_error_flag;

long	get_result(char *str);
long	get_expected(char *str);
void	test(char *str);

int main(int argc, char **argv)
{
	test("5 + 3 - 4 * (10 / 5)");
	test("(4 - 17) * 33 + 22 - (43 + (90 - 21) % 7 + 3) + 5 % 2 * 5 + (4 - 2)");
	test("(4 - 3)");
	test("(((6 - 7)))");
	test("(((2 + 5))) * ((((3 - 17))))");
	test("5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 + 5 * 5 * 5");
	test("3");
	test("0");
	test("-5");
	test("4 + -7");
	test("(3)");
	test("((0))");
	test("   6   ");
	test("  3    -   2");
	test("( 5 + 3)");
	test("(5 + 3 )");
	test("(8   -  2)");
	test("                      0");
	test("-0");
	test("4 + -0");
	test("27 * (-27055149 - 52481068) - 5789");
	test("(178 % 47) * 5 * (164934 / 7 + 508967) + 6 * (3411494297)");

	(void)argc;
	(void)argv;
	return (0);
}

void	test(char *str)
{
	long expected = get_expected(str);
	long result = get_result(str);
	test42f_int_eq(str, result, expected);
}

long	get_result(char *str)
{
	return (eval_expr(str));
}

long	get_expected(char *str)
{
	char cmd[1024];
	char res[32];
	sprintf(cmd, "echo \"%s\" | bc", str);
	FILE *fp;
	fp = popen(cmd, "r");
	fgets(res, 32, fp);
	long expected = atoi(res);
	return (expected);
}
