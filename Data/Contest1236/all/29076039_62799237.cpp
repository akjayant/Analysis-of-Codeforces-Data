#include <cstdio>
#include <algorithm>
using namespace std;

int a[310][310];

int main() {
    int n;
    scanf("%d", &n);
    int cur = 0;
    for(int j=1; j<=n; j++) {
        if(j&1) {
            for(int i=1; i<=n; i++)
                a[i][j] = ++cur;
        }
        else {
            for(int i=n; i>=1; i--)
                a[i][j] = ++cur;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}