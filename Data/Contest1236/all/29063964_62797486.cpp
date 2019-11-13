#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,n;
    cin>>n;

    vector<int> a(n*n);
    int count=1;
    for(i=0;i<(n*n);i++)
    {
        a[i]=count;
        count+=1;
    }
    vector<vector<int>> g(n);

    int var=(n*n)-1;
    int t=0;
    for(i=0;i<n;i++)
    {
        if(t==0)
        {
            for(j=0;j<n;j++)
            {
                g[j].push_back(a[var]);
                var-=1;
            }
        }
        else
        {
            for(j=n-1;j>=0;j--)
            {
                g[j].push_back(a[var]);
                var-=1;
            }
        }
        t=(t+1)%2;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }


}