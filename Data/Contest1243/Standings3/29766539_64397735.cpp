#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = pow(10,9)+7;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int flag=0;
        int as[30]={0};
        int at[30]={0};
        for(int i=0;i<n;i++)
        {
            as[s[i]-'a']++;
            at[t[i]-'a']++;
        }
        for(int i=0;i<30;i++)
        {
            if((as[i]+at[i])%2!=0)
            {
                flag=-1;
                break;
            }
        }
        if(flag==-1)
            cout<<"No"<<endl;
        else
        {
            bool ans=true;
            //cout<<"Yes"<<endl;
            ll m=0;
            vector<pair<ll,ll>>v;
            for(int i=0;i<n-1;i++)
            {
                char c=s[i];
                if(t[i]==s[i])
                    continue;
                int flag=0;
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]==c)
                    {
                        s[j]=t[i];
                        t[i]=c;
                        v.push_back(make_pair(j,i));
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    continue;
                for(int j=i+1;j<n;j++)
                {
                    if(t[j]==c)
                    {
                        t[j]=s[i+1];
                        s[i+1]=c;
                        v.push_back(make_pair(i+1,j));
                        s[i+1]=t[i];
                        t[i]=c;
                        v.push_back(make_pair(i+1,i));
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans=false;
                    break;
                }
            }
            if(!ans)
                cout<<"No"<<endl;
            if(s!=t)
                cout<<"No"<<endl;
            else
            {
                cout<<"Yes"<<endl;
                cout<<v.size()<<endl;
                for(auto x:v)
                    cout<<x.first+1<<" "<<x.second+1<<endl;
            }
        }
        
    }
    return 0;
}
