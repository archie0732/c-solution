#include <stdio.h>

int main(void) {
    int x,a,b,y,output1;                        //定義
    
    printf("請輸入值，中間使用空白");             
    
    scanf("%d %d %d %d", &x , &a , &b , &y);    //輸入的值
    
        output1=2*(x*x)-(4*x)+1 ;              
            printf("(1):%d\n", output1);      //輸出值

        output1=(a*a)+b;1 ;
            printf("(2):%d\n", output1);

        output1=3*(y*y)+(8*y)+4 ;
            printf("(3):%d\n", output1);

    return 0;
    
}