#include "SimpleVector.h"


//using T = template<typename T>;

//���ø��� ����ϸ� �ٸ������� �����Ҷ� Ÿ�Ա��� ��������ߵ�..
//Ư�� Ÿ���� �ٸ��� �ϰ������ ���� �ϸ� �����Ͱ���
// ��ø� T���ϸ�?
//SimpleVector<int>::SimpleVector(int capacity) {
//
//}

//�ȴ�?
//template<typename T>
//SimpleVector<T>::SimpleVector() {
//
//}
//
////�������Լ����� �̷��� �ϴ°� �����ϰŰ����� using std; ó�� ��� ã��
//template<typename T>
//SimpleVector<T>::SimpleVector(int capacity) {
//
//}
//
//
//template<typename T>
//void  SimpleVector<T>::push_back(const T& value) {
//	//�迭���� �ڿ� �־��ֱ�
//
//	//�ϴ� ���� �迭ũ�⺸�� �뷮�� ������ 
//	// ���ڸ��� ä���ֱ�
//	if (currentCapacity < currentSize)
//	{
//		//���� �Ű������� ���� �����־��µ� �����ϴ°� 
//		//�� �迭�� �ε��� ���ִ°� ���̴�. �ּҸ� �����ϴ°� ������ �迭
//		data[currentCapacity] = value;
//
//		//ä���־����� �ε��� ����
//		currentCapacity++;
//
//		cout << "Push \n";
//	}
//}
//
//
//template<typename T>
//
//void pop_back() {
//
//	//�� �ں��� ����
//
//	//�����Ͱ� �ƴϹǷ� �̰Ǿȵ�
//	//delete data[currentCapacity];
//
//	//T�� ��� �ʱ�ȭ��Ű��
//	//T t = T(); ���׸�  �ʱ�ȭ ���
//	data[currentCapacity] = T();
//
//	//0�������� ���  0���ΰ���
//	currentCapacity = --currentCapacity >= 0 ? currentCapacity : 0;
//
//}