#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[500005];
ll brr[500005];

vector<ll>v;
vector<pi>ans;

map<ll,ll>mp;
ll cnt[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,n,m,ts;

    string s,t;

    cin>>ts;

    for(ll cz=1;cz<=ts;cz++){
    memset(cnt,0,sizeof(cnt));
            ans.clear();
            cin>>n;
        cin>>s;
    cin>>t;
    ll chk=0;

    for(i=0;i<n;i++){
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']++;
    }

    for(i=0;i<26;i++){
        if(cnt[i]%2==1){
            cout<<"No"<<endl;
            chk=1;
            break;
        }
    }

    if(chk==1) continue;

    for(i=0;i<n;i++){
            //cout<<s<<" "<<t<<endl;
        if(s[i]==t[i]){ continue;}
        chk=0;
        for(j=i+1;j<n;j++){
            if(s[i]==s[j]){
                ans.push_back({j+1,i+1});
                swap(t[i],s[j]);
                chk=1;
                break;
            }
        }

        if(chk==0){
            for(j=i+1;j<n;j++){
            if(s[i]==t[j]){
                ans.push_back({j+1,j+1});
                swap(s[j],t[j]);

                ans.push_back({j+1,i+1});
                swap(s[j],t[i]);
                chk=1;
                break;
            }
        }
        }

        if(chk==0){
            cout<<"No"<<endl;
            break;
        }
    }
        cout<<"Yes"<<endl<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    }
}

