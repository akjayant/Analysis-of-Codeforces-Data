#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
void test(){cerr<<"\n";}
template<typename T,typename... Args>void test(T x,Args... args){cerr<<x<<" ";test(args...);}
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN=(int)1e5+5;
const int MOD=(int)1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int  a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int a1=(a+c-1)/c;
        int a2=(b+d-1)/d;
        if(a1+a2<=k)cout<<a1<<" "<<a2<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
