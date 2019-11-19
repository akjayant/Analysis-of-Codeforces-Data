#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int MAXN = 1e6+10;
const double EPS = 1e-12;
const int mod = 1e9+7;

int T,n,m,cnt;
ll a[MAXN],b[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll x=0,y=0;
    int flag=1,l=1,r=n;
    while(r>=l){
        if(flag==1){
            x+=a[r];
            r--;
        }
        else{
            y+=a[l];
            l++;
        }
        flag*=-1;
    }
    printf("%lld",x*x+y*y);
}
