#include<stdio.h>
#include<algorithm>
using namespace std;

char str1[10005],str2[10005],te;
int num[30],ans[1000][2];

int main(){
    int n,i,j,k,a,b,c,t;
    scanf("%d",&k);
    for(t=1;t<=k;t++){
        scanf("%d",&n);
        scanf("%s",&str1);
        scanf("%s",&str2);
        a=0;
        for(i=0;i<='z'-'a';i++){
            num[i]=0;
        }
        for(i=0;i<n;i++){
            num[str1[i]-'a']++;
            num[str2[i]-'a']++;
        }
        for(i=0;i<='z'-'a';i++){
            a+=num[i]%2;
        }
        if(a>0){
            printf("No\n");
            continue;
        }
        a=0;
        for(i=0;i<n;i++){
            if(str1[i]==str2[i])continue;
            else{
                for(j=i+1;j<n;j++){
                    if(str1[i]==str1[j]){
                        ans[a][0]=j+1;
                        ans[a][1]=i+1;
                        a++;
                        te=str1[j];
                        str1[j]=str2[i];
                        str2[i]=te;
                        break;
                    }
                }
                if(str1[i]==str2[i])continue;
                for(j=i+1;j<n;j++){
                    if(str1[i]==str2[j]){
                        ans[a][0]=n;ans[a++][1]=j+1;
                        ans[a][0]=n;ans[a++][1]=i+1;
                        str2[j]=str1[n-1];
                        str1[n-1]=str2[i];
                        str2[i]=str1[i];
                        break;
                    }
                }
            }
        }
        printf("Yes\n%d\n",a);
        for(i=0;i<a;i++){
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
}
