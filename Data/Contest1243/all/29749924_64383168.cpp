#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define Find find_by_order
#define Pos order_of_key
#define N 1000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll g=n;
        for(ll i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                g=__gcd(i,g);
                g=__gcd(g,n/i);
            }
        }
        cout<<g;
    }
}