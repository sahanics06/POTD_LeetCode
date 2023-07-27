/*
You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. 
You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert 
another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and 
inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.

Example 1:

Input: n = 2, batteries = [3,3,3]
Output: 4
Explanation: 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.

Example 2:

Input: n = 2, batteries = [1,1,1,1]
Output: 2
Explanation: 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.

Constraints:

1 <= n <= batteries.length <= 105
1 <= batteries[i] <= 109
  */

// Solution using Binary Search. Most optimised

class Solution {
public:
    bool solve(long long m, vector<int>&arr, int n)
    {
        long long avg;
        int sz=arr.size();
        long long sum=0;
        avg=n*m; // We have to get the average from the minimum of batteries or m
        for(int i=0; i<sz; i++)
        {
            avg-=min(m, (long long)arr[i]);  // We have taken minimum because that is the value a battery can give other battery
            if(avg<=0)                       // We can also make a sum variable and add the minimum and if sum>=avg then return true
                return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(), batteries.end());
        long long sum=0;
        for(int i=0; i<batteries.size(); i++)
        {
            sum+=batteries[i];
        }
        long long r=sum/n; // r=avg because that is the highest value we can have after distribution
        long long result=l;
        while(l<=r)
        {
            long long m=l+(r-l)/2;
            if(solve(m, batteries, n))
            {
                result=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return result;
    }
};

// Solution using Brute Force, using queue and decrementing every time the front value and poping it and again pusing it after completing n times over battery. TLE

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long count=0;
        priority_queue<int>pq;
        int sz=batteries.size();
        for(int i=0; i<sz; i++)
        {
            pq.push(batteries[i]);
        }
        while(pq.size()>=n)
        {
            vector<int>vec;
            for(int i=0; i<n; i++)
            {
                int tmp=pq.top();
                pq.pop();
                tmp-=1;
                if(tmp>0)
                {
                    vec.push_back(tmp);
                }
            }
            for(auto it:vec)
            {
                pq.push(it);
            }
            count++;
        }
        return count;
    }
};
