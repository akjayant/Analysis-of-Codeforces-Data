#include <bits/stdc++.h>
using namespace std;
long long n,a,o[2],e[2];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        o[1]=0;o[0]=0;
        e[1]=0;e[0]=0;
        for(int j=0;j<2;j++){
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2)o[j]++;
            else e[j]++;
        }
        }
        //cout<<o[0]<<" "<<o[1]<<" "<<e[0]<<" "<<e[1]<<" ";
        cout<<o[0]*o[1]+e[0]*e[1]<<"\n";
    }
}
