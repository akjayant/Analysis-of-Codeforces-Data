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

		string s, t;
		cin >> s >> t;

		int s1[30]=  {0}, t1[30] = {0};

		tik(i,0,n) {
			s1[s[i]-'a']++;
			t1[t[i]-'a']++;
		}

		bool b = true;

		tik(i,0,30) {
			if((s1[i] + t1[i])%2 == 1) {
				//error(i);
				b = false;
			}
		}

		if(!b) {
			cout << "No\n";
			continue;
		}

		vpi sol;

		tik(i,0,n) {
			if(s[i] == t[i])
				continue;
			bool b = false;
			tik(j,i+1,n) {
				if(s[i] == s[j]) {
					b = true;
					sol.pb({j,i});
					swap(s[j],t[i]);
					break;
				}
			}

			if(b)
				continue;

			tik(j,i+1,n) {
				if(s[i] == t[j]) {
					sol.pb({i+1,j});
					sol.pb({i+1,i});
					swap(s[i+1],t[j]);
					swap(s[i+1],t[i]);
					break;
				}
			}
		}

		if(sz(sol) > 2*n)
			cout << "No\n";
		else {
			cout << "Yes\n" << sz(sol) << "\n";
			for(auto p : sol)
				cout << p.fs + 1<< " " << p.sd + 1<< "\n";
		}
	}
}