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
	int t;
	cin>>t;
	while(t--){
		int n  , a , b,c;
		string s;
		cin>>n>>a>>b>>c>>s;
		string l=s;
		for(int i = 0 ; i < n; i ++){
			l[i]= 'X';
		}
		int bt = 0;
		for(int i = 0 ; i < s.size() ; i ++){
			if(s[i] == 'P'){
				if(c > 0){
					c--;
					l[i] = 'S';
					bt++;
				}
			}
			else if(s[i] == 'R'){
				if(b > 0){
					b--;
					l[i] = 'P';
					bt++;
				}
			}
			else if(s[i] == 'S'){
				if(a > 0){
					a--;
					l[i] = 'R';
					bt++;
				}
			}
		}
		for(int i = 0 ; i < n; i ++){
			if(l[i] == 'X'){
				if(a > 0){
					a--;
					l[i] = 'R';
				}
				else if(b > 0){
					b--;
					l[i] = 'P';
				}
				else if(c > 0){
					c--;
					l[i] = 'S';
				}
			}
		}
		if(2*bt >= n){
			cout<<"YES"<<endl;
			cout<<l<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}