#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 505;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n; char s[maxn];

bool check(int op) {
    stack<int> st;
    for (int i = op; i < n; i++) {
        if (s[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        } else {
            st.push(1);
        }
    }
    return st.empty();
}

int ans, ansL = 1, ansR = 1;
void solve(int left, int right) {
    int sum[maxn] = {};

    int mini_id = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;

        if (sum[i] < sum[mini_id]) mini_id = i;
    }
    int op = mini_id + 1;
    if (op > n) op = 1;

    int cnt = 0;
    for (int i = op; i <= n; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return;
    }
    for (int i = 1; i < op; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return;
    }
    if (cnt > 0) return;

    int tmp = 0;
    cnt = 0;
    for (int i = op; i <= n; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) tmp++;
    }
    for (int i = 1; i < op; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) tmp++;
    }

    if (tmp > ans) {
        ans = tmp;
        ansL = left, ansR = right;
    }
}

int main() {

    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            swap(s[i], s[j]);
            solve(i, j);
            swap(s[i], s[j]);
        }
    }
    printf("%d\n", ans);
    printf("%d %d\n", ansL, ansR);

    return 0;
}

/*
10
()()()()()
 */