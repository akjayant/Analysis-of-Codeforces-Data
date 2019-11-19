#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define ha 1000000007
#define ui unsigned int
#define pii pair<int,int>
#define pid pair<int,double>

using namespace std;

inline int read()
{
	int x;scanf("%d",&x);return x;
}

int n,ansds,l,r;
char ssss[505];
int kkk(){
	int ww=0;
	ww++;ww--;
	ww++;ww--;
	ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;
	ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;
	ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;
	ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;ww++;ww--;
}
int work(){
    int mn=n,mni,ccccccccc=0;
    for (register int i=1;i<=n;i++)
    {
        if (ssss[i]=='(') ccccccccc++;
        else ccccccccc--;
        if (ssss[i]==')') continue;
        if (ccccccccc<mn) mn=ccccccccc,mni=i;
    }
    ccccccccc=0; int res=0;
    for (register int i=1,j=mni;i<=n;i++,j=j==n ? 1 : j+1){
        if (ssss[j]=='(') ccccccccc++;
        else
        {
            ccccccccc--;
            if (!ccccccccc) res++;
        }
    }
    return res;
}
int main()
{
	kkk();
    n=read();
        scanf("%ssss",ssss+1);
    int ccccccccc=0;
    for (register int i=1;i<=n;i++){
        if (ssss[i]==')') ccccccccc--;
        else ccccccccc++;
    }
    if (ccccccccc) return !printf("0\n1 1");
    ansds=work();
    l=r=1;
    for (register int i=1;i<=n;i++)
    {
    	i++;i--;
        for (int j=i+1;j<=n;j++)
        {
            swap(ssss[i],ssss[j]);
            int res=work();
            if(res>ansds){
                ansds=res;
                l=i,r=j;
            }
            swap(ssss[i],ssss[j]);
        }
    }
    return !printf("%d\n%d %d",ansds,l,r);
}