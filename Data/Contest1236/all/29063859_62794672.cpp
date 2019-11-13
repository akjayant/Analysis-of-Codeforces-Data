/*
ID: espr1t
TASK: 
KEYWORDS: 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 303;

int n;

int main(void) {
//	in = fopen("C.in", "rt");

	fscanf(in, "%d", &n);

//  set <int> nums;	
//	for (int i = 1; i <= n * n; i++)
//	    nums.insert(i);
//	int target = n * (n * n + 1) / 2;

	deque <int> q[MAX];
	for (int i = 0; i < n; i++) {
	    for (int num = 1; num <= n; num++)
	       q[i].push_back(i * n + num);
    }
    int parity = 0;
    for (int i = 0; i < n; i++) {
        vector <int> chosen;
        for (int group = 0; group < n; group++) {
            if (parity & 1) {
                chosen.push_back(q[group].back());
                q[group].pop_back();
            } else {
                chosen.push_back(q[group].front());
                q[group].pop_front();
            }
            parity = !parity;
        }
        for (int c = 0; c < (int)chosen.size(); c++)
            fprintf(out, "%d%c", chosen[c], c + 1 == (int)chosen.size() ? '\n' : ' ');
    }
	
	
	return 0;
}
