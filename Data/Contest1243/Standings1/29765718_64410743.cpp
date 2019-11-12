#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
int cnt;
string a,b;
vector< pair<int,int> > kq;
void Solve()
{
    cnt=0;
    cin>>n;
    cin>>a;
    cin>>b;
    a=' '+a;
    b=' '+b;
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=b[i])
        {
            for(int j=i+1; j<=n; j++)
                if(a[j]!=b[j])
                {
                    if(a[j]==a[i])
                    {
                        kq.push_back({j,i});
                        swap(a[j],b[i]);
                        cnt++;
                        break;
                    }
                    else if(b[j]==a[i])
                    {
                        swap(a[j],b[j]);
                        kq.push_back({j,j});
                        cnt++;
                        swap(a[j],b[i]);
                        kq.push_back({j,i});
                        cnt++;
                        break;
                    }
                }
        }
    }
    for(int i=1; i<=n; i++)
        if(a[i]!=b[i])
        {
            cout<<"No"<<endl;
            kq.clear();
            return ;
        }
    if(cnt>2*n)
    {
        cout<<"No"<<endl;
        kq.clear();
        return ;
    }
    cout<<"Yes"<<endl<<cnt<<endl;
    for(int i=0; i<kq.size(); i++)
        cout<<kq[i].first<<" "<<kq[i].second<<endl;
    kq.clear();
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  freopen("test.inp","r",stdin);
    cin>>t;
    for(int i=1; i<=t; i++)
        Solve();
}
