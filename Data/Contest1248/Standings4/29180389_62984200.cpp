#include<bits/stdc++.h>
#define ms(x) memset(x,0,sizeof(x))
#define sws ios::sync_with_stdio(false)
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e6+2;
const ll mod=1e9+7;
const int up=4;
int a[maxn];
int main(){
    int n;
    sws;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int co=(n+1)/2;
    ll ans=0;
    for(int i=n;i>=n-co+1;i--){
        ans+=a[i];
    }
    ll res=0;
    for(int i=1;i<n-co+1;i++) res+=a[i];
    cout<<res*res+ans*ans<<endl;
}


