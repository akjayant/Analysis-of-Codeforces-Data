#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, a, b, c, d, k ;
int main()
{
    IO
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int s=(a+c-1)/c+(b+d-1)/d;
        if(s>k)
            cout<<-1<<endl;
        else
            cout<<(a+c-1)/c<<" "<<(b+d-1)/d<<endl;
    }
}
