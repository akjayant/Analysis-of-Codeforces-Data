 #include<bits/stdc++.h>
    #include <fstream>
    #define ll long long

    using namespace std;



    int main(){

ll k , b;
cin >> k;
for ( int o = 1 ; o <= k ; o++ )
{
    ll n;
cin >> n;
vector < ll > a(n+1,0);
for( int i = 1 ; i <= n ; i++ )
{
    cin >> a[i];
}
sort(a.begin(),a.end());
ll ans = 0;
for ( int i = 1 ; i <= n ; i++ )
{
    ans=max(ans,min(n-i+1,a[i]));
}
cout << ans << endl;

}









    return 0;
    }
