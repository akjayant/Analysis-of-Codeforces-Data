#include<bits/stdc++.h>
#include <time.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define PI acos(-1)
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define el endl
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define sz size()
#define s(x) sort(x.begin(),x.end())
#define rs(x) sort(x.rbegin(),x.rend())
#define all(v) v.begin(),v.end()
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define mod 1000000007

int main()
{
    FAST;
    ll t,n,i,st,en;
    cin>>t;
    while(t--)
    {
        cin>>n;
        st=-1,en=-1;
        string s;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1' && st==-1)
            st=i;
            if(s[i]=='1')
            en=i;
        }
        if(st!=-1)
        cout<<max(2*(en+1),2*(n-st))<<el;
        else
        cout<<n<<el;
    }
}
