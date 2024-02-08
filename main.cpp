#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>

using namespace std;

class StaticTest
{
	StaticTest() { Count++; }
public:
	
	~StaticTest() { Count--; }
	static int Count;
	static void PrintCOunt() { cout << StaticTest::Count << endl; }

	static StaticTest* GetInstance();
	static StaticTest* Instance;
};

int StaticTest::Count = 0;// 클래스 안에만 연관만 있고 메모리 구조는 다른데에 있음
StaticTest* StaticTest::Instance = nullptr;

class ConstructSample
{
public:

	ConstructSample(int NewNumber, char* NewName)
	{
		Number = NewNumber;
		Name = NewName;
	}
	ConstructSample(const ConstructSample& Origin)
	{
		Number = Origin.Number;
		//Name = new char[100];
		//strcpy(Name, Origin.Name);//카피본을 만들어서 ㄱ
		Name = string(Origin.Name);// 복사시에 명확하게 표현해주는게 중요함.
	}
	~ConstructSample()
	{

	}
	int Number;
	std::string Name;
};
//& 참초자 저쪽거를 가져다가 쓸거야라고 명확해짐. const<> & 한셋트
// InOrigin, HitData&InOutData
int ADD(int A, int B)
{
	A + B;
	return A + B;
}
int(*FunctionPointer)(int A, int B);//주소를 기록하겠다. 인자가 있는//  반환형 변수이름 인자
//call back 
void Loadsync(int A, int B)// (*WhenComplete)()
{
	//network
	//Loadding
	FunctionPointer(A, B);
}

// delegate += 에서 이벤트로 언리얼 엔진 이벤트// 클래스 의존성이 부서저서 좋음.

int Compare(const void* PA, const void* PB)
{
	int A = *(int*)PA;
	int B = *(int*)PB;
	if (A < B)
	{
		return 1;
	}
	else if (A > B)
	{
		return -1;

	}
	else
	{
		return 0;
	}
}
int Acceding(const void* PA, const void* PB)//포인터함수.; 반환
{
	int A = *(int*)PA;
	int B = *(int*)PB;
	if (A > B)
	{
		return 1;
	}
	else if (A < B)
	{
		return -1;

	}
	else
	{
		return 0;
	}
}

int main()
{
	int Number[10] = {1,19,2,4,7,9,3,11,50,100};
	qsort(Number, 10, sizeof(int), Compare);
	for (auto D : Number)
	{
		std::cout << D << endl;
	}
	FunctionPointer=[](int A, int B) { return 1; };
	FunctionPointer = ADD;
	FunctionPointer(10, 20);

	char Message[] = "Hellow";
	ConstructSample C1(300,Message);
	ConstructSample C2 =C1;//ConstructSample C2 =ConstructSample(C1) 정확히 표현해야함.
	cout << C1.Number << endl;
	C1.Number = 100;
	cout << C2.Number << endl;

	
	return 0;
}
//방법론//방법론// 맞다 틀리다. 가 아님.
StaticTest* StaticTest::GetInstance()
{
	if(Instance == nullptr)
	{
		Instance = new StaticTest();
	}
	return nullptr;
}
//스ㅐ틱/ 방법론/레퍼런스//복사생성자(딥/라이트); 중요중요
