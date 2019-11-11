#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a, b;
        cin>>a>>b;

        printf("%s\n", __gcd(a, b) != 1? "Infinite": "Finite");
    }

    return 0;
}
