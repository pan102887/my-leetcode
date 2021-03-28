#include <iostream>
#include "../basic_tool/basic.h"

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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        ListNode *cur = head;
        int count = 1;
        while (cur->next)
        {
            cur = cur->next;
            count++;
        }
        int step = k % count;
        if (step == 0)
        {
            return head;
        }
        cur->next = head;
        int move = count - step;
        for (int i = 0; i < move; i++)
        {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};