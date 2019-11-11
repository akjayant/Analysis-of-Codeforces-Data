#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define M 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,a,b,c,i,w;
    cin>>t;
    while(t--)
    {
        string s,ss = "";
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        w = 0;
        for(i=0;i<n;i++)
            if(s[i] == 'R' and b > 0)
                b--, w++, ss += 'P';
            else if(s[i] == 'P' and c > 0)
                c--, w++, ss += 'S';
            else if(s[i] == 'S' and a > 0)
                a--, w++, ss += 'R';
            else
                ss += 'X';
        if(w >= (n+1)/2)
        {
            cout<<"YES\n";
            for(i=0;i<n;i++)
                if(ss[i] != 'X')
                    cout<<ss[i];
                else if(a > 0)
                {
                    a--;
                    cout<<"R";
                }
                else if(b > 0)
                {
                    b--;
                    cout<<"P";
                }
                else if(c > 0)
                {
                    c--;
                    cout<<"S";
                }
            cout<<endl;
        }
        else
            cout<<"NO\n";

    }
    return 0;
}
