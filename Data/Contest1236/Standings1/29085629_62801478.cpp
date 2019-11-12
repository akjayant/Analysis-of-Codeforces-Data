#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int maxN = 333;


vector<int> res[maxN];
int N;

int main() {
    scanf("%d", &N);
    int pos = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            pos++;
            int v = j;
            if (i & 1)
                v = N - v + 1;
            res[v].push_back(pos);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int p : res[i])
            printf("%d ", p);
        puts("");
    }
}
