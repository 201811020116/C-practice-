/*C语言风格的源程序2-01.c，实现读入几个变量，运算后再输出*/
#include <stdio.h>
int main()
{   char c;                            	/*定义变量c、a、f */
    int a;
    float f;
    scanf("%c%d%f",&c,&a,&f);             	/*输入变量c、a、f的值*/
    a=a+c;
    f=f+2*a;
    printf("c=%c a=%d  f=%.1f\n",c,a,f);      	/*输出变量c、a、f的值,f的值保留一位小数*/
    return 0;
}