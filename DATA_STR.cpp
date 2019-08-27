#include"DATA_STR.hpp"

sequenlist *Tlinear_list::Tsequen_list::initSeqList(){
	sequenlist *L;
	L = (sequenlist*)malloc(sizeof(sequenlist));
	L->last = 0;
	return L;
}

void Tlinear_list::Tsequen_list::setNull(sequenlist *L) {
	L->last = 0;
}

int Tlinear_list::Tsequen_list::length(sequenlist *L) {
	return L->last;
}

datatype_seqlist Tlinear_list::Tsequen_list::get(sequenlist *L, int i) {
	return L->data[i];
}

int Tlinear_list::Tsequen_list::insert(sequenlist *L, datatype_seqlist x, int i) {
//O(n/2)
	if (L->last >= maxsize_seqlist - 1) {//����
		cout << "OVERFLOW!!!" << endl;
		return 0;
	}
	else if (i<1 || i>L->last + 1) {//����λ�ò��Ϸ�
		cout << "Wrongful insertion position!!!" << endl;
		return 0;
	}
	else {
		for (int j = L->last; j >= i; j--) {//������
			L->data[j + 1] = L->data[j];
		}
		L->data[i] = x;//����
		L->last++;
		return 1;
	}
}

int Tlinear_list::Tsequen_list::_delete(sequenlist *L, int i) {
//O((n-1)/2)
	if (i<1 || i>L->last) {//ɾ��λ�ò��Ϸ�
		cout << "Wrongful insertion position!!!" << endl;
		return 0;
	}
	else {
		for (int j = i; j <= L->last-1; j++) {//���ǰ��
			L->data[j] = L->data[j + 1];
		}
		L->last--;
		return 1;
	}
}

int Tlinear_list::Tsequen_list::locate(sequenlist *L, datatype_seqlist x) {
	for (int i = 1; i <= L->last; i++) {
		if (L->data[i] == x) {
			return i;
			break;
		}
	}
	//cout << "Not found!!!" << endl;	//����֮��del_note�������
	return 0;
}

int Tlinear_list::Tsequen_list::delNote(sequenlist *L, datatype_seqlist x) {
	/*	�α�����
	int k = locate(L,x);	
	while (k) {//���ҵ���ִ��ѭ����
		if (!_delete(L, k)) {//������Ϊû��Ҫ
			return 0;
			break;
		}
		k = locate(L, x);
	}
	return 1;
	*/
	for (int k = locate(L, x); k; k = locate(L, x)) {
		if (!_delete(L, k)) {//������Ϊû��Ҫ
			return 0;
			break;
		}
	}
	return 1;

}

void Tlinear_list::Tsequen_list::printSeqList(sequenlist *L) {
	for (int i = 1; i <= L->last; i++) {
		printf("a[%d] = ", i);
		cout << L->data[i] << endl;
	}
}

int Tlinear_list::Tsequen_list::scanSeqList(sequenlist *L) {
	cout<<"Enter a number of data and create a sequence table(End with '-1'):"<<endl;
	datatype_seqlist x;
	int i = L->last+1;//���Խ�β����
	for (cin >> x; x != -1; cin >> x,i++) {
		if (!insert(L, x, i)) {
			cout << "OVERFLOW!!!" << endl;
			return 0;
			break;
		}
	}
	return 1;
}