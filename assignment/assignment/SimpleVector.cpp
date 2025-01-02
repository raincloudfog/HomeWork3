#include "SimpleVector.h"


//using T = template<typename T>;

//템플릿을 사용하면 다른곳에서 구현할때 타입까지 지정해줘야됨..
//특정 타입은 다르게 하고싶을때 구현 하면 좋을것같음
// 잠시만 T로하면?
//SimpleVector<int>::SimpleVector(int capacity) {
//
//}

//된다?
//template<typename T>
//SimpleVector<T>::SimpleVector() {
//
//}
//
////하지만함수마다 이렇게 하는건 별로일거같으니 using std; 처럼 방법 찾기
//template<typename T>
//SimpleVector<T>::SimpleVector(int capacity) {
//
//}
//
//
//template<typename T>
//void  SimpleVector<T>::push_back(const T& value) {
//	//배열에서 뒤에 넣어주기
//
//	//일단 현재 배열크기보다 용량이 적으면 
//	// 뒷자리에 채워넣기
//	if (currentCapacity < currentSize)
//	{
//		//흐음 매개변수로 참조 값을주었는데 저장하는건 
//		//아 배열의 인덱스 에있는건 값이다. 주소를 저장하는건 포인터 배열
//		data[currentCapacity] = value;
//
//		//채워넣었으면 인덱스 증가
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
//	//맨 뒤부터 제거
//
//	//포인터가 아니므로 이건안됨
//	//delete data[currentCapacity];
//
//	//T를 어떻게 초기화시키지
//	//T t = T(); 제네릭  초기화 방식
//	data[currentCapacity] = T();
//
//	//0보다작을 경우  0으로고정
//	currentCapacity = --currentCapacity >= 0 ? currentCapacity : 0;
//
//}