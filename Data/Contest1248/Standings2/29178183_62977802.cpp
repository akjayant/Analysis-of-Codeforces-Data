#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < (_n); ++i)
#define FJ(_n) for(int j = 0; j < (_n); ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int n;
    cin >> n;
    vector <ll> a(n);
    for (auto& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    int k1 = a.size() / 2 + (a.size() & 1);
    int k2 = a.size() / 2;
    ll d1 = 0;
    ll d2 = 0;
    FI(k1)
        d1 += a[a.size() - i - 1];
    FI(k2)
        d2 += a[i];
    cout << d1 * d1 + d2 * d2;

    return 0;
}
