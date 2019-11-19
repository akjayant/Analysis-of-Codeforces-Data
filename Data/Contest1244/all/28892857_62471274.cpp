#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int t,n;
int main()
{
    go;
    cin>>t;
    while(t--)
    {
        int ans;
        cin>>n;
        ans=n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ans=max(ans,(i+1)*2);
                ans=max(ans,(n-i)*2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
