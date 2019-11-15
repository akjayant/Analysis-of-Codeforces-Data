#include<bits/stdc++.h>
using namespace std;
int n,m,q,dem[30];
typedef pair<int,int> ii;
vector<ii> vt;
string s,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("1243B.inp","r",stdin);
    //freopen("1243B.out","w",stdout);
    cin>>q;
    while(q--)
    {
        memset(dem,0,sizeof dem);
        cin>>n;
        cin>>s>>t;
        s=" "+s;
        t=" "+t;
        for (int i=1;i<=n;i++)
        {
            dem[s[i]-'a']++;
            dem[t[i]-'a']++;
        }
        bool check=true;
        for (int i=0;i<=26;i++)
            if (dem[i]%2==1)
            {
                check=false;
                break;
            }
        if (!check)
            cout<<"No"<<'\n';
        else
        {
            vt.clear();
            cout<<"Yes"<<'\n';
            for (int i=1;i<=n-1;i++)
                if (s[i]!=t[i])
                {
                    check=false;
                    for (int j=i+1;j<=n;j++)
                        if (s[i]==s[j])
                        {
                            swap(s[j],t[i]);
                            vt.push_back(ii(j,i));
                            check=true;
                            break;
                        }
                    if (!check)
                    {
                        for (int j=i+1;j<=n;j++)
                            if (s[i]==t[j])
                            {
                                vt.push_back(ii(j,j));
                                swap(s[j],t[j]);
                                vt.push_back(ii(j,i));
                                swap(s[j],t[i]);
                                break;
                            }
                    }
                }
            if (vt.size()==0)
                cout<<1<<'\n'<<1<<" "<<1<<'\n';
            else
            {
                cout<<vt.size()<<'\n';
                for (int i=0;i<vt.size();i++)
                    cout<<vt[i].first<<" "<<vt[i].second<<'\n';
            }
        }
    }
}
