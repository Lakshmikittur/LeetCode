/*Question: Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *mid = findMid(head);
        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(mid);
        ListNode *newhead = merge(list1,list2);
        return newhead;
        
    }
    
    ListNode* findMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *temp;
      
        while(fast && fast->next)
        {
            temp=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
       temp->next = NULL;
       return slow;
    }
    
    ListNode *merge(ListNode *list1, ListNode* list2)
    {
        if(!list1) return list2;
        if(!list2) return list1;
                
      
            if(list1->val < list2->val)
            {
                list1->next = merge(list1->next,list2);
                return list1;
            }
            
              
            list2->next = merge(list1,list2->next);
            return list2;       
        
    }
};

//Solution takes O(n logn) time and O(1) memory (i.e. constant space)
