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
const int maxn = 5e2 + 5;
const ll Mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=Mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%Mod;a=a*a%Mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head
    int n;
    char st[maxn];
    int res,resl,resr;

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("D:\\123.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",st);
	res = resl = resr = 0;
	rep(i,0,n-1)
    rep(j,i,n-1){

        int L = 0,R = 0;

        rep(k,0,n-1){

            int kk = k;
            if(kk == i) kk = j;
            else if(kk == j) kk = i;

            if(st[kk] == ')'){
                if(L) L --;
                else R ++;
            }
            else L ++;

        }

        int now = 0,nres = 0;

        while(1){
            if(L == 0 && R == 0) ++ nres;
            if(now == n - 1) break;

            int kk = now;
            if(kk == i) kk = j;
            else if(kk == j) kk = i;

            if(st[kk] == ')'){
                R --; L --;
            }
            else{
                R ++; L ++;
            }
            ++now;
        }
        if(nres > res){
            res = nres;
            resl = i;
            resr = j;
        }
    }
    printf("%d\n",res);
    printf("%d %d\n",resl+1,resr+1);
//    fclose(stdin);
    return 0;
}
