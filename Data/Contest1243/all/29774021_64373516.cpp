#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n);
		reverse(a,a+n);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= (i+1)){
				ans = i+1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

