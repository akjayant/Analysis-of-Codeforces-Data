/*
  AUTHOR:SOURABH
  CREATED:12:10:19
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pair<int, int> , null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAX 100005
#define M 32

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll t,n,i,p,q,k,ma;
    string s;
    cin>>t;
    W(t--)
    {
        cin>>n;
        cin>>s;
        vll a;
        fn(i,n)
        {
            if(s[i]=='1')
            a.pb(i);
        }
        k=a.size();
        if(k>0)
        {
            p=a[k-1];
            ma=p+2+max(n-1-p,p);
            q=a[0];
            ma=max(ma,n-q+1+max(q,n-q-1));
            cout<<ma<<"\n";
        }
        else
        {
            cout<<n<<"\n";
        }
        a.clear();
    }
    return 0;
}






