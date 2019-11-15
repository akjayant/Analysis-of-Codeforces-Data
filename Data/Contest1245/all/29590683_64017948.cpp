#include<bits/stdc++.h>
#define pb(x)push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << y << endl
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define N 101

using namespace std;

int main(){	
	ios::sync_with_stdio(false);
	
	int tc = 0;
	cin >> tc;
	
	while(tc--){
		
		string cad;
		int n, a, b, c;
		cin >> n;
		
		cin >> a >> b >> c;
		cin >> cad;
		
		int r = 0, p = 0, s = 0;
		for(int i = 0; i < n; i++){
			
			if(cad[i] == 'R')r++;
			if(cad[i] == 'P')p++;
			if(cad[i] == 'S')s++;
		}
		
		int min_a, min_b, min_c;
		int wins = (min_a = min(a, s));
		wins += (min_b = min(b, r));
		wins += (min_c = min(c, p));
		
		
		if(wins >= (n + 1)/2){
			
			cout << "YES" << endl;
			string ans = string(n, '0');
			int ca = 0, cb = 0, cc = 0;
			for(int i = 0; i < n; i++){
				
				if(cad[i] == 'S' && ca < min_a)ans[i] = 'R', ca++;
				if(cad[i] == 'R' && cb < min_b)ans[i] = 'P', cb++;
				if(cad[i] == 'P' && cc < min_c)ans[i] = 'S', cc++;
			}
			
			for(int i = 0; i < n; i++)if(ans[i] == '0' && ca < a)ans[i] = 'R', ca++;
			for(int i = 0; i < n; i++)if(ans[i] == '0' && cb < b)ans[i] = 'P', cb++;
			for(int i = 0; i < n; i++)if(ans[i] == '0' && cc < c)ans[i] = 'S', cc++;
				

			cout << ans << endl;
		}
		else cout << "NO" << endl;

		
	}
	

}
