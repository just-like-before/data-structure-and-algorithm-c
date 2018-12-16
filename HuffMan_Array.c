#include <stdio.h>
#include <stdlib.h>
#define n 10
typedef struct{
	char word;
	int weight;
	int left,right,parent;
	int * code;
}Huff;

void printfArray(Huff * f){
	int i;
	for(i = 0;i < (2*n-1);i++){
		printf("�ַ�\tȨ\t����Ů\t����Ů\t˫��\n");
		printf("%c\t%d\t%d\t%d\t%d\n",f[i].word,f[i].weight,f[i].left,f[i].right,f[i].parent);
	}
}

int main(void){
	Huff * f;
	f = (Huff *)malloc((2*n-1)*sizeof(Huff));
	//��ʼ������������ 
	int i;
	for(i = 0;i < n;i++){
		char word = i + 97;
		int weight = i + 1;
		f[i].word = word;
		f[i].weight = weight;
		f[i].left = f[i].right = f[i].parent = -1;
	}
	
	int loop,k1,k2;
	for(loop = 0;loop < n -1;loop++){
		//k1��k2��parent����-1�� 
		for(k1 = 0;k1 < n + loop && f[k1].parent != -1;k1++);
		for(k2 = k1 + 1;k2 < n + loop && f[k2].parent != -1;k2++);
		
		//�ҵ���С�ʹ�С 
		for(i = k2;i < n + loop;i++){
			if(f[i].parent != -1){
				if(f[i].weight < f[k1].weight){
					k2 = k1;
					k1 = i;
				}else if(f[i].weight < f[k2].weight){
					k2 = i;
				}
			} 
		}
		
		//�������м�¼f[i]��������Ů 
		f[i].word = 'x';
		f[i].weight = f[k1].weight + f[k2].weight;
		f[i].left = k1;
		f[i].right = k2;
		f[i].parent = -1;
		
		//�޸�k1��k2��˫��
		f[k1].parent = f[k2].parent = i; 
	}
	
	//��������
	printfArray(f); 
} 
