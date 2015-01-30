/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:47:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/27 12:51:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/***error***/

printf("%ll# 2.3hd\n",356565655);
printf("%ll #0\n");
printf("%####0000 33...12..15..#00d\n", 256);
printf("%0# ..52#d\n", 256);
printf("%....\n");
printf("%\n");
printf("%");
printf("dfsd %");
printf("dfsd %\n");
printf("%0\n");
printf("% hhld\n", 25);
printf("%.#0lld\n", 65);
printf("%ll#+--28.3hd\n",356565655);
printf("%l+-l #0\n");
printf("%###-#0000 33...12..#0+0d\n", 256);
printf("%###-#0000 33...12..#00d\n", 256);
printf("%###+#0000 33...12..#00d\n", 256);
printf("%+0# ..52#d\n", 256);
printf("%-....\n");
printf("%-\n");
printf("%0\n");
printf("% hh-+ld\n", 25);
printf("%.#0-lld\n", 65);

/*****%d****/

printf("%2.1d\n", -5);
printf("%3.2d\n", -5);
printf("%7.3d\n", -5);
printf("%7.1d\n", -346);
printf("%5.3d\n", -346);
printf("%6.2d\n", -346);
printf("%8.0d\n", -346);
printf("%7.3d\n", -346);
printf("% 6d\n", -3455);
printf("%03.d\n", -1);
printf("%03.d\n", -4);
printf("%03.4d\n", 0);
printf("%03.4d\n", 4);
printf("%03.4d\n", 100);
printf("%03.4d\n", 1000);


/*****%i****/

printf("%5.0i\n", -5);
printf("%7.3i\n", -5);
printf("%7.1i\n", -346);
printf("%5.3i\n", -346);
printf("%6.2i\n", -346);
printf("%8.0i\n", -346);
printf("%7.3i\n", -346);
printf("% 6i\n", -3455);
printf("%03.i\n", -1);
printf("%03.i\n", -4);
printf("%03.4i\n", 0);
printf("%03.4i\n", 4);
printf("%03.4i\n", 100);
printf("%03.4i\n", 1000);


/*****%hi****/

printf("%hi\n", 2147483647);
printf("%hi\n", -2147483648);
printf("%3hi\n", 0);
printf("%-3hi\n", 0);
printf("%-hi\n", 2147483647);
printf("%-hi\n", -2147483648);
printf("%-15hi\n", 2147483647);
printf("%-15hi\n", -2147483648);
printf("%.3hi\n", -18);
printf("%.hi\n", 0);
printf("%2.2hi\n", 5);
printf("%2.1hi\n", 5);
printf("%2.3hi\n", 5);
printf("%3.2hi\n", 5);
printf("%5.0hi\n", 5);
printf("%0.2hi\n", 5);
printf("%3.7hi\n", 5);
printf("%7.3hi\n", 5);
printf("%2.2hi\n", 0);
printf("%2.1hi\n", 0);
printf("%2.3hi\n", 0);
printf("%3.2hi\n", 0);
printf("%5.0hi\n", 0);
printf("%0.2hi\n", 0);
printf("%3.7hi\n", 0);
printf("%7.3hi\n", 0);
printf("%2.2hi\n", -5);
printf("%2.1hi\n", -5);
printf("%2.3hi\n", -5);
printf("%3.2hi\n", -5);
printf("%5.0hi\n", -5);
printf("%0.2hi\n", -5);
printf("%3.7hi\n", -5);
printf("%7.3hi\n", -5);
printf("%2.6hi\n", -346);
printf("%7.1hi\n", -346);
printf("%5.3hi\n", -346);
printf("%6.2hi\n", -346);
printf("%8.0hi\n", -346);
printf("%0.8hi\n", -346);
printf("%3.7hi\n", -346);
printf("%7.3hi\n", -346);
printf("%2.6hi\n", 346);
printf("%7.1hi\n", 346);
printf("%5.3hi\n", 346);
printf("%6.2hi\n", 346);
test_printf("%8.0hi\n", 346);
test_printf("%0.8hi\n", 346);
test_printf("%3.7hi\n", 346);
test_printf("%7.3hi\n", 346);




/*****%hd****/



printf("%5.0d$\n", 0);
printf("%0.2hd\n", 0);
printf("%3.7hd\n", 0);
printf("%7.3hd\n", 0);
printf("%2.2hd\n", -5);
printf("%2.1hd\n", -5);
printf("%2.3hd\n", -5);
printf("%3.2hd\n", -5);
printf("%5.0hd\n", -5);
printf("%0.2hd\n", -5);
printf("%3.7hd\n", -5);
printf("%7.3hd\n", -5);
printf("%2.6hd\n", -346);
printf("%7.1hd\n", -346);
printf("%5.3hd\n", -346);
printf("%6.2hd\n", -346);
printf("%8.0hd\n", -346);
printf("%0.8hd\n", -346);
printf("%3.7hd\n", -346);
printf("%7.3hd\n", -346);
printf("%2.6hd\n", 346);
printf("%7.1hd\n", 346);
printf("%5.3hd\n", 346);
printf("%6.2hd\n", 346);
printf("%8.0hd\n", 346);
printf("%0.8hd\n", 346);
printf("%3.7hd\n", 346);
printf("%hd\n", 2147483647);
printf("%hd\n", -2147483648);
printf("%3hd\n", 0);
printf("%-3hd\n", 0);
printf("%-hd\n", 2147483647);
printf("%-hd\n", -2147483648);
printf("%-15hd\n", 2147483647);
printf("%-15hd\n", -2147483648);
printf("%.3hd\n", -18);
printf("%.3hd\n", 0);
printf("%.hd\n", 0);
printf("%2.2hd\n", 5);
printf("%2.1hd\n", 5);
printf("%2.3hd\n", 5);
printf("%3.2hd\n", 5);
printf("%5.0hd\n", 5);
printf("%0.2hd\n", 5);
printf("%3.7hd\n", 5);
printf("%7.3hd\n", 5);
printf("%2.2hd\n", 0);
printf("%2.1hd\n", 0);
printf("%2.3hd\n", 0);
printf("%3.2hd\n", 0);
printf("%5.0hd\n", -5);
printf("%0.2hd\n", -5);
printf("%3.7hd\n", -5);
printf("%7.3hd\n", -5);
printf("%2.6hd\n", -346);
printf("%7.1hd\n", -346);
printf("%5.3hd\n", -346);
printf("%6.2hd\n", -346);
printf("%8.0hd\n", -346);
printf("%0.8hd\n", -346);
printf("%3.7hd\n", -346);
printf("%7.3hd\n", -346);
printf("%2.6hd\n", 346);
printf("%7.1hd\n", 346);
printf("%5.3hd\n", 346);
printf("%6.2hd\n", 346);
printf("%8.0hd\n", 346);
printf("%0.8hd\n", 346);
printf("%3.7hd\n", 346);
printf("%7.3hd\n", 346);
printf("% 6hd\n", -3455);
printf("%-6hd\n", -3455);
printf("%-+6hd\n", -455);
printf("%-+6hd\n", 455);
printf("%- 6d$\n", 455);
printf("% -6d$\n", -455);
printf("%hd\n", -18);
printf("%hd\n", -2387);
printf("%03.4hd\n", 100);
printf("%03.4hd\n", 1000);
printf("%03.4hd\n", -4);
printf("%03.4hd\n", -100);
printf("%03.4hd\n", -1000);
