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
		printf("字符\t权\t左子女\t右子女\t双亲\n");
		printf("%c\t%d\t%d\t%d\t%d\n",f[i].word,f[i].weight,f[i].left,f[i].right,f[i].parent);
	}
}

int main(void){
	Huff * f;
	f = (Huff *)malloc((2*n-1)*sizeof(Huff));
	//初始化哈夫曼数组 
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
		//k1与k2在parent等于-1上 
		for(k1 = 0;k1 < n + loop && f[k1].parent != -1;k1++);
		for(k2 = k1 + 1;k2 < n + loop && f[k2].parent != -1;k2++);
		
		//找到最小和次小 
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
		
		//在数组中记录f[i]的左右子女 
		f[i].word = 'x';
		f[i].weight = f[k1].weight + f[k2].weight;
		f[i].left = k1;
		f[i].right = k2;
		f[i].parent = -1;
		
		//修改k1与k2的双亲
		f[k1].parent = f[k2].parent = i; 
	}
	
	//遍历数组
	printfArray(f); 
} 
