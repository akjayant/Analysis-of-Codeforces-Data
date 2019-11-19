#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
const int N = 2000*2000+5000;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int n,tot,fa[N],light[N];
ll X[N],Y[N],c[N],k[N];
vector<int> v1;
vector<pair<int,int> > v2;
struct Node{
	int a,b;
	ll w;
	bool operator < (Node xx) const {
		return w < xx.w;
	}
}e[N];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) fa[i] = i, light[i] = 0;
	rep(i,1,n) scanf("%lld%lld",&X[i],&Y[i]);
	rep(i,1,n) scanf("%lld",&c[i]);
	rep(i,1,n) scanf("%lld",&k[i]);
	rep(i,1,n) e[++tot] = {i,i,c[i]};
	rep(i,1,n)
		rep(j,i+1,n){
			ll w = abs(X[i]-X[j])+abs(Y[i]-Y[j]);
			w *= (k[i]+k[j]);
			e[++tot] = {i,j,w};
		}
	sort(e+1,e+1+tot);
	ll ans = 0;
	rep(i,1,tot){
		int x = e[i].a, y = e[i].b;
		if(x == y){
			int hp = find(x);
			if(!light[hp]){
				light[hp] = 1;
				v1.push_back(x);
				ans += e[i].w;
			}
		}
		else{
			int fx = find(x), fy = find(y);
			if(fx != fy){
				if(!light[fx] || !light[fy]){
					fa[fx] = fy;
					if(light[fx] || light[fy]){
						fx = find(fx);
						light[fx] = 1;
					}
					v2.push_back(make_pair(x,y));
					ans += e[i].w;
				}
			}
		}
	}
	printf("%lld\n",ans);
	int s1 = v1.size(), s2 = v2.size();
	printf("%d\n",s1);
	rep(i,0,s1-1) printf("%d%c",v1[i]," \n"[i==s1-1]);
	printf("%d\n",s2);
	rep(i,0,s2-1) printf("%d %d\n",v2[i].first,v2[i].second);
	return 0;
}