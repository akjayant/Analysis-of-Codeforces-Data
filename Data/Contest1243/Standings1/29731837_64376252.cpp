#include <bits/stdc++.h>
using namespace std;
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


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	while(k--){
		int n;
		string a , b;
		cin>>n>>a>>b;
		int cnt = 0;
		vector<int> dif;
		for(int i = 0 ; i < n; i ++){
			if(a[i] != b[i]) dif.push_back(i);
		}
		if(dif.size() == 0){
			cout<<"Yes"<<endl;
		}
		else if(dif.size() == 2){
			if(a[dif[0]] == a[dif[1]] && b[dif[0]] == b[dif[1]]){
				cout<<"Yes"<<endl;
			}
			else cout<<"No"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}