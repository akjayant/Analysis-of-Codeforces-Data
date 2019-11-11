#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        string s2 = s;
        int need = (n+1)/2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]  ==  'R')
            {
                if(b > 0)
                {
                    b--;
                    s2[i] = 'P';
                    need--;
                }
                else
                {
                    s2[i]= '*';
                }
            }

            if(s[i]  ==  'S')
            {
                if(a > 0)
                {
                    a--;
                    s2[i] = 'R';
                    need--;
                }
                else
                {
                    s2[i]= '*';
                }
            }

             if(s[i]  ==  'P')
            {
                if(c > 0)
                {
                    c--;
                    s2[i] = 'S';
                    need--;
                }
                else
                {
                    s2[i]= '*';
                }
            }
        }
        if(need <= 0)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                if(s2[i] ==  '*')
                {
                    if(a > 0)
                    {
                        a--;
                        s2[i] = 'R';
                    }
                    else if(b > 0)
                    {
                        b--;
                        s2[i] = 'P';
                    }
                    else
                    {
                        c--;
                        s2[i] = 'S';
                    }
                }
                cout<<s2[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
