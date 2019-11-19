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

    ll n,k,c1,c2,d,ans,i,q;
    cin>>n>>k;
    mll b;
    mll ::iterator it1,it2,it3,it4;
    vll a(n);
    fn(i,n)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    it1=b.begin(),it2=--b.end();
    W(it1!=it2)
    {
        c1=it1->se;
        c2=it2->se;
        //cout<<it1->fi<<" "<<it2->fi<<endl;
        if(c1<=c2)
        {
            it3=it1;
            it3++;
            d=(it3->fi-it1->fi);
            if(c1*d<=k)
            {
                k-=c1*d;
                b[it3->fi]+=c1;
                b.erase(it1);
                it1=b.begin();
            }
            else
            {
                q=k/c1;
                ans=it2->fi-(it1->fi+q);
                cout<<ans;
                return 0;
            }
        }
        else
        {
            it4=it2;
            it4--;
            d=(it2->fi-it4->fi);
            if(c2*d<=k)
            {
                k-=c2*d;
                b[it4->fi]+=c2;
                b.erase(it2);
                it2=(--b.end());
            }
            else
            {
                q=k/c2;
                ans=(it2->fi-q)-it1->fi;
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}







