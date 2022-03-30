#include <stdio.h>


#define PI (3.1415926)



/**
 * @description:  实现arcsin函数计算
 * @param {bool} inputMode:  输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @return {double} outputNum: 输出的arcsinx
 */
double fnArcsin( double inputNum)
{
    
    double outputNum = 0;  //输出
    double coefficient = 1, denominator=1, numerator = 1; //系数，分母，分子


    //进行麦克劳林展开式的计算
    for(int i =0; i<100; ++i)
    {
        numerator = numerator * inputNum;
        if((i-1) % 2 == 0)
        {
            if(inputNum < -1 && inputNum > 1)
                 {
                    printf("Input is out of range.");
                    break;
                }
            denominator=denominator*(i-1);
            coefficient = coefficient*(i-2);
            outputNum += coefficient*numerator/denominator;
        }
    }

    //解决输出负0的问题
    if(outputNum< 0.0001 && outputNum >-0.0001)
    {
        outputNum = 0;
    }
    return outputNum;
}


 
