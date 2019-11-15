#include<iostream>


int gcd(int x, int y)
{
    int z = y;
    while(x%y!=0)
    {
        z = x%y;
        x = y;
        y = z;
    }
    return z;
}

using namespace std;
int t;
int a, b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(gcd(a, b) != 1)
        {
            cout<<"Infinite"<<endl;
        }
        else
        {
            cout<<"Finite"<<endl;
        }
    }
    return 0;
}
