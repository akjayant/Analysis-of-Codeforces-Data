#include <bits/stdc++.h>

#define endl '\n'
#define ll long long int
#define let(x, a) __typeof(a) x(a)
#define all(a) (a).begin(), (a).end()
#define present(c, x) ((c).find(x) != (c).end())
#define tr(v, it) for (let(it, v.begin()); it != v.end(); it++)
#define rtr(v, it) for (let(it, v.rbegin()); it != v.rend(); it++)

#define trace1(x)					cerr << #x << ": " << x << endl;
#define trace2(x, y)				cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)				cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)		cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)	cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

using namespace std;

vector<vector<ll>> V,C;
vector<ll> CC(1e5,0);
vector<ll> D;

void dfs(ll u, ll prev) {
	D.push_back(u);
	for(auto n:V[u]) {
		if(prev!=n) {
			dfs(n,u);
		}
	}
}

ll hoo(ll c1, ll c2) {
	vector<ll> c;
	c.push_back(c1);
	c.push_back(c2);
	if(c1==0) {
		if(c2==1) c.push_back(2);
		else c.push_back(1);
	} else if(c1==1) {
		if(c2==0) c.push_back(2);
		else c.push_back(0);
	} else {
		if(c2==1) c.push_back(0);
		else c.push_back(1);
	}
	ll x=C[c1][D[0]]+C[c2][D[1]],cur=2;
	for(int i=2;i<D.size();i++) {
		x+=C[c[cur]][D[i]];
		cur++;
		cur%=3;
	}
	return x;
}

void foo(ll c1, ll c2) {
	CC[D[0]]=c1+1; CC[D[1]]=c2+1;
	vector<ll> c;
	c.push_back(c1);
	c.push_back(c2);
	if(c1==0) {
		if(c2==1) c.push_back(2);
		else c.push_back(1);
	} else if(c1==1) {
		if(c2==0) c.push_back(2);
		else c.push_back(0);
	} else {
		if(c2==1) c.push_back(0);
		else c.push_back(1);
	}
	ll cur=2;
	for(int i=2;i<D.size();i++) {
		CC[D[i]]=c[cur]+1;
		cur++;
		cur%=3;
	}
}

int main() {
	ios::sync_with_stdio(false);
	ll n,a,b;
	cin>>n;
	C.assign(3,vector<ll>(n,0));
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin>>C[i][j];
		}
	}
	V.assign(n,vector<ll>());
	int flag=0;
	for(int i=0;i<n-1;i++) {
		cin>>a>>b;
		a--; b--;
		V[a].push_back(b);
		V[b].push_back(a);
		if(V[a].size()>2 || V[b].size()>2) {
			flag=1;
		}
	}
	if(flag) {
		cout<<"-1"<<endl;
		return 0;
	}
	int leaf;
	for(int i=0;i<n;i++) {
		if(V[i].size()==1) {
			leaf=i;
			break;
		}
	}
	dfs(leaf,-1);
	vector<vector<ll>> c(3,vector<ll>(3,0));
	ll cc=1e18;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(i==j) continue;
			c[i][j]=hoo(i,j);
			if(c[i][j]<cc) {
				cc=c[i][j];
				foo(i,j);
			}
		}
	}
	cout<<cc<<endl;
	for(int i=0;i<n;i++) {
		cout<<CC[i]<<" ";
	}
	cout<<endl;
	return 0;
}