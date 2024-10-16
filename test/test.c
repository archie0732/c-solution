#include<stdio.h>

int main(void) {
    int n;
    int answer = 1;

    scanf("%d", &n);

    if (n < 0) {
        print("ERROR");
    }

    else if (n == 0) {
        print(1);
    }

    else {
        for (int i = 1; i <= n; i++)
        {
            answer = answer * i;
        }
        print(answer);
    }

    return 0;
}