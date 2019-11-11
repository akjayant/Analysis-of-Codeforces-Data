#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}
