#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < _n; ++i)
#define FJ(_n) for(int j = 0; j < _n; ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int l;
    cin >> l;
    while (l--)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<int> pos;
        FI(n)
            if(s[i] != t[i])
                pos.pb(i);
        if (pos.size() != 2 || s[pos[0]] != s[pos[1]] || t[pos[0]] != t[pos[1]])
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}
