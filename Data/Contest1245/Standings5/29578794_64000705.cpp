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
    int t, a, b, c, n;
    string bob;
    cin >> t;
    while(t--){
    	cin >> n >>  a >> b >> c;
    	int old_a = a;
    	int old_b = b;
    	int old_c = c;
     	cin >> bob;
    	for (int i = 0; i < bob.size(); i++){
    		if (bob[i] == 'R'){
    			b--;
    			b = max(b, 0);
    		}
    		if (bob[i] == 'P'){
    			c--;
    			c = max(c, 0);
    		}
    		if (bob[i] == 'S'){
    			a--;
    			a = max(a, 0);
    		}
    	}
    	int cnt = 0;
    	string ans = "";
    	for (int i = 0; i < bob.size(); i++){
    		if (bob[i] == 'R' && old_b){
    			old_b--;
    			cnt++;
    			ans.pb('P');
    		}else if (bob[i] == 'P' && old_c){
    			old_c--;
    			cnt++;
    			ans.pb('S');
    		}else if (bob[i] == 'S' && old_a){
    			old_a--;
    			cnt++;
    			ans.pb('R');
    		}else{
    			if (b){
    				ans.pb('P');
    				b--;
    			}else if (a){
    				ans.pb('R');
    				a--;
    			}else if (c){
    				ans.pb('S');
    				c--;
    			}
    		}
    	}
    	if (cnt >= ((n + 1) / 2)){
    		cout << "YES" << endl;
    		cout << ans << endl;
    	}else{
    		cout << "NO" << endl;
    	}
    }
}