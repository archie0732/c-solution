# 作業3 


## 題目意思

- 求 n!

$n! = n \times (n - 1) \times (n - 2) \dots \times 1$

ex:

$5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$ 



我們可以先用一個for迴圈

- for 迴圈定義:

```cpp
/*
for( 初始化直; 終止條件 ; 迴圈回朔時執行){
  // 你的程式碼
}
*/

for(int i = 0;i < 3;i++){
  print(i);
}
// 輸出 0 1 2
// 沒有 3 因為 i = 3 時不小於 3
```

處理正常情況

```cpp
#include<stdio.h>

int main(void) {
    int n;
    int answer = 1;

    scanf("%d", &n);

    if (n < 0) { // 非正常情況
        print("ERROR");
    }

    else if (n == 0) { // 當要求 0!時
        print(1);
    }

    else {
        for (int i = 1; i <= n; i++) // 由 1 到 n
        {
            answer = answer * i; // 1 * 2 * 3....* n
        }
        print(answer);
    }

    return 0;
}
```
