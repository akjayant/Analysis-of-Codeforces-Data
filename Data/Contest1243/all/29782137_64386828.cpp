#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{   
    int k;
    cin>>k;

    while(k--)
    {
        int n;
        cin>>n;
        
        string s, t;
        cin>>s>>t;

        vector < pair < int , int > > ans;
        
        int valid = 1;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==t[i])
                continue;
            int found = 0;
            for(int j=i-1;j>=0;j--)
            {
                if(t[j]==t[i])
                {
                    found = 1;
                    swap(s[i], t[j]);
                    ans.push_back({i, j});
                    break;
                }
            }

            if(found == 0)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(s[j]==t[i])
                    {
                        ans.push_back({j,j});
                        swap(s[j], t[j]);
                        swap(s[i], t[j]);
                        ans.push_back({i, j});
                        found = 1;
                        break;
                    }
                }
            }

            if(found == 0)
                valid = 0;
        }

        if(valid==1)
        {
            cout<<"YeS"<<endl;
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
            }
        }
        else
        {
            cout<<"nO"<<endl;
        }
    }

    return 0;
}