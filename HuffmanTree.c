#include <stdio.h>
#include <stdlib.h>

//�������� �����ʵ��
//��������ڵ�
typedef struct node{
	int weight; //�ӵ�ȫ 
	char ch; //�ڵ�洢���ֽ� 
	struct node * left,* right;
}HuffNode;

//������������
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

//ʹ��ǰ������
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

//��������ж�ʮ���ڵ� ��ÿһ���ڵ㹹��һ������ʱ�� ��ɱ��� 
int main(void){
	HuffNode ** F; //��ʼ����ʮ���ڵ������ 
	F = (HuffNode **)malloc(20*sizeof(HuffNode *));
	int i;
	for(i = 0;i < 20;i++){
		F[i] = (HuffNode *)malloc(sizeof(HuffNode));
		F[i] -> weight = i + 1;
		char c = i + 97;
		F[i] -> ch = c;
		F[i] -> left = F[i] -> right = NULL;
	}
	//��������Ƚ��鷳 ���Բ���ѭ�� ��ʼ������ 
	HuffNode * root; //	���õ��Ķ�������һ���� 
	root = CreateHuffTree(F,20);
	PrintHuffTree(root);
	return 0;
}
