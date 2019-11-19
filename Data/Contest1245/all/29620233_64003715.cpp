#include<bits/stdc++.h>
#define DEBUG cerr << "Call out: " << __func__ << "\t" << "Line: " << __LINE__ << "\t :"
using namespace std;
int n;
#define int long long
struct edge{
	int u, v;
	int w;
	const bool operator < (edge x)const{
		return w > x.w;
	}
}a[4010000];
int x[2010];
int y[2010];
int c[2010];
int k[2010];
int f[2010];
int gf(int x){
	if (f[x] == x) return x;
	return f[x] = gf(f[x]);
}
priority_queue <edge> p;
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
	}
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<=n;i++) cin >> k[i];
	for (int i=1;i<=n;i++)
	{
//		cout << c[i] << endl;
		p.push((edge){i,0,c[i]});
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
//			cout << (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])) << '|' << endl;
			p.push((edge){i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});
		}
	}
	stringstream ss1, ss2; int tp1 = 0, tp2 = 0;

	long long ans = 0;
	while (!p.empty()){
		auto top = p.top(); p.pop();
//		cout << top.w << endl;
		if (gf(top.u) != gf(top.v)){
			if (top.v == 0)
				ss1 << top.u << ' ', tp1 ++;
			else
				ss2 << top.u << ' ' << top.v << endl, tp2 ++;
			ans += top.w;
			f[gf(top.u)] = gf(top.v);
		}
	}
	cout << ans << endl;
	cout << tp1 << endl;
	cout << ss1.str() << endl;
	cout << tp2 << endl;
	cout << ss2.str();
}
