#  Oil Deposits 

[題目連結vj](https://vjudge.net/problem/UVA-572)  


#### 解題

依照題目意思
>連在一起的油井算一個油井
>算有幾個油井

遞迴
>找到油井==>去四周(上下左右斜邊)如果有，就把它改成`*`==>再從他開始找(一樣上下左右斜邊)  
>直到在四周再也找不到油井，結束修改


#### code (java)

```java
import java.util.*;

public class Oil_Deposits {
    static String[] hall;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int y = sc.nextInt();
            int x = sc.nextInt();
            if (x == 0 && y == 0) {
                break;
            }
            hall = new String[y];
            for (int i = 0; i < y; i++) {
                hall[i] = sc.next();
            }
            int ans = 0;
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (hall[i].charAt(j) == '@') {
                        find_same(i, j);
                        ans++;
                    }
                }
            }
            System.out.println(ans);

        }

        sc.close();
    }

    public static void find_same(int y, int x) {
        int rows = hall.length;
        int cols = hall[0].length(); // Assuming all rows have the same length

        // Check below
        if (y + 1 < rows && hall[y + 1].charAt(x) == '@') {
            hall[y + 1] = hall[y + 1].substring(0, x) + '*' + hall[y + 1].substring(x + 1);
            find_same(y + 1, x);
        }

        // Check above
        if (y - 1 >= 0 && hall[y - 1].charAt(x) == '@') {
            hall[y - 1] = hall[y - 1].substring(0, x) + '*' + hall[y - 1].substring(x + 1);
            find_same(y - 1, x);
        }

        // Check left
        if (x - 1 >= 0 && hall[y].charAt(x - 1) == '@') {
            hall[y] = hall[y].substring(0, x - 1) + '*' + hall[y].substring(x);
            find_same(y, x - 1);
        }

        // Check right
        if (x + 1 < cols && hall[y].charAt(x + 1) == '@') {
            hall[y] = hall[y].substring(0, x + 1) + '*' + hall[y].substring(x + 2);
            find_same(y, x + 1);
        }

        // Check bottom right
        if (x + 1 < cols && y + 1 < rows && hall[y + 1].charAt(x + 1) == '@') {
            hall[y + 1] = hall[y + 1].substring(0, x + 1) + '*' + hall[y + 1].substring(x + 2);
            find_same(y + 1, x + 1);
        }

        // Check bottom left
        if (x - 1 >= 0 && y + 1 < rows && hall[y + 1].charAt(x - 1) == '@') {
            hall[y + 1] = hall[y + 1].substring(0, x - 1) + '*' + hall[y + 1].substring(x);
            find_same(y + 1, x - 1);
        }

        // Check top right
        if (x + 1 < cols && y - 1 >= 0 && hall[y - 1].charAt(x + 1) == '@') {
            hall[y - 1] = hall[y - 1].substring(0, x + 1) + '*' + hall[y - 1].substring(x + 2);
            find_same(y - 1, x + 1);
        }

        // Check top left
        if (x - 1 >= 0 && y - 1 >= 0 && hall[y - 1].charAt(x - 1) == '@') {
            hall[y - 1] = hall[y - 1].substring(0, x - 1) + '*' + hall[y - 1].substring(x);
            find_same(y - 1, x - 1);
        }
    }

}
```
