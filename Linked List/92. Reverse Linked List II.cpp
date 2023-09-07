/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the 
list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
  */

// Solution

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=0;
        if(head->next==NULL || left==right)
            return head;
        ListNode *cur=head, *first, *second, *start, *end;
        while(cur)
        {
            count++;
            if(count==left-1)
            {
                first=cur;
                start=cur->next;
            }
            if(count==right)
            {
                end=cur;
                break;
            }
            cur=cur->next;
        }
        second=cur->next;
        
        cur=start;
        if(left==1)
            cur=head;
        count=left;
        ListNode *prev=NULL, *tmp;
        while(count<=right && cur)
        {
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
            count++;
        }
        if(left==1)
        {
            head->next=second;
            head=prev;
        }
            
        else
        {
            first->next=prev;
            start->next=second;
        }       
        
        return head;
    }
};
