#  A mid-summer night's dream


[題目連結](https://vjudge.net/problem/UVA-10057)

#### 要求輸出
1. A(最小的那個)
2. 數列有幾個等於A
3. A之間的差距

#### 解題

* 求中位數

  >如果數列數量為基數    
  >> 中位數只有一個  
  >如果中位數數量為偶數    
  >> 中位數有兩個
  
#### code(java)

```java
import java.util.*;

public class A_mid_summer_nights_dream {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int a = sc.nextInt();
            Long[] matrix = new Long[a];
            for (int i = 0; i < a; i++) {
                matrix[i] = sc.nextLong();
            }
            Arrays.sort(matrix);

            long a1 = (n%2 == 0) ? matrix[(a - 1) / 2] : matrix[a/2];
            long a2 = matrix[(a / 2)];
            int ans = 0;
            long c = a2 - a1 + 1;
            for (int i = 0; i < a; i++) {
                if (matrix[i] == a1 || matrix[i] == a2) {
                    ans++;
                }
            }
            System.out.println(a1 + " " + ans + " " + c);

        }

        sc.close();
    }
}
```
