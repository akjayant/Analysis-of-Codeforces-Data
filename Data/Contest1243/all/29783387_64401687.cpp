    #include <bits/stdc++.h>
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("fast-math")
    #pragma GCC optimize("no-stack-protector")
    #pragma GCC target("sse,sse2,sse3,ssse3,mmx,abm,popcnt")
    using namespace std;
    #define fs first
    #define sc second
    typedef long long ll;
    typedef long double ld;
    mt19937 rng(time(NULL));
    const int maxn = 1e3 + 100;
    const int mod = 1e9 + 7;
    const int inf = 1e9;
    const ld eps = 1e-9;
     
    int main() {	
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
     
    	int k;
    	cin>>k;
    	while (k--) {
    		int n;
    		string s,t;
    		cin>>n>>s>>t;
    		vector<int> cnt(26,0), cnt2(26,0);
    		for (int i = 0;i<n;++i) {
    			cnt[s[i]-'a']++;
    			cnt2[t[i]-'a']++;
    		}
    		// bool f = 1;
    		// for (int i = 0;i<26;++i) if (cnt[i] != cnt2[i]) f = 0;
    		// 	if (!f) {
    		// 		cout<<"No\n";
    		// 		continue;
    		// 	}
    		vector<int> p;
    		for (int i = 0;i<n;++i) {
    			if (s[i] != t[i]) p.push_back(i);
    		}
    		if (p.size() == 0)
    			cout << "Yes\n";
    		else if (p.size() == 2) {
    			if (s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]]) cout<<"Yes\n";
    			else cout<<"No\n"; 
    		}
    		else cout<<"No\n";
     
    	}
    	return 0;
    }