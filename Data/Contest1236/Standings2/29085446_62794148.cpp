#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
 
vector<int> ans[303];

int f(int x , int y){
	int cnt = 0;
	for(auto w : ans[x]){
		for(auto j : ans[y]){
			if(w > j) cnt++;
		}
	}
	return cnt;
}

int32_t main(){
	int n;
	cin>>n;
	int cnt = 0;
	bool lst = 0;
	int j = 1;
	for(int i = 1 ; i <= n*n; i ++){
		if(cnt == n){
			cnt = 0;
			lst ^= 1;
			if(lst)
			j = n ;
			else j = 1; 
		}
		if(lst){
			ans[(j-- - 1)%n] .push_back(i);
		}
		else{
			ans[(j++ - 1)%n].push_back(i);
		}
		cnt++;
	}
	for(int i = 0 ; i < n; i ++){
		for(auto w : ans[i]){
			cout<<w<<" ";
		}
		cout<<endl;
	}
}