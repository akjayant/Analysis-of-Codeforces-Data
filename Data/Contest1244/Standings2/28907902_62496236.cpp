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
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l=1,r=n;
    ll mi=a[1],ma=a[n];
    while(k>0&&l<r){
        ///test(l,r,k);
        if(l<=n-r+1){
            ll de=a[l+1]-a[l];
            ll step=l;
            ll sum=min(k/step,de);
            k-=sum*step;
            mi+=sum;
            l++;
          //  debug(mi);
           // debug(a[l]);
            if(mi!=a[l])break;
        }
        else {
            ll de=a[r]-a[r-1];
            ll step=n-r+1;
            ll sum=min(k/step,de);
            k-=sum*step;
            ma-=sum;
            r--;
            if(ma!=a[r])break;
        }
    }
    cout<<ma-mi<<"\n";
    return 0;
}
