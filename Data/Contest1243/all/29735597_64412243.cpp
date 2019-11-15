#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        string s,t;
        vector<pair<int,int>>v;
        vector<int>c(26);
        cin>>s>>t;
        for(i=0;i<n;i++)
            {
                c[s[i]-'a']++;
                c[t[i]-'a']++;
            }
        bool valid=true;
        for(i=0;i<26;i++)
            if(c[i]&1)
        {
            valid=false;
            break;
        }
        if(!valid)
        {
            cout<<"No"<<endl;
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                valid=false;
                for(j=i+1;j<n;j++)
                {
                    if(s[i]==s[j])
                    {
                        valid=true;
                        v.push_back(make_pair(j+1,i+1));
                        swap(s[j],t[i]);
                        break;
                    }
                }
                if(!valid)
                {
                    for(j=i+1;j<n;j++)
                        if(s[i]==t[j])
                    {
                        swap(s[i+1],t[j]);
                        v.push_back(make_pair(i+2,j+1));
                        swap(s[i+1],t[i]);
                        v.push_back(make_pair(i+2,i+1));
                        break;
                    }
                }
            }
        }
        cout<<"Yes"<<endl<<v.size()<<endl;
        for(i=0;i<v.size();i++)
            cout<<v[i].first<<' '<<v[i].second<<endl;
    }
}
