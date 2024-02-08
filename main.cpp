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

int StaticTest::Count = 0;// Ŭ���� �ȿ��� ������ �ְ� �޸� ������ �ٸ����� ����
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
		//strcpy(Name, Origin.Name);//ī�Ǻ��� ���� ��
		Name = string(Origin.Name);// ����ÿ� ��Ȯ�ϰ� ǥ�����ִ°� �߿���.
	}
	~ConstructSample()
	{

	}
	int Number;
	std::string Name;
};
//& ������ ���ʰŸ� �����ٰ� ���ž߶�� ��Ȯ����. const<> & �Ѽ�Ʈ
// InOrigin, HitData&InOutData
int ADD(int A, int B)
{
	A + B;
	return A + B;
}
int(*FunctionPointer)(int A, int B);//�ּҸ� ����ϰڴ�. ���ڰ� �ִ�//  ��ȯ�� �����̸� ����
//call back 
void Loadsync(int A, int B)// (*WhenComplete)()
{
	//network
	//Loadding
	FunctionPointer(A, B);
}

// delegate += ���� �̺�Ʈ�� �𸮾� ���� �̺�Ʈ// Ŭ���� �������� �μ����� ����.

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
int Acceding(const void* PA, const void* PB)//�������Լ�.; ��ȯ
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
	ConstructSample C2 =C1;//ConstructSample C2 =ConstructSample(C1) ��Ȯ�� ǥ���ؾ���.
	cout << C1.Number << endl;
	C1.Number = 100;
	cout << C2.Number << endl;

	
	return 0;
}
//�����//�����// �´� Ʋ����. �� �ƴ�.
StaticTest* StaticTest::GetInstance()
{
	if(Instance == nullptr)
	{
		Instance = new StaticTest();
	}
	return nullptr;
}
//����ƽ/ �����/���۷���//���������(��/����Ʈ); �߿��߿�
