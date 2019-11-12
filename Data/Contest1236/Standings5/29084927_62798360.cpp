#include <bits/stdc++.h>
   #define f first
    #define s second
    #define int long long
    #define ll long long
    using namespace std;
int modexp(int x, int y, int N)
{
  if (y == 0) return 1;
  int z = modexp(x, y / 2, N);
  ll z1 = z*z%N;
  if (y % 2 == 0)
    return z1 % N;
  else
    return (x*z1) % N;
}
  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

ll n;
cin >> n ;
vector < vector < ll > > a(n+1);
ll cur = 1 , now = 1;
for ( int j = 1 ; j <= n ; j++ )
{
    if (now == 1)
    {for ( int i = j ; i <= n ; i++ )
    {
        a[i].push_back(cur);
        cur++;
    }
    for ( int i = 1 ; i < j ; i++ )
    {
        a[i].push_back(cur);
        cur++;
    }
    now = 2;
    }
    else
    {
        for ( int i = j ; i >= 1 ; i-- )
    {
        a[i].push_back(cur);
        cur++;
    }
    for ( int i = n ; i > j ; i-- )
    {
        a[i].push_back(cur);
        cur++;
    }
    now = 1;
    }
}
for ( int i = 1 ; i <= n ; i++ )
{
    for ( int j = 0 ; j < n ; j++ )
    {
        cout << a[i][j] << " ";
    }
    cout << endl;
}

 }
