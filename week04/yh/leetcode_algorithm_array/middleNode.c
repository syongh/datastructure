/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int pow;
            struct ListNode* slow;
            struct ListNode* fast;
    //有一个节点或者没有节点
    if(head == NULL){
       pow = -1;
        return head;
    }
    else if(head->next == NULL){
        pow = head->val;
            return head;
    }
    else{
            //有两个节点和三个节点

            slow = head;
            fast = head->next->next;
        while(1){
            /*
            //1.双数slow的下一个节点fast == NULL;
            if(fast == NULL){
                slow = slow->next;
                break;
            }
            */
            //2.单数slow的当前节点下一个。fast->next == NULL;
            if(fast == NULL || fast->next == NULL){
                slow = slow->next;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    pow = slow->val;
    return slow;
}




/*
leetcode 876题
*/

//标准答案

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next) {       
        fast = fast->next->next;
        slow = slow->next;          
    }
    return slow;
}






//标准答案

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* temp = head;
    int sumCount = 0;
    int nodeIdx = 0;
    
    if (head == NULL) {
        return head;
    }
    
    while (temp) {
        sumCount++;
        temp = temp->next;
    }
    
    nodeIdx = sumCount / 2 + 1;

    temp = head;
    nodeIdx--;
    while (nodeIdx) {
        temp = temp->next;
        nodeIdx--;
    }
    
    return temp;
}











