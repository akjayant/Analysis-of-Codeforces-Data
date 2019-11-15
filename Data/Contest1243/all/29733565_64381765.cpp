#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define gap ' '
#define mod 1000000007
#define INF 1000000000


int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s,t;

        cin>>s>>t;

        vector<char> S,T;

        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                S.pb(s[i]);
                T.pb(t[i]);
            }
        }
        if(S.size()==0)
        {
            cout<<"Yes"<<endl;
        }

        else if(S.size()==2)
        {
            if(S[0]==S[1] && T[0]==T[1])
            {
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }

        }
        else{
            cout<<"No"<<endl;
        }

    }
}
