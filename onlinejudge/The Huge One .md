# The Huge One 

[題目連結](https://vjudge.net/problem/UVA-11344)


* 使用`BigInteger` 全身舒服

#### code (java)

![](https://www.pixiv.cat/77422058.jpg)

```java

import java.util.*;
import java.math.*;

public class The_Huge_One {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            BigInteger num = sc.nextBigInteger();
            int n = sc.nextInt();
            int flag = 0;
            for (int i = 0; i < n; i++) {
                int tem = sc.nextInt();
                String d = String.valueOf(tem);
                BigInteger e = new BigInteger(d);
                if (num.remainder(e).equals(BigInteger.valueOf(0))) {

                } else {
                    flag = 1;
                }
            }
            if (flag == 1) {
                System.out.println(num + " - Simple.");
            } else {
                System.out.println(num + " - Wonderful.");
            }
        }

        sc.close();
    }

}
```
