//递归方法

struct ListNode* newList = NULL;  

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //递归结束条件,把另外一个拼接起来
        if(l1 == NULL){
            newList->next = l2;
            return newList;
        }
        if(l2 == NULL){
            newList->next = l1;
            return newList;
        }
    
    //先给newList 赋一个节点才好递归
    if((newList==NULL) && (l1->val > l2->val)){
        newList = l2;
        l2 = l2->next;
    }
    if((newList == NULL) && (l1->val <= l2->val)){
        newList = l1;
        l1 = l1->next;
    }
    //链入新节点
    if(l1->val > l2->val){
        newList->next = l2;
        l2 = l2->next;
    }
    else{
        newList->next = l1;
        l1 = l1->next;
    }
    mergeTwoLists(l1, l2);
    return newList;
}




/*
递归方式还没实现,需要再调试
*/
