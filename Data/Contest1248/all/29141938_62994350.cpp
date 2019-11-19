#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 505;
int n,prel[MAXN],prer[MAXN];
int minpre[MAXN],minsuf[MAXN];
char str[MAXN];
inline void get()
{
	for(int i = 1; i<=n; i++)
	{
        prel[i] = prel[i-1]+(str[i]=='(');
        prer[i] = prer[i-1]+(str[i]==')');
	}
	for(int i = 1; i<=n; i++)
        minpre[i] = min(minpre[i-1],prel[i]-prer[i]);
    for(int i = n; i>=1; i--)
    {
        minsuf[i] = min(minsuf[i+1],prel[i]-prer[i]);
       // cout << "test1 " << i << " " << minsuf[i] << endl;
	}    
	for(int i = 1; i<=n; i++)
    {
        minsuf[i] -= prel[i-1]-prer[i-1];
       // cout << "test " << i << " " << minsuf[i] << endl;
	}    
}

int main()
{
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> str[i];
	int ans = 0, ansx = 1, ansy = 1;
	get();
	if(prel[n]!=prer[n])
	{
        cout << 0 << endl << 1 << " " << 1 << endl;
        return 0;
    }
	for(int i = 0; i<n; i++)
        if(minsuf[i+1]>=0&&prel[n]-prel[i]-prer[n]+prer[i]+minpre[i]>=0)
        {
		    ans++;
            //cout << i << endl;
        }  
	for(int i = 1; i<=n; i++)
        for(int j = i+1; j<=n; j++)
        {
            swap(str[i],str[j]);
            get();
            int res = 0;
			for(int k = 0; k<n; k++)
                if(minsuf[k+1]>=0&&prel[n]-prel[k]-prer[n]+prer[k]+minpre[k]>=0)
                    res++;
            if(res>ans)
            {
                ans = res;
                ansx = i, ansy = j;
			}
			swap(str[i],str[j]);
	    }
    cout << ans << endl << ansx << " " << ansy << endl;  
	return 0;
}
