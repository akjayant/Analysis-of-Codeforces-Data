#include <bits/stdc++.h>
using namespace std;
void LSH()
{
	#ifndef ONLINE_JUDGE
		freopen("1245B.INP","r",stdin);
		freopen("1245B.OUT","w",stdout);
	#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);
		cout.tie(0);
}
long long t,a,b,c,n,o,p,d,k;
string s,ks;
int main()
{
	LSH();
    cin>>t;
    while(t--)
    {
        o=0;p=0;d=0;
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        ks="";
        for (int i = 0 ; i <= s.size()-1 ; ++i )
        {
            if(s[i]=='R') o = o + 1;
            if(s[i]=='P') p = p + 1;
            if(s[i]=='S') d = d + 1;
        }
        k=min(o,b)+min(p,c)+min(d,a);
        if ( k*2 < n )
            cout<<"NO"<<'\n';
        else
        {
            cout<<"YES"<<'\n';
            for (int i = 0 ; i < s.size() ;++i )
            {
                if (s[i]=='R')
                {
                    if (b>0)
                    {
                        ks=ks+"P";
                        b--;
                    }
                    else ks=ks+"*";
                }
                if (s[i]=='P')
                {
                    if (c>0)
                    {
                        ks=ks+"S";
                        c--;
                    }
                    else ks=ks+"*";
                }
                if (s[i]=='S')
                {
                    if (a>0)
                    {
                        ks=ks+"R";
                        a = a - 1;
                    }
                    else ks=ks+"*";
                }
            }
            for (int i = 0 ; i < ks.size(); ++i )
                if (ks[i]!='*')
                    cout<<ks[i];
                else
                {
                    if (a>0)
                    {
                        cout<<'R';
                        a--;
                    }
                    else
                    {
                        if (b>0)
                        {
                            cout<<'P';
                            b--;
                        }
                        else if (c>0)
                        {
                            cout<<'S';
                            c = c -1;
                        }
                    }
                }
            cout<<'\n';
        }
    }
}