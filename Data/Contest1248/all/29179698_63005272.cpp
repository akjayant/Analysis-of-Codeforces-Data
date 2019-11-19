#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<string>

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int inf = 2e9;
const long long onf = 1e18;
#define me(a, b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI 3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n, m;
string str, temp;
ll a[maxn], sum[maxn];

int check(int x, int y) {
    //temp = str;
    swap(temp[x], temp[y]);
    swap(temp[x + n], temp[y + n]);
    // cout << temp << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        if (temp[i] == ')')
            continue;
        for (int j = i; j < i + n;) {
            if (temp[j] == '(') {
                int s1 = 1;
                while (s1 && j < i + n) {
                    if (temp[++j] == '(')
                        s1++;
                    else
                        s1--;
                }
                s++;
                if (temp[++j] == ')') {
                    s = 0;
                    break;
                }
            } else {
                s = 0;
                break;
            }
        }
        sum = max(sum, s);
        if (sum) {
            swap(temp[x], temp[y]);
            swap(temp[x + n], temp[y + n]);
            return sum;
        }

    }
    swap(temp[x], temp[y]);
    swap(temp[x + n], temp[y + n]);
    return sum;
}

void work() {
    while (cin >> n >> m) {
        if (n < m) swap(n, m);
        a[0] = 2, a[1] = 2, a[2] = 4;
        sum[0] = 0, sum[1] = 2, sum[2] = 4;
        for (int i = 3; i <= n; ++i)
            a[i] = (a[i - 1] + a[i - 2]) % mod, sum[i] = (sum[i - 1] + a[i - 1]) % mod;
        // cout<<a[4]<<" "<<sum[3]<<endl;
        cout << (a[n] + sum[m - 1]) % mod << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
#endif
    int t = 1, Case = 1;
    //cin >> t;
    while (t--) {
        //  printf("Case %d: ", Case++);
        work();
    }
    return 0;
}