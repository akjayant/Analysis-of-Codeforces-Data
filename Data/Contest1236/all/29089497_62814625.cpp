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

const ll N_MAX = 101010;
struct RAQSB{
	ll N;
	ll sN;
	ll data[N_MAX];
	ll bucket[N_MAX];

	RAQSB(ll n){
		sN = (ll)sqrt(n) + 1;
		N = sN * sN;
		REP(i, N_MAX){
			data[i] = 0;
			bucket[i] = 0;
		}
	}

	void add(ll s, ll t, ll x){
		// add x to range [s, t)
		ll ss = s/sN;
		ll tt = t/sN;
		if(ss==tt){
			for(int i=s;i<t;i++){
				data[i] += x;
			}
		}else{
			for(int i=s;i<(ss+1)*sN;i++){
				data[i] += x;
			}
			for(int i=tt*sN;i<t;i++){
				data[i] += x;
			}
			for(int i=ss+1;i<tt;i++){
				bucket[i] += x;
			}
		}
	}

	ll get_val(ll i){
		return data[i] + bucket[i/sN];
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    REP(i, m) cin >> a[i];
    REP(i, m) a[i]--;
    REP(i, m) b[i] = n-1-a[i];

    if(n==1){
    	cout << 0 << endl;
    	return 0;
    }

    //cout << a << endl;
    //cout << b << endl;

    RAQSB r1(n);
    REP(i, n) r1.add(i, i+1, i);
    REP(i, m){
    	ll l = -1;
    	ll u = n;
    	while(u-l>1){
    		ll md = (l+u)/2;
    		if(r1.get_val(md)>=a[i]-1) u = md;
    		else l = md;
    	}
    	ll hidari = u;

    	l = -1;
    	u = n;
    	while(u-l>1){
    		ll md = (l+u)/2;
    		if(r1.get_val(md)>=a[i]) u = md;
    		else l = md;
    	}
    	ll migi = u;

    	r1.add(0, hidari, 1);
    	r1.add(migi, n, 1);
    	//dump(hidari)
    	//dump(migi)

    	//REP(i, n) cout << r1.get_val(i) << " ";
    	//cout << endl;  
    }  
    r1.add(0, n, 1);


    RAQSB r2(n);
    REP(i, n) r2.add(i, i+1, i);
    REP(i, m){
    	ll l = -1;
    	ll u = n;
    	while(u-l>1){
    		ll md = (l+u)/2;
    		if(r2.get_val(md)>=b[i]-1) u = md;
    		else l = md;
    	}
    	ll hidari = u;

    	l = -1;
    	u = n;
    	while(u-l>1){
    		ll md = (l+u)/2;
    		if(r2.get_val(md)>=b[i]) u = md;
    		else l = md;
    	}
    	ll migi = u;

    	r2.add(0, hidari, 1);
    	r2.add(migi, n, 1);
    	//dump(hidari)
    	//dump(migi)

    	//REP(i, n) cout << r2.get_val(i) << " ";
    	//cout << endl;  
    }  
    r2.add(0, n, 1);

    /*
    REP(i, n) cout << r1.get_val(i) << " ";
    cout << endl;  
    
    REP(i, n) cout << r2.get_val(i) << " ";
    cout << endl; 
    */
    

    
    ll res = n * n;
    REP(i, n){
    	ll p = r1.get_val(i);
    	if(p<n-1) res -= (n-1-p);
    } 
    REP(i, n){
    	ll p = r2.get_val(i);
    	if(p<n-1) res -= (n-1-p);
    }
    

    /*
    ll res = 0;
    res += n;
    REP(i, n){
    	ll p = r1.get_val(i);
    	p = min(n-1, p);
    	res += (p - i);
    }
    REP(i, n){
    	ll p = r2.get_val(i);
    	p = min(n-1, p);
    	res += (p - i);
    }
    */

    cout << res << endl;

    return 0;
}