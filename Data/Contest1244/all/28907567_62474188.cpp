#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        string a;
        cin>>a;
        lli i,ans1=0,ans2=0,ma1=-1,ma2=-1,ma;
        for(i=0;i<n;i++)
        {
            if(a[i]=='1') ans1+=2;
            else ans1+=1;
            if(a[i]=='1') ma1=i;
        }//cout<<ans1<<" ";
        for(i=n-1;i>=0;i--)
        {
            if(a[i]=='1') 
            {
                ma2=n-1-i;
            }
        }//cout<<ma1<<" "<<ma2<<" ";
        if(ma1>ma2)
        {
            ans2=(ma1+1)*2;
        }
        else
        {
            ans2=(ma2+1)*2;
        }
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}