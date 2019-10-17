/*
19  21   876  146  141 206链表
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int count = 0;
    struct ListNode* temp = head;
    //链表空
    if(temp == NULL){
        return NULL;
    }
    //计算节点数
    while(temp){
        count++;
        temp = temp->next;
    }
    
    temp = head;
    count = count - n;
    
    //检查是否为第一个节点或者只有一个节点
    if(count != 0){
        count--;
    //确定节点位置
    while(count){
        temp = temp->next;
        count--;
    }
        temp->next = temp->next->next;
    }
    else{
        if(head->next != NULL){
            head = head->next;
            free(temp);
        }    
        else{
            head = NULL;
            free(temp);
        }
        return head;
    }
    return head;
}
