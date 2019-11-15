#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
char a[100005],b[100005];
ll f[100005];
int main(){
    int bo;
    scanf("%s",a);
    int len=strlen(a);
    bo=0;
    for (int i=0;i<len;i++)
        if (a[i]=='w'||a[i]=='m')bo=1;
    if (bo==1)printf("0\n");
    else{
        for (int i=1;i<=len;i++)b[i]=a[i-1];
        memset(f,0,sizeof(f));b[0]='_';
        f[0]=1;
        for (int i=1;i<=len;i++){
            if (b[i]=='n'&&b[i-1]=='n'){
                f[i]=(f[i-1]+f[i-2])%mod;
            }else if (b[i]=='u'&&b[i-1]=='u'){
                f[i]=(f[i-1]+f[i-2])%mod;
            }else f[i]=f[i-1];
        }
        printf("%lld\n",f[len]);
    }
    return 0;
}