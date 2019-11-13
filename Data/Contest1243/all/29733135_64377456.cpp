#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

int main() {

	int t;
	cin >> t;

	while(t--) {

		int n;

		cin >> n;

		int a[n];

		tik(i,0,n)
			cin >> a[i];

		sort(a,a + n);

		int lo = 0, hi = n;

		while(lo < hi) {
			int mid = (lo + hi + 1)/2;  //The solution is less than mid
			int idx = lower_bound(a,a+n,mid) - a;
			if(n-idx < mid)
				hi = mid - 1;
			else
				lo = mid;
		} 

		cout << lo << endl;
	}
}