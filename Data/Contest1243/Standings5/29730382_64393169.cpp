#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int chk[205];
int vis[55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        memset(chk,0,sizeof chk);
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int> tmp;
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
            chk[a[i]]++;
            chk[b[i]]++;
            if(a[i]!=b[i])
            {
                vis[i]=1;
                tmp.push_back(i);
                //cout<<i<<" ";
            }
        }
        //cout<<endl;
        int req=0;
        for(char i='a';i<='z';i++)
        {
            if(chk[i]%2==1)
            {
                req=1;
                break;
            }
        }
        if(req)
        {
            cout<<"No"<<endl;
        }
        else
        {
            vector<pair<int,int> > ans;
            for(int i=0;i<tmp.size();i++)
            {
                int id=tmp[i];
                char x=a[id];
                char y=b[id];
                int next=-1;
                if((i+1)<tmp.size())
                {
                    next=tmp[i+1];
                }
                for(int j=id+1;j<n && a[id]!=b[id];j++)
                {
                    if(vis[j]==1 )
                    {
                        if(y==b[j])
                        {
                            ans.push_back(make_pair(id,j));
                            swap(a[id],b[j]);
                            vis[id]=0;
                            break;
                        }
                    }
                }
                if(vis[id]==1)
                {
                    for(int j=id+1;j<n && a[id]!=b[id];j++)
                    {
                        if(vis[j]==1)
                        {
                            if(a[j]==b[id])
                            {
                                swap(a[j],b[j]);
                                ans.push_back(make_pair(j,j));
                                swap(a[id],b[j]);
                                ans.push_back(make_pair(id,j));
                                vis[id]=0;
                                break;
                            }
                        }

                    }
                }

            }
            if(a==b)
            {
                cout<<"Yes"<<endl;
                cout<<ans.size()<<endl;
                for(int i=0;i<ans.size();i++)
                {
                    cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
                }
            }
            else cout<<"No"<<endl;
        }

    }
    return 0;
}
