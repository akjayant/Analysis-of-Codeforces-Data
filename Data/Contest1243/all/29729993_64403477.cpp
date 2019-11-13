#include<bits/stdc++.h>
using namespace std;

# define C continue;
# define R return

# define D double
# define I insert
# define ll long long
# define ld long double

# define ull unsigned long long
# define ui unsigned int

# define pb push_back
# define pf push_front

# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >

# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";

string vow = "aeiou";

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 0 , 1 } ;
const int dy[] = { 0 , -1 , 1 , 0 } ;

const ld pie = 3.14159265358979 ;
const ll mod = 1e9 + 7 ;

void solve ( int test_case )
{
    int n ; cin >> n ;
    string s , t ;
    cin >> s >> t ;

    int h[26] = {} ;
    for ( auto i : s ) h[i-'a'] ++ ;
    for ( auto i : t ) h[i-'a'] ++ ;

    int i=0 ;
    for ( ; i < 26 && h[i]%2==0 ; i++ ) ;

    if ( i < 26 ) { cout << "No" ; line ; R ; }

    cout << "Yes\n" ;

    vpii v ;
    while ( s != t )
    {
        int i=0 ;
        for ( ; i < n && s[i] == t[i] ; i++ ) ;

        int j = i + 1 ;
        for ( ; j < n && s[j] != s[i] ; j++ ) ;

        if ( j < n )
        {
            v.pb(mp( j , i )) ;
            swap ( s[j] , t[i] ) ;
            C ;
        }

        j = i + 1 ;
        for ( ; j < n && t[j] != t[i] ; j++ ) ;

        if ( j < n )
        {
            v.pb(mp ( i , j ) );
            swap ( s[i] , t[j] ) ;
            C ;
        }

        j = i + 1 ;
        for ( ; j < n && t[j] != s[i] ; j++ ) ;

        v.pb(mp ( i+1 , j ) ) ;
        swap ( s[i+1] , t[j] ) ;

        v.pb ( mp ( i+1 , i ) ) ;
        swap ( s[i+1] , t[i] ) ;
    }

    cout << v.size() ; line
    for ( auto i : v ) cout << i.F + 1 << " " << i.S + 1 , line
}

int main()
{fast
    int t = 1;
    cin >> t;

    for ( int i=0 ; i < t ; i++ ) solve(i);
    return 0;
}
