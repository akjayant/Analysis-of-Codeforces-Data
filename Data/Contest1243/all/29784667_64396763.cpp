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
set<ll> st;
void primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        st.insert(2); 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            st.insert(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        st.insert(n); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    primeFactors(n);
    if(st.size()==1)
    {
        set<ll>::iterator itr;
        itr=st.begin();
        if(*itr!=n)
        {
            cout<<*itr<<endl;
        }
        else
        {
            cout<<n<<endl;
        }
    }
    else
    {
        cout<<"1"<<endl;
    }
}