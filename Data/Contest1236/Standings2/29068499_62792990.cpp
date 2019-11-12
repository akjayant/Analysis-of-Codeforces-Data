#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans[310];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2==0)
                ans[j-1].push_back(i*n+j);
            else
                ans[n-j].push_back(i*n+j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}
