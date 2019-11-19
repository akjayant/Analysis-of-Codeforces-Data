#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        string s;
        cin >> N >> s;
        int firstS = -1, lastS = -1;
        for(int i = 0; i < N; i++) {
            if(s[i] == '1') {
                lastS = i;
                if(firstS == -1) {
                    firstS = i;
                }
            }
        }
        if(firstS == -1) {
            cout << N << endl;
        }
        else {
            cout << max({N, 2 * (N - firstS), 2 * (lastS + 1)}) << endl;
        }
    }
}