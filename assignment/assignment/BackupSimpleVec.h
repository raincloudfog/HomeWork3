#pragma once
#include <iostream>
#include <algorithm>

//Ÿ�Կ� �������� �ʰ� ������ ���� �� �ִ� �迭 ���� // ���ø�
//uml ���¹� ������ private �ʷϻ� public , �׸� ��ڽ� ���� 
using namespace std;


//-1073740940 �ڵ�  ���� ���� �����÷ο�
//�Լ� ȣ�� �� ���� ������ ũ�Ⱑ ������ �Ѱ踦 �ʰ��� �� �� ��.
//�迭�� ũ�� �߸� ���� , ���ȣ��, ������ �޸� ���� , �迭�� ������,


template<typename T>
class SimpleVector {

private:
	//����Ʈ �����ͷ� �ص� �ɵ��ϱ���.
	T* data;
	//���� �迭�� ũ�� 10
	int currentSize = 10;

	//���� �迭�� ������ ������ Ȯ���ϴ� ũ��
	int currentCapacity = 0;

	//ũ�� ���Ҵ�
	void resize(int newCapacity) {

		if (newCapacity < currentSize)
		{
			//���� ���� �Ⱦ����� �ٽ� ���ư���
			return;
		}

		//���ο� T������� // ���� ����
		// ���� ���� ������ �ʱ�ȭ // ���� �̰� Ŭ�������ٸ� Ŭ���� ���ο� ������ ���鵵 ���� ���� �Ȱ� ��?
		// 
		//T* data = new T(data); �̰ſ� ������ �����غ��� // ���� �ּ� �Ʒ��� �� ���� //+ ����ٰ� ũ�⵵ 5�÷�����Ѵ�.

		currentSize += 5;

		T* temp = new T[currentSize];

		for (size_t i = 0; i < currentSize - 5; i++)
		{
			//�����Ұ��� ������ �߰�
			//�̰��� ���� ����
			temp[i] = data[i];
		}

		//���� ����
		//delete data; // �̺κп��� ���� �߻� // ���� ���� : temp���� ���� �ּ�!! �� ����ϴµ� 
		//�����ع����� temp�� ���� �����͵� �����Ǿ���  // �̰� ��۸� ������ �ϰͰ���.
		data = nullptr;

		data = temp;

		//������ ���� ���� ���ٰ� �ּҰ��� �����Ͱ� �޾������� �ʿ�����.
		temp = nullptr;
	}



public:

	//�⺻ ������
	SimpleVector()
	{
		//�⺻ �����ڿ��� ũ�� 10�� �迭 �� �����ߵ�.
		data = new T[currentSize];
		//���� �������� �����͹迭�� ���� �迭�����Ҷ� �ڵ� nullptr�̾ƴ� ������ ���̿�����
		//�̹����� �����غ����ҵ���. // �ʱ�ȭ ���ٰ� �׷��� int , string ��� �������� �ٴٸ� �ٵ�..
	}

	//SimpleVector(int capacity) : SimpleVector() { // �̰͵� �Ǵ� �� ����.

	//�����ε� ������
	SimpleVector(int capacity) {


		//�̰� �߰������༭ ���� ������ �߻�
		// ���� ������(Buffer Overrun)�� ���α׷����� ������ ũ�⸦ �ʰ��Ͽ� �����Ͱ� ��ϵ� �� �߻��ϴ� ����
		// �� ������ �޸� �������� �����ϰ�, ���α׷��� ������ ����, ������ �ջ�, ���� ����� ���� �ʷ�
		// �迭�� ũ�⸦ �ʰ��Ҷ� ������ �� ���� 4���ۿ����µ� 10���� ������ �ϴ� ��Ȳ���� �߻�����.
		currentSize = capacity;
		//�⺻ �����ڿ��� ũ�� capacity�� �迭 �� �����ߵ�.
		data = new T[currentSize];


	}

	//���� ������
	//������ ��ä �Ű�����
	//������ ����
	SimpleVector(const SimpleVector& other)
		: currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		//���� �������ֱ�
		data = new T(other.data);

	}



	//�߰� 

	//���� ���� ��� 
	//�迭 ũ�� �̻��� ���Ұ� ���� ��� �����迭���� ũ�⸦ 5��ŭ �ø��� ���ο� ���� �߰� ( ������ ����)
	void push_back(const T& value) {
		//�迭���� �ڿ� �־��ֱ�



		resize(currentCapacity);


		//�ϴ� ���� �迭ũ�⺸�� �뷮�� ������ 
		// ���ڸ��� ä���ֱ�
		if (currentCapacity < currentSize)
		{
			//���� �Ű������� ���� �����־��µ� �����ϴ°� 
			//�� �迭�� �ε��� ���ִ°� ���̴�. �ּҸ� �����ϴ°� ������ �迭
			data[currentCapacity] = value;

			//ä���־����� �ε��� ����
			currentCapacity++;

			cout << "Push \n";
		}
	}



	//����
	void pop_back() {

		//�� �ں��� ����

		//�����Ͱ� �ƴϹǷ� �̰Ǿȵ�
		//delete data[currentCapacity];

		//T�� ��� �ʱ�ȭ��Ű��
		//T t = T(); ���׸�  �ʱ�ȭ ���
		data[currentCapacity] = T();

		//0�������� ���  0���ΰ���
		currentCapacity = --currentCapacity >= 0 ? currentCapacity : 0;

	}


	//���ڰ� ���� ���� ������ ���� ��ȯ
	int size() {

		return currentSize;
	}


	//capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.
	int capacity() {


		//T�� Ŭ�����ϰ��� ���� ���� ������������
		for (size_t i = 0; i < currentCapacity; i++)
		{
			cout << data[i] << " ";
		}

		cout << endl;
		return currentCapacity;
	}

	//����
	void SortData() {
		//std::sort(data[0], data[currentCapacity]);
		// �迭�� ���Ϳ� �ٸ��� begin, end�� ���� �ʰ� ù �ּҿ� ���ּҸ� �ش�.
		sort(data, data + currentCapacity);
	}


	//�Ҹ���
	~SimpleVector() {

		cout << "Ŭ���� ����";
		delete[] data;
	}
};
