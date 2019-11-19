#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
//#include <random>
//#include <numeric>
//#include <chrono>
//#include <regex>

#define wr 	cout <<
#define ww 	<< ' ' <<
#define br	<< '\n'
#define wln cout << '\n'
#define fori(st, en)			for(int i = (st); i < (en); ++i)
#define forj(st, en)			for(int j = (st); j < (en); ++j)
#define input(arr, n)  			fori(0, (n)) cin >> (arr)[i]
#define input2d(arr, n, m)  	forj(0, (n)) input((arr)[j], (m))
#define print(arr, n, delim)	fori(0, (n)) {cout << (arr)[i] << (delim);}
#define printdown(arr, n, delim)for(int i = (n) - 1; i >= 0; --i) {cout << (arr)[i] << (delim);}
#define printobj(obj, delim)	for(auto it : (obj)) {cout << it << (delim);}
#define print2d(a, row, col, d)	forj(0, (row)) {print((a)[j], (col), (d)); wln;}
#define forit(obj)				for(auto it = (obj).begin(); it != (obj).end(); ++it)
#define all(v)	(v).begin(), (v).end()
#define make(a, b) std::make_pair((a), (b))
#define pb push_back
#define SYNC ios::sync_with_stdio(0)

using namespace std;
typedef long long u;
typedef pair<int, int> ipar;
typedef pair<u, u> upar;
typedef vector<int> vi;
typedef vector<u> vu;
typedef vector<vi> vvi;
typedef vector<string> vstr;
const u mod = 1e9 + 7;

int main(){
    SYNC;
    int n;
    cin >> n;
    vi a(n);
    input(a, n);
    sort(all(a));
    u a1 = 0, a2 = 0;
    fori(0, n) {
        if (i < n / 2) a1 += a[i];
        else a2 += a[i];
    }

    wr (a1*a1 + a2*a2) br;
}