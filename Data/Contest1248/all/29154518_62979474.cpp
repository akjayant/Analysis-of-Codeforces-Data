#include<cstdio>
int ji,ou,n,m;
inline void read(int &ans)
{
	ans=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
		ans=ans*10+c-48,c=getchar();
	return;
}
inline void Part()
{
	int i,a,cnt[2][2]={0};
	read(n);
	for(i=1;i<=n;++i)
		read(a),++cnt[0][a&1];
	read(m);
	for(i=1;i<=m;++i)
		read(a),++cnt[1][a&1];
	printf("%I64d\n",1LL*cnt[0][0]*cnt[1][0]+1LL*cnt[0][1]*cnt[1][1]);
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		Part();
	return 0;
}