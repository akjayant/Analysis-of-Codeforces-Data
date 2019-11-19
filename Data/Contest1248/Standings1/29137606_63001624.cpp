#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int l, top, res, maxb, cnt;
char a[maxn];
char sta[maxn];
deque<char> deq;

int main() {
    cin >> l;
    scanf("%s", a);
    inc(i, 0, l - 1) cnt += a[i] == '(' ? 1 : 0;
    if (cnt * 2 != l) {
        printf("0\n1 1");
        return 0;
    }
    inc(i, l, 2 * l - 1) a[i] = a[i - l];
    inc(i, 0, l - 1) {
        inc(j, i, l - 1) {
            if (a[i] == a[j] && i > 0) continue;
            swap(a[i], a[j]);
            swap(a[i + l], a[j + l]);
            deq.clear();
            int beauty = 0;
            inc(I, l, 2 * l - 1) {
                if (deq.size() == 0 || deq.back() == ')' || a[I] == '(')
                    deq.push_back(a[I]);
                else
                    deq.pop_back();
            }
            if (deq.size() == 0) beauty++;
            dec(k, l - 1, 1) {
                /*top = 0;
                inc(I, k, k + l - 1) {
                    if (top == 0 || sta[top - 1] == ')' || a[I] == '(')
                        sta[top++] = a[I];
                    else
                        top--;
                }
                if (top == 0) beauty++;*/
                if (a[k + l] == '(')
                    deq.pop_back();
                else
                    deq.push_back('(');
                if (deq.size() == 0 || deq.front() == '(' || a[k] == ')')
                    deq.push_front(a[k]);
                else
                    deq.pop_back();
                if (deq.size() == 0) beauty++;
            }
            if (beauty >= maxb) {
                maxb = beauty;
                res = i * l + j;
            }
            swap(a[i], a[j]);
            swap(a[i + l], a[j + l]);
        }
    }
    printf("%d\n%d %d", maxb, res / l + 1, res % l + 1);
}