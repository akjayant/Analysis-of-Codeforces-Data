
//#include "stdc++.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define pb push_back
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
struct subset
{
    int rank,parent;
};
int find(subset subsets[],int i)
{
    if(subsets[i].parent==i)
        return i;
    subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[],int x,int y)
{
    if(subsets[x].rank>subsets[y].rank)
        subsets[y].parent=x;
    else if(subsets[y].rank>subsets[x].rank)
        subsets[x].parent=y;
    else{
        subsets[y].parent=x;
        subsets[x].rank++;
    }
}
int cnt=0;
set<int>unvisited;
void dfs(set<pair<int,int> >&s,int u)
{
    unvisited.erase(u);set<int>::iterator it;
    //cout<<u<<endl;
    cnt++;
    for(it=unvisited.begin();it!=unvisited.end();)
    {
        if(s.find(m1(u,*it))==s.end())
        { dfs(s,*it);
            it=unvisited.begin();
        }
        else
            it++;
        //else
        //{
        //     s.erase(m1(u,*it));
        //     s.erase(m1(*it,u));
        //   }
        
    }
}
int main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");
    int n,m;
    cin>>n>>m;
    set<pair<int,int> >s;int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        s.insert(m1(u,v));
        s.insert(m1(v,u));
    }
    //set<int>unvisited;
    for(int i=1;i<=n;i++)
        unvisited.insert(i);
    vector<int>components;
    while(!unvisited.empty())
    {
        cnt=0;
        dfs(s,(*(unvisited.begin())));
        // cout<<"OK"<<endl;
        components.push_back(cnt);
    }
    cout<<components.size()-1<<endl;
    
    return 0;
}
