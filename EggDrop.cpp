#include<bits/stdc++.h>
using namespace std;

//Using Recursion
int solve(int e, int f) {
	if(f == 0 || f == 1) {
		return f;
	}
	if(e == 1) {
		return f;
	}
	int min = INT_MAX;
	for(int k=1;k<=f;k++) {
		int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
		if(temp < min) {
			min = temp;
		}
	}
	return min;
}

//Using Memoization
int solve_Mem(int e, int f) {
	int dp[11][51];
	memset(dp, -1, sizeof(dp));
	if(e == 1) {
		return f;
	}
	if(f == 0 || f == 1) {
		return f;
	}
	if(dp[e][f] != -1) {
		return dp[e][f];
	}
	int min = INT_MAX;
	for(int k=1;k<=f;k++) {
		int temp = 1 + max(solve_Mem(e-1, k-1), solve_Mem(e, f-k));
		if(temp < min) {
			min = temp;
		}
	}
	dp[e][f] = min;
	return min;
}

int main() {
	int e, f;
	cout<<"Enter the number of eggs: ";
	cin>>e;
	cout<<"Enter the number of floors: ";
	cin>>f;
	int ans = solve(e, f);
	cout<<"Minimum number of ways to find the threshold floor using Recursion is: "<<ans<<endl;
	int ans1 = solve_Mem(e, f);
	cout<<"Minimum number of ways to find the threshold floor using Memoization is:"<<ans1<<endl;
	return 0;
}
