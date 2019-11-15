#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50+20;
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
    memset(num,0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      num[s[i]-'a']++;
      num[t[i]-'a']++;
    }
    int odd=0;
    for (int i = 0; i < 26; ++i) {
      if(num[i]&1){odd++;break;}
    }
    if(odd){puts("No");continue;}
    else puts("Yes");
    vector<int>l,r;
    for (int i = 0; i < n; ++i) {
      if(s[i]==t[i])continue;
      for (int j = i+1; j < n; ++j) {
        if(t[i]==t[j]){swap(s[i],t[j]),l.push_back(i),r.push_back(j);break;}
        if(t[i]==s[j]){
          swap(s[j],t[i+1]),swap(s[i],t[i+1]);
          l.push_back(j),r.push_back(i+1);
          l.push_back(i),r.push_back(i+1);
          break;
        }
      }
    }
    //cout << s << endl;
    //cout << t << endl;
    cout << l.size() << endl;
    for (int i = 0; i < l.size(); ++i) {
      cout << l[i]+1 << " " << r[i]+1 << endl;
    }
  }
}