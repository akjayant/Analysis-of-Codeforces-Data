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
int jc[maxn]={1},inv[maxn];
int qpow(int a,int b){
	int ret=1;
	a%=mod;
	while(b){
		if(b&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ret;
}
void init(){
	rep1(i,100000)jc[i]=1ll*i*jc[i-1]%mod;
	inv[100000]=qpow(jc[100000],mod-2);
	for(int i=99999;~i;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int c(int n ,int m){
	return 1ll*jc[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve()
{
    int t=1;
    init();
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        rep1(i,n){
        	if(s[i]=='m'||s[i]=='w'){
        		printf("0\n");
        		return ;
			}
		}
        int cnt=1;
        int ans=1;
        for(int i=2;i<=n;i++){
        	if(s[i]==s[i-1])cnt++;
        	else {
        		if(cnt>1&&(s[i-1]=='n'||s[i-1]=='u')){
        			int mark=1;
        			for(int j=1;j*2<=cnt;j++)
        				mark=(mark+c(cnt-j,j))%mod;
        			ans=1ll*ans*mark%mod;
				}
        		cnt=1;
			}
		}
		if(cnt>1&&(s[n]=='n'||s[n]=='u')){
        		int mark=1;
        		for(int j=1;j*2<=cnt;j++)
        			mark=(mark+c(cnt-j,j))%mod;
        		ans=1ll*ans*mark%mod;
			}
		ac;
    }
}
int main(){
    //IOS;
    solve();
    return 0;
}
