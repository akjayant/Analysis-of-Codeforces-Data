#include <bits/stdc++.h>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define MAXN        200001
ll int n;
ll int x[MAXN];
ll int y[MAXN];
ll int c[MAXN];
ll int k[MAXN];
ll int parent[MAXN];
ll int cost=0;
vector <pair<ll int,ll int>> ans1;
vector <ll int> ans;
vector <pair<ll int,pair<ll int,ll int>>> edges; 
ll int gerparent(ll int child)
{
    if(parent[child]==child) return child;
    else
    {
        ll int temp=gerparent(parent[child]);
        parent[child]=temp;
        return temp;
    }
}
void init()
{
    rep(i,0,MAXN) parent[i]=i;
}
int main()
{
    init();
    cin >> n;
    rep(i,1,n+1) cin >> x[i] >> y[i];
    rep(i,1,n+1) {cin >> c[i];edges.push_back({c[i],{0,i}});}
    rep(i,1,n+1) cin >> k[i];
    rep(i,1,n+1)
    {
        rep(j,i+1,n+1)
        {
            ll int cost1=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            edges.push_back({cost1,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for (auto it: edges)
    {
        ll int cost1=it.first;
        ll int u=it.second.second;
        ll int v=it.second.first;
        long long int A1=gerparent(u);
        long long int A2=gerparent(v);
        if (A1!=A2)
        {
            if (u==0 or v==0)
            {
                ans.push_back(max(u,v));
            }
            else
            {
                ans1.push_back({u,v});
            }
            cost=cost+cost1;
            if (A1>A2)
            {
                parent[A2]=A1;
            }
            else
            {
                parent[A1]=A2;
            }
        }
    }
    cout << cost << endl;
    cout << ans.size() << endl;
    for (auto i: ans) cout << i << " ";
    cout << endl;
    cout << ans1.size() << endl;
    for (auto it: ans1)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
}