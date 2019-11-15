#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ans[100100];
char s[100100];
int main(){
  int len,i;
  scanf(" %s",s+1);
  len=strlen(s+1);
  ans[0]=1;
  for(i=1;i<=len;i++){
    if(s[i]=='m'||s[i]=='w'){
      printf("0");
      return 0;
    }
    if(i>2&&s[i-2]=='u'&&s[i-1]=='u'&&s[i]=='u'){
      ans[i]=ans[i-1]+ans[i-2];
      ans[i]%=mod;
    }
    else if(i>1&&s[i]=='u'&&s[i-1]=='u'){
      ans[i]=ans[i-2]*2;
      ans[i]%=mod;
    }
    else if(i>2&&s[i-2]=='n'&&s[i-1]=='n'&&s[i]=='n'){
      ans[i]=ans[i-1]+ans[i-2];
      ans[i]%=mod;
    }
    else if(i>1&&s[i]=='n'&&s[i-1]=='n'){
      ans[i]=ans[i-2]*2;
      ans[i]%=mod;
    }
    else ans[i]=ans[i-1];
  }
  printf("%d",ans[len]);
  return 0;
}
