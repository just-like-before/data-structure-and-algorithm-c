#include <stdio.h>
#include <stdlib.h>
//五十个物品 
#define N 50
//箱子的体积是六十 
#define V 60
//贪心算法 装箱问题 
/*
1.计算当前最优解  也是局部的最优解
2.贪心算法 计算后不能再改变 
*/ 

//定义物品的类型 物品有体积 和 记号进行标记
typedef struct{
	int goodsNo; //物品的记号
	int goodsVol; //物品的体积 
}Goods; 

//定义物品的节点类型 不知道一个箱子存储几个 物品所以使用链表
typedef struct goodsNode{
	int goodsNo; //物品的编号 
	struct goodsNode * next;  
}GN; 

//定义箱子的类型 不知道到使用多少个箱子
//所以使用链表 
//其中箱子	记录 存储在其中的一个物品链表的头结点 和箱子剩余的体积
typedef struct boxNode{
	int residueVol; //节点的剩余体积 
	GN * goodsHead; //箱子节点中物品链表的头结点 
	struct boxNode * next;
}BN;

//装箱 
BN * Encasement(Goods * goods){
	BN * head, * tail, * p;
	head = tail = p = NULL;
	GN * gp,* q;
	int i;
	for(i = 0;i < N;i++){
		//当箱子的是空 或者箱子的体积大于物品的体积时 不在寻找 
		for(p = head;p && p -> residueVol < goods[i].goodsVol;p = p -> next);
		//如果当前箱子p是 空 则表示 之前所有剩余的箱子的体积都不能装下这个物品 
		if(!p){
			//所以创建一个空箱子 
			p = (BN *)malloc(sizeof(BN));
			p -> residueVol = 60;
			p -> goodsHead = NULL;
			p -> next = NULL;
			//进行链表的尾插 
			if(!head){
				head = tail = p;
			}else{
				tail = tail -> next = p;
			}
		}
		//创建物品节点 
		gp = (GN *)malloc(sizeof(GN));
		gp -> goodsNo = goods[i].goodsNo;
		gp -> next = NULL;
		 
		if(!p -> goodsHead){
			//尾插是物品节点的头是 null 
			p -> goodsHead = gp;
		}else{
			//如果不是null 则循环直到他的下一个节点是null 
			for(q = p -> goodsHead;q -> next;q = q -> next);
			q -> next = gp;
		}
		//每装入一个物品则 这一个箱子的体积减小 
		p -> residueVol -= goods[i].goodsVol;
		printf("%d\t",goods[i].goodsNo);
		printf("%d\n",goods[i].goodsVol);
	}
	return head; 
}

//void PrintLink(BN * root,Goods * goods){
//	BN * p;
//	GN * q;
//	int cnt = 1,i;
//	for(p = root;p;p = p -> next){
//		printf("第%d个箱子：",cnt++);
//		for(q = p -> goodsHead;q;q = q -> next){
//			printf("%d\n%d\n",q -> goodsNo,goods[q -> goodsNo - 1].goodsVol);
//		} 
//	}
//}

//BN * ZhuangXiang(Goods * goods){
//	BN * head,* tail,* p;
//	head = tail = p = NULL;
//	GN * newGoods,* q;
//	int i;
//	for(i = 0;i < N;i++){
//		for(p = head;p && p -> residueVol < goods[i].goodsVol;p = p -> next);
//		if(!p){
//			p = (BN *)malloc(sizeof(BN));
//			p -> residueVol = V;
//			p -> goodsHead = NULL;
//			p -> next = NULL;
//			if(!head){
//				head = tail = p;
//			}else{
//				tail = tail -> next = p;
//			}
//		}
//		
//		newGoods = (GN *)malloc(sizeof(GN));
//		newGoods -> goodsNo = goods[i].goodsNo;
//		newGoods -> next = NULL;
//		if(!p -> goodsHead){
//			p -> goodsHead = newGoods;
//		}else{
//			for(q = p -> goodsHead;q -> next;q = q -> next);
//			q -> next = newGoods;
//		}
//		p -> residueVol -= goods[i].goodsVol; 
//	}
//	return head;
//}

//遍历装箱后的一个结果 
void PrintBox(BN * root,Goods * goods){
	int cnt = 1;
	int i;
	BN * p;
	GN * q;
	//循环箱子两边 
	for(p = root;p;p = p -> next){
		printf("第%d个箱子:",cnt++);
		i = 0;
		//循环每一个箱子链表的 物品链表 
		for(q = p -> goodsHead;q;q = q -> next){
			//通过当前箱子链表的物品链表 取得这个物品的 编号 然后通过 查找他的体积 
			printf("箱子编号%d\t箱子体积%d\t",q -> goodsNo,goods[q -> goodsNo - 1].goodsVol);
			i++;
		}
		printf("\n");
	}
} 

int main(void){
	Goods * goods;
	//有五十个 物品 
	goods = (Goods *)malloc(N * sizeof(Goods));
	//初始化物品
	int i;
	for(i = 0;i < N;i++){
		goods[i].goodsNo = i+1;
		goods[i].goodsVol = N - i;
	} 
	printf("箱子编号\t箱子体积\n"); 
//	for(i = 0;i < N;i++){
//		printf("%d\t",goods[i].goodsNo);
//		printf("%d\n",goods[i].goodsVol);
//	} 
	BN * root;
	root = Encasement(goods);
	PrintBox(root,goods);
//	int i = NULL;
//	if(i){
//		printf("箱子编号\t箱子体积\n");
//	}
//	printf("箱子编号\t箱");
}


