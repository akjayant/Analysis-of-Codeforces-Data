#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll arr[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int> tmp;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                tmp.push_back(i);
            }
        }
        if(tmp.size()>2)
        {
            cout<<"No"<<endl;
        }
        else if(tmp.size()==1)
        {
            cout<<"No"<<endl;
        }
        else if(tmp.size()==2)
        {
            swap(a[tmp[0]],b[tmp[1]]);
            if(a==b)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                swap(a[tmp[0]],b[tmp[1]]);
                swap(a[tmp[1]],b[tmp[0]]);
                if(a==b) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
