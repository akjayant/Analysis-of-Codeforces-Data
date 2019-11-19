#include <cstdio>
#include <algorithm>

using namespace std;

int T, n;
char s[1005];

int main() {
    scanf("%d", &T);
    while (T--) {
        int cnt = 0, ml = 0, mr = 0;
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++)
            if (s[i] == '1')
                cnt++;
        for (int i = 1; i <= n; i++)
            if (s[i] == '1') {
                mr = i;
                if (!ml)
                    ml = i;
            }
        printf("%d\n", cnt == 0 ? n : max(cnt + n, 2 * max(mr, n - ml + 1)));
    }
    return 0;
}