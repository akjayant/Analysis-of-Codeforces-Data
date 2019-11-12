/**
Code by Nitin1184
**/
# include <bits/stdc++.h>
# define ll long long
# define pi 3.14159265358979323846
# define M 1000000007
# define pb push_back
# define mp make_pair
# define ff first
# define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int f[26]={0};
        for(int i=0;i<n;i++)
        {
            f[s[i]-'a']++;
            f[t[i]-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++)
        {
            if(f[i]%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            if(s.compare(t)==0)
            {
                cout<<1<<endl<<"1 1"<<endl;
            }
            else
            {
                vector<pair<int,int> > ans;
                for(int i=0;i<n;i++)
                {
                    if(s[i]!=t[i])
                    {
                        int ps=-1,pt=-1;
                        for(int j=i+1;j<n;j++)
                        {
                            if(s[j]==s[i])
                            {
                                ps=j;
                                break;
                            }
                        }
                        if(ps!=-1)
                        {
                            ans.pb({ps+1,i+1});
                            char temp=s[ps];
                            s[ps]=t[i];
                            t[i]=temp;
                        }
                        else
                        {
                            for(int j=i+1;j<n;j++)
                            {
                                if(s[i]==t[j])
                                {
                                    pt=j;
                                    break;
                                }
                            }
                            ans.pb({pt+1,pt+1});
                            ans.pb({pt+1,i+1});
                            char temp=s[pt];
                            s[pt]=t[pt];
                            t[pt]=temp;
                            temp=s[pt];
                            s[pt]=t[i];
                            t[i]=temp;
                        }
                    }
                }
                cout<<ans.size()<<endl;
                for(int i=0;i<ans.size();i++)
                    cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
            }
        }
    }
    return 0;
}