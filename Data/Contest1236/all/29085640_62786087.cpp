#include<iostream>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    int a = A, b = B, c = C;
    int now_ans = 0;
    int first_num = min(B, C / 2);
    now_ans += 3 * first_num;
    B -= first_num;
    int second_num = min(A, B / 2);
    now_ans += 3 * second_num;
    ans = max(ans, now_ans);
    
    now_ans = 0;
    first_num = min(A, B / 2);
    now_ans += 3 * first_num;
    B -= 2 * first_num;
    second_num = min(B, C / 2);
    now_ans += 3 * second_num;
    ans = max(ans, now_ans);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(i, 0, T) solve();
    return 0;
}