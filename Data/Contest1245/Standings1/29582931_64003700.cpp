#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
  
int add(int a, int b) {return (a + b) % MOD;}
int mul(int a, int b) {return ((ll)a * b) % MOD;}

int n, fib[MAXN];
string s;
int sol;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAXN; i++)
        fib[i] = add(fib[i-1], fib[i-2]);

    cin >> s;
    s += 'a';
    int len = 0;
    char c = 'a';

    sol = 1;

    for (char x : s) {
        if (x == c) {
            len++;
        } else {
            if (c == 'n' || c == 'u')
                sol = mul(sol, fib[len]);
            c = x;
            len = 1;
        }

        if (x == 'm' || x == 'w') sol = 0;
    }

    cout << sol;


    return 0;
}

