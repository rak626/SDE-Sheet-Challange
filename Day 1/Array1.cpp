/*===================================
Set Matrix Zeros
===================================*/

#include <bits/stdc++.h>
void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	bool fc = 0, fr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			if ( i == 0 && matrix[i][j] == 0)
				fr = 1;
			if ( j == 0 && matrix[i][j] == 0)
				fc = 1;
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (int i = 1 ; i < n; i++) {
		for ( int j = 1; j < m; j++) {
			if (matrix[0][j] == 0 or matrix[i][0] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if (fc) {
		for ( int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}
	if (fr) {
		for ( int j = 0 ; j < m; j++) {
			matrix[0][j] = 0;
		}
	}
}
/*===================================
Pascal's Triangle
===================================*/

#include <bits/stdc++.h>
vector<vector<long long int>> printPascal(int n) {
	vector<vector<long long int>> ans(n);
	for (int i = 0; i < n ; i++) {
		ans[i].resize(i + 1);
		ans[i][0] = ans[i][i] = 1;
		for (int j = 1; j < i; j++) {
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	return ans;

}
/*===================================
next permutation
===================================*/

#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
	int idx, i ;
	for (i = n - 2; i >= 0 ; i--) {
		if (permutation[i] < permutation[i + 1]) {
			idx = i;
			break;
		}
	}
	if (i < 0 ) {
		reverse(permutation.begin(), permutation.end());
	} else {
		for (i = n - 1; i > idx; i--) {
			if (permutation[i] > permutation[idx]) {
				swap(permutation[i], permutation[idx]);
				break;
			}
		}
		reverse(permutation.begin() + idx + 1, permutation.end());
	}
	return permutation;
}
/*============================================
Kadane’s Algorithm / Maximum subarray sum
============================================*/

#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
	long long sum = 0, best = 0;
	for (int i = 0 ; i < n ; i++) {
		sum += arr[i];
		best = max (best , sum);
		if (sum < 0 ) sum = 0;
	}
	return best;
}

/*===================================
Sort an array of 0s, 1s and 2s
===================================*/
// Dutch national flag algorithm

#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
	int l = 0, itr = 0, h = n - 1;
	while (itr <= h) {
		switch (arr[itr]) {
		case 0: swap(arr[l++], arr[itr++]);
			break;
		case 1: itr++;
			break;
		case 2: swap(arr[itr], arr[h--]);
			break;
		}
	}
}

/*===================================
Stock buy and Sell
===================================*/

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
	
	int prev = prices[0], profit = 0;
	for(int i = 1; i < prices.size(); i++){
		profit = max(profit , prices[i] - prev);
		if(prev > prices[i]){
			prev = prices[i];
		}
	}
	return profit;
}
