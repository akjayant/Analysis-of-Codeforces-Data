#include <bits/stdc++.h>
using namespace std;

///Fastio (using only for int)
///Don't use (#define int long long)
void fin(int &a) {
    a = 0;
    char c = getchar();
    bool neg = false;
    while(c < '1' && c > '9' && c != '-')
        c = getchar();
    if(c == '-')
        neg = true, c = getchar();
    while(c != ' ' && c != '\n' && c != EOF)
        a = a * 10 + (c - 48), c = getchar();
    if(neg == true)
        a = -a;
}

void fout(int a) {
    if(a < 0)
        putchar('-');
    if(a == 0) {
        putchar('0');
        return ;
    }
    vector < char > v;
    while(a != 0)
        v.push_back(char(a % 10 + 48)), a = a / 10;
    for(int i = v.size() - 1; i >= 0; i--)
        putchar(v[i]);
}

void fout(string a) {
    for(int i = 0; i < a.size(); i++)
        putchar(a[i]);
}

///End of fastio

#define task ""
#define maxn 100005
#define ll long long
#define mod 1000000007
#define pii pair <int, int>
#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)

int n, a[maxn], res, t;

main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int minn = INT_MAX, res = -1;
        for(int i = n; i >= 1; i--) {
            res = max(res, min(a[i], n - i + 1));
        }
        cout << res << "\n";
    }
}
