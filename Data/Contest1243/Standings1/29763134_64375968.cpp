#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int an[2100];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,j,k;
        for(i = 0;i<n;i++)
            cin>>an[i];
        sort(an,an+n,cmp);
        int ans = 0;
        for(i = 0;i<n;i++)
        {
            int tmp = min(i+1,an[i]);
            ans = max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}
