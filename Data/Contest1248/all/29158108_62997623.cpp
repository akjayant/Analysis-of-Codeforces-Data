/*
   we will use dp , our state will be the current number and the state of the previous two numbers .
   state ---> if we changed them or no .
   we need only to check if we can change the current number with the the previous two numbers and
   the next number .
   if it hold the all condition then all contiguous subsequence will also hold .
*/
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
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
const int N =100005;

ll n,m,mod=1e9+7,mem[N][3][3],mem2[N][3][3];

ll dp(int i=1,int p1=2,int p2=2)
{
    if(i>n)return 1;
    ll&ret=mem[i][p1][p2];
    if(~ret)return ret;
    ret=0;
    if(p1==0&&p2==0)ret+=dp(i+1,1,p1)%mod,ret%=mod;
    else if(p1==1&&p2==1)ret+=dp(i+1,0,p1)%mod,ret%=mod;
    else
    {
        ret+=dp(i+1,1,p1)%mod,ret%=mod;
        ret+=dp(i+1,0,p1)%mod,ret%=mod;
    }
    return ret;
}


ll dp2(int i=1,int p1=2,int p2=2)
{
    if(i>m)return 1;
    ll&ret=mem2[i][p1][p2];
    if(~ret)return ret;
    ret=0;
    if(p1==0&&p2==0)ret+=dp2(i+1,1,p1)%mod,ret%=mod;
    else if(p1==1&&p2==1)ret+=dp2(i+1,0,p1)%mod,ret%=mod;
    else
    {
        ret+=dp2(i+1,1,p1)%mod,ret%=mod;
        ret+=dp2(i+1,0,p1)%mod,ret%=mod;
    }
    return ret;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

    cin>>n>>m;
    memset(mem,-1,sizeof mem);
    memset(mem2,-1,sizeof mem2);
    ll ans=(dp()-2+dp2())%mod;
    cout<<(ans+mod+mod)%mod;







return 0;
}
