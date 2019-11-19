#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv) {
    int T;
    scanf("%d", &T);
    while (T-- != 0) {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        int m;
        scanf("%d", &m);
        vector<int> q(m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &q[i]);
        vector<int> freq(2);
        for (int i = 0; i < m; ++i)
            ++freq[q[i] & 1];
        long long answer = 0;
        for (int i = 0; i < n; ++i)
            answer += freq[p[i] & 1];
        printf("%lld\n", answer);
    }
    return 0;
}