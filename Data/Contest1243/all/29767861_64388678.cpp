#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e9+7

int main()
{
    int q,n;
    cin>>q;
    string s,t;
    while(q--)
    {
        cin>>n;
        cin>>s>>t;
        int cnt=0;
        int arr[26]={};
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
            arr[t[i]-'a']++;
        }
        bool flag=1;
        for(int i=0;i<26;i++)
        {
            if(arr[i]%2)
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            cout<<"No\n";
            continue;
        }
        else
        {
            vector<int>u,v;
            char temp;
            for(int i=0;i<n;i++)
            {
                if(s[i]!=t[i])
                {
                    int pos=n;
                    for(int j=i+1;j<n;j++)
                    {
                        if(s[i]==s[j])
                        {
                            swap(s[j],t[i]);
                            u.push_back(j);
                            v.push_back(i);
                            pos=-1;
                            break;
                        }
                    }
                    if(pos==-1)
                        continue;
                    for(int j=i+1;j<n;j++)
                    {
                        if(s[i]==t[j])
                        {
                            pos=j;
                            break;
                        }
                    }
                    temp=s[i+1];
                    s[i+1]=t[pos];
                    t[pos]=temp;
                    u.push_back(i+1);
                    v.push_back(pos);
                    swap(s[i+1],t[i]);
                    u.push_back(i+1);
                    v.push_back(i);
                }
            }
            cout<<"Yes\n"<<u.size()<<"\n";
            for(int i=0;i<u.size();i++)
                cout<<u[i]+1<<" "<<v[i]+1<<"\n";
        }
    }
    return 0;
}
