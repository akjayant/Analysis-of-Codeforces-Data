#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;

const int INF=0x3f3f3f3f;
const int N=305;

int n;
int mat[N][N];

int main() {
    scanf("%d", &n);
    for (int j=1; j<=n; ++j) {
        if (j%2==0) {
            for (int i=1; i<=n; ++i) {
                mat[i][j]=(j-1)*n+i;
            }
        }
        else {
            int cnt=1;
            for (int i=n; i>=1; --i) {
                mat[i][j]=(j-1)*n+cnt;
                cnt++;
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
