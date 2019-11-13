#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define mx 200007
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        string s,t;
        cin>>s>>t;

        vector<int>a;

        int cnt= 0;

        for( int i=0; i<s.size(); i++ )
        {
            if( s[i]!=t[i] )
                a.push_back(i);
        }

        if( a.size()==0 )
            cout<<"Yes\n";
        else if( a.size()==2 )
        {
            if( s[ a[0] ]==s[ a[1] ] and t[ a[0] ]==t[ a[1] ] )
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else
            cout<<"No\n";

    }
}
