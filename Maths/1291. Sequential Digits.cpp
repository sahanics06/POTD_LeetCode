/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:

10 <= low <= high <= 10^9

  */

// Solution- Finding the length of low and high by converting to string and then using length(), Now we loop from c=low 
// length to c<=high length; inside that we loop from i=1 to 9 and inside that we loop to find number of length c using 
// string. If it is in range then push in answer

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int c=0;
        string a= to_string(low);
        string b= to_string(high);
        int d=b.length();
        c=a.length();
        vector<int>ans;
        while(c<=d)
        {
            for(int i=1; i<9; i++)
            {
                string s="";
                int t=c;
                int j=i;
                while(t && j<=9)
                {
                    char ch=j+'0';
                    s+=ch;
                    j++;
                    t--;
                }
                if(s.length()==c)
                {
                    int tmp = stoi(s);
                    if(tmp>=low && tmp<=high)
                        ans.push_back(tmp);
                }
            }
            c++;
        }   
        return ans;     
    }
};
