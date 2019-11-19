#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ll long long
#define ld long double
#define vi   vector<int>
#define pii pair<int, int>
#define ull unsigned long long
#define sz(v)  ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
#define MEM(dp,i) memset(dp ,i, sizeof (dp))
#define repit( cont , i  ) for( auto i : cont)
#define forr(c,x,n)   for(ll c=x;c<=(ll)n; ++c )
#define forrr(c,x,n)  for(ll c=x;c>=( ll )n ;--c )
#define db(x) cout << " LOOK " <<(#x) <<" = " <<  x << '\n'
#define ICPC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define printarr(a , l , r ) forr ( i , l , r )cout << a[i] << " ";cout<<endl;
#define printarr2(a, n , m) forr ( i , 1 , n){forr ( j , 1, m )cout << a[i][j] << " ";cout<<endl;}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);


int p[] = { 0 , 1 , 2} ;
int a[3][100007];
vector < int > v[100007];
vector <int > nod ;
void dfs ( int x , int p )
{
    nod.push_back(x);
    for ( auto i : v[x] )
    {
        if ( i != p  )
            dfs( i , x );
    }
}
int main()
{
ICPC;
int n ;
cin >> n ;
for (int i = 0 ; i < 3;  i++ )
    for ( int j = 1 ; j <= n ;  j++ )
        cin >> a[i][j];


for (int i = 0  ; i < n-1 ; i++ )
{
    int x , y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
}
int idx = -1;
for ( int i = 1 ; i <= n;  i++ )
{
    if ( v[i].size() >= 3 )
        return cout << -1 , 0 ;
    if ( v[i].size() == 1 )
        idx = i ;
}
dfs( idx , -1  );

int ansp[3];
ll mn = 1e18;
do{
  ll sum = 0 ;
 for ( int i = 0 ; i < n ; i++ )
  sum += a[p[i%3]][nod[i]];


  if ( sum < mn )
  {
      mn = sum;
      for ( int j = 0; j < 3;  j++ )
        ansp[j] = p[j];
  }

}while ( next_permutation( p , p+3 ));

int nodp[100007];
for ( int i = 0 ; i < n ; i++ )
 nodp[nod[i]] = ansp[i % 3 ] + 1 ;

cout << mn  << endl;
for ( int i = 1 ; i <= n ; i++ )
    cout << nodp[i] << " ";
}
