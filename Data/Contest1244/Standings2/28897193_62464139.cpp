#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+23;

int n,m,x,y;
int a,b,c,d,k;
int main()
{
    int t;
    cin >>t ;
    while(t--){
        cin >>a >> b >>c >>d >> k;
        int a1=(a-1)/c+1,a2=(b-1)/d+1;
        if(a1+a2<=k) printf("%d %d\n",a1,a2);
        else printf("-1\n");
    }
}
