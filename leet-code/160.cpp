struct ListNode {
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    int calcLenght(ListNode *head)
    {
        if (!head)
            return 0;

        int i = 0;
        for (; head != nullptr; ++i, head = head->next)
            continue;
    }

  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = calcLenght(headA), lenghtB = calcLenght(headB);

        if (lengthA > lenghtB)
            for (int i = 0; i < lengthA - lenghtB; ++i)
                headA = headA->next;
        else
            for (int i = 0; i < lenghtB - lengthA; ++i)
                headB = headB->next;

        for (; headA != nullptr; headA = headA->next, headB = headB->next)
            if (headA == headB)
                return headA;

        return nullptr;
    }
};
