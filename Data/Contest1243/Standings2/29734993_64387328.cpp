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

int is_prime(uint64_t n)
{
	uint64_t k;
	//<2 => not prime
	if (n < 2)
		return 0;
	//2,3 are prime
	if (n < 4)
		return 1;
	//check for divisibility by 2 or 3
	if (n > 3 && (n%2==0 || n%3==0))
		return 0;
	//check for other primes less than or equal to sqrt(k)
	uint64_t y = (uint64_t)sqrt(n);
	for (k = 5; k <= y; k+=6)
		if (n%k == 0 || n%(k+2) == 0)
			return 0;
	return 1;
}


uint64_t n;

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
	cin >> n;
	vector<uint64_t> primes;
	for (uint64_t k=2; k*k <= n; k++) {
		if (is_prime(k)) {
			primes.push_back(k);
		}
	}
	vector<uint64_t> div;
	for (uint64_t p: primes) {
		if (n%p == 0) {
			div.push_back(p);
			while (n%p == 0) n /= p;
		}
	}
	if (is_prime(n)) {
		div.push_back(n);
	}
	if (div.size() == 1) {
		cout << div[0] << endl;
	} else {
		cout << 1 << endl;
	}
	#ifdef POLYTOPE_TESTING
	}
	cout << "polytope-test end\n";
	#endif
	return 0;
}
