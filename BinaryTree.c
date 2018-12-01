#include <stdio.h>
#include <stdlib.h>
#define N 10
//结构体定义二叉树的类型 
typedef struct node{
	int data;
	struct node * left,* right;
}BTNode;

//创建一个二叉树 
BTNode * CreateBinaryTree(int a[]) {
	BTNode * root,* c,* pa,* p;
	//创建根节点 
	root = (BTNode *)malloc(sizeof(BTNode));
	root -> data = a[0];
	root -> left = root -> right = NULL;
	int i;
	for(i = 1;i < N;i++){
		//创建非根节点 
		p = (BTNode *)malloc(sizeof(BTNode));
		p -> data = a[i];
		p -> left = p -> right = NULL;
		c = root;
		//寻找这个给节点的父节点 
		while(c){
			pa = c;
			if(c -> data > p -> data){
				c = c -> left;
			}else{
				c = c -> right;
			}
		}
		//将根节点插入二叉树 
		if(pa -> data > p -> data){
			pa -> left = p;
		}else{
			pa -> right = p;
		}
	}
	return root;
}

//二叉树的递归遍历 前序遍历
void PrintBinaryTree1(BTNode * root){
	if(root){
		printf("%d\t",root -> data);
		PrintBinaryTree1(root -> left);
		PrintBinaryTree1(root -> right);
	}
} 

//二叉树的递归遍历 中序遍历 
void PrintBinaryTree2(BTNode * root){
	if(root){
		PrintBinaryTree2(root -> left);
		printf("%d\t",root -> data);
		PrintBinaryTree2(root -> right);
	}
}

//二叉树的递归遍历 后续遍历
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
