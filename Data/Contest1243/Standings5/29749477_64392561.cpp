#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define int long long

using namespace std;

int fact(int n) {
    int cnt = 1;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            if (cnt != 1 && cnt != i)
                return -1;
            else
                cnt = i;
            n /= i;
        }
    }
    if (n != 1) {
        if (cnt != 1 && cnt != n)
            return -1;
        else
            return n;
    }
    return cnt;
}

signed main() {
    int n;
    cin >> n;
    int t = fact(n);
    if (t == -1)
        cout << 1;
    else
        cout << t;
    return 0;
}