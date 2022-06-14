/*===================================================
Pair Sum 2-sum
===================================================*/

#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s) {
	vector<vector<int>> ans;
	map<int, int> m;
	for (int i = 0; i < arr.size(); i++) {
		int fkey = s - arr[i];
		if (m.find(fkey) != m.end()) {
			for (int j = 0; j < m[fkey]; j++) {
				vector<int> res(2);
				res[0] = fkey > arr[i] ? arr[i] : fkey;
				res[1] = fkey > arr[i] ? fkey : arr[i];
				ans.push_back(res);
			}
		}
		m[arr[i]]++;
	}
	sort(ans.begin(), ans.end());
	return ans;
}

/*===================================================
4-sum-Problem
===================================================*/

//leetcode
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& arr, int target) {
		int n = arr.size();
		vector<vector<int>> ans;
		if (n == 0) return ans;
		sort(arr.begin(), arr.end());
		for (int i = 0 ; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int target2 = target - (arr[i] + arr[j]);
				int l = j + 1, r = n - 1;
				while (l < r) {
					int pairSum = arr[l] + arr[r];

					if (pairSum < target2) l++;
					else if ( pairSum > target2) r--;
					else {
						vector<int> qurd(4, 0);
						qurd[0] = arr[i];
						qurd[1] = arr[j];
						qurd[2] = arr[l];
						qurd[3] = arr[r];
						ans.push_back(qurd);

						while (l < r && arr[l] == qurd[2]) ++l;
						while (l < r && arr[r] == qurd[3]) --r;
					}
				}
				while ( j + 1 < n && arr[j + 1] == arr[j])++j;
			}
			while (i + 1 < n && arr[i + 1] == arr[i]) ++i;
		}
		return ans;
	}
};

// codestudio
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
	unordered_map<int, pair<int, int>> mp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];
			mp[sum] = {i, j};
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int left = target - (arr[i] + arr[j]);

			if (mp.find(left) != mp.end())
			{
				pair<int, int> it = mp[left];
				int k = it.first;
				int l = it.second;

				if (i != k && i != l && j != k && j != l)
					return "Yes";
			}
		}
	}

	return "No";
}

/*===================================================
Longest Consecutive Sequence
===================================================*/

#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
	unordered_set<int> s;
	for (auto x : arr) s.insert(x);
	int maxLen = 0;
	for (auto x : arr) {
		if (s.find(x - 1) == s.end()) {
			int cnt = 1 , num = x + 1;
			while (s.find(num) != s.end()) {
				cnt++;
				num++;
			}
			maxLen = max(cnt, maxLen);
		}
	}
	return maxLen;
}

/*===================================================
Longest Subarray Zero Sum
===================================================*/

#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {
	unordered_map<int, int> m;
	int maxLen = 0, sum = 0;
	for (int i = 0 ; i < arr.size(); i++) {
		sum += arr[i];
		if (sum == 0) {
			maxLen = max(maxLen , i + 1);
		} else {
			if (m.find(sum) != m.end()) {
				maxLen = max(maxLen , i - m[sum]);
			} else {
				m[sum] = i;
			}
		}

	}
	return maxLen;
}

/*===================================================
Count Subarrays with Given XOR
===================================================*/

// XR = Y ^ K => Y = XR ^ K
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x) {
	map<int, int> m;
	int cnt = 0;
	int preXor = 0;
	for (auto it : arr) {
		preXor = preXor ^ it;
		if (preXor == x) cnt++;
		int y = preXor ^ x;
		if (m.find(y) != m.end()) {
			cnt += m[y];
		}
		m[preXor]++;
	}
	return cnt;
}

/*===================================================
Longest Substring Without Repeating Characters
===================================================*/


//move l after the duplicate ele. direct jump not step by step
#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
	int l = 0 , len = 0;
	int n = input.size();
	map<int, int> m;
	for (int r = 0 ; r < n; r++) {
		if (m.find(input[r]) != m.end()) {
			int dupPos = m[input[r]];
			if (dupPos >= l) {
				l = dupPos + 1;
			}
		}
		len = max(len, r - l + 1);
		m[input[r]] = r;

	}
	return len;
}
