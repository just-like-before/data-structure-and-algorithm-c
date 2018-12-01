#include <stdio.h>
#include <stdlib.h>
#define N 10
//�ṹ�嶨������������� 
typedef struct node{
	int data;
	struct node * left,* right;
}BTNode;

//����һ�������� 
BTNode * CreateBinaryTree(int a[]) {
	BTNode * root,* c,* pa,* p;
	//�������ڵ� 
	root = (BTNode *)malloc(sizeof(BTNode));
	root -> data = a[0];
	root -> left = root -> right = NULL;
	int i;
	for(i = 1;i < N;i++){
		//�����Ǹ��ڵ� 
		p = (BTNode *)malloc(sizeof(BTNode));
		p -> data = a[i];
		p -> left = p -> right = NULL;
		c = root;
		//Ѱ��������ڵ�ĸ��ڵ� 
		while(c){
			pa = c;
			if(c -> data > p -> data){
				c = c -> left;
			}else{
				c = c -> right;
			}
		}
		//�����ڵ��������� 
		if(pa -> data > p -> data){
			pa -> left = p;
		}else{
			pa -> right = p;
		}
	}
	return root;
}

//�������ĵݹ���� ǰ�����
void PrintBinaryTree1(BTNode * root){
	if(root){
		printf("%d\t",root -> data);
		PrintBinaryTree1(root -> left);
		PrintBinaryTree1(root -> right);
	}
} 

//�������ĵݹ���� ������� 
void PrintBinaryTree2(BTNode * root){
	if(root){
		PrintBinaryTree2(root -> left);
		printf("%d\t",root -> data);
		PrintBinaryTree2(root -> right);
	}
}

//�������ĵݹ���� ��������
void PrintBinaryTree3(BTNode * root){
	if(root){
		PrintBinaryTree3(root -> left);
		PrintBinaryTree3(root -> right);
		printf("%d\t",root -> data);
	}
} 
 
int main(void){
	int a[N] = {3,2,5,8,4,7,6,9,10,11};
	BTNode * root;
	root = CreateBinaryTree(a);
	PrintBinaryTree1(root);
	printf("\n");
	PrintBinaryTree2(root);
	printf("\n");
	PrintBinaryTree3(root);
} 
