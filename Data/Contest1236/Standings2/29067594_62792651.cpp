#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500;
vector<int> a[maxn];
int main()
{
    int n;
    cin>>n;
    int j=1, k=1;
    for(int i=1; i<=n*n; i++)
    {
        if(j>0 && j<=n)
        {
            a[j].push_back(i);
            j+=k;
        }
        if(j==0) { j=1; k*=-1; }
        if(j==n+1) { j=n; k*=-1; }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<a[i].size(); j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
