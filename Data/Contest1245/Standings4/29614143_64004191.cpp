#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxx=1e3+10;
char s[maxx];
int mp[200];
char str[10]={'0','P','R','S'};
char ans[maxx];
int ok[maxx];
int main(){
    int t; cin>>t;
    while(t--){
        memset(mp,0,sizeof mp);
        memset(ok,0,sizeof ok);
        int n; cin>>n;
        int a,b,c; cin>>b>>a>>c;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<=a;i++){
            if(mp[str[2]]<i) continue;
            for(int j=0;j<=b;j++){
                if(mp[str[3]]<j) continue;
                for(int k=0;k<=c;k++){
                    if(mp[str[1]]<k) continue;
                    if(i+j+k>=(n+1)/2){
                        int x,y,z; x=i,y=j,z=k;
                        for(int i=1;i<=n;i++){
                            if(s[i]=='R'&&x){
                                ans[i]='P';
                                ok[i]=1;
                                x--;
                            }
                            else if(s[i]=='S'&&y){
                                ans[i]='R';
                                ok[i]=1;
                                y--;
                            }
                            else if(s[i]=='P'&&z){
                                ans[i]='S';
                                ok[i]=1;
                                z--;
                            }
                        }
                        a-=i,b-=j,c-=k;
                        goto l;
                    }
                }
            }
        }
        puts("NO");
        continue;
        l:;
        puts("YES");
        for(int i=1;i<=n;i++){
            if(ok[i]){
                printf("%c",ans[i]);
            }else{
                if(a){
                    printf("P"); a--;
                }
                else if(b){
                    printf("R"); b--;
                }else{
                    printf("S"); c--;
                }
            }
        }
        puts("");
    }
}
