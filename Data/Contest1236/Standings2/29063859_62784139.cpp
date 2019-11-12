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

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 1024;

int main(void) {
//	in = fopen("A.in", "rt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	
	for (int t = 0; t < numTests; t++) {
	    int a, b, c;
	    fscanf(in, "%d %d %d", &a, &b, &c);
	    int ans = 0;
	    while (b >= 1 && c >= 2) {
	        ans += 3;
	        b -= 1, c -= 2;
        }
	    while (a >= 1 && b >= 2) {
	        ans += 3;
	        a -= 1, b -= 2;
        }
        fprintf(out, "%d\n", ans);
    }
	
	return 0;
}
