#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int N = 100000 + 5;

int n;
int a[N];
int dd[N];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    int l = 0, r = 0;
    while(true)
    {
        if(dd[j]) break;
        dd[j] = 1;
        l += a[j];
        j -= 1;

        if(dd[i]) break;
        dd[i] = 1;
        r += a[i];
        i += 1;
    }
    cout << (1ll * l * l) + (1ll * r * r);

}

/**
    Code by: Best_Nakroth 12TH.


*/
