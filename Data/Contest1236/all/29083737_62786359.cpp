/**
*
* Author: MARS
* Lang: GNU C++14
*
**/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl E = 2.71828182845904523536;
const ldbl pi = acos(-1);
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

/** /////////// ** Code ** /////////// **/

const int N=111;
int mem[N][N][N];

int dp(int a,int b,int c){
    int &ret = mem[a][b][c];
    if(ret != -1)
        return ret;

    ret=0;

    if(a >= 1 && b >=2 && c >=2) return ret = 3+max(dp(a-1,b-2,c),dp(a,b-1,c-2));
    if(a >= 1 && b >= 2) return ret = 3+dp(a-1,b-2,c);
    if(b >= 1 && c >= 2) return ret = 3+dp(a,b-1,c-2);

    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    memset(mem,-1,sizeof mem);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",dp(a,b,c));
    }
    return 0;
}
