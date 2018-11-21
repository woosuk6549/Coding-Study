#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//바이토닉 부분수열 : S[0]<S[1]<...< S[k] >S[k+1]>S[k+2]>....>S[n]
int S[1001], cache[1001];
int n;

bool change = false;//내림차순으로 변화시 true
int func(int start) {
	int& ret = cache[start];
	if (ret != -1)return ret;

	ret = 1;

	for (int next = start + 1; next < n; ++next) {
		if (S[start] < S[next]&&change==false) {
			ret = max(ret,func(next)+1);
		}
		if (S[start] > S[next]) {
			change = true; 
			ret = max(ret, func(next) + 1);
			change = false;
		}
	}
	return ret;
}

int main() {
	

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> S[i];

	int max_result = 0;
	int result;
	for (int i = 0; i < n; ++i) {
		memset(cache, -1, sizeof(cache));
		result = func(i);
		if (max_result < result)
			max_result = result;
	}
	cout << max_result << endl;
	return 0;
}