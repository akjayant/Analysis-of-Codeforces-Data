#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <bitset>
#include <list>
#define MOD 1000000007
#define INF 1000000007

using namespace std;

typedef pair<int, int> pii;

long long int n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    long long int partialMod = 2;
    long long int answer = 1;
    while (m) {
        if (m % 2 == 1) answer = (answer * partialMod) % MOD;
        m /= 2;
        partialMod = (partialMod * partialMod) % MOD;
    }
    partialMod = answer - 1;
    answer = 1;
    while (n) {
        if (n % 2 == 1) answer = (answer * partialMod) % MOD;
        n /= 2;
        partialMod = (partialMod * partialMod) % MOD;
    }
    printf("%lld\n", answer);
}