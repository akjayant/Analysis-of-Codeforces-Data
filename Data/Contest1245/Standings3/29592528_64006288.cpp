#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll R, P, S;
		cin >> R >> P >> S;
		string s;
		cin >> s;
		int pt = 0;
		int sz = s.size();
		string out;
		for(auto i: s){
			out += '#';
		}
		ll res = 0;
		while(pt != sz && R){
			if(s[pt] == 'S'){
				R--;
				s[pt] = '#';
				out[pt] = 'R';
				res++;
			}
			pt++;
		}
		pt = 0;
		while(pt != sz && P){
			if(s[pt] == 'R'){
				P--;
				s[pt] = '#';
				out[pt] = 'P';
				res++;
			}
			pt++;
		}
		pt = 0;
		while(pt != sz && S){
			if(s[pt] == 'P'){
				S--;
				s[pt] = '#';
				out[pt] = 'S';
				res++;
			}
			pt++;
		}
		pt = 0;
		while(R && pt != sz){
			if(s[pt] != '#'){
				out[pt] = 'R';
				s[pt] = '#';
				R--;
			}
			pt++;
		}
		pt = 0;
		while(P && pt != sz){
			if(s[pt] != '#'){
				out[pt] = 'P';
				s[pt] = '#';
				P--;
			}
			pt++;
		}
		pt = 0;
		while(S && pt != sz){
			if(s[pt] != '#'){
				out[pt] = 'S';
				s[pt] = '#';
				S--;
			}
			pt++;
		}
		if(res * 2 >= sz){
			cout << "YES\n";
			cout << out << "\n";
		}
		else cout << "NO\n";
	}
	
	return 0;
}
