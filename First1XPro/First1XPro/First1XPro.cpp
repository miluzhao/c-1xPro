// First1XPro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <initializer_list>
#include <vector>
#include <iostream>
#include<functional>
#include <algorithm>
using namespace std;

class MagicFoo {
public:
	std::vector<int> vec;
	MagicFoo(std::initializer_list<int> list) {
		// 从 C++11 起, 使用 auto 关键字进行类型推导
		for (auto it = list.begin(); it != list.end(); ++it) {
			vec.push_back(*it);
		}
	}
};


template<typename T, typename U>
class MagicType {
public:
	T dark;
	U magic;
};

typedef int(*process)(void *);
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;



int foo(int a, int b) {
	return a + b;
}
class Mybind {
public:
	int  operator()(int a, int b)
	{
		return a + b;
	}
};

//lambda
bool cmp(int a, int b)
{
	return  a < b;
}


int main() {
	MagicFoo magicFoo = { 1, 2, 3, 4, 5 };
	std::cout << "magicFoo: ";
	for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::vector<int> vecTemp;
	for (size_t i = 0; i < 10; i++)
	{
		vecTemp.push_back(i);
	}
	for (auto iter = vecTemp.begin(); iter != vecTemp.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	for(auto i : vecTemp)
	{
		std::cout << i << std::endl;
	}

	//bind and placehodler test
	auto temp = std::bind(foo, std::placeholders::_1, 2);
	std::cout << temp(10) << std::endl;

	Mybind m;
	auto mybind = std::bind(m, std::placeholders::_1, 15);
	cout << mybind(20) << endl;

	//bind lambda
	auto myLambda = std::bind([](int a, int b)->int {return a + b; }, std::placeholders::_1, std::placeholders::_2);
	cout<<myLambda(20, 20)<<endl;

	//lambda

	vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
	vector<int> lbvec(myvec);

	sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
	cout << "predicate function:" << endl;
	for (int it : myvec)
		cout << it << ' ';
	cout << endl;

	sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
	cout << "lambda expression:" << endl;
	for (int it : lbvec)
		cout << it << ' ';

	return 0;
}
