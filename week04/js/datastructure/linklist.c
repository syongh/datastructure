#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct linklist{
	datatype data;
	struct linklist *next
}linklist;  
int go_on(){
	int flag=1;
	char choice;
	while(1){
		printf("继续吗？[Y/N]");
		choice=getchar();
		if(choice=='Y'||choice=='y')
				break;
		else if(choice=='N'||choice=='n')
				flag=0;
				break;
	}
}
linklist* create_linklist(datatype n){
		linklist *head=(linklist*)malloc(sizeof(linklist));
		head->data=n;
		head->next=	NULL;
		return head;
}
int length_linklist(linklist *l){
	linklist *p=l->next;
	int k;
	k=0;
	while(p!=NULL){
		k++;
		p=p->next;
	}
	return k;	
}
linklist *locatei_linklist(linklist *l,int i){
	linklist *p=l;
	int j=0;
	while(p->next!=NULL&&j<=i){
		j++;
		p=p->next;
	}
	if(j==i)
			return p;
	else 
			return (NULL); 
}
int insert_linklist(linklist *l,int i,datatype x){
	linklist *p, *s;
	int len;
	len=length_linklist(l);
	if(i<1||i>len+1){
		printf("插入位置不对\n");
		return 0;
	}
	p=locatei_linklist(l,i-1);
	s=(linklist*)malloc(sizeof(linklist));
	if(s==NULL){
		printf("内存分配失败\n");
		exit(-1);
	}
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
void insert(linklist *l){
	datatype x;
	int i,flag=1,insertflag;
	while(flag){
		printf("请输入要插入元素位置\n");
		scanf("%d",&i);
		printf("请输入要插入的元素\n ");
		scanf("%d",&x);
		insertflag=insert_linklist(l,i,x);
		if(insertflag==1)
				printf("插入成功\n");
		else
				printf("插入失败\n");
	flag=go_on();		

	}
}


void bubblesort(linklist *l){
	int len=length_linklist(*head);
	linklist *temp;
	for(int i=0;i<len-1;i++){
		linklist *t =l;
		linklist *p=t->next;
		linklist *q=p->next;
		int flag=1;
		for(int j=0;j<len-1-i;j++){
			if(p->data > q->data){
				t->next=q;
				p->next=q->next;
				q->next=p;
				temp=p;
				p=q;
				q=temp;
				flag=0;
		    }
			t=t->next;
			p=t->next;
			q=p->next;
	
		}
	if(flag)
	break;
	}
}

int main(){
		int d;
	printf("print the headnode's data\n");
	scanf("%d",&d);
	linklist *head=create_linklist(d);
	return  0;
}

