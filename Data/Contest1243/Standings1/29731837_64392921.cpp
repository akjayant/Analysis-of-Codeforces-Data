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
	cin.tie(0) , cout.tie(0);
	int k;
	cin>>k;
	while(k--){
		int n;
		string a , b;
		cin>>n>>a>>b;
		vector<int> dif;
		for(int i = 0 ; i < n; i ++){
			if(a[i] != b[i]) dif.push_back(i);
		}
		map<char ,int> F;
		for(auto w : dif) F[a[w]] ++ , F[b[w]]++;
		bool can = true;
		for(auto w : F){
			if(w.S %2) can = false; 
		}
		if(dif.size() == 0){
			cout<<"Yes"<<endl;
		}
		else if(can){
			vector<pii> moves;
			for(int i = 0 ; i < n; i ++){
				if(a[i] != b[i]){
					bool jf = false;
					for(int j = i +1 ; j < n; j ++){
						if(a[j] != b[j] && a[j] == a[i]){
							moves.push_back(pii(j+1 , i+1));
							swap(b[i] , a[j]);
							jf = true;
						}
						if(jf) break;
					}
					if(jf) continue;
					for(int j = i + 1 ; j < n; j ++){
						if(a[j] != b[j] && b[j] == a[i]){
							moves.push_back(pii(j+1 , j+1));
							swap(a[j] , b[j]);
							moves.push_back(pii(j+1 , i +1));
							swap(b[i] , a[j]);
							jf = true;
						}
						if(jf) break;
					}
					if(jf) continue;
				}
			}
			if(a != b){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
				cout<<moves.size() << endl;
				for(auto w : moves){
					cout<<w.F<<" " <<w.S << endl;
				}
			}
		}
		else{
			cout<<"No"<<endl;
		}
	}
}