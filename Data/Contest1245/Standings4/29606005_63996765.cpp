#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;

int f(int a,int b)
{
    while(a!=0)
    {
        b%=a;
        swap(a,b);
    }
    return b;
}

int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a,b;
    cin >> a >> b;
    if(f(a,b) == 1)
    {
        cout << "Finite\n";
    }
    else
    {
        cout << "Infinite\n";
    }

    }

    return 0;
}
