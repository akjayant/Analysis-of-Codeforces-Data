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

    int T,n,res,cuo[maxn],cuonum;
    char s[maxn],t[maxn];
    int tong[maxn];
    vector<pair<int,int>> vec;

int main()
{
    #ifdef LOCAL
        freopen("D:\\123.txt","r",stdin);
    #endif // LOCAL
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        rep(i,1,26) tong[i] = 0;
        rep(i,0,n-1){
            if(s[i] != t[i]){
                tong[s[i]-'a'+1] ++;
                tong[t[i]-'a'+1] ++;
            }
        }
        bool bo = true;
        rep(i,1,26){
            if(tong[i] % 2 != 0){
                bo = false;
                break;
            }
        }
        if(!bo){
            puts("No");
            continue;
        }
        vec.clear();

        rep(i,0,n-1){
            if(s[i] != t[i]){
                rep(j,i+1,n-1){
                    if(s[j] != t[j]){
                        if(s[j] == s[i]){
                            vec.push_back(mp(j,i));
                            swap(s[j],t[i]);
                            break;
                        }
                        if(t[j] == s[i]){
                            vec.push_back(mp(j,j));
                            swap(s[j],t[j]);
                            vec.push_back(mp(j,i));
                            swap(s[j],t[i]);
                            break;
                        }
                    }
                }
            }
        }
        puts("Yes");
        printf("%d\n",vec.size());
        int nn = vec.size();
        rep(i,0,nn-1){
            printf("%d %d\n",vec[i].first+1,1+vec[i].second);
        }
    }
    return 0;
}

