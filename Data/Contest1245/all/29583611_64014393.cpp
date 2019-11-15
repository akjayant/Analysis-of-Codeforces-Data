#include <bits/stdc++.h>
#define MAX 100 * 10000

using namespace std;

int col[MAX];

int gcd( int a, int b){
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int t;
    for(cin >> t; t--; ){
        int a, b;
        memset(col, -1, sizeof col);
        cin >> a >> b;
        /*
        for( int i = 0; i < MAX; i++ ){
            if( i == 0 )
                col[i] = 0;
            else if( i >= a && col[i - a] == 0 )
                col[i] = 0;
            else
                if( i >= b && col[i - b] == 0 )
                col[i] = 0;
            else
                col[i] = 1;
        }
        */
        string res = "Finite";
        /*for( int i = MAX - 20000; i < MAX; i++ )
            if(col[i]){
                res = "Infinite";
            }
        */
        if( gcd(a, b) != 1)
            res = "Infinite";
        cout << res << endl;
    }
    return 0;
}