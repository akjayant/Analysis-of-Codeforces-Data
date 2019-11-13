#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b, c, res = 0;
		cin >> a >> b >> c;
		for(int i = 0; i <= a; i++){
			for(int j = 0; j <= b; j++){
				for(int k = 0; k <= c; k++){
					if(2 * i + j <= b && 2 * j <= c)
						res = max(res, i + i * 2 + j + j * 2);
				}
			}
		}
		cout << res << "\n";
	}
}