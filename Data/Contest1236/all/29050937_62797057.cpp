// Thu Oct 17 19:29:16 IST 2019
#include<bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
    #include "/home/raghukul/Competitive/templates/debug.h"
#else
    #define debug(args...)
    #define DBG(x...)
#endif

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.precision(17);
    int n;
    cin >> n;
    vector<int> t[n];
    bool cn = true;
    for(int i = 1;i <= n*n;i+=n) {
    	if(cn)
    		for(int j = 0;j < n;j++)
    			t[j].push_back(i+j);
    	else
    		for(int j = 0;j < n;j++)
    			t[j].push_back(i+n-j-1);
    	cn = !cn;
    }
    for(int i = 0;i < n;i++) {
    	for(int j = 0;j < n;j++)
    		cout << t[i][j] << " ";
    	cout << endl;
    }
    return 0;
}
