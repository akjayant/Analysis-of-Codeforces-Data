///*******HuyKun*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define maxn 1000111
#define pb push_back
using namespace std;
string a;
string b;
int dem=0;
int n;
int flag;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    for(int k=1; k<=q; k++)
    {
        vector<pii> res;
        dem=0;
        flag=0;
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
                {
                    if(a[j]!=b[j])
                    {
                        if(a[j]==a[i])
                        {
                            res.pb({j,i});
                            swap(a[j],b[i]);
                            dem++;
                            break;
                        }
                        else if(b[j]==a[i])
                        {
                            res.pb({j,j});
                            swap(a[j],b[j]);
                            dem++;
                            res.pb({j,i});
                            swap(a[j],b[i]);
                            dem++;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]!=b[i])
            {
                cout<<"No"<<'\n';
                flag=1;
                break ;
            }
        }
        if(flag==1) continue;
        if(dem>2*n)
        {
            cout<<"No"<<'\n';
            flag=1;
            break;
        }
        if(flag==1) continue;
        cout<<"Yes"<<'\n';
        cout<<dem<<'\n';
        for(int i=0; i<res.size(); i++)
        {
            cout<<res[i].F<<" "<<res[i].S<<'\n';
        }
    }
}
