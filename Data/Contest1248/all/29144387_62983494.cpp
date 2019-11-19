#include<iostream>
using namespace std;
const int maxn=100010;
long long p[maxn],q[maxn];
long long cnt1,cnt2;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        cnt1=0;cnt2=0;
        long long n,m;cin>>n;
        for(long long i=1;i<=n;i++) cin>>p[i],cnt1+=((p[i]%2)?1ll:0ll);
        cin>>m;
        for(long long i=1;i<=m;i++) cin>>q[i],cnt2+=((q[i]%2)?1ll:0ll);
        cout<<cnt1*cnt2+(n-cnt1)*(m-cnt2)<<endl;
    }
    return 0;
}