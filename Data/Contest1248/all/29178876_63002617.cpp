#include<iostream>
#include<algorithm>
using namespace std;
const int maxN = 510;
char b[maxN];
int a[maxN];
int s[maxN];
int minid;
int maxis = 0;
int n;
int cnt ;
int al = 1, ar = 1;
int main()
{
      cin >> n;
      cin >> b;
      for(int i = 0; i < n; i++)
            a[i] = (b[i] == '(' ? 1 : -1);
      for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
            {
                  swap(a[i],a[j]);
                  s[0] = a[0];
                  for(int k = 1; k < n; k++)
                        s[k] = s[k-1] + a[k];
                  if(s[n-1] != 0)
                  {
                        cout << 0 << '\n' << 1 << ' ' << 1 << '\n';
                        return 0;
                  }
                  minid = 0;
                  for(int k = 1; k < n; k++)
                        if(s[k] < s[minid])
                              minid = k;
                  cnt = 0;
                  for(int k = 0; k < n; k++)
                        if(s[k] == s[minid])
                              ++cnt;
                  if(cnt > maxis)
                  {
                        maxis = cnt;
                        al = i;
                        ar = j;
                  }
                  swap(a[j],a[i]);
            }
      cout << maxis << '\n' << al+1 << ' ' << ar+1 << '\n';
      return 0;
}