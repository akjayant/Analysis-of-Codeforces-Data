#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#define INF 1000000007
//#define POLYTOPE_TESTING // set to true if you're running polytope testing
//#define DEBUG


using namespace std;
typedef long long s64;
typedef unsigned long long u64;
template<typename T>
ostream& operator<<(ostream &out, vector<T> &vec) {
	out << "[";
	if (vec.size() > 0) {		
		for (int i=0; i<vec.size()-1; ++i)
			out << vec[i] << ", ";
		out << vec[vec.size()-1];
	}
	out << "]";
	return out;
}

template<typename T>
ostream& operator<<(ostream &out, vector<T> &&vec) {
	out << "[";
	if (vec.size() > 0) {		
		for (int i=0; i<vec.size()-1; ++i)
			out << vec[i] << ", ";
		out << vec[vec.size()-1];
	}
	out << "]";
	return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, unordered_map<T1, T2> &dict) {
	out << "{";
	int k = dict.size();
	for (auto it=dict.begin(); it!=dict.end(); ++it) {
		out << (it->first) << ": " << (it->second);
		if (k > 1) {
			out << ", ";
		}
		--k;
	}
	out << "}";
	return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, map<T1, T2> &dict) {
	out << "{";
	int k = dict.size();
	for (auto it=dict.begin(); it!=dict.end(); ++it) {
		out << (it->first) << ": " << (it->second);
		if (k > 1) {
			out << ", ";
		}
		--k;
	}
	out << "}";
	return out;
}

template<typename T>
ostream& operator<<(ostream &out, unordered_set<T> &S) {
	out << "{";
	int k = S.size();
	for (auto it=S.begin(); it!=S.end(); ++it) {
		out << (*it);
		if (k > 1) {
			out << ", ";
		}
		--k;
	}
	out << "}";
	return out;
}

template<typename T>
ostream& operator<<(ostream &out, set<T> &S) {
	out << "{";
	int k = S.size();
	for (auto it=S.begin(); it!=S.end(); ++it) {
		out << (*it);
		if (k > 1) {
			out << ", ";
		}
		--k;
	}
	out << "}";
	return out;
}

int n,m;
bool good[100100];
vector<int> notadj[100100];
unordered_map<int, unordered_map<int, bool> > adj;
vector<int> adjl[100100];
int color[100100];

void dfs(int v) {
	for (int u: adjl[v]) {
		if (color[u] == 0) {
			#ifdef DEBUG
			cout << "[dfs]: setting color[" << u << "] = " << color[v] << endl;
			#endif
			color[u] = color[v];
			dfs(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	#ifdef POLYTOPE_TESTING
	int polytope_ntests;
	cin >> polytope_ntests;
	string polytope_sampstr;
	int tnum;
	for (int polytope_tn=1; polytope_tn <= polytope_ntests; polytope_tn++) {
		cout << "polytope-test " << polytope_tn << "\n";
		cin >> polytope_sampstr >> tnum;
	#endif 
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		notadj[i].clear();
		adjl[i].clear();
	}
	adj.clear();
	int a,b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		notadj[a].push_back(b);
		notadj[b].push_back(a);
	}
	int best = 1;
	for (int i=1; i<=n; i++) {
		if (notadj[i].size() < notadj[best].size()) {
			best = i;
		}
	}
	
	#ifdef DEBUG
	cout << "choosing minimally connected (best) vertex = " << best << endl;
	#endif
	
	for (int i=1; i<=n; i++) good[i] = true;
	for (int v: notadj[best]) good[v] = false;
	
	int goods = n-notadj[best].size();
	bool added = true;
	while (added) {
		added = false;
		for (int v: notadj[best]) {
			if (!good[v] && notadj[v].size() < goods) {
				#ifdef DEBUG
				cout << "adding vertex " << v << " because it's nonadjacent to " << notadj[v].size() << " things and there are " << goods << " good vertices\n";
				#endif
				good[v] = true;
				goods++;
				added = true;
			}
		}
	}
	
	#ifdef DEBUG
	cout << "vertices adjacent to best: ";
	for (int v=1; v<=n; v++) {
		if (good[v]) {
			cout << v << " ";
		}
	}
	cout << endl;
	#endif
	
	for (int v: notadj[best]) {
		//cout << v << endl;
		if (good[v]) continue;
		//cout << v << endl;
		int ok = 0;
		for (int u: notadj[best]) {
			if (u != v) adj[v][u] = 1;
		}
		for (int u: notadj[v]) {
			if (!good[u]) {
				adj[v][u] = 0;
				ok++;
			}
		}
		if (notadj[v].size()-ok < goods) {
			adj[v][0] = 1;
			adj[0][v] = 1;
		} else {
			adj[v][0] = 0;
			adj[0][v] = 0;
		}
	}
	
	vector<int> things;
	things.push_back(0);
	for (int v: notadj[best]) {
		if (!good[v]) {
			things.push_back(v);
		}
	}
	
	#ifdef DEBUG
	cout << "adjmat\n";
	cout << "  ";
	for (int v: things) {
		cout << v << " ";
	}
	cout << endl;
	#endif
	for (int u: things) {
		#ifdef DEBUG
		cout << u << " ";
		#endif
		for (int v: things) {
			if (adj[u][v]) {
				adjl[u].push_back(v);
				adjl[v].push_back(u);
			}
			#ifdef DEBUG
			cout << adj[u][v] << " ";
			#endif
		}
		#ifdef DEBUG
		cout << endl;
		#endif
	}
	
	int k = 0;
	for (int v: things) {
		color[v] = 0;
	}
	for (int v: things) {
		if (color[v] == 0) {
			k++;
			color[v] = k;
			#ifdef DEBUG
			cout << "setting color[" << v << "] = " << k << endl;
			#endif
			dfs(v);
		}
	}
	
	cout << (k-1) << endl;
	
	#ifdef POLYTOPE_TESTING
	}
	cout << "polytope-test end\n";
	#endif
	return 0;
}
