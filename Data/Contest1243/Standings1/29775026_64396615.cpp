#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i=x;i<=y;i++)
#define per(i,x,y) for (int i=x;i>=y;i--)
#define quicker ios::sync_with_stdio(false);
#define first fi
#define second sec
typedef long double ld;
typedef long long ll;
const long long INF=2147483647;
int main()
{
	ll n,x=0;
    cin>>n;
    if(n==1){cout<<1<<endl;return 0;}
    for(x=2;x<=sqrt(n);++x) if(n%x==0) break;if(n%x!=0) x=n;while(n%x==0) n/=x;
    if(n!=1) cout<<1<<endl; else cout<<x<<endl;
	return 0;
}
