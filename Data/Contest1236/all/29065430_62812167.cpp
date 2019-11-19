#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 100007 //10e6 +7


vector<int>vm[N];
vector<int>vn[N];

map<pii, bool>has;

int n, m, k;

bool sol(int a, int b, int c, int d){
	//cout << a << " " << b << " " << c << " " << d << endl;
	if(a>c or d>b)return true;
	pii p = {-1, -1};

	p = {-1, -1};
	for(int i=0; i<vn[a].size(); i++){
		if(vn[a][i]>=d and vn[a][i]<=b){
			p = {a, vn[a][i]};
			break;
		}
	}

	//cout << "a is " << a << endl;
	if(p.fi == a){
		//cout << "straight" << endl;
		//cout << "pair is " << p.fi << " " << p.se << endl;

		for(int i=a; i<=c; i++){
			for(int j=p.se; j<=b; j++){
				//cout << "check " << i << " " << j << endl;
				if(has[mk(i, j)]==false)return false;
			}
		}
		b = p.se - 1;
	}

	p = {-1, -1};
	for(int i=0; i<vm[b].size(); i++){
		if(vm[b][i]>a and vm[b][i]<=c){
			p = {b, vm[b][i]};
			break;
		}
	}

	//cout << "b is " << b << endl;
	if(p.fi == b){
		//cout << "down" << endl;
		//cout << "pair is " << p.fi << " " << p.se << endl;
		for(int i=p.se; i<=c; i++){
			for(int j=d; j<=b; j++){
				//cout << "check " << i << " " << j << endl;
				if(has[mk(i, j)]==false)return false;
			}
		}
		c = p.se - 1;
	}

	p = {-1, -1};
	for(int i=vn[c].size()-1; i>=0; i--){
		//cout << "found " << c << " " << vn[c][i] << endl;
		if(vn[c][i]>=d and vn[c][i]<b){
			p = {c, vn[c][i]};
			break;
		}
	}

	//cout << "c is " << c << endl;
	if(p.fi == c){
		//cout << "left" << endl;
		//cout << "pair is " << p.fi << " " << p.se << endl;
		for(int i=a+1; i<=c; i++){
			for(int j=d; j<=p.se; j++){
				//cout << "check " << i << " " << j << endl;
				if(has[mk(i, j)]==false)return false;
			}
		}
		d = p.se + 1;
	}

	p = {-1, -1};
	for(int i=vm[d].size()-1; i>=0; i--){
		if(vm[d][i]>a and vm[d][i]<c){
			p = {d, vm[d][i]};
			break;
		}
	}

	//cout << "d is " << d << endl;
	if(p.fi == d){
		//cout << "up" << endl;
		//cout << "pair is " << p.fi << " " << p.se << endl;
		for(int i=a+1; i<=p.se; i++){
			for(int j=d; j<b; j++){
				//cout << "check " << i << " " << j << endl;
				if(has[mk(i, j)]==false)return false;
			}
		}
		a = p.se + 1;
	}else a++;

	return sol(a, b-1, c-1, d+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		int a, b;
		cin >> a >> b;
		has[mk(a, b)]=1;
		vm[b].pb(a);
		vn[a].pb(b);
	}
	if(k==0){
		cout << "Yes" << endl;
		return 0;
	}
	for(int i=1; i<N; i++){
		sort(vm[i].begin(), vm[i].end());
		sort(vn[i].begin(), vn[i].end());
	}
	
	if(sol(1, m, n, 1))cout << "Yes" << endl;
	else cout << "No" << endl;
}