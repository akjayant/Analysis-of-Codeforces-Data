#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=55;

int T,n,c[26];
char s1[maxn],s2[maxn];
vector<pii> res;

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s%s",s1,s2);
        memset(c,0,sizeof(c));
        for(int i=0;i<n;++i){
            ++c[s1[i]-'a'];
            ++c[s2[i]-'a'];
        }
        bool ok=true;
        for(int i=0;i<26;++i){
            if(c[i]&1){
                ok=false;
                break;
            }
        }
        if(!ok){
            puts("No");
            continue;
        }
        res.clear();
        for(int i=0;i<n;++i){
            if(s1[i]==s2[i]) continue;
            for(int j=i+1;j<n;++j){
                if(s1[j]==s1[i]){
                    swap(s2[i],s1[j]);
                    res.push_back(make_pair(j,i));
                    break;
                }
                if(s2[j]==s1[i]){
                    swap(s1[j],s2[j]);
                    swap(s2[i],s1[j]);
                    res.push_back(make_pair(j,j));
                    res.push_back(make_pair(j,i));
                    break;
                }
            }
        }
        puts("Yes");
        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();++i) printf("%d %d\n",1+res[i].first,1+res[i].second);
    }
    return 0;
}