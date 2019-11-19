#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;
  
int h[12][12];

ld e[12][12];

void advance(int& i, int& j) {
    if (i % 2) {
        if (j == 9) i--;
        else j++;
    } else {
        if (j == 0) i--;
        else j--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> h[i][j];

    e[0][0] = 0;
    for (int i = 0; i < 10; i++) {
        int j;
        if (i == 0) j = 1;
        else if (i % 2) j = 9;
        else j = 0;

        while (true) {
            int possible = 0;
            ld sum_e = 0;

            int i1 = i, j1 = j;

            for (int k = 1; k <= 6; k++) {
                if (i == 0 && k > j) break;
                possible++;
            
                advance(i1, j1);
                int i2 = i1 - h[i1][j1];
                int j2 = j1;

                sum_e += min(e[i1][j1], e[i2][j2]);
            }

            e[i][j] = (sum_e + (ld)6) / (ld)possible;

            if (i % 2) j--;
            else j++;

            if (j == -1 || j == 10) break;
        }
    }

    cout << fixed << setprecision(10) << e[9][0];

    return 0;
}

