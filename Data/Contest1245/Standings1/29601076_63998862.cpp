#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define INF 1e9+7
#define pf2 pop_front
#define pb2 pop_back
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz size
#define eps 1e-7
#define fod find_by_order
#define fastio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ofk order_of_key
#define val(x) cout << "Value dari "<< #x << " adalah " << x  << "\n"
#define tr tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

void readf(string x){
	freopen((x+".in").c_str(),"r",stdin);
	freopen((x+".out").c_str(),"w",stdout);
}

void pr(string x){
	freopen((x+".in").c_str(),"w",stdout);
}


int read()
{
	bool min = 0;
	int  result = 0;
	char ch;
	ch = getchar();
	while(1)
	{
		if(ch == '-') break;
		if(ch >='0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') min = 1;else result = ch-'0';
	while(1)
	{
		ch =getchar();
		if(ch< '0' || ch>'9') break;
		result = result * 10 + (ch-'0');
	}
	if(min) return -result;
	return result;
}
//Reynaldo's Template

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		char x[n+5];
		for(int i = 1; i <= n; i++) cin>> x[i];
		
		int aa = 0, bb = 0, cc = 0;
		for(int i = 1; i <= n; i++) {
			if (x[i] == 'R') aa++;
			if (x[i] == 'P') bb++;
			if (x[i] == 'S') cc++;
		}
		
		int ans = 0;
		ans = ans + min(b, aa) + min(c, bb) + min(a, cc);
		
		char zz[n+5];
		bool gg[n+5];
		memset(gg, 0, sizeof gg);
		if(ans >= (n + 1) / 2) {
			cout << "YES\n";
			for(int i = 1; i <= n; i++) {
				if(x[i] == 'R') {
					if (b) {
						zz[i] = 'P';
						b--;
						gg[i] = 1;
					}
				}
				
				if (x[i] == 'P') {
					if(c) {
						zz[i] = 'S';
						c--;
						gg[i] = 1;
					}
				}
				
				if (x[i] == 'S') {
					if (a) {
						zz[i] = 'R';
						a--;
						gg[i] = 1;
					}
				}
			}
			
			for(int i = 1; i <= n; i++) {
				if(!gg[i]) {
					if (a) {
						zz[i] = 'R';
						a--;
					}
					else if(b) {
						zz[i] = 'P';
						b--;
					}
					else {
						zz[i] = 'S';
						c--;
					}
				}
				cout << zz[i];
			}
			cout << "\n";
		}
		else cout << "NO\n";
	}
}
