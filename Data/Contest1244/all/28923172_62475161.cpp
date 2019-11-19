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

#define N 1009

char s[N];

int solve(int n) {
    int prv = -1, res = 0;
    int y = 0;
    int res1 = 0;
    int maxx = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            y ^= 1;
            res += 2;
            res1 = max(res1, res + i - prv - 1);
            maxx = i;
            prv = i;
        } else {
            res++;
        }
    }
    int res3 = 0;
    if (maxx > -1) {
        res3 = 2 * (maxx + 1);
    }
    return max(max(res, res1), res3);
}

int main() {
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n;
        scanf("%d %s", &n, s);
        int res = solve(n);
        reverse(s, s + n);
        res = max(res, solve(n));
        printf("%d\n", res);
    }
}