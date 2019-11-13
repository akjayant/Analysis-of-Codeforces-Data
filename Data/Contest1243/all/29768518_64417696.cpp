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
    while (tc--) {
        string a,b;
        int n;
        cin>>n;
        cin>>a>>b;
        map<char,int>mp;
        for (int i=0;i<n;i++)
        {
            mp[a[i]]++;
            mp[b[i]]++;
        }
        bool chk=true;
        for (int i=0;i<n;i++)
        {
            if (mp[a[i]]%2==1 || mp[b[i]]%2==1)
            {
                chk=false;
                break;
            }
        }
        if (chk==false)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int cnt=0;
            vector<int>v;
            for (int i=0;i<n;i++)
            {
                bool flag=false;
                if (a[i]==b[i]) continue;
                for (int j=i+1;j<n;j++)
                {
                    if (a[i]==a[j] && a[j]!=b[j])
                    {
                        swap(b[i],a[j]);
                        v.push_back(j);
                        v.push_back(i);
                        cnt++;
                        flag=true;
                        break;
                    }
                }
                if (flag) continue;

                for (int j=i+1;j<n;j++)
                {
                    if (b[i]==b[j] && a[j]!=b[j])
                    {
                        v.push_back(i);
                        v.push_back(j);
                        swap(a[i],b[j]);
                        cnt++;
                        flag=true;
                        break;
                    }
                }
                if (flag) continue;

                int pos;
                for (int j=i+1;j<n;j++)
                {
                    if (b[j]==a[i] && a[j]!=b[j])
                    {
                        pos=j;
                        break;
                    }
                }
                swap(a[pos],b[pos]);
                v.push_back(pos);
                v.push_back(pos);

                swap(a[pos],b[i]);
                v.push_back(pos);
                v.push_back(i);
                cnt+=2;


            }
            if (cnt<=(2*n))
            {
                cout<<"YES"<<endl;
                cout<<cnt<<endl;
                for (int i=1;i<v.size();i+=2)
                {
                    cout<<v[i-1]+1<<' '<<v[i]+1<<endl;
                }
            }
            else
                cout<<"NO"<<endl;
        }

    }

    return 0;
}
