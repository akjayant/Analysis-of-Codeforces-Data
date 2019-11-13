#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

#define ndl cout << '\n'
#define sz(v) int(v.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define present(a, x) (a.find(x) != a.end())
#ifdef LOCAL
#define db(...) ({cout << "> Line " << __LINE__  \
		<< ": "; _db(#__VA_ARGS__, __VA_ARGS__);})
#define RNG() rng()
#else
#define db(...) true
#define RNG() true
#endif

template<class T>
void _db(const char *dbStr, T e) {
	cout << dbStr << " = " << e << endl;
}
template<class T, class... L>
void _db(const char *dbStr, T e, L... r) {
  while(*dbStr != ',') cout << *dbStr++;
  cout << " = " << e << ','; _db(dbStr + 1, r...);
}
template<class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& v) {
	o << "["; int i = 0;
	for (const pair<S, T>& pr : v) o << (!i++ ? "" : ", ") << "{"
	<< pr.fs << " : " << pr.sc << "}"; return o << "]";
}
template<template <class, class...> class S, class T, class... L>
ostream& operator<<(ostream& o, const S<T, L...>& v) {
	o << "["; int i = 0;
	for (const auto& e : v) o << (!i++ ? "" : ", ") << e;
	return o << "]";
}
template<class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& pr) {
	return o << "(" << pr.fs << ", " << pr.sc << ")";
}
ostream& operator<<(ostream& o, const string& s) {
	for (const char& c : s) o << c;
	return o;
}

template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = VV<V<T>>;
using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;

int T;
string s, t;
int freqS[26], freqT[26];
vii moves;

void SWAP(int i, int j) {
	moves.pb(mp(i + 1, j + 1));
	--freqS[s[i] - 'a'], ++freqT[s[i] - 'a'];
	--freqT[t[j] - 'a'], ++freqS[t[j] - 'a'];
	db(s[i], t[j]);
	swap(s[i], t[j]);
	db(s, t);
}


int main() {
	#ifdef LOCAL
	auto stTime = clock();
//	freopen("in.txt", "r", stdin);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	ios::sync_with_stdio(false);
	cout.precision(10);
	cin.tie(0);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n >> s >> t;
		for (int i = 0; i < 26; ++i) {
			freqS[i] = freqT[i] = 0;
		}
		moves.clear();
		for (int i = 0; i < n; ++i) {
			++freqS[s[i] - 'a'];
			++freqT[t[i] - 'a'];
		}
		bool no = false;
		for (int i = 0; i < 26; ++i) {
			if ((freqS[i] + freqT[i]) & 1)
				no = true;
		}
		if (no) {
			cout << "No\n";
			continue;
		}
		for (int c = 0; c < 26; ++c) {
			char ch = c + 'a';
			for (int i = 0; i < n; ++i) {
				if (s[i] != t[i]) {
					if (s[i] == ch && freqS[c] > freqT[c]) {
						for (int j = 0; j < n; ++j) {
							if (i != j && s[j] == ch && t[j] != ch) {
								SWAP(i, j);
								break;
							}
						}
					}
					if (t[i] == ch && freqT[c] > freqS[c]) {
						for (int j = 0; j < n; ++j) {
							if (i != j && t[j] == ch && s[j] != ch) {
								SWAP(j, i);
								break;
							}
						}
					}
				}
			}
			vi pS, pT;
			for (int i = 0; i < n; ++i) {
				if (s[i] != t[i]) {
					if (s[i] == ch)
						pS.pb(i);
					if (t[i] == ch)
						pT.pb(i);
				}
			}
			db(ch, pS, pT);
			assert(sz(pS) == sz(pT));
			for (int i = 0; i < sz(pS); ++i) {
				SWAP(pS[i], pS[i]);
				SWAP(pT[i], pS[i]);
			}
		}

		cout << "Yes\n" << sz(moves) << '\n';

		for (auto& move : moves) {
			cout << move.fs << ' ' << move.sc << '\n';
		}


	}



	#ifdef LOCAL
	cout << "\n\n\nExecution time: " <<
		(clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
	#endif
    return 0;
}
