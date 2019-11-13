#include<bits/stdc++.h>
typedef long long ll;

#define pb push_back
#define mp make_pair
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int win = n/2;
        if(n%2!=0)
            win++;
        int a,b,c;
        cin>>a>>b>>c;
        string  str;
        cin>>str;
        string ans;
        int res=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='P')
            {
                if(c > 0)
                    {
                        c--;
                        ans.push_back('S');
                        res++;
                    }
                else
                    ans.push_back('.');

            }
            else if(str[i]=='S'){
               if(a > 0)
                    {
                        a--;
                        ans.push_back('R');
                        res++;
                    }
                else
                    ans.push_back('.');
            }
            else{
                if(b > 0)
                    {
                        b--;
                        ans.push_back('P');
                        res++;
                    }
                else
                    ans.push_back('.');
            }
        }
        if(res>=win)
        {
            cout<<"YES\n";
            for(int i=0;i<ans.size();i++){
                if(ans[i]=='.')
                {
                    if(a > 0)
                    {
                        ans[i] = 'R';
                        a--;
                    }
                    else if(b > 0){
                        ans[i] = 'P';
                        b--;
                    }
                    else{
                        ans[i]='S';
                        c--;
                    }
                }
            }
            cout<<ans<<"\n";

        }
        else
            cout<<"NO\n";
    }
    return 0;
    
}