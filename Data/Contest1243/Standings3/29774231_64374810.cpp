#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 99999999999999999
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
#define mxnn 500
#define mod (ll)998244353

int32_t main(){
int t;
cin >>t;
while(t--)
{
    int n;
    cin >>n;
    vector<int>v(n);
    for(int i = 0 ;i <n; i++) cin >>v[i];
    sort(v.rbegin(), v.rend());
    int ans;
    for(int i = 0; i<n; i++)
    {
        if(v[i] > i)
        {
            ans = i+1;
        }
        else break;
    }
    cout<<ans<<"\n";
}
return 0;
}
