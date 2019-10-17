/*
typedef struct LRUCache{
    int key;
    int value;
    struct LRUCache *next;
    struct LRUCache *prev;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    static int max_cap = capacity;
    static int count = 0;
    static LRUCache *arr[10] = {0};
    LRUCache *head;
    head = (LRUCache *)malloc(sizeof(LRUCache));
   // tail = (LRUCache *)malloc(sizeof(LRUCache));
    //初始化双向链表
    head->next = NULL;
    head->prev = NULL;
 //   tail->prev = head;
  //  tail->next = NULL;
    
    head->key = -1;
    head->value = 0;
    //tail->key = -1;
    //tail->value = 0;
    
    return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
     LRUCache *head = obj;
    //key 最小最大范围不超过散列数组长度
    int hash_key = key%10;
    //判断是不是首节点，是则不变，是尾节点并且节点数大于等于2前插，节点数超过三则移动后前插。
        if(arr[hash_key] != NULL){
            if(head->next == arr[hash_key]){
                continue;
            }
            else if(count >= 2 && arr[hash_key] == NULL){
                arr[hash_key]->prev->next = NULL;
                
                //插入头部
                arr[hash_key]->next = head->next;
                head->next = arr[hash_key];
                
                arr[hash_key]->prev = head;
                arr[hash_key]->next->prev = arr[hash_key];
            }
            else{
                //断开
                
                arr[hash_key]->prev->next = arr[hash_key]->next;
                arr[hash_key]->next->prev = arr[hash_key]->prev;
                
                //插入头部
                arr[hash_key]->next = head->next;
                head->next = arr[hash_key];
                
                arr[hash_key]->prev = head;
                arr[hash_key]->next->prev = arr[hash_key];
            }
            return arr[hash_key]->value;
        }
        else{
            return -1;
        }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
   int hash_key = key%10;
    //密钥已经存在，无法插入；
    if(arr[hash_key] != NULL){
        printf("插入失败，链表中已有key与之相同\n");
    }
    
    //密钥不存在
    else{
    //未满插入添加散列值
            if(count <  max_cap){
                LRUCache *tmp = (LRUCache *)malloc(sizeof(LRUCache));
                tmp->key = key;
                tmp->value = value;
                //插入只有头结点，count加一
                if(obj->next == NULL){
                    count++;
                    obj->next = tmp;
                    tmp->prev = obj;
                }
                else{
                    count++;
                      //插入头部
                tmp->next = obj->next;
                obj->next = tmp;
                
                tmp->prev = obj;
                tmp->next->prev = tmp;
                }
                arr[hash_key] = tmp;
            }
    //满了修改散列值 
            else{
                if(count ==  max_cap){
                    //释放尾节点，并且修改散列。
                    LRUCache *tmp; 
                    while(tmp->next != NULL){
                        tmp = tmp->next;
                    }
                    arr[tmp->key%10] = 0;
                    lRUCacheFree(tmp);
                  
                    //插入头结点，并修改散列数组。
                    tmp = (LRUCache *)malloc(sizeof(LRUCache));
                    tmp->key = key;
                    tmp->value = value;
                    

                          //插入头部
                    tmp->next = obj->next;
                    obj->next = tmp;

                    tmp->prev = obj;
                    tmp->next->prev = tmp;
                }
            }
    }
}
void lRUCacheFree(LRUCache* obj) {
         LRUCache *tmp;
        while(obj->next != NULL){
            tmp = obj;
            obj = obj->next;
            free(tmp);
        }
        free(obj);
}

*/
/*
1.继续调试
2.
*/

