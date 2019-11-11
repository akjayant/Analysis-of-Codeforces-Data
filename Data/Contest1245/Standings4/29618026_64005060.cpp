#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
int t,n,a,b,c,res;
string s;
string ans;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans.clear();
        res=0;
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='R'&&b>0)
            {
                b--;
                ans=ans+'P';
                res++;
            }
            else if(s[i]=='P'&&c>0)
            {
                c--;
                ans=ans+'S';
                res++;
            }
            else if(s[i]=='S'&&a>0)
            {
                a--;
                ans=ans+'R';
                res++;
            }
            else ans = ans + '0';
        }
        if(res*2 >= n)
        {
            cout<<"YES"<<endl;
            for (int i = 0; i < ans.size(); i++){
                if (ans[i] == '0'){
                    if (a>0) ans[i] = 'R',a--;
                    else if (b >0 ) ans[i] = 'P',b--;
                    else if (c >0) ans[i] = 'S',c--;
                }
            }
            cout<<ans<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
}
