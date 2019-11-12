#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int group[n][n];
    int count=1;
    bool flag=0;
    for(int j=0;j<n;j++)
    {
        if(flag==0)
        {
            for(int i=0;i<n;i++)
                group[i][j]=count++;
            flag=1;
            continue;
        }
        for(int i=n-1;i>=0;i--)
            group[i][j]=count++;
        flag=0;

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<group[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}