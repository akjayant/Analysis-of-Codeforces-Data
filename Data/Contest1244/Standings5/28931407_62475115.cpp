#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long LL;

int n, a, b;
char s[maxn];

int main(){
	int T; cin >> T;
	while(T--){
		cin >> n;
		cin >> (s + 1);
		bool ok = 0;
		for(int i = 1; i <= n; ++i){
			if(s[i] == '1'){
				b = n - i + 1;
				ok = 1;
				break;
			}
		}
		for(int i = n; i >= 1; --i){
			if(s[i] == '1'){
				a = i;
				ok = 1;
				break;
			}
		}
		if(ok){
			cout << max(2 * a, 2 * b) << endl;
		}else{
			cout << n << endl;
		}
	}
}