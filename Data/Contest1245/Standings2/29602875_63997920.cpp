#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;


#define ll long long
const ll mod = 1e9 + 7;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(gcd(a, b) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}