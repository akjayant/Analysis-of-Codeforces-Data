#include<bits/stdc++.h>
#define M 100001
#define MAX 1000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool ans = true;
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int fr[26] = {0};
        for(int i = 0;i<n;i++)
        {
            fr[s[i]-'a']++;
            fr[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(fr[i]%2 == 1)
                ans = false;
        }
        if(ans)
        {
            vector<pair<int,int> >v;
            for(int i = 0;i<n;i++)
            {
                if(s[i] != t[i])
                {
                    bool check = true;
                    for(int j=i+1;j<n;j++)
                    {
                        if(s[j]!=t[j] && s[j]==s[i])
                        {
                            v.pb({j+1,i+1});
                            swap(s[j],t[i]);
                            check = false;
                            break;
                        }
                    }
                    if(check)
                    {
                        int ind1=-1,ind2=-1;
                        for(int j=i+1;j<n;j++)
                        {
                            if(t[j]==s[i])
                            {
                                ind1=j;
                                break;
                            }
                        }
                        for(int j=i+1;j<n;j++)
                        {
                            if(s[j]!=t[j])
                            {
                                ind2 = j;
                                break;
                            }
                        }
                        swap(t[ind1],s[ind2]);
                        v.pb({ind2+1,ind1+1});
                        swap(s[ind2],t[i]);
                        v.pb({ind2+1,i+1});
                    }
                }
            }
            cout<<"YES\n"<<v.size()<<endl;
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i].first<<" "<<v[i].second<<endl;
            }
        }
        else
        {
            cout<<"NO\n";
        }
        
    }


    return 0;
}