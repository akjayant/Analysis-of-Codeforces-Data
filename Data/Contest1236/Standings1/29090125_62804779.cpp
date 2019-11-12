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
#define MOD 1000000000
#define INF 1000000007

using namespace std;

typedef pair<int, int> pii;

int T, a, b, c;

int main() {
    scanf("%d", &T);
    while (T) {
        scanf("%d %d %d", &a, &b, &c);
        int answer = 0;
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                if (a >= i && b >= 2 * i + j && c >= 2 * j) answer = max(answer, 3 * (i + j));
            }
        }
        printf("%d\n", answer);
        T--;
    }
}