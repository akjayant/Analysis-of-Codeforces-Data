#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define left  (2*idx)+1
#define right (2*idx)+2
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
 

const ll MOD = (ll)(1e9 + 7); 
const ll N = 0;

int main()
{
	FIO;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		int r, s, p;
		char ch;
		r = s = p = 0;
		string str;
		cin >> str;
		string ans = str;
		for(int i=1; i<=n; i++) {
			ans[i-1] = '.';
			ch = str[i-1];
			if(ch == 'R'){
				r+=1;
			} else if(ch == 'S') {
				s+=1;
			} else {
				p+=1;
			}
		}
		int m = min(b, r) + min(a, s) + min(c, p);
		if(m >= (n+1)/2) {
			cout << "YES\n";
			for(int i=0; i<n; i++) {
				if(a == 0) break;
				if(str[i] == 'S'){ ans[i] = 'R'; a--;}
			}

			for(int i=0; i<n; i++) {
				if(b == 0) break;
				if(str[i] == 'R'){ans[i] = 'P'; b--;}
			}

			for(int i=0; i<n; i++) {
				if(c == 0) break;
				if(str[i] == 'P') {ans[i] = 'S'; c--;}
			}

			for(int i=0; i<n; i++) {
				if(ans[i]!='.') continue;
				if(a!=0) {ans[i] = 'R'; a--;}
				else if(b!=0) {ans[i] = 'P'; b--;}
				else {ans[i] = 'S'; c--;}
				
			}
			cout << ans << "\n";

		} else {
			cout << "NO\n";
		}
	}
	return 0;	
}	