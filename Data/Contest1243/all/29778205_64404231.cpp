
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;

void nhap()
{
    int n,cnt=0;
    vector<pii> ans;
    cin>>n;
    string a;
    string b;
    cin>>a;
    a=' '+a;
    cin>>b;
    b=' '+b;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]!=b[j])
                    {
                        if(a[j]==a[i])
                        {
                            ans.push_back({j,i});
                            swap(a[j],b[i]);
                            cnt++;
                            break;
                        }
                        else if(b[j]==a[i])
                        {
                            ans.push_back({j,j});
                            swap(a[j],b[j]);
                            cnt++;
                            ans.push_back({j,i});
                            swap(a[j],b[i]);
                            cnt++;
                            break;
                        }
                    }
                }
            }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"No"<<'\n';
            return ;
        }
    }
    if(cnt>2*n)
    {
        cout<<"No"<<'\n';
        return ;
    }
    cout<<"Yes"<<'\n';
    cout<<cnt<<'\n';
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].F<<" "<<ans[i].S<<'\n';
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Zo".inp","r",stdin);
//    freopen(Zo".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        nhap();
}