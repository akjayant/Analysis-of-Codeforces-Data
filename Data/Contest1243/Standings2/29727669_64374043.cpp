#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<int,pi>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int t;
int a[1010],suf[1010];
int main()
{
    go;
    cin>>t;
    while(t--)
    {
        int x,n,ans=0;
        cin>>n;
        memset(suf,0,sizeof suf);
        for(int i=0;i<n;i++)
            cin>>a[i],suf[a[i]]++;
        for(int i=1000;i>=0;i--)
        {
            suf[i]+=suf[i+1];
            if(suf[i]>=i)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
