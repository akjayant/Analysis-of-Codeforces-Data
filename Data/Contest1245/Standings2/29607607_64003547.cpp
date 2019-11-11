#include<bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define ll long long
using namespace std;
 
const int INF = 1e9;
const long long LINF = 1e18;
 
void test(){
 
}
 
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a,b,c; cin >> a >> b >> c;
		string s; cin >> s;
		int wins = 0;
		string res = s;
		for(int i = 0; i < n; i++) res[i] = '0';
		for(int i = 0; i < n; i++){
			if(s[i] == 'R' && b > 0){
				b--;
				res[i] = 'P';
				wins++;
			} else if(s[i] == 'P' && c > 0){
				c--;
				res[i] = 'S';
				wins++;
			} else if(s[i] == 'S' && a > 0){
				a--;
				res[i] = 'R';
				wins++;
			}
		}
		for(int i = 0; i < n; i++){
			if(res[i] == '0'){
				if(a > 0){
					res[i] = 'R';
					a--;
				} else if(b > 0){
					res[i] = 'P';
					b--;
				} else if(c > 0){
					res[i] = 'S';
					c--;
				}
			}
		}
		if(n%2 == 1) n++;
		int ile = n/2;
		if(wins >= ile){
			cout << "YES\n";
			cout << res << "\n";
		} else {
			cout << "NO\n";
		}
	}
}