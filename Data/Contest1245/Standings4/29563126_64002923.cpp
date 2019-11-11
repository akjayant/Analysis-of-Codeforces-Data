#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" --> "<<x<<endl;
#define N 100005
#define M 1000000007
#define pii pair<int,int>
using namespace std;
main()
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
        string e;
        for(int i=0; i<n; i++)
        {
            e.push_back('1');
        }
        map<char,int>mp;
        for(auto u:s)
        {
            mp[u]++;
        }
        int j=0;
        int a1=min(mp['S'],a);
        for(int i=0; i<n; i++)
        {
            if(s[i]=='S'&&j<a1)
            {
                j++;
                e[i]='R';
            }
        }
        int a2=min(mp['R'],b);
        j=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='R'&&j<a2)
            {
                j++;
                e[i]='P';
            }

        }
        int a3=min(mp['P'],c);
        j=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='P'&&j<a3)
            {
                j++;
                e[i]='S';
            }

        }
        int need=n/2;
        if(n%2==1)
            need++;




        if(a1+a2+a3>=need)
        {
            cout<<"Yes\n";
            for(int i=0; i<n; i++)
            {
                if(e[i]=='1')
                {
                    if(a1!=a)
                    {
                        e[i]='R';
                        a1++;
                    }
                    else if(a2!=b)
                    {
                        e[i]='P';
                        a2++;
                    }
                    else
                    {
                        e[i]='S';
                        a3++;
                    }

                }

            }
            cout<<e<<'\n';
        }
        else
        {
            cout<<"No\n";
        }
    }

}
