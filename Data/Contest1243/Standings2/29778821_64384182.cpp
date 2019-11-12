#include<bits/stdc++.h>
#define LL long long int
#define FIO ios::sync_with_stdio(false)
#define FRD freopen("input.txt","r",stdin)
#define lowbit(x) (x&-(x))
#define ms(x) memset(x,0,sizeof x)
#define pb(x) push_back(x)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
#define all(x)	x.begin(),x.end()
#define SORT(x) sort(all(x))
#define LISAN(x) x.erase(UNIQUE(all(x)),x.end())
#define lid(vec,x)	lower_bound(all(vec),x)-vec.begin()+1
#define uid(vec,x)	upper_bound(all(vec),x)-vec.begin()+1
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define con(u,v)	vec[u].pb(v);
#define conw(u,v,w)		vec[u].pb(pii(v,w))
#define repn(i,a,n)	for(int i=a;i<=n;i++)
#define rep(i,a,n)	for(int i=a;i<n;i++)
using namespace std;
const LL MOD=1e9+7,INF=1e18;
const double eps=1e-8;
template<class T> inline T Min(const T& a,const T& b){return a<b?a:b;}
template<class T> inline T Max(const T& a,const T& b){return a<b?b:a;}
inline int read(){char ch = getchar();int x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline LL readl(){char ch = getchar();LL x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline double readf(){char ch = getchar();double x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}bool flag=false;double bit=0.1;while('0' <= ch && ch <= '9') {if(!flag)	x = x * 10 + ch - '0';else	x+=bit*(ch-'0'),bit*=0.1;ch=getchar();if(ch=='.'){flag=true,ch=getchar();}}return x * f;}
inline LL ksm(LL a,LL b){LL res=1;while(b){if(b&1)	res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
inline LL ksc(LL a,LL b){LL res=0;while(b){if(b&1)	res=res+a>=MOD?res+a-MOD:res+a;a=a+a>=MOD?a+a-MOD:a+a;b>>=1;}return res;}
inline double fixed(const double& x){if(fabs(x)<=eps)	return 0;return x;}
const int N=200+7;
int cnt[N];
int main(){
	#ifndef ONLINE_JUDGE
    	int startTime = clock();
		FRD;
	#endif
	FIO;
	int T;
	cin>>T;
	start:;
	while(T--){
		int n;cin>>n;
		string s,t;
		cin>>s>>t;
		ms(cnt);
		for(int i=0;i<n;i++)	cnt[s[i]]++,cnt[t[i]]++;
		for(char i='a';i<='z';i++){
			if(cnt[i]%2==1){
				//cout<<i<<' '<<cnt[i]<<endl; 
				cout<<"No\n";
				goto start;
			}
		}
		vector<pii> ans;
		while(s!=t){
			for(int i=0;i<n;i++){
				if(s[i]!=t[i]){
					for(int j=i+1;j<n;j++){
						if(s[j]!=t[j]){
							if(s[j]==t[i]){
								ans.pb(pii(i,i));
								swap(s[i],t[i]);
								ans.pb(pii(j,i));
								swap(s[j],t[i]);
								break;
							}
							else if(t[j]==t[i]){
								ans.pb(pii(i,j));
								swap(s[i],t[j]);
								break;
							}
						}
					}
					break;
				}
			}
		}
		cout<<"Yes\n";
		cout<<ans.size()<<endl;
		for(auto x:ans){
			cout<<x.fi+1<<' '<<x.se+1<<endl;
		}
	}
	#ifndef ONLINE_JUDGE
    	printf("Time = %dms\n", clock() - startTime);
	#endif
	return 0;
}



