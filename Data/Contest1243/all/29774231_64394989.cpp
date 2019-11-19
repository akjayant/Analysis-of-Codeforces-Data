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
sp;
int n;
cin >>n;
vector<int>prime;
int x = n;
int j = 2;
while(x > 0 && j*j<=x)
{
    if(x%j == 0)
    {
        prime.pb(j);
        while(x > 1 && x%j == 0)
            x = x/j;
    }
    j++;
}
if(x > 1) prime.pb(x);
if(prime.size() == 1)
{
    cout<<prime[0];
}
else
{
    cout<<1;
}
return 0;
}
