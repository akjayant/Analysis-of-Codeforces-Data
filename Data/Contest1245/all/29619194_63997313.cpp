#include <bits/stdc++.h>

using namespace std;

const int N=1e6+2,MOD=1e9+7;

typedef long long ll;

int a[N],b[N],n,m,x,y,u,v,tc,k,ans,l,r,q;

char s[N];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        scanf("%d%d",&a,&b);
        if (__gcd(a,b)!=1)
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
}
