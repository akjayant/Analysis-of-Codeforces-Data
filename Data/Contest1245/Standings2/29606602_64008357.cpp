/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+55;
const long long MD = 1e9+7;

long long n, m;
int a[3];
string s;

long long arr[N];


int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/
    cin >> s;

    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i < N; i++) arr[i] = (arr[i-1] + arr[i-2] ) % MD;

    char last = 'q';
    int cnt = 0;

    long long ans = 1;

    for (auto c : s) {
        if (c == 'm' || c == 'w') ans = 0;
        if (c == last) cnt++;
        else {
            if (last == 'u' || last == 'n') {
                ans = ans * arr[cnt] % MD;
            }
            last = c;
            cnt = 1;
        }
    }
    if (last == 'u' || last == 'n') {
        ans = ans * arr[cnt] % MD;
    }

    cout << ans;


    return 0;
}
