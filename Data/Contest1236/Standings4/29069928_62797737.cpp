#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls x<<1
#define rs x<<1|1
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-6;
const ull hashp=1e7+19;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e3+100;
int ans[maxn][maxn];
void solve()
{
    int n;scd(n);
    int sta=0;
    rep1(i,n){
    	sta=!sta;
    	rep1(j,n){
    		if(sta)ans[j][i]=(i-1)*n+j;
    		else ans[j][i]=i*n-j+1;
		}
	}
	rep1(i,n){
		rep1(j,n)printf("%d ",ans[i][j]);
		printf("\n");
	}
}
int main(){
    //IOS;
    solve();
    return 0;
}