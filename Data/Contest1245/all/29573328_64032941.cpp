#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string s;
long long d[1000001]; // [][0] - last is not in pair yet
vector<char> ans;
int main() {
//    d[1][0] = 1;
//    d[1][1] = 0;
//    d[2][0] = 1;
//    d[2][1] = 1;
    long long E = 1e9 + 7;
//    for (int i = 3; i < 1000000; ++i) {
//        d[i][0] = (d[i - 1][1] + d[i - 1][0]) % E;
//        d[i][1] = d[i - 1][0] % E;
//    }
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    for (int i = 4; i < 200000; ++i) {
        d[i] = (d[i - 1] + d[i - 2]) % E;
    }
    //cout << d[199999];
    //824037258
    //cout << d[999999][0] <<  " " << d[999999][1] << endl;
    //cout << LONG_LONG_MAX << endl;
    //cout << E * E << endl;
    //cout << d[3][0] << " " << d[3][1] << " " << d[4][0] << " " << d[4][1];
    cin >> s;
    long long sum = 1;
    int amount = 1;
    if (s[0] == 'm' || s[0] == 'w') {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= s.size(); ++i) {
        if (i < s.size() && (s[i] == 'w' || s[i] == 'm')) {
            cout << 0;
            return 0;
        }
        if (i < s.size() && s[i] == s[i - 1]) {
            ++amount;
            continue;
        } else {
            if ((s[i - 1] == 'n' || s[i - 1] == 'u') && amount > 1) {
                long long am = d[amount];
                sum *= am;
                sum %= E;
            }
            amount = 1;
        }
    }
    cout << sum % E;
    return 0;
}