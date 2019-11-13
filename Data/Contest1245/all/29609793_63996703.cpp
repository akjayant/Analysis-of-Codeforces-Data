#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x);
#define rep(x ,n) for(int x=0; x<n; x++)
#define ll long long
#define finish(x) return cout << x << endl,0;
#define scarr(a,n) for(int x=0; x<n; x++)scanf("%d",&a[x]);

#define MAX_N 2003

int main()
{
    int t;
    sc(t)
    while(t--){
        int a ,b;
        sc(a)sc(b)
        if(__gcd(a ,b) != 1)
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
}
