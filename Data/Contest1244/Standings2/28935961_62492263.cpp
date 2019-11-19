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

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    map<ll, ll> mp;
    REP(i, n) mp[a[i]]++;

    deque<pll> dq;
    for(auto x: mp){
    	dq.push_back({x.first, x.second});
    }

    while(1){
    	/*
    	cout << "----" << endl;
    	for(auto x: dq){
    		cout << x.first << " " << x.second << endl; 
    	}
    	dump(k)
    	*/
    	if(k==0) break;
    	if(dq.size()==1) break;

    	pll mae = dq.front();
    	pll ato = dq.back();
    	if(mae.second <= ato.second){
    		dq.pop_front();
    		ll val = mae.first;
    		ll kazu = mae.second;

    		pll tsugi = dq.front();
    		ll val_tsugi = tsugi.first;
    		ll kazu_tsugi = tsugi.second;

    		ll opera = min((val_tsugi-val)*kazu, k);
    		ll susumu = opera/kazu;
    		k -= opera;

    		if(susumu == val_tsugi-val){
    			dq.pop_front();
    			dq.push_front({val_tsugi, kazu+kazu_tsugi});
    		}else{
    			dq.push_front({val+susumu, kazu});
    		}
    	}else{
    		dq.pop_back();
    		ll val = ato.first;
    		ll kazu = ato.second;

    		pll tsugi = dq.back();
    		ll val_tsugi = tsugi.first;
    		ll kazu_tsugi = tsugi.second;

    		ll opera = min((val-val_tsugi)*kazu, k);
    		ll susumu = opera/kazu;
    		k -= opera;

    		if(susumu == val-val_tsugi){
    			dq.pop_back();
    			dq.push_back({val_tsugi, kazu+kazu_tsugi});
    		}else{
    			dq.push_back({val-susumu, kazu});
    		}
    	}
    }

    ll res = dq.back().first - dq.front().first;
    cout << res << endl;
    return 0;
}