#include <bits/stdc++.h>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)

int T;
LL N,p,w,d;
vector <int> _listModulo;

void process(){
	FOR(i,0,d - 1){
		LL w2 = ((w % d) * (LL)(i)) % d;
		LL p2 = p % d;
		if(w2 == p2) _listModulo.push_back(i);
	}
	//
	double dmax = (double)p/double(w);
	if(dmax < 0){
		cout << -1;
		return ;
	}
	double dmin = ((double)p - (double)N * (double)d)/((double)w - double(d));
	dmin = max(dmin,(double)0);
	LL vmax = (LL)trunc(dmax);
	LL vmin = (LL)trunc(dmin);
	while(vmin < dmin) ++vmin;
//	cout << vmax << " " << vmin << endl;
	REP(i,0,_listModulo.size()){
		LL z = _listModulo[i];
		LL x = dmin/d;
		x = x * d + z;
		while(x < dmin) x += d;
		while(x - d >= dmin) x -= d;
		if(x <= dmax){
			LL y = trunc(((double)p - (double)x * (double)w)/(double)d);
			cout << x << " " << y << " " << N - x - y;
			//cout << endl << " " << x * w + y * d;
			return ;
		}
	}
	cout << -1;
}
int main(){
	cin >> N >> p >> w >> d;
	process();
	return 0;
}