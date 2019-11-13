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
const int maxn=2e5+100;
char s[maxn];
int ans[maxn];
void solve()
{
    int t;scd(t);
    while(t--){
        int a,b,c,n;
        scd(n);
        rep1(i,n)ans[i]=0;
		scddd(a,b,c); 
		scanf("%s",s+1);
		int mark=0;
		rep1(i,n){
			if(s[i]=='R'){
				if(b){
					b--;
					ans[i]=2;
					mark++;
				}
			}
			else if(s[i]=='P'){
				if(c){
					c--;
					ans[i]=3;
					mark++;
				}
			}
			else {
				if(a){
					a--;
					ans[i]=1;
					mark++;
				}
			}
		}
		if(mark>=(n+1)/2){
			printf("YES\n");
			rep1(i,n){
				if(ans[i]==1||(ans[i]==0&&a)){
					if(ans[i]==0)a--;
					printf("R");
				}
				else if(ans[i]==2||(ans[i]==0&&b)){
					if(ans[i]==0)b--;
					printf("P");
				}
				else if(ans[i]==3||(ans[i]==0&&c)){
					if(ans[i]==0)c--;
					printf("S");
				}
			}
			printf("\n");
		}
		else printf("NO\n");
    }
}
int main(){
    //IOS;
    solve();
    return 0;
}
