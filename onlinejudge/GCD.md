# GCD

[題目連結](https://vjudge.net/problem/UVA-11417)  


#### 解題

寫出`最大公因數`的程式再按規則算出就行  

==>輾轉相除法

![](https://th.bing.com/th/id/OIP.qi55B8Jw-yek_vI6A__zRQHaJ4?rs=1&pid=ImgDetMain)

```java
import java.util.*;

public class GCD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {

            int x = sc.nextInt();
            if (x == 0) {
                break;
            }
            long ans = 0;
            for (int i = 1; i < x; i++) {
                for (int j = i + 1; j <= x; j++) {
                    ans += gcd(i, j);
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
