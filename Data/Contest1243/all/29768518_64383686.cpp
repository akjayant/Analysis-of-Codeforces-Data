#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tc;
    cin>>tc;
    while (tc--)
    {
        string a,b;
        int n;
        cin>>n;
        cin>>a>>b;
        vector<int>v;
        for (int i=0;i<n;i++)
        {
            if (a[i]!=b[i])
            {
                v.push_back(i);
            }
        }
        if (v.size()>2 || v.size()==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            char temp=a[v[0]];
            a[v[0]]=b[v[1]];
            b[v[1]]=temp;
            if (a==b)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
