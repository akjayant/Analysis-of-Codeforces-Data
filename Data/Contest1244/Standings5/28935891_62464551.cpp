#include<bits/stdc++.h>

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

int main(){
    for(int T = inp(); T >= 1; T--){
        int a = inp();
        int b = inp();
        int c = inp();
        int d = inp();
        int k = inp();
        int num1 = (a - 1) / c + 1;
        if((k - num1) * d >= b)
            printf("%d %d\n", num1, k - num1);
        else
            printf("-1\n");
    }
}