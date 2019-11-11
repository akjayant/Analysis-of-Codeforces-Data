#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a,b,c; cin>>a>>b>>c;
		string ss; cin>>ss;
		int r=0,p=0,s=0;
		for (char x: ss) {
			if (x=='R') r++;
			else if (x=='P') p++;
			else if (x=='S') s++;
		}
		int beat = min(r,b)+min(p,c)+min(s,a);
		if (beat>=(n+1)/2) {
			cout<<"YES"<<endl;
			vector<char> T; T.assign(n,'@');
			for (int i=0; i<n; ++i) {
				char x = ss[i];
				if (x=='R' && b>0) {T[i]='P'; b--;}
				else if (x=='P' && c>0) {T[i]='S'; c--;}
				else if (x=='S' && a>0) {T[i]='R'; a--;}
			}
			for (int i=0; i<n; ++i)
				if (T[i]=='@') {
					if (a>0) {T[i]='R'; a--;}
					else if (b>0) {T[i]='P'; b--;}
					else {T[i]='S'; c--;}
				}
			for (int i=0; i<n; ++i) cout<<T[i]; cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}