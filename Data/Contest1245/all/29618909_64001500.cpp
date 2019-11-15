#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n,a,b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		
		string ans(n,'?');
		for (int i=0;i<n;++i) {
			if (s[i]=='R' && b>0) {--b; ans[i]='P';}
			if (s[i]=='P' && c>0) {--c; ans[i]='S';}
			if (s[i]=='S' && a>0) {--a; ans[i]='R';}
		}
		if ( 2*(a+b+c)>n ) cout << "NO" << endl;
		else {
			string rem=string(a,'R')+string(b,'P')+string(c,'S');
			int j=0;
			for (int i=0;i<n;++i) if (ans[i]=='?') ans[i]=rem[j++];
			cout << "YES\n" << ans << endl;
		}



	}
}