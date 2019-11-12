#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
typedef set <int> si;
typedef map <int, int> mii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vector <int>> vvi;  
#define F(i, a, b) for(int i = a; i <= (int)b; i++)
#define f(i, a, b) for(int i = a; i >= (int)b; i--)
#define F2(i, a, b) for(int i = a; i <= (int)b; i+=2)
#define f2(i, a, b) for(int i = a; i >= (int)b; i-=2)
#define wh(n) int iteration = n; while(iteration--) 
#define For(t, it) for(auto it = (t).begin(); it != (t).end(); ++it)
#define IN insert
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define RS resize
#define GRAF(n) vvi gr; gr.resize(n+1); vector <bool> was; was.resize(n+1, 0);


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif
	int k;
	cin >> k;
	wh(k){
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector <pii> ans;
		bool fnd = 1;
		F(i, 0, n-1){
			if(s[i] == t[i])
				continue;
			bool found = 0;
			F(j, i+1, n-1){
				if(s[j] == s[i]){
					ans.PB(MP(j, i));
					swap(s[j], t[i]);
					found = 1;
					break;
				}
				if(t[j] == t[i]){
					ans.PB(MP(i, j));
					swap(s[i], t[j]);
					found = 1;
					break;
				}
			}
			if(found)
				continue;
			F(j, i+1, n-1){
	        		if(s[i] == t[j]){
	        			ans.PB(MP(j, j));
	        			swap(s[j], t[j]);
	        			found = 1;
	        			ans.PB(MP(j, i));
					swap(s[j], t[i]);	
	        			break;
	        		}
	        		if(t[i] == s[j]){
	        			ans.PB(MP(j, j));
	  	      			swap(s[j], t[j]);
	        			found = 1;
	        			ans.PB(MP(i, j));
					swap(s[i], t[j]);	
	        			break;
	        		}	
	        	}
	        	if(!found){
	        		fnd = 0;
	        		break;
	        	}
		}
	        if(!fnd){
	        	cout << "No\n";
	        	continue;
	        }
	        cout << "Yes\n" << ans.size() << '\n';
	        F(i, 0, ans.size()-1){
	        	cout << ans[i].first + 1 << ' ' << ans[i].second +1 << '\n';	
	        }
	}
	return 0;
}