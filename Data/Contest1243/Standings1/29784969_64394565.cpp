#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll> 
#define vv vector<v>
#define p pair<ll,ll>
#define vc vector<char>
#define fi first
#define se second
// qwertyiopwo

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    // string a="abc";
    // string b="def";
    // swap(a[0],b[0]);
    // cout<<a<<endl;
    while (t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        v a(27,0);
        v b(27,0);
        for (int i=0; i<s.length(); i++)
        {
            a[s[i]-'a']++;
        }
        for (int i=0; i<s.length(); i++)
            b[t[i]-'a']++;
        bool f=1;
        for (int i=0; i<26; i++)
        {
            if ((a[i]+b[i])%2!=0)
                f=0;
        }
        if (f==0)
        {
            cout<<"No"<<endl;
        } 
        else
        {
            cout<<"Yes"<<endl;
            vector<p> temp;
            for (int i=0; i<n; i++)
            {
                if (s[i]==t[i])
                    continue;
                bool done=0;
                for (int j=i+1; j<n; j++)
                {
                // if (i==0)
                //     cout<<j<<" "<<s[j]<<" "<<t[i]<<endl;
                    if (s[j]==s[i])
                    {

                        done=1;
                        swap(s[j],t[i]);
                        temp.push_back(p(j+1,i+1));
                        break;
                    }
                    if (t[j]==t[i])
                    {
                        done=1;
                        swap(s[i],t[j]);
                        temp.push_back(p(i+1,j+1));
                        break;
                    }
                }
                if (done)
                {
                    continue;
                }
                swap(s[i],t[i]);
                temp.push_back(p(i+1,i+1));
                for (int j=i+1; j<n; j++)
                {
                // if (i==0)
                //     cout<<j<<" "<<s[j]<<" "<<t[i]<<endl;
                    if (s[j]==s[i])
                    {

                        done=1;
                        swap(s[j],t[i]);
                        temp.push_back(p(j+1,i+1));
                        break;
                    }
                    if (t[j]==t[i])
                    {
                        done=1;
                        swap(s[i],t[j]);
                        temp.push_back(p(i+1,j+1));
                        break;
                    }
                }


            }
            cout<<temp.size()<<endl;
            for (int i=0; i<temp.size(); i++)
                cout<<temp[i].first<<" "<<temp[i].second<<endl;
        }
    }
    return 0;
}