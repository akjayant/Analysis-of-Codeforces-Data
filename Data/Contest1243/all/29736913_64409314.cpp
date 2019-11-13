#include<bits/stdc++.h>
 
const int maxn=102020;

std::unordered_map<int,int>vi;
int n;
char a[maxn],b[maxn];
struct edge{
    int x,y;
}d[maxn*2];
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int t;scanf("%d",&t);
	while(t--)
	{
		vi.clear();
		scanf("%d%s%s",&n,a,b);
		for(int i=0;i<n;i++) vi[a[i]]++,vi[b[i]]++;
		int f=0;
		for(auto i='a';i<='z';i++)
            if(vi[i]&1) f=1;
        if(f) puts("No");
        else
        {
        	int cnt=0;puts("Yes");
        	for(int i=0;i<n;i++)
        	{
        		if(a[i]!=b[i])
        		{
        			for(int j=i+1;j<n;j++)
                    {
                        if(a[i]==a[j])
                        {
                            d[cnt].x=j;d[cnt].y=i;
                            std::swap(a[j],b[i]);cnt++;
                            break;
                        }
                        else if(b[i]==b[j])
                        {
                            d[cnt].x=i;d[cnt].y=j;
                            std::swap(a[i],b[j]);cnt++;
                            break;
                        }
                        else if(a[i]==b[j])
                        {
                            d[cnt].x=j;d[cnt].y=j;
                            std::swap(a[j],b[j]);cnt++;
                            d[cnt].x=j;d[cnt].y=i;
                            std::swap(a[j],b[i]);cnt++;
                            break;
                        }
                        else if(b[i]==a[j])
                        {
                            d[cnt].x=j;d[cnt].y=j;
                            std::swap(a[j],b[j]);cnt++;
                            d[cnt].x=i;d[cnt].y=j;
                            std::swap(a[i],b[j]); cnt++;
                            break;
                        } 
                    }
        		}
        	}
        	printf("%d\n",cnt);
            for(int i=0;i<cnt;i++)
            {
                printf("%d %d\n",d[i].x+1,d[i].y+1);
            }
        }
	}
	return 0;
}