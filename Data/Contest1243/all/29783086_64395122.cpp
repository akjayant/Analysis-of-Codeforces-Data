#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define INF (1 << 29)
#define LLINF (1LL << 60)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;

string to_string(string s) { return s; }

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class S>
string to_string(unordered_set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S, class T>
string to_string(map<S, T> m) {
  string ret = "{";
  for (pair<S, T> x : m) ret += to_string(x) + ",";
  return ret + "}";
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  cin.tie(0);
	int k;
	cin>>k;
	while(k--){
		int n;cin>>n;
		string s,t;
		cin>>s>>t;
		vector<unordered_set<int>> pool(26);
		FOR(i,n){
			pool[s[i]-'a'].insert(i);
			pool[t[i]-'a'].insert(i+n);
		}
		vector<Pi> ans;
		bool f=1;
		FOR(i,n){
			pool[s[i]-'a'].erase(i);
			pool[t[i]-'a'].erase(i+n);
			if(s[i]!=t[i]){
				if(!pool[s[i]-'a'].empty()){
					int put_from=*pool[s[i]-'a'].begin();
					if(put_from>=n){
						ans.push_back(Pi(i,i));
						ans.push_back(Pi(i,put_from-n));
						t[put_from-n]=t[i];
					}else{
						ans.push_back(Pi(put_from,i));
						s[put_from]=t[i];
					}
					pool[s[i]-'a'].erase(put_from);
					pool[t[i]-'a'].insert(put_from);
				}else{
					f=0;
					break;
				}
			}
		}
		if(f){
			cout<<"Yes"<<endl;
			if(ans.size()==0){
				ans.push_back(Pi(0,0));
			}
			cout<<ans.size()<<endl;
			for(Pi p:ans){
				cout<<p.first+1<<" "<<p.second+1<<"\n";
			}
		}else{
			cout<<"No"<<endl;
		}
	}
  return 0;
}