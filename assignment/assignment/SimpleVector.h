#pragma once
#include <iostream>
#include <algorithm>

//타입에 의존하지 않고 데이터 받을 수 있는 배열 구현 // 템플릿
//uml 보는법 빨간색 private 초록색 public , 네모난 빈박스 변수 
using namespace std;


//-1073740940 코드  스택 버퍼 오버플로우
//함수 호출 중 지역 변수의 크기가 스택의 한계를 초과할 때 발 생.
//배열의 크기 잘못 설정 , 재귀호출, 해제된 메모리 접근 , 배열의 경계넘음,
 

template<typename T>
class SimpleVector {

private:
	//스마트 포인터로 해도 될듯하긴함.
	//unique_ptr<T*> data; 이거랑은 좀 다른듯함.
	
	unique_ptr<T[]> data;
	//현재 배열의 크기 10
	int currentSize = 10;

	//현재 배열이 어디까지 찻는지 확인하는 크기
	int currentCapacity= 0;

	//크기 재할당
	void resize(int newCapacity) {

		if (newCapacity < currentSize)
		{
			//아직 넘지 안았으니 다시 돌아가기
			return;
		}

		//새로운 T만들어줌 // 깊은 복사
		// 이후 원래 데이터 초기화 // 만약 이게 클래스였다면 클래스 내부에 데이터 값들도 전부 전달 된걸 까?
		// 
		//T* data = new T(data); 이거와 차이점 생각해보기 // 위는 주소 아래는 값 전달 //+ 여기다가 크기도 5늘려줘야한다.

		currentSize += 5;

		unique_ptr<T[]> temp = make_unique<T[]>(currentSize);

		for (size_t i = 0; i < currentSize - 5; i++)
		{
			//복제할곳에 데이터 추가
			//이것은 얕은 복사
			temp[i] = data[i];
		}

		//이후 삭제
		//delete data; // 이부분에서 오류 발생 // 이유 생각 : temp에서 같은 주소!! 를 사용하는데 
		//삭제해버려서 temp가 받은 데이터도 해제되었음  // 이게 댕글링 포인터 일것같음.
		data.reset();

		data = move( temp);

		//어차피 지역 변수 에다가 주소값도 데이터가 받아줬으니 필요없어보임.
		temp = nullptr;
	}
	


public :

	//기본 생성자
	SimpleVector()
	{
		//기본 생성자에서 크기 10인 배열 을 만들어야됨.
		data = make_unique<T[]>(currentSize);
		//저번 과제에서 포인터배열인 경우는 배열생성할때 자동 nullptr이아닌 임의의 값이였으니
		//이번에도 조사해봐야할듯함. // 초기화 해줄것 그런데 int , string 등등 변수마다 다다를 텐데..
	}

	//SimpleVector(int capacity) : SimpleVector() { // 이것도 되는 것 같음.
	
	//오버로딩 생성자
	SimpleVector(int capacity) {


		//이걸 추가안해줘서 버퍼 오버런 발생
		// 버퍼 오버런(Buffer Overrun)은 프로그램에서 버퍼의 크기를 초과하여 데이터가 기록될 때 발생하는 오류
		// 이 오류는 메모리 안전성을 위협하고, 프로그램의 비정상 종료, 데이터 손상, 보안 취약점 등을 초래
		// 배열의 크기를 초과할때 나오는 것 같음 4개밖에없는데 10개를 꺼내려 하는 상황에서 발생했음.
		currentSize = capacity;
		//기본 생성자에서 크기 capacity인 배열 을 만들어야됨.
		data = make_unique<T[]>(currentSize);





	}

	//복사 생성자
	//복사할 객채 매개변수
	//변수들 복사
	SimpleVector(const SimpleVector& other) 
		: currentSize(other.currentSize) , currentCapacity(other.currentCapacity)
	{
		//깊은 복사해주기
		data = move(other.data);

	}



	//추가 

	//도전 과제 기능 
	//배열 크기 이상의 원소가 들어올 경우 기존배열보다 크기를 5만큼 늘리고 새로운 원소 추가 ( 기존값 유지)
	void push_back(const T& value) {
		//배열에서 뒤에 넣어주기
		
		
			
		resize(currentCapacity);
		

		//일단 현재 배열크기보다 용량이 적으면 
		// 뒷자리에 채워넣기
		if (currentCapacity < currentSize)
		{
			//흐음 매개변수로 참조 값을주었는데 저장하는건 
			//아 배열의 인덱스 에있는건 값이다. 주소를 저장하는건 포인터 배열
			data[currentCapacity] = value;

			//채워넣었으면 인덱스 증가
			currentCapacity++;

			cout << "Push \n";
		}
	}

	

	//제거
	void pop_back() {

		//맨 뒤부터 제거

		//포인터가 아니므로 이건안됨
		//delete data[currentCapacity];

		//T를 어떻게 초기화시키지
		//T t = T(); 제네릭  초기화 방식
		data[currentCapacity] = T();

		//0보다작을 경우  0으로고정
		currentCapacity = --currentCapacity >= 0 ? currentCapacity : 0;

	}


	//인자가 없고 현재 원소의 개수 반환
	int size() {

		return currentSize;
	}


	//capacity 현재 내부 배열의 크기를 반환합니다.
	int capacity() {


		//T가 클래스일경우는 오류 나올 수있으니주의
		for (size_t i = 0; i < currentCapacity; i++)
		{
			cout << data[i] << " ";
		}

		cout << endl;
		return currentCapacity;
	}

	//정렬
	void SortData() {
		//std::sort(data[0], data[currentCapacity]);
		// 배열은 벡터와 다르게 begin, end로 하지 않고 첫 주소와 끝주소를 준다.
		//sort(data, data + currentCapacity);
	}


	//소멸자
	~SimpleVector() {

		cout << "클래스 삭제";
		//일반 포인터에 경우 딜리트하고 찾으려하면 댕글링 포인터가 나오니
		//편하게 유니크 포인터 사용 //그런데 클래스가 사라지면서 자동으로 사라지지 않나?
		data.reset();
	}
};
