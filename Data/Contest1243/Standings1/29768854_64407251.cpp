#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
long long mod=1000000007;
void swap(string &s1, string &s2, int i, int j){
    char a=s1[i];
    char b=s2[j];
    s1[i]=b;
    s2[j]=a;

}

int main()
{
    fastio;
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        int freq[26]={0};
        for(int i=0;i<n;i++)
        {
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']++;
        }
        bool poss=true;
        for(int i=0;i<26;i++)
        if(freq[i]%2){
            poss=false;
            break;
        }
        if(!poss){
            cout<<"No \n";
            continue;
        }
        cout<<"Yes \n";
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])
            continue;
            bool done=false;
            for(int j=i+1;j<n;j++){
                if(s1[j]==s1[i]){
                    ans.push_back({j+1,i+1});
                    swap(s1,s2,j,i);
                    done=true;
                    break;
                }
            }
            if(!done){
                for(int j=i+1;j<n;j++){
                    if(s2[j]==s1[i]){
                        ans.push_back({n,j+1});
                        swap(s1,s2,n-1,j);
                        ans.push_back({n,i+1});
                        swap(s1,s2,n-1,i);
                        break;
                    }
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}