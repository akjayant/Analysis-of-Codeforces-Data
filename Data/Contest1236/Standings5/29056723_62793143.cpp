#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include<stdio.h>
#include<iomanip>
#include<set>
#include<string>
#include<map>
#include<bitset>
#include <math.h>
#include<queue>
#include<complex>
#include<ctime>
#include<list>
#include<stack>
#define ll  long long
#define fi first
#define ld long double
#define se second
#define pb push_back
#define pii pair<int,int>
#define pdi pair<int,double>
#define pll pair<ll,ll>
#define vi vector<int>
using namespace std;
const ll mod= 1e9+7;
ll n,m;
ll binpow(ll a, ll p){
    if(!p)
        return 1;
    if(p&1)
        return (a*binpow(a,p-1))%mod;
    ll b = binpow(a,p/2);
    return (b*b)%mod;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//freopen("cycling.in","r",stdin);
//freopen("cycling.out","w",stdout);
 srand (time(NULL));
    cin >> n >> m;
    cout << (binpow(((binpow(2,m) - 1+mod)%mod),n)%mod) <<"\n";
  return  0;
}