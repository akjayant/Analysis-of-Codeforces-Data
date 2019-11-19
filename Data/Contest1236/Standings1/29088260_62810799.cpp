#include<cstdio>
const int MaxN=100005,MaxM=100005,MaxK=100005;
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
int n,m,K,x,y,cntX[MaxN+1],cntY[MaxM+1],delLine=0,delRow=0,L,R,Top,Bottom;
int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
long long rest;
int main()
{
	int i,j,k;
	read(n),read(m),read(K),rest=1LL*n*m,L=1,R=m,Top=1,Bottom=n;
	for(i=1;i<=K;++i)
		read(x),read(y),++cntX[x],++cntY[y],--rest;
	int mode=0;
	while(rest)
	{
		switch(mode)
		{
			case 0:
				while(L<=R&&cntY[R]-delLine==Bottom-Top+1)
					--R,++delRow;
				if(cntX[Top]-delRow>0)
					return puts("No"),0;
				rest-=R-L+1,++Top;
				break;
			case 1:
				while(Top<=Bottom&&cntX[Bottom]-delRow==R-L+1)
					--Bottom,++delLine;
				if(cntY[R]-delLine>0)
					return puts("No"),0;
				rest-=Bottom-Top+1,--R;
				break;
			case 2:
				while(L<=R&&cntY[L]-delLine==Bottom-Top+1)
					++L,++delRow;
				if(cntX[Bottom]-delRow>0)
					return puts("No"),0;
				rest-=R-L+1,--Bottom;
				break;
			case 3:
				while(Top<=Bottom&&cntX[Top]-delRow==R-L+1)
					++Top,++delLine;
				if(cntY[L]-delLine>0)
					return puts("No"),0;
				rest-=Bottom-Top+1,++L;
				break;
		}
//		printf("mode=%d L=%d R=%d Top=%d Bottom=%d\n",mode,L,R,Top,Bottom);
		mode=(mode+1)%4;
//		puts("233");
	}
	puts("Yes");
	return 0;
}