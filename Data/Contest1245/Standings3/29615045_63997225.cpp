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

ll Euclid(ll A, ll B){
    if(A<B) swap(A, B);
    ll C = B;
    while(C != 0){
        C = A%B;
        A = B;
        B = C;
    }
    return A;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while(t--){
    	ll A, B;
    	cin >> A >> B;
    	ll G = Euclid(A, B);
    	cout << (G==1 ? "Finite" : "Infinite") << endl;
    }
    return 0;
}