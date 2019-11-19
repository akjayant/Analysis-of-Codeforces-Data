#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 100000
#define M 205

int main()
{
//    freopen("f.txt","r",stdin);
//    freopen("g.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d,k,x,y,t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>a>>s;
        int ans=a;
        for(int i=1; i<=a; i++)
        {
            if(s[i-1]=='1')
            {
                ans=max(ans,max((a-i+1)*2,i*2));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
