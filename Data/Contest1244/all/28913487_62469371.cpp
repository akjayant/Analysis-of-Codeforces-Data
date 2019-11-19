#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int num1 = (a+c-1)/c;
        int num2 = (b+d-1)/d;
        if(num1+num2 > k)
            cout<<-1<<endl;
        else
            cout<<num1<<' '<<num2<<endl;
    }
    return 0;
}
