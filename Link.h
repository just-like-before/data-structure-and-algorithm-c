/*
单向非空链表的常用创建
以及常用的方法 
*/ 
#include <stdio.h>
#include <stdlib.h>
#define N 5

//链表的类型 
typedef struct node{
	int data;
	struct node * next;
}ElemSN;

//创建链表 
ElemSN * CreateLink(int a[]){
	int i;
	ElemSN * p,* head = NULL,* tail;
	for(i = 0;i < N;i++){
		p = (ElemSN *)malloc(sizeof(ElemSN));
		p -> data = a[i];
		p -> next = NULL;
		if(!head){
			head = tail = p;
		}else{
			tail = tail -> next = p;
		}
	}
	return head;
}

//寻找最大值结点
ElemSN * MaxNode(ElemSN * head){
	ElemSN * p,* pmax;
	for(pmax = head,p = head -> next;p;p = p -> next){
		if(p -> data > pmax -> data){
			pmax = p;
		}
	}
	return pmax;
} 


//找到值为key的链表
ElemSN * FindKeyLink(ElemSN * head,int key){
	ElemSN * p;
	for(p = head;p && p -> data - key;p = p -> next);
	return p;
}

//将链表逆向输出
ElemSN * LinkReversal(ElemSN * head){
	ElemSN * p = NULL,* t;
	while(head){
		t = head;
		head = head -> next;
		t -> next = p;
		p = t;
		
		
	}
	return p;
} 

//得到链表的结点的个数
int NodeCount(ElemSN * head){
	int count = 0;
	ElemSN * p;
	for(p = head;p;p = p -> next){
		count++;
	}
	return count;
}

//升序排列，尾插
ElemSN * AscendingSort(ElemSN * head){
	ElemSN *q,* p,* pm,* qm,* h1 =NULL;
	while(head){
		for(q = pm = head,p = head -> next;p;q = p,p = p -> next){
			if(pm -> data < p -> data){
				pm = p;
				qm = q;
			}
		}
		if(pm - head){
			qm -> next = pm -> next;
		} else{
			head = head -> next;
		}
		pm -> next = h1;
		h1 = pm;
	}
	return h1;
} 

//将head1和head2两个升序列表合并为一个升序链表
ElemSN * CombineAscendingLink(ElemSN * head1,ElemSN * head2){
	ElemSN * t,* h = NULL,* p;
	while(head1 && head2){
		if(head1 -> data < head2 -> data){
			p = head1;
			head1 = head1 -> next;
		}else{
			p = head2;
			head2 = head2 -> next;
		}
		p -> next = NULL;
		if(!h){
			h = t = p;
		}else{
			t = t -> next = p;
		}
	}
	if(head1){
		t = head1;
	}else{
		t = head2;
	}
	return h;
} 

//选择排序，升序
ElemSN * SelectSort(ElemSN * head){
	ElemSN * p,* q,* pmin,* qmin =  NULL,* h1 = NULL,* t;
	q = pmin = head;
	p = head -> next;
	while(head){
		//找出最小的节点 
		for(q = pmin = head,p = head -> next;p;q = p,p = p -> next){
			if(pmin -> data > p -> data){
				pmin = p;
				qmin = q;
			}
		}
		//删除 
		if(pmin - head){
			qmin -> next = pmin -> next;
		}else{
			head = head -> next;
		}
		
		//正建立链表 
		pmin -> next = NULL;
		if(h1){
			t = t -> next = pmin;
		} else{
			h1 = t = pmin;
		}
	} 
	return h1;
} 

//遍历链表 
void PrintLink(ElemSN * head){
	ElemSN * p;
	for(p = head;p;p = p -> next){
		printf("%d\n",p -> data);
	}
}


