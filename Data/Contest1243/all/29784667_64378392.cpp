#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<int,int>, null_type,less< pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update> 
//find_by_order(k) - k is the kth element of the set
//order_of_key(k) - Number of elements striclty samller than k
void build(ll segt[],ll arr[],ll l,ll r,ll ind)
{
    if(l==r)
    {
        segt[ind]=arr[l];
        return;
    }
    ll mid=l+(r-l)/2;
    build(segt,arr,l,mid,2*ind+1);
    build(segt,arr,mid+1,r,2*ind+2);
    segt[ind]=min(segt[2*ind+1],segt[2*ind+2]);
}
//llim-lower limit of array,rlim-upper limit of array
//l,r- range of query
ll sum(ll segt[],ll llim,ll rlim,ll l,ll r,ll ind)
{
    //cout<<llim<<" "<<rlim<<endl;
    if(l<=llim && rlim<=r)
    {
        //cout<<"here "<<segt[ind]<<" "<<ind<<endl;
        return segt[ind];
    }
    if(r<llim || rlim<l)
    {
        return 1e18;
    }
    ll mid=llim+(rlim-llim)/2;
    return min(sum(segt,llim,mid,l,r,2*ind+1),sum(segt,mid+1,rlim,l,r,2*ind+2));
}
void update(ll segt[],ll llim,ll rlim,ll diff,ll upind,ll ind)
{
    if(upind<llim || upind>rlim)
        return;
    segt[ind]=min(segt[ind],diff);
    if(llim==rlim)
    {
        segt[ind]=diff;
        return;
    }
    if(llim!=rlim)
    {
        ll mid=llim+(rlim-llim)/2;
        update(segt,llim,mid,diff,upind,2*ind+1);
        update(segt,mid+1,rlim,diff,upind,2*ind+2); 
    }
}
ll modularExponentiation(ll x,ll n,ll M=1000000007)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
 
}
ll modInverse(ll A,ll M=1000000007)
{
    return modularExponentiation(A,M-2,M);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll cnt=0;
        ll a=-1,b=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                cnt++;
                if(a==-1)
                {
                    a=i;
                }
                else
                {
                    b=i;
                }
            } 
                
        }
        if(cnt!=2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(s[a]==s[b] && t[a]==t[b])
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
    }
}