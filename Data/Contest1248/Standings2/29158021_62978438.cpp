// Need to git gud and reach 1900+
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >
#define prev prev123
#define next next123
#define pow pow123
#define left left123
#define right right123

const int N = 2e5 + 7;
const int INF = 1e9 + 7;

int x[N], y[N];
int q;

main(){ // If you don't know what to do, check the text box at the bottom
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        int ec, oc;
        ec = oc = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &x[i]);
            if (x[i] % 2 == 0)
                ec++;
            else
                oc++;
        }
        int m;
        cin >> m;
        ll ans = 0;
        for (int i = 1; i <= m; i++){
            scanf("%d", &y[i]);
            if (y[i] % 2 == 0)
                ans += ec;
            else
                ans += oc;
        }
        cout << ans << endl;
    }
}

/*
    Totally not inspired by BenQ's template
    Things you should do:
    1. Look for stupid typos in code e.g 1 instead of -1 etc
    2. Check if there is no infinite loops
    3. "Measure twice, cut once"
    4. Stay focused
*/

