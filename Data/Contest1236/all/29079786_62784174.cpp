#pragma comment(linker, "/STACK:134217728") //128mb
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;


typedef long long ll;
const long long MOD = 1000000007; //1e9+7
const long long MAXN = 100000 + 100; //1e5




int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        int res = 0;
        for (int fst = 0; fst <= a; ++fst) {
            for (int snd = 0; snd <= b; ++snd) {
                if (b - 2*fst - snd >= 0 && c >= 2*snd) {
                    res= max(res, 3*fst + 3*snd);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
