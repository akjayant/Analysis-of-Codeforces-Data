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
    int n,arr[maxn];
    ll res,s1,s2;

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	rep(i,1,n){
        if(i <= n/2) s1 += arr[i];
        else s2 += arr[i];
	}
	res = s1 * s1 + s2 * s2;
	cout << res << endl;
	return 0;
}
