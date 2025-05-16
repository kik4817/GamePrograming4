#include "ConsoleUtility.h"

/*
* 목표 : 배열의 크기를 수동으로 변경하는 코드를 만든다
*       "자동" vector
*/

/*
* int 10개 배열로 저장한다.
* 배열의 특징 : 크기가 고정. 만들 때 크기를 정해줘야 한다. 40바이트 공간을 확보해야한다.
* 41바이트 떨어진 공간에서 메모리를 접근 - 문제가 발생
*/

// 배열의 크기를 N 받을 수 있게 코드를 추가해보기
// String, char, double 코드를 추가해보세요

/*
* vector 클래스의 기능
* 
* push_back : 백터의 끝에 데이터를 추가한다.(이미 존재하는 데이터를)
* size : 백터의 길이를 변환한다
* emplace_back : 백터의 끝에 직접 생성한 데이터를 바로 추가한다.
* pop_back : 가장 뒤에 있는 데이터 한개를 제거한다.
* empty : 백터의 크기가 0미만 true, 이상이면 false 변환한다.
* inster() : 주어진 위치에 데이터를 입력한다. ver.insert(vec.begin()+2, 10);
* erase() : 주저잊ㄴ 위치의 데이터를 제거한다. ver.erase(vec.begin();
*/

template<typename T,int N>

void MakeArray(T*& ptr, T value) // 주소를 변경
{
	// 연결된 메모리를 해제
	// 배열의 크기를 수동으로 만들고 보여주는 예제 코드
	delete[] ptr;
	ptr = new T[N];

	for (int i = 0; i < N;i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}
	cout << endl;

	/*delete[] aPtr;

aPtr = new int[20];
for (int i = 0; i < 20;i++)
{
	*(aPtr + i) = 0;
	cout << *(aPtr + i) << " ";
}*/
	
}

// 클래스 이름 Monster 번호, 이름

class Monster
{
	int _number;
	string _name;
public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : _number(num), _name(name){}

	int get_num() const { return _number; }
	string get_name() const { return _name; }

	// "cout << Monster출력했을 때의 오류"
	// friend 외부 클래스의 private에 접근할 수 있게 해주는 키워드
	friend ostream& operator<<(ostream& os, Monster& obj)
	{
		os << obj._number << " " << obj._name << " ";
		return os;
	}
};

template<typename T>
void Show(vector<T>& vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}



int main()
{
	// 수동으로 배열의 크기를 변경하고 생성하는 함수 탬플릿
	// 클래스 템플릿
	// 인벤토리 10개 -> 11개 (Array 10개) -> 

	int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "고블린");

	MakeArray<int, 15>(aPtr,0);
	MakeArray<double, 10>(bPtr,0.1);
	MakeArray<string, 10>(cPtr, "AAA");
	MakeArray<Monster, 10>(dPtr, sample);
		

	cout << "\n백터 사용 예제" << endl;
	// vector로 쉽게 배열을 생성하고 출력하기
	
	vector<int> nums; // vector int를 저장하는 가변배열 클래스
		
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
		
	//for (int i = 0;i < nums.size();i++)
	//{
	//	cout << nums[i] << " ";
	//}

	Show<int>(nums);
	
	vector<double> doublecontainer;
	vector<string> stringcontainer;

	vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "고블린");
	monsterDatabase.emplace_back(2, "슬라임");
	monsterDatabase.emplace_back(3, "골램");

	//monsterDatabase.pop_back();
	//monsterDatabase.clear();
	for (int i = 0;i < 10;i++)
	{
		nums.push_back(0);
		doublecontainer.push_back(0.1);
		stringcontainer.push_back("AAA");
		monsterDatabase.push_back(sample);
	}

	Show<int>(nums);
	Show<double>(doublecontainer);
	Show<string>(stringcontainer);
	Show<Monster>(monsterDatabase);
	
	Show<Monster>(monsterDatabase);
	//if (monsterDatabase.empty())
	//{
	//	cout << "데이터가 있습니다." << endl;
	//}

	// int타입을 저장하는 배열을 vector 컨테이너에 저장하는 코드를 작성하세요.
	vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();
	
	// 테트리스 4가지 블럭
	// vector<Block> block;

	// 4가지 직업 : 전사, 마법사, 도적, 궁수
	// vector<GameClass> gameClasses;

	// 객체 Monster
	// 관리하는 클래스 MonsterManager
	// vector<Monster>
}