//https://github.com/magdy-hasan/competitive-programming/blob/8cbf7891ccb20207e90ca25c5841661c0727afa0/CSA/CSA%20Smallest%20Subsets.cpp#L35
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=300009,M=1000000;
int n,m;
vector<int>a[N];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

      cin>>n>>m;
      int u,v;
      forr(i,1,m)
      {
          cin>>u>>v;
          a[u].push_back(v);
          a[v].push_back(u);
      }
      set<pair<int,int>>s;
      map<int,int>k;
      forr(i,1,n)
      {
          s.insert({a[i].size(),i});
          k[i]=a[i].size();
      }

      int ans=0,sz=n;
      while(s.size())
      {
          sz--;
          auto it=--s.end();
          auto p=*it;
          s.erase(it);
          if(sz==p.F)ans++;
          for(auto v:a[p.S])
          {
              auto t=s.lower_bound({k[v],v});
              pair<int,int>nw=*t;
              if(t==s.end()||nw.S!=v)continue;
              s.erase(t);
              s.insert({nw.F-1,nw.S});
              k[nw.S]--;
          }
      }
      cout<<ans-1;




return 0;
}
