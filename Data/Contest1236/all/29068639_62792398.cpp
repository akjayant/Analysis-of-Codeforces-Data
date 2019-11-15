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

int poww( int a, int b ){
    //cout << a << ' '<< b << endl;
    if( a == 0 )
        return 1;
    if( a % 2 == 0 ){
        int x = poww( a/2,b );
        return (x*1ll*x)%mod;
    }else{
        int x = poww( a/2,b );
        return ((1ll*x*b)%mod*x)%mod;
    }
}

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

    int n, m;
    cin >> n >> m;
    cout << poww(n, ( poww(m,2)-1 ));
    return 0;
}


