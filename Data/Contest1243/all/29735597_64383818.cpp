#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        string s,t;
        vector<int>tt;
        cin>>s>>t;
        for(i=0; i<n; i++)
            if(s[i]!=t[i])
                tt.push_back(i);
        if(tt.size()!=2)
            cout<<"No"<<endl;
        else
        {
            if(s[tt[0]]==s[tt[1]]&&t[tt[0]]==t[tt[1]])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
