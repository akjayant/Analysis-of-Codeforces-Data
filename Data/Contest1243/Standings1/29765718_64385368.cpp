/// !!!!!!!! NGHI VAN HACK !!!!!!!! ///

#include <bits/stdc++.h>
#define Killian "TASK"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int t,n;
char c1[10005],c2[10005];
vector <pair <char,char>> pos;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Killian".inp","r",stdin);
//    freopen(Killian".out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>c1[i];
        for (int i=1; i<=n; i++)
            cin>>c2[i];
        int dem=0;
        for (int i=1; i<=n; i++)
        {
            if (c1[i]!=c2[i])
            {
                pos.push_back(make_pair(c1[i],c2[i]));
                dem++;
            }
        }
        if (dem>2)
        {
            cout<<"No"<<endl;
            pos.clear();
            continue;
        }
        else
        {
            if (pos[0].first==pos[1].first && pos[0].second==pos[1].second)
            {
                cout<<"Yes"<<endl;
                pos.clear();
                continue;
            }
        }
        cout<<"No"<<endl;
        pos.clear();
    }
}
