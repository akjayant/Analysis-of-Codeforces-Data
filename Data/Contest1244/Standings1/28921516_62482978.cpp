#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint MOD = 1e9 + 7;

int main() {
    llint N, P, W, D;
    cin >> N >> P >> W >> D;
    for(llint Y = 0; Y <= W + 5; Y++) {
        if((P - Y*D) % W == 0) {
            llint X = (P - Y*D) / W;
            if(X >= 0 && Y >= 0 && X + Y <= N) {
                cout << X << " " << Y << " " << N - X - Y;
                return 0;
            }
        }
    }
    cout << -1;
}