#include <cstdlib>
#include <iostream>
#include "algorithm"
#include "cstring"
#include <vector>
#include <climits>

using namespace std;
void knapsack()
{
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W=50;
    int size=3;
    int K[size+1][W+1];
    
    for(int i=0; i<size+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0||j==0)
                K[i][j]=0;
            else if (j>=weight[i-1])
                K[i][j] = max(value[i-1]+K[i-1][j-weight[i-1]], K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    
    cout<<K[size][W]<<endl;
}

void UnboundedKnapsack()
{
    int val[] = {10, 40, 50, 70};
    int wt[]  = {1, 3, 4, 5} ;
    int W=8;
    int n=sizeof(val)/sizeof(val[0]);
    
    int dp[W+1];
    //intialize with 0, memset is declared in cstring
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=W; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i>=wt[j])
              dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
        }
    }
    
    cout<<dp[W]<<endl;
}

int FibonacciRecursive(int n)
{
    if(n<=1)
        return n;
    else
        return FibonacciRecursive(n-1)+ FibonacciRecursive(n-2);
}

int FibonacciDynamicBottomUp(int n)
{
    vector<int> fib(n+1);
    
    fib[0]=1;
    fib[1]=1;
    
    for (int i=2; i<=n; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    
    return fib[n];
    
}


//The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.
//For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.
int lisRecursive(int arr[], int n, int *max)
{
	if(n==1)
		return 1;
	int res;
	 // 'max_ending_here' is length of LIS ending with arr[n-1]
	int max_ending_here=1;

	 /* Recursively get all LIS ending with arr[0], arr[1] ...
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and
       max ending with arr[n-1] needs to be updated, then
       update it */
	for(int i=1;i<n;i++)
	{
		res = lisRecursive(arr, i, max);
		if(arr[i-1]<arr[n-1]&&res+1>max_ending_here)
			max_ending_here=res+1;
	}

	if(*max<max_ending_here)
		*max=max_ending_here;
}

//lis[i] stores the lis length at i so firstloop will calculate the length for every i while j always start from 0 for every i
//Complexity = O(n2)
int lis_Dynamic(int arr[], const int n)
{
	vector<int> lis(n);
	for(int i=0;i<n;i++)
		lis[i]=1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i])
				lis[i]= max(lis[i], lis[j]+1);
		}
	}

	int max_length;
	/* Pick maximum of all LIS values */
    for (int i = 0; i < n; i++ )
        if (max_length < lis[i])
            max_length = lis[i];
	return max_length;
}

//LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
//For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.
int lcsRecursive(string x, string y, int lx, int ly)
{
    if(lx==0||ly==0)
        return 0;
    else if(x[lx-1]==y[ly-1])
        return 1+lcsRecursive(x, y, lx-1, ly-1);
    else
        return max(lcsRecursive(x, y, lx-1, ly), lcsRecursive(x, y, lx, ly-1));
}


int lcsDynamic(string x, string y, int lx, int ly)
{
	vector<vector<int>> lcs;

	for(int i=0;i<=lx;i++)
	{
		for(int j=0;j<=ly;j++)
		{
			if(i==0||j==0)
				lcs[i][j]=0;
			else if(x[i]==y[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else 
				lcs[i][j]= max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	return lcs[lx][ly];
}

//Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.
//Insert, Remove, Replace
int EditDistanceRecursive(string x, string y, int lx, int ly)
{
	if(lx==0)
		return ly;
	if(ly==0)
		return lx;
	if(x[lx-1]==y[ly-1])
		return EditDistanceRecursive(x, y, lx-1, ly-1);
	else
		return 1+ min(EditDistanceRecursive(x, y, lx-1, ly), min(EditDistanceRecursive(x, y, lx-1, ly-1), EditDistanceRecursive(x, y, lx, ly-1)));
}

int EditDistanceDynamic(string x, string y, int lx, int ly)
{
	vector<vector<int>> ED;
	for(int i=0;i<=lx;i++)
	{
		for(int j=0;j<=ly;j++)
		{
			if(i==0)
				ED[i][j]=j;
			if(j==0)
				ED[i][j]=i;
			
            // If last characters are same, ignore last char
            // and recur for remaining string
			if(x[i-1]==x[j-1])
				ED[i][j]=ED[i-1][j-1];
			else
				ED[i][j]= 1+min(ED[i-1][j], min(ED[i-1][j-1],ED[i][j-1]));
		}
	}

	return ED[lx][ly];
}

//Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0)
//You can only traverse down, right and diagonally lower cells from a given cell
int MinCostPathRecursive(int cost[3][3], int m, int n)
{
    if(m<0||n<0)
        return INT_MAX;
    if(m==0&&n==0)
        return cost[m][n];
    else
        return cost[m][n]+min(MinCostPathRecursive(cost, m-1, n), min(MinCostPathRecursive(cost, m, n-1), MinCostPathRecursive(cost, m-1, n-1)));
}

int MinCostPathDynamic(int cost[3][3], int m, int n)
{
	vector<vector<int>> TC;
	TC[0][0]=cost[0][0];
	for (int i = 1; i <= m; i++)
		TC[i][0] = TC[i-1][0]+cost[i][0];
	for (int j = 1; j <= n; j++)
		TC[0][j] = TC[0][j-1]+cost[0][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{			
			TC[i][j]= cost[i][j]+min(TC[i-1][j], min(TC[i-1][j-1],TC[i][j-1]));
		}
	}

	return TC[m][n];
}