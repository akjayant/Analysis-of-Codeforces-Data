#include<bits/stdc++.h>
using namespace std;
//B
int q,a,b,c,n;
string s,out;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        scanf("%d %d %d",&a,&b,&c);
        cin>>s;
        int x=0,y=0,z=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
                x++;
            if(s[i]=='P')
                y++;
            if(s[i]=='S')
                z++;
        }
        int ans=min(x,b)+min(y,c)+min(z,a);
        if(ans>=(n+1)/2)
        {
            cout<<"YES\n";
            out=s;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='R')
                {
                    if(b>0)
                    {
                        b--;
                        out[i]='P';
                    }
                    else
                        out[i]='X';
                }
                if(s[i]=='P')
                {
                    if(c>0)
                    {
                        c--;
                        out[i]='S';
                    }
                    else
                        out[i]='X';
                }
                if(s[i]=='S')
                {
                    if(a>0)
                    {
                        a--;
                        out[i]='R';
                    }
                    else
                        out[i]='X';
                }
            }
            for(int i=0;i<s.size();i++)
            {
                if(out[i]!='X')
                    continue;
                if(s[i]=='R')
                {
                    if(c>0)
                    {
                        c--;
                        out[i]='S';
                    }
                    else
                    {
                        a--;
                        out[i]='R';
                    }
                }
                if(s[i]=='P')
                {
                    if(a>0)
                    {
                        a--;
                        out[i]='R';
                    }
                    else
                    {
                        b--;
                        out[i]='P';
                    }
                }
                if(s[i]=='S')
                {
                    if(b>0)
                    {
                        b--;
                        out[i]='P';
                    }
                    else
                    {
                        c--;
                        out[i]='S';
                    }
                }
            }
            cout<<out<<"\n";
        }
        else
            cout<<"NO\n";
    }
    
}

//E
