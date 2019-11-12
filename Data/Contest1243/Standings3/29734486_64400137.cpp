#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define line cout<<"---------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
int  main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    string str,str1;
    cin>>n>>str>>str1;
    int cnt[26]={0};
    vector<int> a[26],b[26];
    for(int i=0;i<n;i++)
    {
        cnt[str[i]-'a']++;
        cnt[str1[i]-'a']++;
        a[str[i]-'a'].pb(i);
        b[str1[i]-'a'].pb(i);
    }
    bool ck=0;
    for(int i=0;i<26;i++)
    {
        if(cnt[i]%2)
        {
            ck=1;
            break;
        }
    }
    if(ck) cout<<"No"<<endl;
    else
    {
        vector<pair<int,int> > ans;
        for(int i=0;i<n;i++)
        {
            if(str[i]==str1[i]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(str[i]==str1[j])
                {
                    swap(str[i+1],str1[j]);
                    ans.pb({i+1,j});
                    swap(str[i+1],str1[i]);
                    ans.pb({i+1,i});
                    break;
                }
                else if(str[i]==str[j])
                {
                    swap(str[j],str1[i]);
                    ans.pb({j,i});
                    break;
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(auto x: ans)
        {
            cout<<x.first+1<<' '<<x.second+1<<endl;
        }
    }
    }


}
