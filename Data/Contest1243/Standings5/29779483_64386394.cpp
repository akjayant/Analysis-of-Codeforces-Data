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

    ll q,n,i,ans,c,id1,id2;
    string s,t;
    cin>>q;
    W(q--)
    {
        cin>>n;
        cin>>s>>t;
        c=0;
        fn(i,n)
        {
            if(s[i]!=t[i] && c==0)
            {c++;id1=i;}
            else if(s[i]!=t[i] && c==1)
            {c++;id2=i;}
            else if(s[i]!=t[i])
                c++;
        }
        if(c==0)
            cout<<"Yes\n";
        else if(c>2 || c==1)
            cout<<"No\n";
        else
        {
            if(s[id1]==s[id2] && t[id1]==t[id2])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}




























