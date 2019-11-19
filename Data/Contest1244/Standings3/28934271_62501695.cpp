#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define endl '\n'
int32_t main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int l=0;
    int r=n-1;
    int currl=v[0];
    int currr=v[n-1];
    int count1=1;
    int count2=1;
    int ans=v[n-1]-v[0];
    while(l<r&&k>0)
    {
        if(count1>count2)
        {
            int req=(currr-v[r-1])*count2;
            if(k>=req)
            {
                k-=req;
                count2++;
                currr=v[r-1];
                ans=min(ans,currr-currl);
                r--;
                continue;
            }
            currr-=k/count2;
            ans=min(ans,currr-currl);
            break;
        }
        int req=(v[l+1]-currl)*count1;
        if(k>=req)
        {
            k-=req;
            count1++;
            currl=v[l+1];
            ans=min(ans,currr-currl);
            l++;    
            continue;
        }
        currl+=k/count1;
        ans=min(ans,currr-currl);
        break;
    }
    cout<<ans;
}
    