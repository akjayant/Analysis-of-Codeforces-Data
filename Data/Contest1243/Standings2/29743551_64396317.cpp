#include<bits/stdc++.h>
using namespace std;
int cnt1[26];
int cnt2[26];
typedef pair<int,int> pii;
#define fi first
#define se second
int main()
{
    ios::sync_with_stdio(false);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int>vec;
        for(int i=0;i<26;i++) cnt1[i]=cnt2[i]=0;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])
                vec.push_back(i);
        for(int i=0;i<vec.size();i++)
        {
            cnt1[s[vec[i]]-'a']++;
            cnt2[t[vec[i]]-'a']++;
        }
        bool f=1;
        for(int i=0;i<26;i++)
            if((cnt1[i]+cnt2[i])%2)
                f=0;
        if(!f) {cout<<"No\n";continue;}
        cout<<"Yes\n";
        vector<pii>ans;
        for(int i=0;i<26;i++)
        {
            vector<int>tp[2];
            for(int j=0;j<vec.size();j++)
            {
                if(s[vec[j]]==t[vec[j]]) continue;
                if(s[vec[j]]-'a'==i)
                    tp[0].push_back(vec[j]);
                if(t[vec[j]]-'a'==i)
                    tp[1].push_back(vec[j]);
            }
            int sz0=tp[0].size(),sz1=tp[1].size();
            if(sz0>1)
            {
                for(int j=0;j<=(sz0-2)/2;j++)
                {
                    ans.push_back(pii(tp[0][j],tp[0][sz0-j-1]));
                    swap(s[tp[0][j]],t[tp[0][sz0-j-1]]);
                }
            }
            if(sz1>1)
            {
                for(int j=0;j<=(sz1-2)/2;j++)
                {
                    ans.push_back(pii(tp[1][sz1-j-1],tp[1][j]));
                    swap(t[tp[1][j]],s[tp[1][sz1-j-1]]);
                }
            }
            if(sz0%2)
            {
                int pos1=tp[0][sz0/2],pos2=tp[1][sz1/2];
                ans.push_back(pii(pos1,pos1));
                ans.push_back(pii(pos2,pos1));
                swap(s[pos1],t[pos1]);
                swap(s[pos2],t[pos1]);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].fi+1<<' '<<ans[i].se+1<<endl;
    }
}
