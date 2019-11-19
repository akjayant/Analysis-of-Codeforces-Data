#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint MOD = 1e9 + 7;

int main() {
    llint N, K;
    cin >> N >> K;
    vector<llint> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    llint minimals = 0, maximals = 0;
    for(int i = 0; i < N; i++) {
        if(v[i] == v[0])
            minimals++;
        if(v[i] == v[N - 1])
            maximals++;
    }
    llint MIN = v[0], MAX = v[N - 1];
    while(K > 0) {
        if(minimals + maximals > N) {
            cout << 0;
            return 0;
        }
        if(minimals < maximals) {
            llint diff = v[minimals] - v[minimals - 1];
            if(diff * minimals <= K) {
                K -= diff*minimals;
                MIN = v[minimals];
                while(minimals + 1 < N && v[minimals + 1] == v[minimals]) {
                    minimals++;
                }
                minimals++;
            }
            else {
                MIN = v[minimals - 1] + K / minimals;
                break;
            }
        }
        else {
            llint diff = v[N - maximals] - v[N - maximals - 1];
            if(diff * maximals <= K) {
                K -= diff * maximals;
                MAX = v[N - maximals - 1];
                while(N - maximals - 2 >= 0 && v[N - maximals - 2] == v[N - maximals - 1]) {
                    maximals++;
                }
                maximals++;
            }
            else {
                MAX = v[N - maximals] - K / maximals;
                break;
            }
        }
        // cout << MIN << " " << MAX << " " << minimals << " " << maximals << endl;
    }
    // cout << minimals << " " << maximals << endl;
    cout << MAX - MIN;
}