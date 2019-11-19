#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int i,x,even=0,e=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            if((x%2)==0)
                even++;
        }
        long long int m;
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>x;
            if((x%2)==0)
                e++;
        }
        cout<<even*e+(n-even)*(m-e)<<"\n";
    }
    return 0;
}