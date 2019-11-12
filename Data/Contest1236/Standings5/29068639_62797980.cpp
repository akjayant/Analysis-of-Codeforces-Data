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

const int mod = 1e9+7;

int n;
vector < int > gr[600];

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

    cin >> n;
    int id = 1, sp = -1;
    for( int i = n*n; i >= 1; i -- ){
        if( i % n == 0 ){
            if( i != n*n )
                id -= sp;
            sp = -sp;

        }
        gr[id].push_back( i );
        id += sp;
    }
    for( int i = 1; i <= n; i ++ ){
        for( auto c: gr[i] ){
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}


