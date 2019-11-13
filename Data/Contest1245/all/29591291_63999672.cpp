#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n, t, a, b, c;
string s;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
    	cin >> n >> a >> b >> c >> s;
    	int x = 0;
    	vector<char> v;
    	for(int i = 0; i < n; i++){
    		if(s[i] == 'R'){
    			if(b-- > 0){x++; v.pb('P');}
    			else v.pb('?');
    		}
    		if(s[i] == 'P'){
    			if(c-- > 0){x++; v.pb('S');}
    			else v.pb('?');
    		}
    		if(s[i] == 'S'){
    			if(a-- > 0){x++; v.pb('R');}
    			else v.pb('?');
    		}
    	}
    	if(2 * x < n) cout << "NO" << endl;
    	else{
    		cout << "YES" <<endl;
    		for(char x : v){
    			if(x == '?'){
    				if(a-- > 0) cout << 'R';
    				else if(b-- > 0) cout << 'P';
    				else cout << 'S';
    			} else{
    				cout << x;
    			}
    		}
    	}
    	cout << endl;
    }
}