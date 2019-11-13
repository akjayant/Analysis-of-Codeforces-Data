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

#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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
const int N =500005;
int n,a[305][305];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

    cin>>n;
    int c=0;
    forr(j,1,n)
    {
       if(j%2)
       {
           int c=(j-1)*n;
           forr(i,1,n)a[i][j]=++c;
       }
       else
       {
           int c=j*n;
           forr(i,1,n)a[i][j]=c--;
       }

    }

    forr(i,1,n)
    {
        forr(j,1,n)cout<<a[i][j]<<" ";
        cout<<endl;
    }


return 0;
}
