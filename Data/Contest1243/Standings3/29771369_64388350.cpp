#include <bits/stdc++.h>
using namespace std;
#define opt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long int
// I might be a loser, but I have nothing to lose :p
int main()
{
opt;
ll k,n,f,f1;
string s,t;
cin>>k;
while(k--)
{
    vector<int> m(26);
    cin>>n;
    cin>>s>>t;
    f=0;
    for(int i =0;i<n;i++)
    {
        m[s[i]-'a']++;
        m[t[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(m[i]%2==1)
            f=1;
    }
    if(f==1)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
    vector< pair<int,int> > ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])
            continue;
        else
        {
            f1=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    f1=1;
                    swap(s[j],t[i]);
                    ans.push_back(make_pair(j,i));
                    break;
                }
            }
            if(f1==0)
            {
                for(int j=i+1;j<n;j++)
                {
                   if(s[i]==t[j])
                   {
                       swap(t[j],s[n-1]);
                       ans.push_back(make_pair(n-1,j));
                       swap(s[n-1],t[i]);
                       ans.push_back(make_pair(n-1,i));
                       break;
                   }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i =0;i<ans.size();i++)
    {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
}
return 0;
}