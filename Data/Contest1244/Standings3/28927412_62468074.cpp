#include<bits/stdc++.h>
#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
#define mod Mod
#define LL ll
typedef vector<long long> VI;
typedef pair<long long,long long> PII;

typedef long long ll;
const int maxn = 2e5 + 5;
const ll Mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=Mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%Mod;a=a*a%Mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head
    int a,b,c,d,k;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
        scanf("%d %d %d %d %d", &a ,&b, &c ,&d ,&k);
//        cout << a << b << c << d << k;
        int res1 = 0,res2 = 0;
        res1 = a / c + (a % c != 0);
        res2 = b / d + (b % d != 0);
//        cout << res1 << " " << res2 << endl;
        if(res1 + res2 > k) cout << "-1" << endl;
        else cout << res1 << " " << res2 << endl;
//        cout << res << endl
	}
	return 0;
}
