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
        ll c=0;
        v temp;
        for (int i=0; i<s.length(); i++)
        {
            c+=(s[i]!=t[i]);
            a[s[i]-'a']++;
            if (s[i]!=t[i])
            {
                temp.push_back(i);
            }
        }
        for (int i=0; i<s.length(); i++)
            b[t[i]-'a']++;
        ll count=0;
        bool f=1;
        for (int i=0; i<26; i++)
        {
            if ((a[i]+b[i])%2!=0)
                f=0;
            count+=abs(a[i]-b[i]);
        }
        // cout<<c<<endl;
        if (f==1 && c<=2 && count<=4 && count%2==0)
        {
            if (temp.size()==2)
            {
                int i=temp[0];
                int j=temp[1];
                swap(s[i],t[j]);
                if (s==t)
                {
                    cout<<"Yes"<<endl;
                    continue;
                }
                swap(s[i],t[j]);
                swap(s[j],t[i]);
                if (s==t)
                {
                    cout<<"Yes"<<endl;
                }
                else
                    cout<<"No"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }

        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}