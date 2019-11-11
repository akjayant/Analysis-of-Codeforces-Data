#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int& a, int b) { a = add(a, b); }
void subs(int& a, int b) { a = sub(a, b); }
void muls(int& a, int b) { a = mul(a, b); }
void maxs(int& a, int b) { a = max(a, b); }
void mins(int& a, int b) { a = min(a, b); }
int pwr(int a, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int fib[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for (char c : s)
        if (c == 'm' || c == 'w')
            return cout << 0, 0;

    s.push_back('a');
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 100000; ++i)
        fib[i] = add(fib[i - 1], fib[i - 2]);

    int n = s.size();
    int cnt = 1, sol = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            if (s[i - 1] == 'u' || s[i - 1] == 'n')
                muls(sol, fib[cnt]);
            cnt = 1;
        }
    }
    cout << sol;
}
