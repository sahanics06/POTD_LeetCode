/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of 
consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times 
you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.
 

Constraints:

n == answerKey.length
1 <= n <= 5 * 104
answerKey[i] is either 'T' or 'F'
1 <= k <= n
  */

// Solution optimistic- Single pass. Sliding Window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length(), i=0, j=0, result=0;
        unordered_map<char, int>mp;
        while(i<n)
        {
            mp[answerKey[i]]++;
            while(min(mp['F'], mp['T'])>k)
            {
                mp[answerKey[j]]--;     // We flip the character whose frequency is less
                j++;
            }
            result=max(result, i-j+1);
            i++;
        }
        return result;
    }
};


// Solution using Sliding window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ansf=0, anst=0, t=0, f=0, i=0, tj=0, fj=0, n=answerKey.length();
        while(i<n)
        {
            if(answerKey[i]=='T')
            {
                t++;
            }
            else
            {
                f++;
            }
            if(t>k)
            {
                while(t>k&&fj<i)
                {
                    t-=answerKey[tj]=='T';                    
                    tj++;
                }
            }
            if(f>k)
            {
                while(f>k &&tj<i)
                {
                    f-=answerKey[fj]=='F';
                    fj++;
                }
            }
            anst=max(anst, i-tj+1);
            ansf=max(ansf, i-fj+1);
            i++;
        }
        return max(ansf, anst);
    }
};


// Solution Sliding Window- Two pass

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0, j=0, countT=0, countF=0, result=0, n=answerKey.length();
        while(i<n)
        {
            if(answerKey[i]=='F')
            {
                countF++;
            }
            if(countF>k)
            {
                while(countF>k)
                {
                    if(answerKey[j]=='F')
                    {
                        countF--;
                    }
                    j++;
                }
            }
            result=max(result, i-j+1);
            i++;
        }
        i=0, j=0;

        while(i<n)
        {
            if(answerKey[i]=='T')
            {
                countT++;
            }
            if(countT>k)
            {
                while(countT>k)
                {
                    if(answerKey[j]=='T')
                    {
                        countT--;
                    }
                    j++;
                }
            }
            result=max(result, i-j+1);
            i++;
        }
        return result;
    }
};

// Solution Brute Force

class Solution {
public:
    int result;
    int n;
    void findMax(string &answerKey)
    {
        int length=0;
        int i=0;
        while(i<n)
        {
            if(answerKey[i]=='T')
            {
                length=1;
                i++;
                while(i<n && answerKey[i]=='T')
                {
                    length++;
                    i++;
                }
                result=max(result, length);
            }
            else
            {
                length=1;
                i++;
                while(i<n && answerKey[i]=='F')
                {
                    length++;
                    i++;
                }
                result=max(result, length);
            }
        }
    }
    void solve(string &answerKey, int i, int k)
    {
        findMax(answerKey);
        if(i>=n || k<=0)
        {
            return;
        }
        answerKey[i]=answerKey[i]=='T'?'F':'T';
        solve(answerKey, i+1, k-1);
        answerKey[i]=answerKey[i]=='T'?'F':'T';
        solve(answerKey, i+1, k);
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        n=answerKey.length();
        solve(answerKey, 0, k);
        return result;
    }
};

