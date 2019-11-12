/*
	author : pshishod2645
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;
#define cerr cout
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
inline int add(int a, int b){a += b; if(a >= MOD)a -= MOD; return a;}
inline int sub(int a, int b){a -= b; if(a < 0)a += MOD; return a;}
inline int mul(int a, int b){return (int)((long long) a * b %MOD);}
inline int binpow(int a, int b){int res = 1; while(b > 0){ if(b & 1)res = mul(res, a); a = mul(a, a);b /= 2;} return res;}
inline int inv(int a){return binpow(a, MOD - 2);}
int gcd(int a, int b, int &x, int &y){if(a == 0){x = 0, y = 1; return b;} int x1, y1;  int d = gcd(b%a, a, x1, y1); x = y1 - (b/a) * x1; y = x1; return d;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int test; cin>>test; 
	while(test--){
		int n; cin>>n;
		string s, t; cin>>s>>t; 
		bool check = true; 
		vector<pair<int, int> > ans; 
		for(int i = 0;i < n; ++i){
			if(s[i] == t[i])continue; 
			int id = -1; 
			char c = s[i]; 
			for(int j = i + 1; j < n; ++j)if(s[j] != t[j] && s[j] == c)id = j; 
			if(id != -1){
				swap(s[id], t[i]); 
				ans.push_back({id, i}); 
				continue; 
			}
			swap(s[i], t[i]); ans.push_back({i, i}); 
			for(int j = i + 1; j < n; ++j)if(s[j] != t[j] && t[j] == c)id = j; 
			if(id == -1){
				check = false; break; 
			}
			swap(s[i], t[id]); ans.push_back({i, id}); 
		}
		if(!check){
			cout<<"No\n"; 
		}else{
			cout<<"Yes\n"; 
			cout<<ans.size()<<"\n"; 
			assert(s == t); 
			for(int i = 0;i < ans.size(); ++i)cout<<ans[i].first + 1<<" "<<ans[i].second +1<<"\n"; 
		}
	}

    return 0;
}	