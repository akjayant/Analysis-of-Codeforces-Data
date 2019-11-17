const int tt=1000000007;
int n,f[100005];
long long ans=1;
char s[100005];
int main(){
 int i,j;
 scanf("%s",s);
 n=strlen(s);
 f[1]=1; f[2]=2; f[3]=3;
 for (i=4;i<=n;i++) f[i]=(f[i-1]+f[i-2])%tt;
 for (i=0;i<n;i++)
 if (s[i]=='w'||s[i]=='m') ans=0;
 if (ans){
  for (i=0;i<n;i=j)
  {
   for (j=i+1;j<n;j++)
   if (s[j]!=s[i]) break;
   if (s[i]=='u'||s[i]=='n') ans=ans*f[j-i]%tt;
  }
 }
 printf("%d\n",ans);
 return 0;
}
