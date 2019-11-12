#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
#define mk make_pair
int main(){
    int k;
    scanf("%d",&k);
    vector<P > ans;
	int n;
	int cnt[30];
	char s[110],t[110];
    while (k--){
		scanf("%d",&n);
		scanf("%s%s",s,t);
        ans.clear();
        memset(cnt,0,sizeof cnt);
        for (int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool flag=true;
        for (int i=0;i<='z'-'a';i++){
            if (cnt[i]%2!=0) flag=false;
        }
        if (!flag) printf("No\n");
        else {
            for (int i=0;i<n;i++){
                if (s[i]==t[i]) continue;
                bool flag2=false;
                for (int j=i+1;j<n;j++){
                    if (s[i]==s[j]) {
                        swap(s[j],t[i]);
                        ans.push_back(mk(j+1,i+1));
                        flag2=true;
                        break;
                    }
                }
                if (!flag2){
                    for (int j=i+1;j<n;j++){
                        if (s[i]==t[j]){
                            swap(s[i+1],t[j]);
                            swap(s[i+1],t[i]);
                            ans.push_back(mk(i+1+1,j+1));
                            ans.push_back(mk(i+1+1,i+1));
                            break;
                        }
                    }
                }
            }
            printf("Yes\n");
            int len=ans.size();
            printf("%d\n",len);
            for (int i=0;i<len;i++) printf("%d %d\n",ans[i].first,ans[i].second);
        }

    }
}
