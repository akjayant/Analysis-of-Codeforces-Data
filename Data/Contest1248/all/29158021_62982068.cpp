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

int a[N];
int n;

main(){ // If you don't know what to do, check the text box at the bottom
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ll lc = 0, rc = n + 1;
    ll ls = 0, rs = 0, it = 0;
    while (lc + 1 < rc){
        if (it % 2 == 0){
            rc--;
            rs += a[rc];
        }
        else {
            lc++;
            ls += a[lc];
        }
        it++;
    }
    cout << ls * ls + rs * rs;
}

/*
    Totally not inspired by BenQ's template
    Things you should do:
    1. Look for stupid typos in code e.g 1 instead of -1 etc
    2. Check if there is no infinite loops
    3. "Measure twice, cut once"
    4. Stay focused
*/

