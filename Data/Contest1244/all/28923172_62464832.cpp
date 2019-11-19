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
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        int A = (a + c - 1) / c;
        int B = (b + d - 1) / d;
        if (A + B <= k) {
            printf("%d %d\n", A, B);
        } else {
            puts("-1");
        }
    }
}