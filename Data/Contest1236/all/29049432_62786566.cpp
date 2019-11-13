#include <bits/stdc++.h>
/*
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
/**
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("fast-math") 
#pragma GCC optimize("section-anchors") 
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer") 
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers") 
#pragma GCC optimize("move-loop-invariants") 
#pragma GCC optimize("unswitch-loops") 
#pragma GCC optimize("function-sections") 
#pragma GCC optimize("data-sections") 
#pragma GCC optimize("branch-target-load-optimize") 
#pragma GCC optimize("branch-target-load-optimize2") 
#pragma GCC optimize("btr-bb-exclusive")
**/
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

using namespace std;

inline void using_file(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

//typedef __int128 vll;

mt19937 gen_rand;

/*OUTPUT*/
/*PAIR*/
/*
void read(vll &x) {
    string s;
    cin >> s;
    x = 0;
    int buf = 1;
    for (auto c : s) {
        if (c == '-') {
            assert(buf != -1);
            buf = -1;
            continue;
        }
        x *= 10;
        x += (c - '0');
    }  
    x *= buf;
}

ostream &operator<<(ostream &os, vll x) {
	deque<char> res;
    int buf = 0;
	if (x < 0) {
        buf = 1;
		x = -x;
		res.push_back('-');
	} 
	bool flag = false;
	while (x > 0 || !flag) {
		flag = true;
		res.push_back(char('0' + x % 10));
		x /= 10;
	}
	reverse(res.begin() + buf, res.end());
	for (auto c : res) {
		os << c;
	}  
    return os;
}
*/

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &a) {
    os << "(";
    os << a.first << ", ";
    os << a.second;
    os << ")";
    return os;
}
/*PAIR*/

/*ARR*/
template<typename T>
ostream &operator<<(ostream &os, vector<T> &a) {
    os << "{";
    bool was = false;
    for (auto &x: a) {
        if (was) {
            os << ", ";
        }
        was = true;
        os << x;
    }
    os << "}";
    return os;
}
/*ARR*/
/*OUTPUT*/

/*DEBUG*/
template<typename T>
inline void debug(const char* sdbg, T x) {
    cerr << "The value of " << sdbg << " is " << x << "\n";
};

template<typename T, typename... U>
inline void debug(const char* sdbg, T h, U... t) {
    cerr << "The value of ";
    while (*sdbg != ',') {
        cerr << *sdbg++;
    }
    cerr << " is " << h << "\n";
    debug(sdbg + 1, t...);
    cerr << "\n";
}

#define value(...) debug(#__VA_ARGS__, __VA_ARGS__)
/*DEBUG*/

template<typename T>
T abs(T x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

template<typename T>
T sqr(T x) {
    return x * x;
};

const long long INF_FOR_SHORT_TIME = (long long)(1e9);

template<typename T>
T mul(T a, T b, T m) {
    if (a <= INF_FOR_SHORT_TIME && b <= INF_FOR_SHORT_TIME) {
        return (a * b) % m;
    } 
    T q = (long long)((long double)a * (long double)b / (long double)m);
    T r = a * b - q * m;
    return (r + 5 * m) % m;
}

template<typename T, typename U>
T binpow(T a, U n, T MOD) {
	T res = 1;
	while (n) {
		if (n & 1) {
            res = mul(res, a, MOD);
		} 
        a = mul(a, a, MOD);
		n >>= 1;
	}
	return res;
};

template<typename T>
int sign(T x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
};

template<typename T>
T gcd(T a, T b) {
    if (a > b) {
        swap(a, b);
    }
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
};

template<typename T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};

template<typename T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

/*curlink v1.9 + 128*/

const int mod = int(1e9) + 7;

int bp(int x, int n) {
    if (n == 0) {
        return 1;
    } 
    if (n % 2) {
        return (1LL * x * bp(x, n - 1)) % mod;
    } else {
        return sqr(1LL * bp(x, n / 2)) % mod;
    }
}

int main() {
    gen_rand.seed(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << bp(((bp(2, m) - 1 + mod) % mod), n);
    return 0;
}