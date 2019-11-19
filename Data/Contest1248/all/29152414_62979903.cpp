#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<utility>
#include<set>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
    long long int n,m;
    cin>>n;
    long long int a[n];
    long long int pe=0,po=0,qe=0,qo=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        pe++;
        else po++;
    }
    cin>>m;
    long long int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        if(b[i]%2==0)
        qe++;
        else
        qo++;
    }
    long long int ans=pe*qe+po*qo;
    cout<<ans<<endl;
}
return 0;
}
