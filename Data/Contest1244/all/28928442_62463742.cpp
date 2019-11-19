// Need to git gud and reach 1900+
#include <bits/stdc++.h>
using namespace std;

#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

int n;

main(){ // If you don't know what to do, check the text box at the bottom
    int t;
    cin >> t;
    while (t-- ){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int g1 = ((a + c - 1) / c);
        int g2 = ((b + d - 1) / d);
        if (g1 + g2 <= k){
            cout << g1 << ' ' << g2 << endl;
        }
        else
            puts("-1");


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
