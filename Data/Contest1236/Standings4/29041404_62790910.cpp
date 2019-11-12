#include <bits/stdc++.h>
using namespace std;
long long base = 1000000007;
long long tinh( int x , int y)
{
    if ( y==1 ) return x;
    if ( y==0 ) return 1;
    long long res = tinh( x , y/2 );
    res = res * res ;
    res %= base ;
    if ( y%2 == 1 ) res *= x;
    res %= base ;
    return res;
}

long long n,m;
int F[1001];

int main()
{
    cin>>n>>m;

    for (int i=1;i<=110;i++) F[i] += 2;
    for (int i=1;i<=110;i++) F[i] += 3;
    for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;

    long long ans = 0;
    ans = tinh( 2 , m );
 for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;

    ans -= 1;
 for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;

    ans = tinh(  ans , n  );
 for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;

    cout<<ans;

    return 0;
}
