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

int k;
int n;
string s,t;

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
	cin >> k;
	for (int test=0; test<k; test++) {
		cin >> n;
		cin >> s >> t;
		vector<int> diffs;
		for (int j=0; j<n; j++) {
			if (s[j] != t[j]) {
				diffs.push_back(j);
			}
		}
		if (diffs.size() != 2) {
			cout << "No\n";
		} else {
			int p = diffs[0], q = diffs[1];
			if (s[p] == s[q] && t[q] == t[p]) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	#ifdef POLYTOPE_TESTING
	}
	cout << "polytope-test end\n";
	#endif
	return 0;
}
