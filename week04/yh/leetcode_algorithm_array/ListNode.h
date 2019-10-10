
//definition for singly-linked list

typedef struct ListNode{

	int val;
	struct ListNode *next;

}list, *listptr;

//创建链表
listptr Create_head();

//释放链表
void Free_list(listptr head);


//头插法
void Add_node(listptr head, int val);
