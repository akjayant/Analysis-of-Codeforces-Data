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

ll a,b,c;
cin >> a >> b ;
ll mod=1e9+7;
cout << modexp(modexp(2,b,mod)-1,a,mod);


 }
