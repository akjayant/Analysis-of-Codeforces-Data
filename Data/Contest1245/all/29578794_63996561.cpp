#include <bits/stdc++.h>
  
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   
typedef long long ll;
typedef long double ld;
    
using namespace std;

signed main(){
    ios;
    int t, a, b;
    cin >> t;
    while(t--){
    	cin >> a >> b;
    	if (__gcd(a, b) == 1){
    		cout << "Finite" << endl;
    	}else{
    		cout << "Infinite" << endl;
    	}
    }
}