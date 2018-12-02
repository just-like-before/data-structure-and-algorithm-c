#include <stdio.h>
#include <stdlib.h>
//��ʮ����Ʒ 
#define N 50
//���ӵ��������ʮ 
#define V 60
//̰���㷨 װ������ 
/*
1.���㵱ǰ���Ž�  Ҳ�Ǿֲ������Ž�
2.̰���㷨 ��������ٸı� 
*/ 

//������Ʒ������ ��Ʒ����� �� �ǺŽ��б��
typedef struct{
	int goodsNo; //��Ʒ�ļǺ�
	int goodsVol; //��Ʒ����� 
}Goods; 

//������Ʒ�Ľڵ����� ��֪��һ�����Ӵ洢���� ��Ʒ����ʹ������
typedef struct goodsNode{
	int goodsNo; //��Ʒ�ı�� 
	struct goodsNode * next;  
}GN; 

//�������ӵ����� ��֪����ʹ�ö��ٸ�����
//����ʹ������ 
//��������	��¼ �洢�����е�һ����Ʒ�����ͷ��� ������ʣ������
typedef struct boxNode{
	int residueVol; //�ڵ��ʣ����� 
	GN * goodsHead; //���ӽڵ�����Ʒ�����ͷ��� 
	struct boxNode * next;
}BN;

//װ�� 
BN * Encasement(Goods * goods){
	BN * head, * tail, * p;
	head = tail = p = NULL;
	GN * gp,* q;
	int i;
	for(i = 0;i < N;i++){
		//�����ӵ��ǿ� �������ӵ����������Ʒ�����ʱ ����Ѱ�� 
		for(p = head;p && p -> residueVol < goods[i].goodsVol;p = p -> next);
		//�����ǰ����p�� �� ���ʾ ֮ǰ����ʣ������ӵ����������װ�������Ʒ 
		if(!p){
			//���Դ���һ�������� 
			p = (BN *)malloc(sizeof(BN));
			p -> residueVol = 60;
			p -> goodsHead = NULL;
			p -> next = NULL;
			//���������β�� 
			if(!head){
				head = tail = p;
			}else{
				tail = tail -> next = p;
			}
		}
		//������Ʒ�ڵ� 
		gp = (GN *)malloc(sizeof(GN));
		gp -> goodsNo = goods[i].goodsNo;
		gp -> next = NULL;
		 
		if(!p -> goodsHead){
			//β������Ʒ�ڵ��ͷ�� null 
			p -> goodsHead = gp;
		}else{
			//�������null ��ѭ��ֱ��������һ���ڵ���null 
			for(q = p -> goodsHead;q -> next;q = q -> next);
			q -> next = gp;
		}
		//ÿװ��һ����Ʒ�� ��һ�����ӵ������С 
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
//		printf("��%d�����ӣ�",cnt++);
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

//����װ����һ����� 
void PrintBox(BN * root,Goods * goods){
	int cnt = 1;
	int i;
	BN * p;
	GN * q;
	//ѭ���������� 
	for(p = root;p;p = p -> next){
		printf("��%d������:",cnt++);
		i = 0;
		//ѭ��ÿһ����������� ��Ʒ���� 
		for(q = p -> goodsHead;q;q = q -> next){
			//ͨ����ǰ�����������Ʒ���� ȡ�������Ʒ�� ��� Ȼ��ͨ�� ����������� 
			printf("���ӱ��%d\t�������%d\t",q -> goodsNo,goods[q -> goodsNo - 1].goodsVol);
			i++;
		}
		printf("\n");
	}
} 

int main(void){
	Goods * goods;
	//����ʮ�� ��Ʒ 
	goods = (Goods *)malloc(N * sizeof(Goods));
	//��ʼ����Ʒ
	int i;
	for(i = 0;i < N;i++){
		goods[i].goodsNo = i+1;
		goods[i].goodsVol = N - i;
	} 
	printf("���ӱ��\t�������\n"); 
//	for(i = 0;i < N;i++){
//		printf("%d\t",goods[i].goodsNo);
//		printf("%d\n",goods[i].goodsVol);
//	} 
	BN * root;
	root = Encasement(goods);
	PrintBox(root,goods);
//	int i = NULL;
//	if(i){
//		printf("���ӱ��\t�������\n");
//	}
//	printf("���ӱ��\t��");
}


