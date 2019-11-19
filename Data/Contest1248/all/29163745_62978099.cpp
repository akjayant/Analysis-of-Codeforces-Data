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
        #define int long long
using namespace std;

 main() {
int t = 0;
cin >> t;
while(t--)
{
    int a = 0 , b = 0 , c =0 , d = 0;
    int n;
    int q;
    cin >> n;
    while(n--)
    {
        cin >>q;
        if(q%2==0)
            ++a;
        else ++b;
    }
    cin >> n;
    while(n--)
    {
        cin >>q;
        if(q%2==0)
            ++c;
        else ++d;
    }

    cout << a*c + b*d << endl;

}
}
