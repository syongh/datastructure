#include"ListNode.h"
#include<stdbool.h>

bool hasCycle(struct ListNode *head) {
   //同起点
    int pos = 0;
    int slow_num = 0;
    int fast_num = 0;
    struct ListNode *slow = head;
   struct ListNode* fast = head;
    
    //只能判断不小于两个节点
    while(fast && slow){
        //慢指针
        slow = slow->next;
        slow_num++;
        //不小于两个节点
        if(fast->next != NULL){
            fast = fast->next->next;
            fast_num++;
        }
        if(slow == fast){
            
            pos =  fast_num-slow_num;
            return true;
        }
    }
    pos = -1;
    return false;
}

/*
最后一个8000多的样本案例测试不通过
*/
