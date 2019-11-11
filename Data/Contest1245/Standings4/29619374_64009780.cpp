#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <queue>
using namespace std;
 


int main() {
    string s;
    cin >> s;
    vector<long long>fib(s.size() + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= 1000000007;
    }
    int unow = 0;
    int nnow = 0;
    long long ans = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
        else if (s[i] == 'u') {
            ++unow;
            ans *= fib[nnow];
            ans %= 1000000007;
            nnow = 0;
        }
        else if (s[i] == 'n') {
            ++nnow;
            ans *= fib[unow];
            ans %= 1000000007;
            unow = 0;
        }
        else {
            ans *= fib[nnow];
            ans %= 1000000007;
            ans *= fib[unow];
            ans %= 1000000007;
            nnow = 0;
            unow = 0;
        }
    }
    ans *= fib[nnow];
    ans %= 1000000007;
    ans *= fib[unow];
    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}
