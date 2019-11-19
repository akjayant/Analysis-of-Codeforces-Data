#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <random>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#define LL long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 11234567;

int inp[5];

int main()
{
    ios::sync_with_stdio(false);

    int t;

    scanf("%d", &t);
    while(t--){

    for (int i = 0; i < 5; ++i) scanf("%d", &inp[i]);

    int a, b;
    a = (inp[0]+inp[2]-1)/inp[2];
    b = (inp[1]+inp[3]-1)/inp[3];

    if (a+b > inp[4]) puts("-1");
    else printf("%d %d\n", a, inp[4]-a);
    }

    return 0;
}
