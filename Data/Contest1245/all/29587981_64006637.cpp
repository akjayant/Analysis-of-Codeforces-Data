#include <bits/stdc++.h>
using namespace std;

int trace[107];

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a,b,c,a1=0,b1=0,c1=0;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            if (s[i]=='R') b1++;
            if (s[i]=='P') c1++;
            if (s[i]=='S') a1++;
            trace[i]=-1;
        }
        ans=min(a,a1) + min(b,b1) + min(c,c1);
        if (ans>=(n/2) + (n%2==1)) 
        {
            printf("YES\n");
            a1=min(a,a1); b1=min(b,b1); c1=min(c,c1);
            for(int i=0; i<n; ++i)
            {
                if (s[i]=='R') 
                    if (b1>0) { --b1; --b; trace[i]=1; }
                if (s[i]=='P') 
                    if (c1>0) { --c1; --c; trace[i]=2; }
                if (s[i]=='S')
                    if (a1>0) { --a1; --a; trace[i]=0; }
            }
            for(int i=0; i<n; ++i)
                if (trace[i]==-1)
                {
                    if (a>0) { trace[i]=0; --a;}
                    else
                        if (b>0) { trace[i]=1; --b;}
                        else 
                            if (c>0) { trace[i]=2; --c;}
                }
            for(int i=0; i<n; ++i)
            {
                if (trace[i]==0) printf("R");
                if (trace[i]==1) printf("P");
                if (trace[i]==2) printf("S");
            }
            cout<<endl;
        }
        else printf("NO\n");
    }
}