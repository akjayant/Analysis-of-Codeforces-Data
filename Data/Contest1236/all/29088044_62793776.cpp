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
    int n;
    cin >> n;

    for (int j = 1; j <= n; ++j){
        for (int i = 0; i < n; ++i){
            if (i & 1) cout << i*n + n - j + 1 << " ";
            else cout << i*n + j << " ";
        }

        cout << "\n";
    }

}   