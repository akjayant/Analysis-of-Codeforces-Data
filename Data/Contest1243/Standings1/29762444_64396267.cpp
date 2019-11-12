#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[105],t[105];
int num[105],us[105];
int anss[205],anst[205];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        for(int i=0;i<n;i++) num[s[i]-'a']++;
        for(int i=0;i<n;i++) num[t[i]-'a']++;
        int flag=0;
        for(int i=0;i<26;i++){
            if(num[i]%2!=0) flag=1;
        }
        if(flag==1){
            printf("No\n");
            continue;
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                int pos=-1;
                for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        pos=j;
                        break;
                    }
                }
                if(pos==-1){
                    for(int j=i+1;j<n;j++){
                        if(t[j]==s[i]){
                            pos=j;
                            break;
                        }
                    }
                    swap(s[i+1],t[pos]);
                    k++;
                    anss[k]=i+1;
                    anst[k]=pos;
                    swap(s[i+1],t[i]);
                    k++;
                    anss[k]=i+1;
                    anst[k]=i;
                }
                else{
                    swap(t[i],s[pos]);
                    k++;
                    anss[k]=pos;
                    anst[k]=i;
                }
            }
        }
        printf("Yes\n");
        printf("%d\n",k);
        for(int i=1;i<=k;i++){
            printf("%d %d\n",anss[i]+1,anst[i]+1);
        }
    }
    return 0;
}
