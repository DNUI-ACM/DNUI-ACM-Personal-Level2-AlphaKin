#include <iostream>
#include <cstdio>
#include "jlist.hpp"
using namespace jj;
using namespace std;
int main(){
	freopen("out", "w", stdout);

	jlist<int> listA = {3, 2, 8, 4, 5, 6, 2, 1};
	jlist<int> listB(listA);
	jlist<int>::iterator p;
 

	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "在listB的2位置插入3:" << endl;
	p = listB.begin() + 2;
	listB.insert(p, 3);
	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "listB向后插入: 55, 66, 77" << endl;
	listB.push_back(55);
	listB.push_back(66);
	listB.push_back(77);
	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "移除listB的第4个元素:" << endl;
	p = listB.begin() + 4;
	listB.erase(p);
	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "listB向前插入: 99, 11, 33" << endl;
	listB.push_front(99);
	listB.push_front(11);
	listB.push_front(33);
	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "交换listA 和 list B:" << endl;
	listA.swap(listB);
	cout << "遍历listA:" << endl;
	for(auto i : listA)
		cout << i << ' ';
	cout << endl;
	cout << "遍历listB:" << endl;
	for(p=listB.begin(); p!=listB.end(); ++p)
		cout << *p << ' ';
	cout << endl << endl;

	cout << "向后移除10个listA元素：" << endl;
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	listA.pop_back();
	cout << "遍历listA:" << endl;
	for(auto i : listA)
		cout << i << ' ';
	cout << endl << endl;

	cout << "反转listA:" << endl;
	listA.reverse();
	cout << "遍历listA:" << endl;
	for(auto i : listA)
		cout << i << ' ';
	cout << endl << endl;

	cout << "归并listA 和 listB:" << endl;
	listA.merge(listB);
	cout << "遍历listA:" << endl;
	for(auto i : listA)
		cout << i << ' ';
	cout << endl << endl;


	cout << "将listA按升序进行归并排序" << endl << endl;
	listA.sort();

	cout << "反向迭代器遍历listA:" << endl;
	auto rp = listA.rbegin();
	for(; rp!=listA.rend(); ++rp)
		cout << *rp << ' ';
	cout << endl << endl;

	cout << "清空listA." << endl;
	listA.clear();
	cout << "遍历listA:" << endl;
	for(auto i : listA)
		cout << i << ' ';
	cout << endl << endl;
	return 0;
}

/*
OUTPUT:

遍历listB:
3 2 8 4 5 6 2 1 

在listB的2位置插入3:
遍历listB:
3 2 3 8 4 5 6 2 1 

listB向后插入: 55, 66, 77
遍历listB:
3 2 3 8 4 5 6 2 1 55 66 77 

移除listB的第4个元素:
遍历listB:
3 2 3 8 5 6 2 1 55 66 77 

listB向前插入: 99, 11, 33
遍历listB:
33 11 99 3 2 3 8 5 6 2 1 55 66 77 

交换listA 和 list B:
遍历listA:
33 11 99 3 2 3 8 5 6 2 1 55 66 77 
遍历listB:
3 2 8 4 5 6 2 1 

向后移除10个listA元素：
遍历listA:
33 11 99 3 

反转listA:
遍历listA:
3 99 11 33 

归并listA 和 listB:
遍历listA:
3 3 2 8 4 5 6 2 1 99 11 33 

将listA按升序进行归并排序

反向迭代器遍历listA:
99 33 11 8 6 5 4 3 3 2 2 1 

清空listA.
遍历listA:
*/