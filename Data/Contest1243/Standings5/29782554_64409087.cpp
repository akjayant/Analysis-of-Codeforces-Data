#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int k,n,ma[30],ok,ans;

struct madoka{
    int i;
    int j;
}lin1;
char s1[100],s2[100],lin;
vector<int >ho;
vector<madoka>sa;

int main(){
    scanf("%d",&k);
    while(k--){
        ans=0;
        memset(ma,0,sizeof(ma));
        scanf("%d",&n);
        scanf("%s%s",s1+1,s2+1);
        ho.clear();
        sa.clear();
        for(int i=1;i<=n;i++){
            if(s1[i]!=s2[i]){
                ma[s1[i]-'a'+1]++;
                ma[s2[i]-'a'+1]++;
                ho.push_back(i);
            }
        }
        ok=1;
        for(int i=1;i<=26;i++){
            if(ma[i]%2!=0){
                ok=0;
                break;
            }
        }
        if(ok==0){
            printf("No\n");
        }
        else{
            printf("Yes\n");
            for(int i=0;i<ho.size();i++){
                if(s1[ho[i]]==s2[ho[i]])continue;
                ok=0;
                for(int j=i+1;j<ho.size();j++){
                    if(s1[ho[i]]==s1[ho[j]]){
                        lin=s2[ho[i]];
                        s2[ho[i]]=s1[ho[j]];
                        s1[ho[j]]=lin;
                        lin1.i=ho[j];
                        lin1.j=ho[i];
                        sa.push_back(lin1);
                        ans++;
                        ok=1;
                        break;
                    }
                }
                if(ok==1)continue;
                for(int j=i+1;j<ho.size();j++){
                    if(s1[ho[i]]==s2[ho[j]]){
                        lin=s2[ho[j]];
                        s2[ho[j]]=s1[ho[j]];
                        s1[ho[j]]=lin;
                        lin1.j=ho[j];
                        lin1.i=ho[j];
                        sa.push_back(lin1);
                        lin=s2[ho[i]];
                        s2[ho[i]]=s1[ho[j]];
                        s1[ho[j]]=lin;
                        lin1.i=ho[j];
                        lin1.j=ho[i];
                        sa.push_back(lin1);
                        ans+=2;
                        break;
                    }
                }
            }
            printf("%d\n",ans);
            for(int i=0;i<sa.size();i++){
                printf("%d %d\n",sa[i].i,sa[i].j);
            }
        }
    }
    return 0;
}