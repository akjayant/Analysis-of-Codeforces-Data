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
#include <unordered_map>
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
template <class T>
string to_string(vector<T> v);

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
string to_string(unordered_map<S, T> m) {
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

struct UnionFind {
  vector<int> data;
  UnionFind(int size) { data = vector<int>(size, -1); }
  bool union_set(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

int main() {
  cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<unordered_set<int>> out(n);
	FOR(i,m){
		int a,b;
		cin>>a>>b;
		out[a-1].insert(b-1);
		out[b-1].insert(a-1);
	}
	vector<int> skip(n);
	UnionFind uf(n);
	FOR(i,n){
		if(!skip[i]){
			FOR(j,n){
				if(i==j)continue;
				if(!out[i].count(j)){
					uf.union_set(i,j);
					if(i<j)skip[j]=1;
				}
			}
		}
	}
	unordered_map<int,vector<int>> skiplist;
	FOR(i,n){
		if(skip[i]){
			skiplist[uf.root(i)].push_back(i);
		}
	}
	for(pair<int,vector<int>> p1:skiplist){
		for(pair<int,vector<int>> p2:skiplist){
			if(p1.first==p2.first)continue;
			bool brk=0;
			for(int a:p1.second){
				if(brk)break;
				for(int b:p2.second){
					if(!out[a].count(b)){
						uf.union_set(a,b);
						brk=1;
					}
				}
			}
		}
	}
	unordered_set<int> mp;
	FOR(i,n)mp.insert(uf.root(i));
	cout<<((int)mp.size()-1)<<endl;
  return 0;
}