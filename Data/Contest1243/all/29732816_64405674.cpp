/*================= *\
|  ID : aman__guta__ |
|      LANG: C++     |
\*==================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define fs first
#define sc second 
#define mod 1000000007
#define JOKER ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
main()
{
    JOKER
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int b[26]={0};
        for(int i=0; i<n; i++)
        {
            b[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        int flag=0;
        for(int i=0; i<26; i++)
        {
            if(b[i]%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout<<"NO\n";
            continue;
        }
        int arr[110][2];
        int f=0;
        map <int,pair<char,char> > mp;
        for(int i=0; i<n; i++)
        {
            if(s[i]!=t[i])
                mp[i]=(mk(s[i],t[i]));
        }
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            char p=it->sc.fs;
            char q=it->sc.sc;
            for(auto itr=it; ; )
            {
                itr++;
                if(itr==mp.end())
                    break;
                if(itr->sc.fs==p)
                {
                    arr[f][0]=itr->fs+1;
                    arr[f++][1]=it->fs+1;
                    char c=itr->sc.fs;
                    char d=it->sc.sc;
                    it->sc.sc=c;
                    itr->sc.fs=d;
                    break;
                }
                if(itr->sc.sc==p)
                {
                    char c,d;
                    arr[f][0]=itr->fs+1;
                    arr[f++][1]=itr->fs+1;
                    c=itr->sc.fs;
                    d=itr->sc.sc;
                    itr->sc.sc=c;
                    itr->sc.fs=d;
                    arr[f][0]=itr->fs+1;
                    arr[f++][1]=it->fs+1;
                    c=itr->sc.fs;
                    d=it->sc.sc;
                    it->sc.sc=c;
                    itr->sc.fs=d;
                    break;
                }
            }
        }
        cout<<"YES\n";
        cout<<f<<endl;
        for(int i=0; i<f; i++)
            cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}