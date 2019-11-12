/*
  AUTHOR:SOURABH
  CREATED:26:10:19
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pll , null_type, less< pll >, rb_tree_tag, tree_order_statistics_node_update>
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

    ll q,n,i,c,k,j,f;
    string s,t;
    cin>>q;
    W(q--)
    {
        cin>>n;
        cin>>s>>t;
        vll pos;
        vector<pll> ans;
        fn(i,n)
        {
            if(s[i]!=t[i])
            pos.pb(i);
        }
        k=pos.size();
        c=0;
        fn(i,k)
        {
            if(s[pos[i]]==t[pos[i]])
                continue;
            f=0;
            fs(j,i+1,k)
            {
                if(s[pos[j]]==s[pos[i]])
                {
                    swap(s[pos[j]],t[pos[i]]);
                    ans.pb({pos[j]+1,pos[i]+1});
                    f=1;
                    c++;
                    break;
                }
            }
            if(f==0)
            {
            fs(j,i+1,k)
            {
                if(t[pos[j]]==s[pos[i]])
                {
                    swap(s[pos[j]],t[pos[j]]);
                    swap(s[pos[j]],t[pos[i]]);
                    ans.pb({pos[j]+1,pos[j]+1});
                    ans.pb({pos[j]+1,pos[i]+1});
                    f=1;
                    c+=2;
                    break;
                }
            }
            }
            if(f==0)
            {cout<<"No\n";goto e;}
        }
        if(c>2*n)
        {cout<<"No\n";goto e;}
        cout<<"Yes\n";
        k=ans.size();
        cout<<k<<"\n";
        fn(i,k)
        cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
        e:
            ;
    }
    return 0;
}





























