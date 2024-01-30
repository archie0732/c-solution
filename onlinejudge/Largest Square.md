# Largest Square

[題目連結](https://vjudge.net/problem/UVA-10908)

#### 解題

* 由左上至右下判斷正方形

#### code (cpp)

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int x, y, n;
    cin >> x >> y >> n;
    vector<string> v(x);
    for (int i = 0; i < x; i++)
    {
      cin >> v[i];
    }
    cout << x << " " << y << " " << n << endl;
    while (n--)
    {
      int a, b;
      cin >> a >> b;
      int ans = 1, flag = 1;

      for (int i = 1; flag; i++)  
      {
        for (int px = a - i; px <= a + i && flag; px++)  
        {
          for (int py = b - i; py <= b + i && flag; py++)  
          {
            if (px < 0 || py < 0 || px >= x || py >= y || v[px][py] != v[a][b])
            {
              flag = 0;
              break;
            }
          }

        }
        if (flag)
        {
          ans += 2;
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}

```
**java**  
```java
import java.util.*;

public class LS {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      int n = sc.nextInt();
      String[] board = new String[a];
      for (int i = 0; i < a; i++) {
        board[i] = sc.next();
      }
      System.out.println(a + " " + b + " " + n);
      while (n-- > 0) {
        int x = sc.nextInt();
        int y = sc.nextInt();

        int flag = 1, ans = 1;

        for (int i = 1;; i++) {
          for (int px = x - i; px <= x + i; px++) {
            for (int py = y - i; py <= y + i; py++) {
              if (px >= a || py >= b || px < 0 || py < 0 || board[px].charAt(py) != board[x].charAt(y)) {
                flag = 0;
                break;
              }
            }
          }
          if (flag == 1) {
            ans += 2;
          } else {
            break;
          }
        }
        System.out.println(ans);
      }

    }
    sc.close();
  }

}
```
