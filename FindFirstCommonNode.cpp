/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	/*用栈来实现*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> sA,sB;
        ListNode *la,*lb;
        la = headA;
        lb = headB;
        if(headA == NULL || headB == NULL)
            return NULL;
        while(la != NULL)
        {
            sA.push(la);
            la = la->next;
        }
        while(lb != NULL)
        {
            sB.push(lb);
            lb = lb->next;
        }
        while(sA.size() != 0 && sB.size() != 0)
        {
            if(sA.top() == sB.top())
            {
                sA.pop();
                sB.pop();
            }
            else
                break;
        }
        if(sA.size() == 0 && sB.size() == 0)
            return headA;
        if(sA.size() != 0)
            return sA.top()->next;
        if(sB.size() != 0)
            return sB.top()->next;
    }
};

/*不是用栈*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL && headB == NULL)
            return NULL;
         int lenA,lenB;
         lenA = getListLength(headA);
         lenB = getListLength(headB);
         if(lenA < lenB)
         {
             for(int i=0;i<lenB-lenA;i++)
                 headB = headB->next;
         }
         else
         {
             for(int i=0;i<lenA-lenB;i++)
                headA = headA->next;
         }
         while(headA != NULL && headB != NULL && headA != headB)
         {
             headA = headA->next;
             headB = headB->next;
         }
         return headA;
    }
    
    int getListLength(ListNode *l)
    {
        int res = 0;
        ListNode *tmp = l;
        if(tmp == NULL)
            return 0;
        while(tmp != NULL)
        {
            res++;
            tmp = tmp->next;
        }
        return res;
    }