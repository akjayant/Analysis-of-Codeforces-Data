#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000;
int n;
char b[MAXN];

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        int min_dis = n;
        for (int i = 0; i < n; i++) {
            scanf("%c", &(b[i]));
            if (b[i] == '1') {
                if (i < min_dis) {
                    min_dis = i;
                }
                if (n - 1 - i < min_dis) {
                    min_dis = n - 1 - i;
                }
            }
        }
        if (min_dis == n) {
            printf("%d\n", n);
        } else {
            printf("%d\n", (n - min_dis) * 2);
        }
    }
    return 0;
}
