#include <bits\stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long LL;
typedef pair<int, int> pii;
int n;
LL k;
int a[maxn];
pii b[maxn];
int main()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    register int cnt;
    int head, tail;
    tail = 0;
    for (int i = 1; i <= n;) {
        cnt = 1;
        while (++i <= n && a[i] == a[i - 1])
            cnt++;
        b[++tail] = make_pair(a[i - 1], cnt);
    }
    if (tail == 1) {
        printf("0\n");
        return 0;
    }
    LL sum = k;
    head = 1;
    while (head < tail) {
        if (b[head].second < b[tail].second) {
            LL cnt = LL(b[head + 1].first - b[head].first) * b[head].second;
            if (cnt <= sum){
                sum -= cnt;
                head++;
                b[head].second += b[head - 1].second;
            }
            else{
                b[head].first += sum / b[head].second;
                break;
            }
        }
        else{
            LL cnt = LL(b[tail].first - b[tail-1].first) * b[tail].second;
            if (cnt <= sum){
                sum -= cnt;
                tail--;
                b[tail].second += b[tail + 1].second;
            }
            else{
                b[tail].first -= sum / b[tail].second;
                break;
            }
        }
    }
    printf("%d\n", b[tail].first - b[head].first);
    return 0;
}