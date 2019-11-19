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
int a , ans;
cin >> a;
const int A = a ;
int mas[A];
for(int i = 0; i < a ; ++i)
    cin >> mas[i];

    sort(mas , mas + a);



    int sh1 = 0;
    int sh2 = 0;


    

    for(int i = 0 ; i < a/2; ++ i)
        sh1+=mas[i];
    for(int i = a/2 ; i < a ;++ i)
        sh2+=mas[i];



    cout << sh1*sh1 + sh2*sh2;
}

