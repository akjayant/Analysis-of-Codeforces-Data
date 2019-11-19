#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main() {
    kekek;
    
    long long n;
    cin >> n;
    if (n == 1) return cout << 1, 0;
    vector<long long> div;
    long long save = n;
    for (long long i = 2; i * i <= n; i++) {
        if (save % i == 0) {
            div.push_back(i);
            while (save % i == 0) save /= i;
        }
    }

    if (save != 1) {
        div.push_back(save);
    }

    if (div.size() > 1) {
        cout << 1;
    }
    else {
        cout << div[0];
    }
    
    //system("pause");
    return 0;
}