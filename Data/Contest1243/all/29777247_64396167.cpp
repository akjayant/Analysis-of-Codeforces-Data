#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define N 1010010
#define M 2000100
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1);
#define fi first
#define se second
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)

long long n, x, fac[50], num;
int cnt, pri[N / 10];
bool isnpri[N];

void init()
{
    isnpri[1] = true;
    for(int i = 2; i < N; i++) {
        if(!isnpri[i]) {
            pri[cnt++] = i;
        }
        for(int j = 0; j < cnt && (long long)i * pri[j] < N; j++) {
            isnpri[i * pri[j]] = true;
            if(i % pri[j] == 0) {
                break;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
    #endif

    init();
    while(cin >> n) {
        x = n; num = 0;
        for(int i = 0; i < cnt && (long long)pri[i]*pri[i] <= x; i++) {
            if(x % pri[i] == 0) {
                while(x % pri[i] == 0) x /= pri[i];
                fac[num++] = pri[i];
            }
        }
        if(x > 1) fac[num++] = x;

        if(num == 1) {
            printf("%I64d\n", fac[0]);
        }
        else printf("1\n");
    }

    return 0;
}
