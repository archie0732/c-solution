[題目連結](https://vjudge.net/problem/UVA-11186)



#### 解題

* 根據公式＝>把角度換成點的位置
* 用外積（叉積）得三角行面積
* **記得用long最後用**
* 還有絕對值

#### java code
```java
import java.util.*;

public class Circum_Triangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double r = sc.nextDouble();

        while (N != 0 || r != 0) {
            double ans = 0;
            double[][] point = new double[N][2];// using x and y to express point(in x-axis and y-axis)
            for (int i = 0; i < N; i++) {
                double x = sc.nextDouble();
                point[i][0] = r * Math.cos(x / 180 * Math.PI);
                point[i][1] = r * Math.sin(x / 180 * Math.PI);
            }

            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    for (int k = j + 1; k < N; k++) { // Calculate the cross product for three points and determine the
                                                      // area of the resulting triangle
                        double area = Math.abs((point[i][0] - point[j][0]) * (point[i][1] - point[k][1])
                                - (point[i][1] - point[j][1]) * (point[i][0] - point[k][0])) / 2.0;
                        ans += area;
                    }
                }
            }
            
            System.out.println((long) Math.round(ans));

            N = sc.nextInt();
            r = sc.nextDouble();
        }

        sc.close();
    }
}
```
