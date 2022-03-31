/*
 * @Description: 
 * @Author: Longjing Xia
 * @FilePath: \tri_func\fnArctan.h
 * @Date: 2022-03-27 15:06:41
 * @LastEditTime: 2022-03-27 16:34:20
 */

#pragma once

double fnArctan (double x) {
    double sqr = x * x;
	double e = x > 0 ? x : -x;
    int flag = x > 0 ? 1 : -1;
	double r = 0;
	int i = 1;
	while (e / i > 1e-15) 
	{
		double f = e / i;
		r = (i % 4 == 1)? r+f: r-f;
		e = e * sqr;
		i += 2;
	}
	return r * flag;
}
	