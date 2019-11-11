#include <bits/stdc++.h>
#define DIM 107
#define INF 1000000007
using namespace std;

long long t,n,a,b,c,ans[DIM];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>c>>b>>s;
        long long k = 0;
        memset(ans,0,sizeof(ans));
        for(int i = 0; i < s.size(); ++i)
            if(s[i]=='P')
            {
                if(b>0)
                {
                    k++;
                    b--;
                    ans[i] = 2;
                }
            }
            else if(s[i]=='S')
            {
                if(a>0)
                {
                    k++;
                    a--;
                    ans[i] = 1;
                }
            }
            else
            {
                if(c>0)
                {
                    k++;
                    c--;
                    ans[i] = 3;
                }
            }
        if(k>=(n+1)/2)
        {
            cout<<"YES"<<endl;
            for(int i = 0; i < n; ++i)
                if(ans[i])
                {
                    if(ans[i] == 1) cout<<'R';
                    else if(ans[i]==2) cout<<'S';
                    else cout<<'P';
                }
                else
                {
                    if(a)
                    {
                        cout<<'R';
                        a--;
                    }
                    else if(b)
                    {
                        cout<<'S';
                        b--;
                    }
                    else
                    {
                        cout<<'P';
                        c--;
                    }
                }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}
