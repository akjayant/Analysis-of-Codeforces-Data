#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000010;
const int mod=1000000007;
char s[N];
ll a[N];
struct Point
{
    ll x, y;
};
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,m,t,k;
    cin>>t;
    while(t--) {
        ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>k;
            if(k&1) cnt1++;
            else cnt2++;
        }
        cin>>m;
        for(int i=1;i<=m;i++) {
            cin>>k;
            if(k&1) cnt3++;
            else cnt4++;
        }
        printf("%lld\n",cnt1*cnt3+cnt2*cnt4);
    }
    return 0;
}
