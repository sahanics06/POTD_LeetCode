/*
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
 

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
 

Constraints:

1 <= num <= 1000
At most 1000 calls will be made in total to popSmallest and addBack.
*/

// Solution using vector to keep track of all the elements.

class SmallestInfiniteSet {
public:
    vector<int>nums;
    int i;
    SmallestInfiniteSet() {
        nums=vector<int>(1001, true);
        i=1;
    }
    
    int popSmallest() {
        int result=i;
        nums[i]=false;
        for(int j=i+1; j<1001; j++)
        {
            if(nums[j]==true)
            {
                i=j; 
                break;
            }
        }
        return result;
    }
    
    void addBack(int num) {
        nums[num]=true;
        if(num<i)
        {
            i=num;
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

//Solution using min heap to get the smallest number in O(1) and using set to check if duplicate ar not coming.

class SmallestInfiniteSet {
public:
    unordered_set<int>st;
    priority_queue<int, vector<int>, greater<int>>p;
    int cur_Smallest;
    SmallestInfiniteSet() {
        cur_Smallest=1;
    }
    
    int popSmallest() {
        int result;
        if(!p.empty())
        {
            result=p.top();
            p.pop();
            st.erase(result);
        }
        else
        {
            result=cur_Smallest;
            cur_Smallest++;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=cur_Smallest || st.find(num)!=st.end())
        {
            return;
        }
        st.insert(num);
        p.push(num);
    }
};

// Solution using ordered set. Reducing the need for priority queue.

class SmallestInfiniteSet {
public:
    set<int>st;
    int cur_Smallest;
    SmallestInfiniteSet() {
        cur_Smallest=1;
    }
    
    int popSmallest() {
        int result;
        if(st.size()!=0)
        {
            result=*st.begin();
            st.erase(st.begin());
        }
        else
        {
            result=cur_Smallest;
            cur_Smallest++;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=cur_Smallest || st.find(num)!=st.end())
        {
            return;
        }
        st.insert(num);
    }
};


