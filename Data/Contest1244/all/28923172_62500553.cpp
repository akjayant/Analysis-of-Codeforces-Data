#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <complex>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#define Int long long
#define INF 0x3F3F3F3F
#define eps 1e-9
using namespace std;

int main() {
    int n, i;
    Int k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> M;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        M[a[i]]++;
    }
    while (M.size() > 1) {
        auto L = *M.begin();
        auto R = *M.rbegin();
        if (L.second < R.second && L.second <= k) {
            auto L1 = *++M.begin();
            auto it = min(k / L.second, (Int)L1.first - L.first);
            if (it == 0) {
                break;
            }
            k -= L.second * it;
            M.erase(L.first);
            M[L.first + it] += L.second;
        } else if (R.second <= k) {
            auto R1 = *++M.rbegin();
            auto it = min(k / R.second, (Int)R.first - R1.first);
            if (it == 0) {
                break;
            }
            k -= R.second * it;
            M.erase(R.first);
            M[R.first - it] += R.second;
        } else {
            break;
        }
    }
    printf("%d\n", M.rbegin()->first - M.begin()->first);
}