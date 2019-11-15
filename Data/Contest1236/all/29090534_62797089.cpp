#include <iostream>
#define mod 1000000007;
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%2==1)
                cout<<(j-1)*n+i;
            else
                cout<<j*n-i+1;
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
