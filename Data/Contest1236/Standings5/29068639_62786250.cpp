# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <string>
# include <set>
# include <map>
# include <bitset>
# include <queue>
# include <iomanip>
# include <string>

# define FILE

using namespace std;

int main()
{
    # ifdef FILEs
        freopen( "ANSWER.IN", "r", stdin );
        freopen( "ANSWER.OUT", "w", stdout );
    # endif // FILE

    # ifdef FILEs
        freopen( "input.txt", "r", stdin );
        freopen( "output.txt", "w", stdout );
    # endif // FILE
    ios_base::sync_with_stdio( false );

    int t;
    cin >> t;
    while( t -- ){
        int a,b,c, ans = 0;
        cin >> a >> b >> c;
        for( int i = 0; i <= 100; i ++ ){
            for( int j = 0; j <= 100; j ++ ){
                int x = min(min( i, a ), min( b/2, i ));
                int y = b - x*2;
                int z = min( min(j, y), min( c/2, j ) );
                ans = max( ans, x*3+z*3 );
            }
        }
        cout << ans << endl;
    }
    return 0;
}


