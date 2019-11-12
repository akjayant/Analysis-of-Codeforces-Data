    #include <iostream>
        #include <cstdio>
        #include <map>
        #include <vector>
        #include <algorithm>
        #include <deque>
		#include <cmath>
        #include <set>
        #define ld long double
        #define ll long long
        #define cld const long double
        #define cll const long long
using namespace std;

int main() {

int t ; cin >>t ;
 while(t--)
 {
     int a , b , c ; cin >> a >> b >> c;
     int ans=0;
     ans+=3*min(b , c/2);
     int sh = min(b , c/2);
     b-=sh;
     c-=sh*2;

     ans+=3*min(a , b/2);

     cout << ans << endl;
 }
}

