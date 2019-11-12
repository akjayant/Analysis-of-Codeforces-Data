#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<(int)(y);++i)
#define FORE(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=2e9;
const int MOD=1e9+7;
const int MAXN=1e6+6;

int ans=0;
int n,m,k,q;
int a,b,c;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>q;
    while(q--){
        cin>>a>>b>>c;
        ans=min(c/2,b);
        b-=ans;
        ans+=min(b/2,a);
        cout<<ans*3<<"\n";
    }
    return 0;
}
