/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    int beg=1,en=n;
    int mid,ans;

    int cnt;
    while(beg<=en)
    {
        mid=(beg+en)/2;

        cnt=0;
        for(int i=0;i<n;++i)
        {
            if(v[i]>=mid)
                ++cnt;
        }

        if(cnt>=mid)
        {
            ans=mid;
            beg=mid+1;
        }
        else
            en=mid-1;
    }

    cout<<ans<<"\n";
}

int32_t main()
{
    fast();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

