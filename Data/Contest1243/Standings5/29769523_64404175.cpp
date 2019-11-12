#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string ss,tt;
        cin>>ss>>tt;
        vector<pair<int,int> >ans;
        for(int i=0; i<n; i++)
        {
            if(ss[i]!=tt[i])
            {
                bool flag=0;
                for(int j=i+1; j<n; j++)
                {
                    if(ss[j]==ss[i])
                    {
                        ss[j]=tt[i];
                        tt[i]=ss[i];
                        ans.push_back({j+1,i+1});
                        flag=1;
                        break;
                    }
                }
                if(!flag && i<n-1)
                {
                    for(int j=i+1; j<n; j++)
                    {
                        if(tt[j]==ss[i])
                        {
                            tt[j]=ss[i+1];
                            ss[i+1]=ss[i];
                            ans.push_back({i+2,j+1});

                            ss[i+1]=tt[i];
                            tt[i]=ss[i];
                            ans.push_back({i+2,i+1});
                            flag=1;
                            break;
                        }
                    }
                }

            }
        }
        if(ss!=tt)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        }
    }
}
