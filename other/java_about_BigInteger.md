# 關於java中`BigInteger`的常用含式


![](https://pixiv.cat/116700405.jpg)



## 初始化

```java

// 標頭黨
import java.math.*;

//宣告
BigInteger a = new BigInteger("0");// 初始化為0
BigInteger b = sc.nextBigInteger(); // 可以輸入

//要存入值，要轉成String

int num = 100000;

String c = String.vauleOf(num);
BigInteger d = new BigInteger(c);


```

## 基本運算

```java

import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        
        BigInteger num1 = new BigInteger("12345678901234567890");
        BigInteger num2 = new BigInteger("98765432109876543210");

        // 加法
        BigInteger sum = num1.add(num2);
        System.out.println("加法结果：" + sum);

        // 減法
        BigInteger difference = num1.subtract(num2);
        System.out.println("减法结果：" + difference);

        // 乘法
        BigInteger product = num1.multiply(num2);
        System.out.println("乘法结果：" + product);

        // 除法
        BigInteger divide_res = num1.divide(num2);

        // 取餘
        BigInteger remainder_res = num1.remainder(num2);

        // 比較大小
        int comparisonResult = num1.compareTo(num2);
        if (comparisonResult < 0) {
            System.out.println("num1 < num2");
        } else if (comparisonResult > 0) {
            System.out.println("num1 > num2");
        } else {
            System.out.println("num1 = num2");
        }

        // 检查相等
        if (num1.equals(num2)) {
            System.out.println("num1 == num2");
        } else {
            System.out.println("num1 != num2");
        }

    }
}
```
