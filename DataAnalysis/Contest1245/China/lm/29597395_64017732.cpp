using namespace std;
char ch[100005];
long long f[100005];

signed main()
{


 cin>>ch;
 long long i=0;
 long long len=strlen(ch);
 long long ans=1;
 f[0]=1;
 f[1]=1;
 for(long long i=2;i<=100000;i++)
     f[i]=(f[i-1]+f[i-2])%1000000007;
 while(i<len)
 {
  if(ch[i]=='m'||ch[i]=='w')
  {
   cout<<"0";
   return 0;
  }
  else if(ch[i]=='n')
  {
      long long num=0;
   while(ch[i]=='n')
       num++,i++;
   ans=(ans*f[num])%1000000007;
  }
  else if(ch[i]=='u')
  {
   long long num=0;
   while(ch[i]=='u')
       num++,i++;
   ans=(ans*f[num])%1000000007;
  }
  else
      i++;
 }
    cout<<ans<<endl;
 return 0;
}
