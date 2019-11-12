#include<bits/stdc++.h>
using namespace std;
string s,t;
int n;
int cnt[200];
vector<pair<int,int> > ans;
int main(){
    int T;
    cin>>T;
    while (T--){
        ans.clear();
        for (int i='a';i<='z';i++) cnt[i]=0;
        cin>>n;
        cin>>s>>t;
        for (int i=0;i<n;i++){
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
        bool flag=true;
        for (int i='a';i<='z';i++){
            if (cnt[i]%2!=0) flag=false;
        }
        if (!flag) puts("No");
        else {
            for (int i=0;i<n;i++){
                if (s[i]==t[i]) continue;
                bool flag2=false;
                for (int j=i+1;j<n;j++){
                    if (t[i]==t[j]) {
                        swap(s[i],t[j]);
                        ans.push_back(make_pair(i+1,j+1));
                        flag2=true;
                        break;
                    }
                }
                if (!flag2){
                    for (int j=i+1;j<n;j++){
                        if (t[i]==s[j]){
                            swap(t[i+1],s[j]);
                            swap(t[i+1],s[i]);
                            ans.push_back(make_pair(j+1,i+1+1));
                            ans.push_back(make_pair(i+1,i+1+1));
                            break;
                        }
                    }
                }
            }
            puts("Yes");
            cout<<ans.size()<<endl;
            for (int i=0;i<ans.size()-1;i++) printf("%d %d\n",ans[i].first,ans[i].second);
            if (T==0) printf("%d %d",ans[ans.size()-1].first,ans[ans.size()-1].second);
            else printf("%d %d\n",ans[ans.size()-1].first,ans[ans.size()-1].second);
        }

    }
}