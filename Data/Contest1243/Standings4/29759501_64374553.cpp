#include <bits/stdc++.h>

using namespace std;

int A[2000];

int main()
{
    int t;
    for(cin >> t; t--; ){
        int n;
        cin >> n;
        for( int i = 0; i < n; i++ ){
            cin >> A[i];
        }
        int res = 0;
        for( int i = 0; i < n; i++ ){
            int cnt = 0;
            for( int j = 0; j < n; j++ )
                if( A[j] >= A[i] )
                    cnt++;
            res = max(res, min(cnt, A[i]));
        }
        cout << res << endl;
    }

    return 0;
}