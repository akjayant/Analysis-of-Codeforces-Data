#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int inf = 2e9;
const int N = 2e5 + 15;
int n, a, b, c, t, x[N];
string s;

main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> t;
    while(t--) {
        for(int i = 0; i <= n; ++i)
            x[i] = 0;
        cin >> n >> a >> b >> c >> s;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'R') {
                if(b) {
                    --b, ++ans;
                    x[i] = 2;
                }
            }
            else if(s[i] == 'P') {
                if(c) {
                    --c, ++ans;
                    x[i] = 3;
                }
            }
            else {
                if(a) {
                    --a, ++ans;
                    x[i] = 1;
                }
            }
        }
        if(ans * 2 >= n) {
            cout << "Yes" << endl;
            for(int i = 0; i < n; ++i) {
                if(!x[i]) {
                    if(a) {
                        x[i] = 1;
                        --a;
                    }
                    else if(b) {
                        x[i] = 2;
                        --b;
                    }
                    else {
                        x[i] = 3;
                        --c;
                    }
                }
                if(x[i] == 1)
                    cout << 'R';
                else if(x[i] == 2)
                    cout << 'P';
                else
                    cout << 'S';
            }
            cout << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}