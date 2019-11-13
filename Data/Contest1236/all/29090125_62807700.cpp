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

int n;
vector<int> answer[400];

int main() {
    scanf("%d", &n);
    bool dir = true;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (dir) for (int j = 1; j <= n; j++) answer[j].push_back(cnt++);
        else for (int j = n; j >= 1; j--) answer[j].push_back(cnt++);
        dir = !dir;
    }
    for (int i = 1; i <= n; i++) {
        for (auto &x: answer[i]) printf("%d ", x);
        printf("\n");
    }
}