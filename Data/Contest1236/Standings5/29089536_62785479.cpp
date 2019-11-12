#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define allin(x, V) for(auto x : V)

#define endl '\n'
#define debug(vrb) {cerr << #vrb << ": " << vrb << endl;}
#define DEBUG(cnt) {cerr << #cnt << ": "; for(auto vrb : cnt) cerr << vrb << ", "; cerr << endl;}

typedef long long ll;
typedef long double ld;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout.setf(ios::fixed);
    //cout.precision(4);

    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	int sol = 0;
    	if (2*b <= c) {
    		sol += 3*b;
    		c -= 2*b;
    		b = 0;
    	}
    	else {
    		sol += 3*(c - c%2)/2;
    		b -= (c - c%2)/2;
    		c = c%2;
    	}

    	if (2*a <= b) {
    		sol += 3*a;
    		b -= 2*a;
    		a = 0;
    	}
    	else {
    		sol += 3*(b - b%2)/2;
    		a -= (b - b%2)/2;
    		b = b%2;
    	}

    	cout << sol << endl;
    		
    }
}
