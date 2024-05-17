# Satellites

[題目連結](https://vjudge.net/problem/UVA-10221)


#### 解題

* 一度=60分鐘
* r 是半徑(已加6440)
* c 是度數(已經換成度)

***
###### 公式

* 弧長: $`2*r*(c/180)*PI`$
* 弦長: $`2*r^2-a^2*\cos{c/180}`$

### 2024-05-17(更新-讓 zero-judge 也能過，但CPE不確定


```cpp

#include <iostream>
#include <cmath>
#include <string>

#define ll long long 
#define dou double


using namespace std;

int main() {
    dou d, c;
    string s;
    
    while(cin >> d >> c >> s){
    	
    	d += 6440; 
    	// 60 min = 1 degree 
    	if(s=="min")c = c/60;
    	if(c>180)c-=180;
    	dou radians = c * M_PI / 180.0;
    
    	// 1/2 * 2*r*radians
   	 	dou arc = d*radians;
    	dou chord = sqrt(2 * d * d - 2 * d * d * cos(radians));
    
    	printf("%.6f %.6f\n",arc,chord);
    }
    return 0;
}

```


#### code (java)


```java
import java.util.*;

public class Satellites {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            double a = sc.nextInt();
            double c = sc.nextInt();
            String s = sc.next();
            if (c > 180) {
                c = 360 - c;
            }
            double c2 = change_de_min(c, s);
            double ans1 = arc(a, c2);

            System.out.printf("%.6f", ans1);
            System.out.print(" ");
            chord(a, c2);
            System.out.println();
        }
        sc.close();
    }

    public static double change_de_min(double a, String s) {
        if (s.equals("min")) {
            return (double) a / 60.0; // 將a轉換為double再進行除法
        } else {
            return a;
        }
    }

    public static void chord(double a, double c) {
        
        double cosValue = Math.cos(Math.toRadians(c));
        double ans = Math.sqrt(2 * (a + 6440) * (a + 6440) - 2 * (a + 6440) * (a + 6440) * cosValue);

        System.out.printf("%.6f", ans);

    }

    public static double arc(double a, double c) {
        double ans = (a + 6440) * c / 180 * Math.PI;
        return ans;
    }
}
```

```cpp
#include <iostream>
#include <cmath>
#include <string>

#define ll long long 
#define dou double
#define PI 2*acos(0.0)

using namespace std;

int main() {
    dou d, c;
    string s;
    
    while(cin >> d >> c >> s){
    	
    	d += 6440; 
    	// 60 min = 1 degree 
    	if(s=="min")c = c/60;
    	if(c>180)c-=180;
    	dou radians = c * PI / 180.0;
    
    	// 1/2 * 2*r*radians
   	 	dou arc = d*radians;
    	dou chord = sqrt(2 * d * d - 2 * d * d * cos(radians));
    
    	printf("%.6f %.6f\n",arc,chord);
    }
    return 0;
}

```



