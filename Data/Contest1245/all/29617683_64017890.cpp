#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
#define maxm 200005
#define INF 1234567890
#define p 1000000007
string s;
char pre='0';
ll ans=1,tot,dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    dp[0]=dp[1]=1;
    for(ll i=2;i<maxn;i++)
        dp[i]=(dp[i-1]+dp[i-2])%p;
    cin>>s;
    for(ll i=0,j;s[i]!='\0';i++)
    {
        j=i;
        if(s[i]=='u')
        {
            while(s[i]=='u')i++;
            i--;
        }
        else if(s[i]=='n')
        {
            while(s[i]=='n')i++;
            i--;
        }
        else if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<endl;
            return 0;
        }
        ans=(ans*dp[i-j+1])%p;
        if(s[i]=='\0')break;
    }
    cout<<ans<<endl;
    return 0;
}
