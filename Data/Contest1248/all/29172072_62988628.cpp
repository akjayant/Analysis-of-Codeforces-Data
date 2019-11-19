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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int vertical = 0;
    int horizontal = 0;
    int in_vertical = n >> 1;
    for (int i = 0; i < in_vertical; ++i)
        vertical += a[i];
    for (int i = in_vertical; i < n; ++i)
        horizontal += a[i];
    long long answer = 1LL * vertical * vertical + 1LL * horizontal * horizontal;
    printf("%lld\n", answer);
    return 0;
}