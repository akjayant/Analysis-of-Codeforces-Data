#include <cstdio>
#include <algorithm>
#include <cctype>
using std::swap;

const int kLen = 505;
char str[kLen];
int sum[kLen];

void read_char(char& ch) {
    ch = getchar();
    while(isspace(ch)) {
        ch = getchar();
    }
}

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int len;
    scanf("%d", &len);
    for(int i = 1; i <= len; i++) {
        read_char(str[i]);
    }
    int left_bracket = 0, right_bracket = 0;
    for(int i = 1; i <= len; i++) {
        if(str[i] == '(') {
            left_bracket++;
        }
        else {
            right_bracket++;
        }
    }
    if(left_bracket != right_bracket) {
        printf("0\n1 1\n");
    } else {
        int ans = 0, ansl, ansr;
        for(int i = 1; i <= len; i++) {
            for(int j = i; j <= len; j++) {
                swap(str[i], str[j]);
                sum[0] = 0;
                int cnt = 1, mn = len;
                for(int k = 1; k <= len; k++) {
                    sum[k] = sum[k - 1] + (str[k] == '(' ? 1 : -1);
                    if(sum[k] < mn) {
                        cnt = 1;
                        mn = sum[k];
                    } else if(sum[k] == mn) {
                        cnt++;
                    }
                }
                if(cnt > ans) {
                    ans = cnt;
                    ansl = i;
                    ansr = j;
                }
                swap(str[i], str[j]);
            }
        }
        printf("%d\n%d %d\n", ans, ansl, ansr);
    }
    return 0;
}