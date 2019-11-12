#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define gap ' '
#define mod 1000000007
#define INF 1000000000


int main()
{
    int k;

    cin>>k;

    while(k--)
    {
        int n;

        cin>>n;

        string s,t;

        cin>>s>>t;
        vector< pair<int,int> > v;

        int ara[30]={0};

        for(int i=0;i<n;i++)
        {
            ara[s[i]-'a']++;
            ara[t[i]-'a']++;
        }

        int poss=1;

        for(int i=0;i<26;i++)
        {
            if(ara[i]%2)
            {
                cout<<"No"<<endl;
                poss=0;
                break;
            }
        }

        if(poss)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<n;i++)
            {
                if(s[i]!=t[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(t[j]==s[i])
                        {
                            v.pb({j,j});
                            v.pb({j,i});

                            swap(s[j],t[j]);
                            swap(s[j],t[i]);

                            break;
                        }
                    }
                }

                if(s[i]!=t[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(s[j]==s[i])
                        {
                            v.pb({j,i});
                            swap(s[j],t[i]);

                            break;
                        }
                    }
                }
            }

            cout<<v.size()<<endl;

            for(int i=0;i<v.size();i++)
            {
                cout<<v[i].f+1<<gap<<v[i].s+1<<endl;
            }
        }

    }
}
