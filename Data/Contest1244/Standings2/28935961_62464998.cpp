#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while(t--){
    	ll a, b, c, d, k;
    	cin >> a >> b >> c >> d >> k;

    	ll p = -1, q = -1;
    	for(int x=0;x<=k;x++){
    		int y = k - x;
    		if(c*x>=a && d*y>=b){
    			p = x, q = y;
    		}
    	}
    	if(p>=0 && q>=0){
    		cout << p << " " << q << endl;
    	}else{
    		cout << -1 << endl;
    	}
    }
    return 0;
}