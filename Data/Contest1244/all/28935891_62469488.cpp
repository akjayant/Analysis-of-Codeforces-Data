#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647

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

char s[1010];

int main(){
    for(int T = inp(); T >= 1; T--){
        int n = inp();
        scanf("%s", s + 1);
        int min = INF;
        int max = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '1'){
                min = std::min(min, i);
                max = i;
            }
        }
        if(max == 0)
            printf("%d\n", n);
        else
            printf("%d\n", std::max(n - min + 1, max) << 1);
    }
}