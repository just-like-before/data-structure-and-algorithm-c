#include <stdio.h>
#include <stdlib.h>
#define N 10
//�������ķǵݹ�Ӧ��
//�ڵ����Ͷ���
typedef struct node{
	int data;
	struct node * left,* right;
}BTNode;

//����һ�������� 
BTNode * CreateBinaryTree(int a[]){
	BTNode * root,* c,* pa,* p;
	int i;
	root = (BTNode *)malloc(sizeof(BTNode));
	root -> data = a[0];
	root -> left = root -> right = NULL;
	for(i = 1;i < N;i++){
		p = (BTNode *)malloc(sizeof(BTNode));
		p -> data = a[i];
		p -> left = p -> right = NULL;
		c = root;
		while(c){
			pa = c;
			if(c -> data > p -> data){
				c = c -> left;
			}else{
				c = c -> right;
			}
		}
		if(pa -> data > p -> data){
			pa -> left = p;
		}else{
			pa -> right = p;
		}
	}
	return root;
}

void PrintBinaryTree1(BTNode * root){
	if(root){
		printf("%d\t",root -> data);
		PrintBinaryTree1(root -> left);
		PrintBinaryTree1(root -> right);
	}
}

//��������һ���ǵݹ����  ǰȥ���� 
void PrintBinaryTree2(BTNode * root){
	BTNode * p;
	BTNode ** s;
	s = (BTNode **)malloc((N+2)*sizeof(BTNode));
	int top = -1;
	s[++top] = root;
	while(-1 - top){
		p = s[top--];
		printf("%d\t",p -> data);
		if(p -> right){
			s[++top] = p -> right;
		} 
		if(p -> left){
			s[++top] = p -> left;
		}
	}
	free(s);
}

int main(void){
	int a[N] = {3,2,5,8,4,7,6,9,1,10};
	BTNode * root;
	root = CreateBinaryTree(a);
	PrintBinaryTree1(root);
	printf("\n");
	PrintBinaryTree2(root);
} 
