#include<bits/stdc++.h>
#define int long long
#define M 998244353
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main(){
ios
int t=1;
cin>>t;
while(t--)
{
    int n;cin>>n;
    string s,t;cin>>s>>t;
    vector<int> hsh(26,0);
    for(int i=0;i<n;i++)
    {
        hsh[s[i]-'a']++;
        hsh[t[i]-'a']++;
    }
    int cnt=0;
    for(int i=0;i<26;i++)
    cnt+=hsh[i]%2;
    if(cnt)cout<<"No\n";
    else 
    {
        cout<<"Yes\n";
        vector<int> ans1,ans2;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[i]==s[j])
                    {
                        ans1.push_back(j+1);
                        ans2.push_back(i+1);
                        swap(t[i],s[j]);
                        break;
                    }
                    else if(s[i]==t[j])
                    {
                        ans1.push_back(j+1);
                        ans2.push_back(j+1);
                        ans1.push_back(j+1);
                        ans2.push_back(i+1);
                        swap(t[j],s[j]);
                        swap(s[j],t[i]);
                        break;

                    }
                    else if(t[i]==t[j])
                    {
                        ans1.push_back(i+1);
                        ans2.push_back(j+1);
                        swap(s[i],t[j]);
                        break;
                    }
                    else if(t[i]==s[j])
                    {
                        ans1.push_back(j+1);
                        ans2.push_back(j+1);
                        ans1.push_back(i+1);
                        ans2.push_back(j+1);
                        swap(t[j],s[j]);
                        swap(s[i],t[j]);
                        break;
                    }
                }
            }
            else 
            {
                ans1.push_back(i+1);
                ans2.push_back(i+1);
            }
        }
        cout<<ans1.size()<<'\n';
        for(int i=0;i<ans1.size();i++)
        cout<<ans1[i]<<" "<<ans2[i]<<'\n';
    }

    
}
}
