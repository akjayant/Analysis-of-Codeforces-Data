#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(__gcd(x,y) == 1)
        {
            cout<<"Finite\n";
        }
        else
            cout<<"Infinite\n";
    }
    return 0;
}
