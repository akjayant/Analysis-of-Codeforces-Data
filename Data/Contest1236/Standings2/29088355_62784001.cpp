#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 5*100000+1;
const int MOD = 1000000007;
const ll MAX = 10000000000;
const int oo = 1e9;

int t;

int main(){
	cin >> t;
	while(t--){
		int a , b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for(int i = 0 ; i <= a ; ++i){
			for(int j = 0 ; j <= b ; ++j){
				int f = i;
				int s = i*2+j;
				int th = 2*j;
				if(f <= a && s <= b && th <= c)
					ans = max(ans,f+s+th);
			}
		}
		cout << ans << endl;
	}
	return 0;
}