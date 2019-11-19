#include<bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define int long long int
#define S second
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const int MOD = 998244353;
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp>  
//using namespace __gnu_pbds; 
//stringstream ss; string temp; ss<<str(original string) ss>>temp;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	s = ' '+s;

	vector<int> ans{n};

	for(int i = 1; i <= n; ++i) {
		if(s[i] == '1') {
			ans.push_back(2*i);
			ans.push_back(2*(n-i+1));
			ans.push_back(n+1);
		}
	}
	cout << *max_element(ans.begin(), ans.end()) << endl;
}

int32_t main()
{	
	boost
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--) {
    	solve();
    }
  	
	return 0;
} 
