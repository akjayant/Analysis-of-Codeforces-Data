#include <bits/stdc++.h>
using namespace std;
#define asp " " 
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){

		int n;
		int a,b,c;

		cin >> n;
		cin >> a >> b >> c;

		string s;
		cin >> s;

		string ans;
		int win = 0;

		for(int i=0;i<n;i++){
			ans += 'X';
		}

		for(int i=0;i<n;i++){
			if(a == 0) break;
			if(s[i] == 'S'){
				ans[i] = 'R';
				a--;
				win++;
			}
		}
		for(int i=0;i<n;i++){
			if(b == 0) break;
			if(s[i] == 'R'){
				ans[i] = 'P';
				b--;
				win++;
			}
		}

		for(int i=0;i<n;i++){
			if(c == 0) break;
			if(s[i] == 'P'){
				ans[i] = 'S';
				c--;
				win++;
			}
		}

		for(int i=0;i<n;i++){
			if(ans[i] == 'X'){
				if(a > 0){
					ans[i] = 'R';
					a--;
				}
				else if(b > 0){
					ans[i] = 'P';
					b--;
				}
				else{
					ans[i] = 'S';
					c--;
				}
			}
		}

		int nec = ceil((double)n/two);

		if(win >= nec){
			cout << "YES" << endl;
			cout << ans << endl;
		}
		else cout << "NO" << endl; 
	}
}