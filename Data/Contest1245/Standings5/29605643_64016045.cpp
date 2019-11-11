//
#include<iostream>
#include<cstring>
using namespace std;
int t;
int n;
int main()
{
    cin>>t;
    string s;
    while(t--)
    {
        string k;
        k.clear();
        int a,b,c;
        cin>>n;cin>>a>>b>>c;
        s.clear();
        cin>>s;
        int tmp1=0,tmp2=0,tmp3=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')tmp1++;
            if(s[i]=='P')tmp2++;
            if(s[i]=='S') tmp3++;
        }
        int win=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='S')
            {
                tmp3--;
                if(a>=1)
                {
                    a--;
                    k.push_back('R');
                    win++;
                    continue;
                }
                    if(b>tmp1)
                    {
                        b--;
                        k.push_back('P');
                        continue;
                    }
                if(c>tmp2)
                {
                    c--;
                    k.push_back('S');
                    continue;
                }
                if(b>=1)
                {
                    b--;
                    k.push_back('P');
                    continue;
                }
                if(c>=1)
                {
                    c--;
                    k.push_back('S');
                    continue;
                }
            }
            if(s[i]=='R')
            {
                tmp1--;
                if(b>=1)
                {
                    b--;
                    k.push_back('P');
                    win++;
                    continue;
                }
                
                if(a>tmp3)
                {
                    a--;
                    k.push_back('R');
                    continue;
                }
                if(c>tmp2)
                {
                    c--;
                    k.push_back('S');
                    continue;
                }
                if(a>=1)
                {
                    a--;
                    k.push_back('R');
                    continue;
                }
                if(c>=1)
                {
                    c--;
                    k.push_back('S');
                    continue;
                }
            }
            if(s[i]=='P')
            {
                tmp2--;
                if(c>=1)
                {
                    c--;
                    k.push_back('S');
                    win++;
                    continue;
                }
                
                if(a>tmp3)
                {
                    a--;
                    k.push_back('R');
                    continue;
                }
                if(b>tmp1)
                {
                    b--;
                    k.push_back('P');
                    continue;
                }
                if(a>=1)
                {
                    a--;
                    k.push_back('R');
                    continue;
                }
                if(b>=1)
                {
                    b--;
                    k.push_back('P');
                    continue;
                }
            }
            }
        
        if(win>=((n+1)/2))
        {
            puts("YES");
            cout<<k<<endl;
            continue;
        }
        else{
            puts("NO");
        }
        }
    }

