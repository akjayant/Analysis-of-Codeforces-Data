#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    for(int i= 0; i < t; i++){
        int a,b;
        cin >> a >> b;
        if(a ==1 || b == 1){
            cout << "Finite" << endl;
        }
        else{
            bool teilt = gcd(a,b) != 1;
            cout << (teilt ? "Infinite" : "Finite") << endl;
        }

    }
    return 0;
}
