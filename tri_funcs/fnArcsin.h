/*
 * @Description: arcsin函数
 * @Author: Longjing Xia
 * @FilePath: \tri_func\tri_funcs\fnArcsin.h
 * @Date: 2022-03-27 16:46:45
 * @LastEditTime: 2022-04-01 00:28:13
 */
#pragma once

#include <stdio.h>

#define PI (3.1415926535898)


/**
 * @description: 实现arcsin函数计算
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum
 * @param {double} precision
 * @return {double} outputNum
 */
double fnArcsin(bool inputMode, double inputNum, double precision = 0.000000001)
{        
   /* double factorM = 1;
    double factorX = inputNum;*/
    double outputNum = inputNum ; //输出
    double squareX = inputNum * inputNum;
    
    //进行麦克劳林展开式的计算
    double curPrecision = inputNum;
    int m = 1;
    while (curPrecision >= precision || curPrecision <= -precision) {
		double tmp = 2.0 * m;
        curPrecision *= ((1 + 1.0 / tmp -4.0 / (tmp + 1)) * squareX);
        outputNum += curPrecision;
        //printf("m=%d, curPrecision=%lf, outputNum=%lf\n",m, curPrecision, outputNum);
        ++m;
    }

    //解决输出负0的问题
    if(outputNum< precision && outputNum > -precision)
    {
        outputNum = 0;
    }
    else{}

    //弧度转角度：inputMode = 1，输出角度
    if(inputMode)
    {
        outputNum = outputNum * 180 / PI;
    }
    else{}

    return outputNum;
}


