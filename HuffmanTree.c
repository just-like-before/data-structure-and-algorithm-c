#include <stdio.h>
#include <stdlib.h>

//哈夫曼树 链表的实现
//定义链表节点
typedef struct node{
	int weight; //接的全 
	char ch; //节点存储的字节 
	struct node * left,* right;
}HuffNode;

//创建哈夫曼树
HuffNode * CreateHuffTree(HuffNode ** F,int n){
	HuffNode * p;
	int loop,i,k1,k2;
	for(loop = 1;loop < n;loop++){
		for(k1 = 0;k1<n&&!F[k1];k1++);
		for(k2 = k1+1;k2<n&&!F[k2];k2++);
		for(i = k2;i < n;i++){
			
			if(F[i]){
				if(F[i] -> weight < k1){
					k2 = k1;
					k1 = i;
				}else if(F[i] -> weight < k2){
					k2 = i;
				}
			}
		}
		p = (HuffNode *)malloc(sizeof(HuffNode));
		p -> ch = 'x';
		p -> weight = F[k2] -> weight;
		p -> left = F[k2];
		p -> right = F[k1];
		F[k1]  = p;
		F[k2] = NULL;
	}
	return p;
} 

//使用前驱遍历
void PrintHuffTree(HuffNode * h){
	if(h){
		if(h -> ch == 'x'){
			PrintHuffTree(h -> left);
			PrintHuffTree(h -> right);
		}else{
			printf("%c\t",h -> ch);
			printf("%d\n",h -> weight);
			PrintHuffTree(h -> left);
			PrintHuffTree(h -> right);
		}
	}
} 

//这个链表共有二十各节点 当每一个节点构成一个树的时候 完成编码 
int main(void){
	HuffNode ** F; //初始化二十个节点个链表 
	F = (HuffNode **)malloc(20*sizeof(HuffNode *));
	int i;
	for(i = 0;i < 20;i++){
		F[i] = (HuffNode *)malloc(sizeof(HuffNode));
		F[i] -> weight = i + 1;
		char c = i + 97;
		F[i] -> ch = c;
		F[i] -> left = F[i] -> right = NULL;
	}
	//由于输出比较麻烦 所以采用循环 初始化链表 
	HuffNode * root; //	最后得到的二叉树的一个根 
	root = CreateHuffTree(F,20);
	PrintHuffTree(root);
	return 0;
}
