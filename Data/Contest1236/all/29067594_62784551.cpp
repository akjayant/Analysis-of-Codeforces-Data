#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int sum=0;
        if(2*b>=c)
        {
            b-=c/2;
            sum+=c/2*3;
        }
        else
        {
            sum+=b*3;
            b=0;
        }
        if(a*2>=b)
        {
            a-=b/2;
            sum+=b/2*3;
        }
        else sum+=a*3;
        cout<<sum<<endl;
    }
    return 0;
}
