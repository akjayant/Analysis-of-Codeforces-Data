#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4+20;
const ll MOD = 1e9+7;
char s[MAXN],t[MAXN];
int num[30];
int main()
{
  int _;
  cin >> _;
  while (_--){
    int n;
    cin >> n;
    scanf("%s",s);scanf("%s",t);
    int difn=0,maxn=1;
    int idx[2]={0,0};
    memset(num,0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      if(s[i]!=t[i]){
        difn++;
        if(difn>2)break;
        idx[difn-1]=i;
      }
      num[s[i]-'a']++;
      maxn=max(maxn,num[s[i]-'a']);
    }
    //cout << difn << endl;
    //cout << maxn << endl;
    if((difn==2 && s[idx[0]]==s[idx[1]] && t[idx[0]]==t[idx[1]]) || (difn==0&&maxn>1))puts("Yes");
    else puts("No");
  }
}
