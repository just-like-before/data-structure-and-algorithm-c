/*
����ǿ�����ĳ��ô���
�Լ����õķ��� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#define N 5

//��������� 
typedef struct node{
	int data;
	struct node * next;
}ElemSN;

//�������� 
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

//Ѱ�����ֵ���
ElemSN * MaxNode(ElemSN * head){
	ElemSN * p,* pmax;
	for(pmax = head,p = head -> next;p;p = p -> next){
		if(p -> data > pmax -> data){
			pmax = p;
		}
	}
	return pmax;
} 


//�ҵ�ֵΪkey������
ElemSN * FindKeyLink(ElemSN * head,int key){
	ElemSN * p;
	for(p = head;p && p -> data - key;p = p -> next);
	return p;
}

//�������������
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

//�õ�����Ľ��ĸ���
int NodeCount(ElemSN * head){
	int count = 0;
	ElemSN * p;
	for(p = head;p;p = p -> next){
		count++;
	}
	return count;
}

//�������У�β��
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

//��head1��head2���������б�ϲ�Ϊһ����������
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

//ѡ����������
ElemSN * SelectSort(ElemSN * head){
	ElemSN * p,* q,* pmin,* qmin =  NULL,* h1 = NULL,* t;
	q = pmin = head;
	p = head -> next;
	while(head){
		//�ҳ���С�Ľڵ� 
		for(q = pmin = head,p = head -> next;p;q = p,p = p -> next){
			if(pmin -> data > p -> data){
				pmin = p;
				qmin = q;
			}
		}
		//ɾ�� 
		if(pmin - head){
			qmin -> next = pmin -> next;
		}else{
			head = head -> next;
		}
		
		//���������� 
		pmin -> next = NULL;
		if(h1){
			t = t -> next = pmin;
		} else{
			h1 = t = pmin;
		}
	} 
	return h1;
} 

//�������� 
void PrintLink(ElemSN * head){
	ElemSN * p;
	for(p = head;p;p = p -> next){
		printf("%d\n",p -> data);
	}
}


