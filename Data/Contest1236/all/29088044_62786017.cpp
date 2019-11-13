#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;


int main (){
    int t;
    cin >> t;

    for (int cases = 0; cases < t; ++cases){
        int a, b, c;
        cin >> a >> b >> c;

        if (b*2 < c) cout << 3*b << endl;
        else {
            int rest = c/2;

            int ans = rest*3;
            b -= rest;

            int restb = b/2;

            cout << ans + min(3*a, 3*restb) << endl;
        }
    }
}  