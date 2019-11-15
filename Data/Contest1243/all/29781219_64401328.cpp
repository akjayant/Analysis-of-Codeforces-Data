#include <bits/stdc++.h>
using namespace std;
string s[2];
vector<pair<int,int>> sol;
int main ()
{
    int t,n,i,j,nr,ok;
    cin>>t;
    while(t--)
    {
        cin>>n>>s[0]>>s[1];
        sol.clear();
        for(i=0;i<n;i++)
            if(s[0][i]!=s[1][i])
            {
                ok=1;
                for(j=i+1;ok&&j<n;j++)
                    if(s[0][i]==s[0][j])
                    {
                        sol.push_back({j,i});
                        s[0][j]=s[1][i];
                        ok=0;
                    }
                for(j=i+1;ok&&j<n;j++)
                    if(s[0][i]==s[1][j])
                    {
                        sol.push_back({j,j});
                        sol.push_back({j,i});
                        swap(s[0][j],s[1][j]);
                        s[0][j]=s[1][i];
                        ok=0;
                    }
                if(ok)
                    break;
            }
        if(i!=n)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        cout<<sol.size()<<"\n";
        for(auto it:sol)
            cout<<it.first+1<<" "<<it.second+1<<"\n";
    }
    return 0;
}