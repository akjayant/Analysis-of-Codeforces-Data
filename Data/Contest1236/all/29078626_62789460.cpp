#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <limits.h>
#define rep(i,a) for(i=0;i<a;i++)
#define lp(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
typedef long long ll;
typedef unsigned long ul;
using namespace std;

const ll MOD = 1000000007;

ll GCD(ll a,ll b){
    if(b==0)
        return a;
    return GCD(b,a%b);
}

void extendedEuclid(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    ll x1,y1;
    extendedEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-((a/b)*y1);
}

ll exp(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //begin here
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    cout<<exp((exp(2,m)-1+MOD)%MOD,n);
    return 0;
}
