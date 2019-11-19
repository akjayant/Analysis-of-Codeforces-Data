#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;

ll a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll l=1,r=n,b=0,c=0;
    while(l<=r)
    {
        b+=a[r--];
        if(l<=r)c+=a[l++];
    }
    printf("%lld",b*b+c*c);
    return 0;
}
