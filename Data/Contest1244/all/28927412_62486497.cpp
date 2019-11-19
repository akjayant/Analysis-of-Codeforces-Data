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

    ll n,p,x,y,z,xx,yy,zz,jia;
    int d,w;
    bool boo[maxn];

inline ll yu(ll o,ll p){
    return (o % p + p) % p;
}

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%I64d%I64d%d%d",&n,&p,&w,&d);
	jia = 1ll * w * (w - d) / gcd(w,w-d);

	yy = (w * n - w * z - p);
    if(yu(yy,w-d) == 0 || yu(yy,w-d)%gcd(w-d,w) == 0){
        // 6666;
    }
    else{
        printf("-1\n");
        return 0;
    }

    int tot = 0;

    while(yy % (w - d) != 0){
        yy += w;
    }


    yy %= jia;
    if(yy >= 0) yy -= jia;
    tot = 0;
    bool bo = true;
    while(1){
        tot ++;
//        cout << tot << endl;
        if(yy < 0 && bo){
            yy %= jia;
            if(yy < 0)yy += jia;
            bo = false;
        }
        else yy += jia;
        y = yy / (w - d);
        x = (p - y * d) / w;
        z = n - x - y;
        if(x >= 0 && y >= 0 && z >= 0){
            printf("%I64d %I64d %I64d\n",x,y,z);
//            cout << tot << endl;
//            cout << x << " " << y " " << z << endl;
            return 0;
        }
        else if(x < 0 || z < 0){
            break;
        }
    }
    printf("-1\n");
//	y = n - p / w;
//	x = (p - y * d) / w;
//	z = n - x - y;
//	y += w;
//	cout << x << " " << y << " " << z;
	return 0;
}
