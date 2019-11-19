#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int P = 1e9 + 7;

string s;
int len;
int cal()
{
	int pos = 0, tmp = 0, mx = -1e9,cnt=0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == ')') ++tmp;
		else --tmp;
		if (tmp > mx) {
			mx = tmp;
			pos = (i + 1) % len;
		}
	}
	tmp = 0;
	for (int i = pos; i < len; ++i) {
		if (s[i] == '(') --tmp;
		else ++tmp;
		if (tmp == 0) ++cnt;
	}
	for (int i = 0; i < pos; ++i) {
		if (s[i] == '(') --tmp;
		else ++tmp;
		if (tmp == 0) ++cnt;
	}
	return cnt;
}
int main()
{ 
	int n;
	cin >> n;
	cin >> s;
	len = s.length();
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '(') ++sum;
		else --sum;
	}
	if (sum != 0) {
		puts("0");
		puts("1 1");
	}
	else {
		int ans = 0,l=1,r=1;
		for (int i = 0; i < len; ++i) {
			for (int j = i; j < len; ++j) {
				swap(s[i], s[j]);
				int tmp = cal();
				if (tmp > ans)
				{
					ans = tmp;
					l = i, r = j;
				}
				swap(s[i], s[j]);
			}
		}
		printf("%d\n", ans);
		printf("%d %d\n", l+1, r+1);
	}
}