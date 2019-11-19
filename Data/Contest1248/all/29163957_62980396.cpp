//Author: gkashish

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define mod 1000000007
#define x first
#define y second


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int j = n - 1, i = 0, turn = 1;
    long long int len1 = 0, len2 = 0;
    while (i <= j) {
        if (turn) {
            len1 += arr[j--];
        } else {
            len2 += arr[i++];
        }
        turn = turn ^ 1;
    }
    cout << len1 * len1 + len2 * len2;
    return 0;
}
