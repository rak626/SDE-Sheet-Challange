// =============================
// rotate image by 90 deg
// =============================


#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(mat[i][j] , mat[j][i]);
        }
    }
    for (int i = 0; i < n ; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }

}


/*======================
Merge Intervals
======================*/

#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> t(2);
    t = intervals[0];
    for (int i = 0; i < intervals.size(); i++) {
        if (t[1] >= intervals[i][0]) {
            t[1] = max(t[1] , intervals[i][1]);
        } else {
            ans.push_back(t);
            t = intervals[i];
        }
    }
    ans.push_back(t);
    return ans;
}

/*======================================================
Merge two sorted Arrays without extra space
======================================================*/

#include <bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // Write your code here.
    int size = m + n ;
    for (int i = m; i < size; i++) {
        arr1[i] = arr2[i - m];
    }

    int gap = ceil((float) size / 2);
    while (gap) {
        int i = 0 , j = gap;
        while (j < size) {
            if (arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            }
            i++; j++;
        }
        if (gap == 1) break;
        gap = ceil((float)gap / 2);
    }
    return arr1;

}
/*===================================
Find Duplicate in Array
===================================*/

#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n) {
    int fast = arr[0], slow = arr[0];
    do {
        fast = arr[arr[fast]];
        slow = arr[slow];
    } while ( fast != slow);

    fast = arr[0];
    while (fast != slow) {
        fast = arr[fast];
        slow = arr[slow];
    }
    return fast;
}

/*===================================
Missing and repeating numbers
===================================*/

// using sum and sqsum method (integer out of bound may be happen)
#include <bits/stdc++.h>
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    pair<int, int> p;
    long long sum = (long long)n * (n + 1) / 2;
    long long sqsum = (long long) n * (n + 1) * (2 * n + 1) / 6;
    long long temp, miss, rept;
    for (long long i = 0; i < n ; i++) {
        temp = (long long)arr[i];
        sum -= temp;
        sqsum -= temp * temp;
    }
    miss = (sum + (sqsum / sum)) / 2;
    rept = miss - sum;
    p.first = miss;
    p.second = rept;
    return p;
}


// using xor method (most optimized)
#include <bits/stdc++.h>
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++) {
        xor1 ^= arr[i];
    }
    for (int i = 1; i <= n ; i++) {
        xor1 ^= i;
    }
    int setbits = xor1 & ~(xor1 - 1);
    int x = 0 , y = 0 ;
    for (int i = 0; i < n ; i++) {
        if (setbits & arr[i] ) {
            x ^= arr[i];
        } else {
            y ^= arr[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (setbits & i) {
            x ^= i;
        } else {
            y ^= i;
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        return {y, x};
    }
    return {x, y};
}

/*===================================
Count Inversion
===================================*/

#include <bits/stdc++.h>

void merge(long long *arr, long long *temp, int s, int mid, int e, long long int& cnt) {
    int i = s;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            cnt += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= e) {
        temp[k++] = arr[j++];
    }
    //copying temp elements  back to the array
    for (int i = s; i <= e; i++)
        arr[i] = temp[i];
}
void mergesort(long long *arr, long long *temp, int s, int e, long long int& cnt) {
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergesort(arr, temp, s, mid, cnt);
    mergesort(arr, temp, mid + 1, e, cnt);
    merge(arr, temp, s, mid, e, cnt);
}


long long getInversions(long long *arr, int n) {
    // Write your code here.
    long long int cnt = 0;
    long long temp[n];
    mergesort(arr, temp, 0, n - 1, cnt);
    return cnt;
}