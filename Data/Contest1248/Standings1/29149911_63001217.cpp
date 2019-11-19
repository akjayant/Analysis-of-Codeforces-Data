#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string s;
deque < char > dq;
int mx = 0, a = 1, b = 1;
int it;
stack < char > stk;
int frnt;
int chk()
{
    while(stk.size()) stk.pop();
    frnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        dq.push_back(s[i]);
        if (s[i] == ')')
        {
            if (stk.empty()) ++frnt;
            else stk.pop();
        }
        else stk.push('(');
    }
    int cnt = stk.empty() && !frnt;
    for (int i = 0; i < s.size()-1; ++i)
    {
        if (s[i] == ')')
            --frnt;
        else ++frnt;
        if (s[i] == ')')
        {
            if (stk.empty()) ++frnt;
            else stk.pop();
        }
        else stk.push('(');
        cnt += stk.empty() && !frnt;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
        {
            swap(s[i], s[j]);
            it = chk();
            if (it > mx)
            {
                mx = it;
                a = i + 1;
                b = j + 1;
            }
            swap(s[i], s[j]);
        }
    cout << mx << "\n" << a << " " << b << "\n";
	return 0;
}
