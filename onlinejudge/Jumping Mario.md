# Jumping Mario 


[題目連結](https://vjudge.net/problem/UVA-11764)


* 原本以為是`BigInteger` 結果是水題


```cpp
import java.util.*;
import java.math.*;

public class Jumping_Mario {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int turn = 1;
        while (t-- > 0) {

            int n = sc.nextInt();

            int low = 0, hight = 0;

            BigInteger a1 = sc.nextBigInteger();

            for (int i = 1; i < n; i++) {

                BigInteger a2 = sc.nextBigInteger();

                int tem = a1.compareTo(a2);

                if (tem < 0) {
                    hight++;
                }
                if (tem > 0) {
                    low++;
                }
                a1 = a2;
            }

            System.out.println("Case " + turn + ": " + hight + " " + low);
            turn++;

        }

        sc.close();
    }

}
```
