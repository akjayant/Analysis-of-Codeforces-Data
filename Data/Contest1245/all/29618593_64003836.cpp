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
	int t;
	cin >> t;
	wh(t){
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		int b1 = 0, a1 = 0, c1 = 0;
		string s = "";
		F(i, 1, n){
		  	char d;
		  	cin >> d;
		  	s += d;
		  	if(d == 'R') b1++;
		  	if(d == 'P') c1++;
		  	if(d == 'S') a1++;	
		}
		int mnc = min(c1, c);
		int mnb = min(b1, b); 
		int mna = min(a1, a);
		int cnt = mna + mnb + mnc;
		int k = (n % 2 ? n/2 + 1 : n/2);
		if(cnt >= k){
			cout << "YES\n";
		}else{
			cout << "NO\n";
			continue;
		}
		a -= mna;
		b -= mnb;
		c -= mnc;
		F(i, 0, n-1){
			if(s[i] == 'R' && mnb){
				cout << 'P';
				mnb--;
				continue;
			}
			if(s[i] == 'P' && mnc){
				cout << "S";
				mnc--;
				continue;
			}
			if(s[i] == 'S' && mna){
				cout << "R";
				mna--;
				continue;                         
			}
			if(a){
				cout << "R";
				a--;
				continue;
			}
			if(b){
				cout << "P";
				b--;
				continue;
			}
			if(c){
				cout << "S";
				c--;
				continue;
			}
		}
		cout << '\n';
	}
	return 0;
}