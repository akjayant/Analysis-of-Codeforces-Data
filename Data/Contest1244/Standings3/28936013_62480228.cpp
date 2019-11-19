#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
#define int long long
 
using namespace std;
 
const int N = (2e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);
 
main()
{	
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	int l = 0, r = 1e9;
	while(r - l > 1){
		int mid = (r + l) >> 1;
		int x = (p - mid * d) / w; 
		if(x + mid <= n && x >= 0){
			l = mid;
		}
		else{
		  r = mid;
		}
	}
	int x, y, z;
	for(int i = max(0ll, l - 100000); i <= r + 100000; i++){
		if((p - i * d) % w == 0){
			x = (p - i * d) / w;
			y = i;
			z = n - (p - i * d) / w - i;
			if(x >= 0 && y >= 0 && z >= 0){	
				cout << x << " " << y << " " << z;
				return 0;
			}
		}
	}
	cout << -1;
	
}
