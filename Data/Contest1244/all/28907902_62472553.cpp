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
int gao(const string &s){
    int n=s.size();
    int res=n;
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp++;
        if(s[i]=='1'){
            tmp++;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=gao(s);
        reverse(s.begin(),s.end());
        ans=max(ans,gao(s));
        int ma=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ma=max(ma,i+1);
                ma=max(ma,n-i);
            }
        }

        ans=max(ans,ma*2);
        cout<<ans<<"\n";
    }
    return 0;
}
