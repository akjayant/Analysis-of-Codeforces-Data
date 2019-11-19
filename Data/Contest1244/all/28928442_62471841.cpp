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
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        if (l == -1)
            cout << n << endl;
        else {
            int r1 = r + 1 + max(r + 1, n - r);
            int r2 = n - l + max(l + 1, n - l);
            cout << max(r1, r2) << endl;
        }
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
