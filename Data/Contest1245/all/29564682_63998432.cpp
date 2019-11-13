#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 1000007 //10e6 +7

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a, b, c;
		cin >> a>> b >> c;
		string s;
		cin >> s;
		bool vis[107];
		memset(vis, false, sizeof vis);
		string t=s;
		int w = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] == 'R'){
				if(b){
					b--;
					t[i]='P';
					w++;
					vis[i]=true;
				}
			}else if(s[i]=='P'){
				if(c){
					c--;
					t[i]='S';
					w++;
					vis[i]=true;
				}
			}else{
				if(a){
					a--;
					t[i]='R';
					w++;
					vis[i]=true;
				}
			}
		}
		if(w >= (n+1)/2){
			cout << "YES" << endl;
			for(int i=0; i<n; i++){
				if(vis[i]==false){
					if(a)t[i]='R', a--;
					else if(b)t[i]='P', b--;
					else t[i]='S', c--;
				}
			}
			cout << t << endl;
		}else cout << "NO" << endl;
	}
}