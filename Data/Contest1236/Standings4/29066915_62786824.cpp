#include<bits/stdc++.h>
using namespace std;

int t,a,b,c,ans;

int main(){
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d %d %d", &a, &b, &c);
        int c1 = c/2;
        if (c1 >= b){
            printf("%d\n", 3*b);
            continue;
        }
        ans = c1*3;
        int b1 = (b-c1)/2;
        ans += 3*min(a, b1);
        printf("%d\n", ans);
    }
    return 0;
}
