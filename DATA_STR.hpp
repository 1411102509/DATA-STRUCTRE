#include<iostream>
#include<stdio.h>

using namespace std;

/***********************���Ա�***********************/
//˳���
#define maxsize_seqlist 1000
typedef int datatype_seqlist;
typedef struct seqlist{						 
	datatype_seqlist data[maxsize_seqlist];//�����a0����
	int last;//��¼��
}sequenlist;

class Tlinear_list{	//���Ա� 
	public:
		class Tsequen_list{	//˳��� 
			public:         
				sequenlist *Tdata;	//��������

				sequenlist *initSeqList();					//���ձ� 
				void setNull(sequenlist *L);				//�ÿձ�
				int length(sequenlist *L);					//�󳤶�
				datatype_seqlist get(sequenlist *L,int i);	//ȡ��� 
				int insert(sequenlist *L, datatype_seqlist x, int i);	//����
				int _delete(sequenlist *L, int i);			//ɾ��(λ��)
				int locate(sequenlist *L, datatype_seqlist x);		//����
				int delNote(sequenlist *L, datatype_seqlist x);//ɾ������ֵΪx�Ľ��
				void printSeqList(sequenlist *L);			//���
				int scanSeqList(sequenlist *L);

		};
};

//������


