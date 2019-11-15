#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        ll cnt[26]={0},cnt1[26]={0},cnt2[26]={0};
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
            cnt1[s[i]-'a']++;
            cnt2[t[i]-'a']++;
        }
        bool valid=1;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                valid=0;
                break;
            }
        }
        if(!valid){
            cout<<"No"<<endl;
            continue;
        }
        vector <pll> ans;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) continue;
            if(cnt1[s[i]-'a']>(cnt[s[i]-'a']/2)){
                ll id;
                for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        id=j;
                        break;
                    }
                }
                cnt1[s[i]-'a']--;
                cnt1[t[i]-'a']++;
                cnt2[t[i]-'a']--;
                cnt2[s[i]-'a']++;
                ans.pb({id+1,i+1});
                swap(s[id],t[i]);
            }
            else{
                ll id;
                for(int j=i+1;j<n;j++){
                    if(t[j]==s[i]){
                        id=j;
                        break;
                    }
                }
                cnt1[s[i+1]-'a']--;
                cnt1[t[i]-'a']++;
                cnt2[t[i]-'a']--;
                cnt2[s[i+1]-'a']++;
                ans.pb({i+2,id+1});
                swap(s[i+1],t[id]);
                ans.pb({i+2,i+1});
                swap(s[i+1],t[i]);
            }

        }
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
    }
    return 0;
}
