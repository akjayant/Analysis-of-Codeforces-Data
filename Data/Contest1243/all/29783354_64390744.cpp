 #include<bits/stdc++.h>
    #include <fstream>
    #define ll long long
#define f first
#define s second
    using namespace std;



    int main(){

ll n ;
cin >> n;
ll p1 = 0 , p2 = 0;
for ( int i = 2 ; i <= sqrt(n+1) ; i++ )
{
    if (n%i==0) {p1 = i;while(n%i==0) n/=i;break;}
}
if (p1==0) {cout << n ; return 0;}
if (n==1) {cout << p1 ; return 0;}
cout << 1;










    return 0;
    }
