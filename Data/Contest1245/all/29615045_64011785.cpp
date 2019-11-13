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
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while(t--){
    	ll n, a, b, c;
    	cin >> n >> a >> b >> c;
    	string st;
    	cin >> st;
    	vector<char> res(n, 'N');
    	REP(i, n){
    		if(st[i]=='P'){
    			if(c>0){
    				res[i] = 'S';
    				c--;
    			}
    		}
    		if(st[i]=='R'){
    			if(b>0){
    				res[i] = 'P';
    				b--;
    			}
    		}
    		if(st[i]=='S'){
    			if(a>0){
    				res[i] = 'R';
    				a--;
    			}
    		}
    	}
    	if(n-(a+b+c)<(n+1)/2){
    		cout << "NO" << endl;
    		continue;
    	}
    	queue<char> qu;
    	REP(i, a) qu.push('R');
    	REP(i, b) qu.push('P');
    	REP(i, c) qu.push('S');
    	REP(i, n){
    		if(res[i]=='N'){
    			res[i] = qu.front();
    			qu.pop();
    		}
    	}
    	cout << "YES" << endl;
    	REP(i, n) cout << res[i];
    	cout << endl;
    }
    return 0;
}