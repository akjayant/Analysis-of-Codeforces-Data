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
const int N=1e3+10;
int T,n,m;
int main(){
    IO;
    cin>>T;
    while(T--){
        cin>>n;
        ll a=0,b=0,c=0,d=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x%2)a++;
            else b++;
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            if(x%2)c++;
            else d++;
        }
        ll ans=a*c+b*d;
        cout<<ans<<endl;
    }
}
