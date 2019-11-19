#define bug(x) cout<<#x<<" is "<<x<<endl
#define IO std::ios::sync_with_stdio(0)
#include <bits/stdc++.h>
#define iter ::iterator
#define pa pair<int,ll>
#define pp pair<int,pa>
using namespace  std;
#define ll long long
#define mk make_pair
#define pb push_back
#define se second
#define fi first
#define ls o<<1
#define rs o<<1|1
const ll mod=1e9+7;
const int N=1e5+10;
int T,n,m;
ll a[N];
int main(){
    IO;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll h=0,k=0,res=0;
    for(int i=1;i<=n/2;i++){
        h+=a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        k+=a[i];
    }
    res=h*h+k*k;
    cout<<res<<endl;
}