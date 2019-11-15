/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
int cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    please followmeoninsta
    int t;
    cin >> t;
    for(; t; --t)
    {
        int a, b;
        cin >> a >> b;
        if(cmmdc(a, b) == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }
    return 0;
}
