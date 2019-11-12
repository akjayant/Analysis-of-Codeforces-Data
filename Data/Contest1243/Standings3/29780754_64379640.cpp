#include<stdio.h>
#include<algorithm>
using namespace std;

char str1[10005],str2[10005];

int main(){
    int n,i,j,k,a,b,c,t;
    scanf("%d",&k);
    for(t=1;t<=k;t++){
        scanf("%d",&n);
        scanf("%s",&str1);
        scanf("%s",&str2);
        a=0;b=-1;c=-1;
        for(i=0;i<n;i++){
            if(str1[i]==str2[i])a++;
            else{
                if(b<0)b=i;
                else c=i;
            }
        }
        if(a==n)printf("Yes\n");
        else if(a!=n-2)printf("No\n");
        else if(a==n-2){
            if(str1[b]==str1[c]&&str2[b]==str2[c]){
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
}
