#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back 
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define ld long double
#define int long long int 
#define F first 
#define S second
signed main()
{
    fast;
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int h[26]={};
        set<int> st1[26],st2[26];
        for(int i=0;i<n;i++)
        {
            h[s[i]-'a']++;
            st1[s[i]-'a'].insert(i);
            st2[t[i]-'a'].insert(i);
            h[t[i]-'a']++;
        }
        int flag = 1;
        for(int i=0;i<26;i++)
        {
            if(h[i]%2)
            {
                flag = 0;
                break;
            }
        }
        if(!flag)
            cout<<"No\n";
        else
        {
            vector<pii> op;
            for(int i=0;i<n;i++)
            {
                if(s[i] == t[i])
                    continue;
                char req = t[i];
                auto it = st2[req-'a'].lb(i+1);
                if(it == st2[req-'a'].end())
                {
                    it = st1[req-'a'].lb(i+1);
                    if(it == st1[req-'a'].end())
                    {
                        req = s[i];
                        auto it = st1[req-'a'].lb(i+1);
                        if(it == st1[req-'a'].end())
                        {
                            it = st2[req-'a'].lb(i+1);
                            if(it == st1[req-'a'].end())
                            {
                                flag = 0;
                                break;
                            }
                            else
                            {
                                swap(t[*it],s[*it]);
                                op.pb({*it,*it});
                                st2[t[*it]-'a'].insert(*it);
                                st1[s[*it]-'a'].insert(*it);
                                st2[s[*it]-'a'].erase(*it);
                                st1[t[*it]-'a'].erase(*it);
                                swap(s[*it],t[i]);
                                op.pb({*it,i});
                                st2[t[i]-'a'].insert(*it);
                                st1[s[*it]-'a'].insert(i);
                                st1[t[i]-'a'].erase(*it);
                                st2[s[*it]-'a'].erase(i);
                            }
                        }
                        else
                        {
                            swap(s[*it],t[i]);
                            op.pb({*it,i});
                            st2[t[i]-'a'].insert(*it);
                            st1[s[*it]-'a'].insert(i);
                            st1[t[i]-'a'].erase(*it);
                            st2[s[*it]-'a'].erase(i);
                        }

                    }
                    else
                    {
                        swap(s[*it],t[*it]);
                        op.pb({*it,*it});
                        st2[t[*it]-'a'].insert(*it);
                        st1[s[*it]-'a'].insert(*it);
                        st2[s[*it]-'a'].erase(*it);
                        st1[t[*it]-'a'].erase(*it);
                        swap(s[i],t[*it]);
                        op.pb({i,*it});
                        st2[t[*it]-'a'].insert(*it);
                        st1[s[i]-'a'].insert(i);
                        st1[t[*it]-'a'].erase(i);
                        st2[s[i]-'a'].erase(*it);
                    }
                }
                else
                {
                    swap(s[i],t[*it]);
                    op.pb({i,*it});
                    st2[t[*it]-'a'].insert(*it);
                    st1[s[i]-'a'].insert(i);
                    st1[t[*it]-'a'].erase(i);
                    st2[s[i]-'a'].erase(*it);
                }
            }
            if(flag && s == t && (int)op.size()<=2*n)
            {
                cout<<"Yes\n";
                cout<<op.size()<<"\n";
                for(auto it:op)
                {
                    cout<<it.first+1<<" "<<it.second+1<<"\n";
                }
            }
            else cout<<"No\n";
        }
    }
}