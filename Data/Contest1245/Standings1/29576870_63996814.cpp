#include <bits/stdc++.h>

using namespace std;

#define MAX 300005
#define ll long long

int main()
{
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int a, b;
        scanf("%d %d", &a, &b);
        int g = __gcd(a, b);
        if(g == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
}