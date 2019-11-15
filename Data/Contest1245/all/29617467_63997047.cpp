#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b==0? a : gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        int x = gcd(a, b);
        if (x==1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
        
    }
}