#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int gcd(int a,int b)
{
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(gcd(a,b) == 1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;
}
