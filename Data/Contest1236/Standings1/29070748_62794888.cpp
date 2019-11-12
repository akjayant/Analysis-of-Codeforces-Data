#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t=n*n-i;
        for(int j=0;j<n;j++)
        {
            cout<<t<<' ';
            t=t-2*((t-1)%n)-1;

        }
        cout<<'\n';
    }
}
