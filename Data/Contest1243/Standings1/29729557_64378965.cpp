#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e5+5;
const ll mod=1e9+7;

char ch[2][maxn];
int in[2][30],a[maxn*2];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<2;i++)scanf("%s",ch[i]);
        int tot=0;
        for(int i=0;i<n;i++){
            if(ch[0][i]!=ch[1][i]){
                a[++tot]=ch[0][i]-'a';
                a[++tot]=ch[1][i]-'a';
            }
        }
        if(tot<=4){
            if(tot==0)printf("Yes\n");
            else if(tot==2)printf("No\n");
            else{
                if(a[1]==a[3]&&a[2]==a[4])printf("Yes\n");
                else printf("No\n");
            }
        }
        else printf("No\n");
    }
    return 0;
}
