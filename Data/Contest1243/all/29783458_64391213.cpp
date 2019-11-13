#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<pair<int,int>> ans;
        bool check = true;
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                for(int j = i+1;j<n;j++)
                {
                    if(s2[j]==s2[i])
                    {
                        ans.push_back(make_pair(i+1,j+1));
                        char temp = s1[i];
                        s1[i] = s2[j];
                        s2[j] = temp;
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                   for(int j = i+1;j<n;j++)
                   {
                       if(s1[j]==s2[i])
                       {
                            ans.push_back(make_pair(j+1,j+1));
                            ans.push_back(make_pair(i+1,j+1));
                            char temp = s1[j];
                            s1[j] = s2[j];
                            s2[j] = temp;
                            temp = s1[i];
                            s1[i] = s2[j];
                            s2[j] = temp;
                            break;
                       }
                   }
                }
            }
            //cout<<s1<<" "<<s2<<endl;
            check = true;
        }
        check = true;
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                check = false;
                break;
            }
        }
        if(check&&ans.size()<=2*n)
        {
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for(int i = 0;i<ans.size();i++)
            {
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
