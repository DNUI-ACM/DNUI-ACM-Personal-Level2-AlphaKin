#include <iostream>
#include <cstdio>
#include "jvector.hpp"
using namespace std;

int main(){
	//freopen("out", "w", stdout);

	jj::jvector<int> va;

	va.push_back(2);
	va.push_back(3);
	va.push_back(4);
	va.push_back(5);
	va.push_back(1);
	va.push_back(6);
	va.resize(2, 2);//重新分配
	va.push_back(100);


	jj::jvector<int> vb(va);//拷贝构造
	vb.push_back(77);
	vb.resize(10, 5);//重新分配
	vb.push_back(66);
	vb.erase(5);//删除第5个元素
	

	jj::jvector<int> vc(5, 3);


	cout << "下标遍历va:" << endl;
	for(int i=0; i<va.size(); ++i)
		cout << va[i] << ' ';
	cout << endl << endl;
	cout << "下标遍历vb:" << endl;
	for(int i=0; i<vb.size(); ++i)
		cout << vb[i] << ' ';
	cout << endl << endl;


cout << "预留va的8个空间" << endl;
	va.reserve(8);
cout << endl;


	cout << "迭代器遍历va:" << endl;
	jj::jvector<int>::iterator p;//迭代器
	cout << "display:" << ' ';
	for(p=va.begin(); p!=va.end(); ++p)
		cout << *(p) << ' ';
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	cout << "范围删除vb中[1, 3)的元素" << endl;
	vb.erase(1, 3);

cout << endl;
	cout << "迭代器遍历vb:" << endl;
	jj::jvector<int>::iterator ps;
	cout << "display:" << ' ';
	for(ps=vb.begin(); ps!=vb.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;


	cout << "迭代'倒'遍历va:" << endl;

	cout << "display:" << ' ';
	for(p=va.end()-1; p!=va.begin(); --p)
		cout << *(p) << ' ';
	cout << *(p);
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	cout << "迭代器遍历vb:" << endl;
	cout << "display:" << ' ';
	for(ps=vb.begin(); ps!=vb.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

cout << endl;

	
	jj::jvector<int>::reverse_iterator rp;//反向迭代器
	cout << "反向迭代器遍历va:" << endl;
	cout << "display:" << ' ';
	for(rp=va.rbegin(); rp!=va.rend(); ++rp)
		cout << *(rp) << ' ';
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	
	cout << "反向迭代器'倒'遍历vb:" << endl;
	cout << "display:" << ' ';
	for(rp=vb.rend()+1; rp!=vb.rbegin(); --rp)
		cout << *(rp) << ' ';
	cout << *(rp);
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

cout << endl;
	
	cout << "迭代器遍历vc:" << endl;
	cout << "display:" << ' ';
	for(ps=vc.begin(); ps!=vc.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

cout << endl;

	jj::jvector<int>::iterator p1 = vb.end() - 1;
	jj::jvector<int>::iterator p2 = vb.begin() + vb.size() - 1;
	cout << "令:p1 = vb.end() - 1;\n   p2 = vb.begin + vb.size(); - 1" << endl;
	puts(p1 == p2 ? "则p1 == p2" : "则p1 != p2");
	cout << *(p1) << ' ' << *(p2) << endl;

cout << endl;

	cout << "*(p1-1) = " << *(p1-1) << endl;
}

/*
下标遍历va:
2 3 100 

下标遍历vb:
2 3 100 77 5 5 5 5 5 66 

预留va的8个空间

迭代器遍历va:
display: 2 3 100 
space:   3/8

范围删除vb中[1, 3)的元素

迭代器遍历vb:
display: 2 77 5 5 5 5 5 66 
space:   8/20
迭代'倒'遍历va:
display: 100 3 2
space:   3/8

迭代器遍历vb:
display: 2 77 5 5 5 5 5 66 
space:   8/20

反向迭代器遍历va:
display: 100 3 2 
space:   3/8

反向迭代器'倒'遍历vb:
display: 97 0 2 77 5 5 5 5 5 66
space:   8/20

迭代器遍历vc:
display: 3 3 3 3 3 
space:   8/20

令:p1 = vb.end() - 1;
   p2 = vb.begin + vb.size(); - 1
则p1 == p2
66 66

*(p1-1) = 5

*/
