#include <cstdio>
#include <algorithm>
using namespace std;
char a[100861];
int main()
{
    int t,n,m,i,j,l,r,ansl,ansr,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",a+1);
        flag=0;
        for(i=1;i<=n;i++){
            if(a[i]=='1')flag=1;
        }
        if(flag==0)printf("%d\n",n);
        else{
            for(i=1;i<=n;i++){
                if(a[i]=='1'){
                    r=i;
                }
            }
            ansr=r*2;
            for(i=n;i>=1;i--){
                if(a[i]=='1'){
                    l=n-i+1;
                }
            }
            ansl=l*2;
            printf("%d\n",max(ansl,ansr));
        }
    }
    return 0;
}
