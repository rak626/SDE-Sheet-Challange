/*===========================
Search In A 2D Matrix
===========================*/

// optimal approach for gfg and better approach for leetcode
#include <bits/stdc++.h>
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
	int i = 0, j = n - 1;
	while (i < m and j >= 0) {
		if (mat[i][j] == target)
			return 1;
		if (mat[i][j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return 0;
}

//optimal approach for leetcode

#include <bits/stdc++.h>
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
	if (!mat.size()) return false;
	int l = 0, h = (m * n) - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		int cur = mat[mid / n][mid % n];
		if (cur == target) return 1;
		if ( target < cur) {
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return 0;
}
/*================================
Modular Exponentiation
================================*/

// codestudio code using mod
// using fast exponentiation
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	long ans = 1;
	long xx = x;
	while (n > 0) {
		if (n % 2 != 0) {
			ans = ((ans) % m * (xx) % m ) % m;
		}
		xx = ((xx) % m * (xx) % m) % m;
		n = n >> 1;
	}
	return (int) (ans % m);
}

//leetcode code
class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1.0;
		long long nn = n;
		if (nn < 0) nn = -1 * nn;
		while (nn) {
			if ( nn & 1) {
				ans *= x;
				nn -= 1;
			} else {
				x *= x;
				nn = nn / 2;
			}
		}
		if ( n < 0) ans = (double) (1.0) / (double) (ans);
		return ans;
	}
};

/*==================================
Majority element (> n /2 times)
==================================*/

#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n) {
	int ele = 0, cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		if (cnt == 0) {
			ele = arr[i];
		}
		if (arr[i] == ele) cnt++;
		else cnt--;
	}
	cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		if (ele == arr[i]) {
			cnt++;
		}
	}
	if (cnt > (n / 2)) return ele;
	return -1;
}

/*===================================
Majority Elements(>N/3 times)
===================================*/

#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr) {
	int n = arr.size();
	int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
	for (auto ele : arr) {
		if (ele == num1) c1++;
		else if (ele == num2) c2++;
		else if (c1 == 0) num1 = ele, c1 = 1;
		else if (c2 == 0) num2 = ele, c2 = 1;
		else c1--, c2--;
	}
	c1 = c2 = 0;
	for (auto ele : arr) {
		if (ele == num1) c1++;
		if (ele == num2) c2++;
	}
	vector<int> ans;
	if (c1 > n / 3 ) {
		ans.push_back(num1);
	}
	if (c2 > n / 3) {
		ans.push_back(num2);
	}
	return ans;
}

/*=====================
Grid Unique Paths
=======================*/

// by recursion
#include <bits/stdc++.h>

int findPaths(int i, int j, int m, int n) {
	if (i == m - 1 and j == n - 1) return 1;
	if (i >= m or j >= n) return 0;
	return findPaths(i + 1, j, m, n) + findPaths(i, j + 1, m, n);
}

int uniquePaths(int m, int n) {
	return findPaths(0, 0, m, n);
}

// by DP
#include <bits/stdc++.h>

int findPaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
	if (i == m - 1 and j == n - 1) return 1;
	if (i >= m or j >= n) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = findPaths(i + 1, j, m, n, dp) + findPaths(i, j + 1, m, n, dp);
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return findPaths(0, 0, m, n, dp);
}

// by Combinatorics
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
	int N = m + n - 2;
	int r =  n < m ? n - 1 : m - 1;
	double res = 1;
	for (int i = 1 ; i <= r; i++) {
		res = res * (N - r + i) / i;
	}
	return (int)res;
}

/*===================
Reverse Pairs
==================*/

//by modified margesort

#include <bits/stdc++.h>

void merge(vector<int>& arr, vector<int>& temp, int l, int mid, int h, int &cnt) {
	int i = l, j = mid + 1, k = l;

	while (i <= mid and j <= h) {
		if (arr[i] > 2 * arr[j]) {
			cnt += mid - i + 1;
			j++;
		} else {
			i++;
		}
	}
	i = l, j = mid + 1;
	while (i <= mid and j <= h) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= h) {
		temp[k++] = arr[j++];
	}
	for (i = l; i <= h; i++) {
		arr[i] = temp[i];
	}
}

void mergesort(vector<int>&arr, vector<int> &temp, int l, int h, int &cnt) {
	if (h > l) {
		int mid = l + (h - l) / 2;
		mergesort(arr, temp, l, mid, cnt);
		mergesort(arr, temp, mid + 1, h, cnt);
		merge(arr, temp, l, mid, h, cnt);
	}
}

int reversePairs(vector<int> &arr, int n) {
	int cnt = 0;
	vector<int> temp(n, 0);
	mergesort(arr, temp, 0, n - 1, cnt);
	return cnt;
}
