#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6;

char str[N];

int main() {
    // freopen("in.txt", "r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> str + 1;

    pair<int, int> ans2 = {1, 1};
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = i;j <= n;j ++) {
    // for(int i = 1;i <= 1;i ++) {
    //     for(int j = i;j <= 1;j ++) {
            int res = 0;
            swap(str[i], str[j]);
            int cot0 = 0, cot1 = 0;
            // cot0 )  cot1 (
            for(int k = 1;k <= n;k ++) {
                if(str[k] == ')') {
                    if(cot1) cot1 --;
                    else cot0 ++;
                }
                else cot1 ++;
            }
            // updata
            // cout << i << " " << j << " " << cot0 << " " << cot1 << endl;
            if(cot0 || cot1) {
                if(cot0 != cot1) res = 0;
                else {
                    int ss = cot0, tmp, top = 0;
                    for(int k = n;k >= 1;k --) {
                        if(str[k] == '(') ss --; else ss ++;

                        if(ss == 0) {
                            tmp = k;
                            break;
                        }
                    }
                    tmp --;
                    // cout << tmp << endl;
                    for(int k = tmp;k >= 1;k --) {
                        if(str[k] == ')') {
                            if(!top) res ++;
                            top ++;
                        }
                        else top --;
                    }
                }
            }
            else {
                int top = 0;
                for(int k = 1;k <= n;k ++) {
                    if(str[k] == '(') {
                        if(!top) res ++;
                        top ++;
                    }
                    else top --;
                }
            }
            if(res > ans) {
                ans = res;
                ans2 = {i, j};
            }
            swap(str[i], str[j]);
        }
    }
    cout << ans << endl;
    cout << ans2.first << " " << ans2.second << endl;

    return 0;
}