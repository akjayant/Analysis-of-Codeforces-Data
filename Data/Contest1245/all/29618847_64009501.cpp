#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

const int NMAX = 112345;
char in[NMAX];
char out[NMAX];

void task()
{
	D printf("task\n");
	int n;
	int r,p,s;
	scanf("%d%d%d%d%s",&n,&r,&p,&s,in);
	int R=0,P=0,S=0;
	for(int i=0;i<n;i++)
	{
		if(in[i]=='R') R++;
		if(in[i]=='P') P++;
		if(in[i]=='S') S++;
	}
	int pos = min(R,p) + min(P,s) + min(S,r);
	if(pos >= (n+1)/2)
	{
		for(int i=0;i<n;i++)
		{
			out[i]=out[i+1]=0;
			if(in[i]=='R' && p) {p--;out[i]='P';}
			if(in[i]=='P' && s) {s--;out[i]='S';}
			if(in[i]=='S' && r) {r--;out[i]='R';}
		}
		for(int i=0;i<n;i++)
		{
			if(out[i]==0 && p) {p--;out[i]='P';}
			if(out[i]==0 && s) {s--;out[i]='S';}
			if(out[i]==0 && r) {r--;out[i]='R';}
		}
		printf("YES\n%s\n",out);
	}
	else
		printf("NO\n");

}
int main()
{
	int t;
	scanf("%d",&t);
	for(;t;t--) task();


}

