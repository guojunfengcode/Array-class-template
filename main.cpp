/**********************************************
# Author: guojunfeng
# GitHub: https://github.com/guojunfengcode
# Last modified: 2020-10-30 15:47
# Filename: main.cpp
# Description: 
**********************************************/
#include "myarray.hpp"
#include <algorithm>
using namespace std;

template<class T>
void printfarray(const Myarray<T> &m) {
	int i;
	for (i = 0; i < m.getsize(); i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void printfpersonarray(Myarray<person> &m) {
#if 0
	int i;
	for (i = 0; i < m.getsize(); i++) {
		cout << m[i].name << ":" << m[i].age << " " << endl;
	}
#endif
	reverse(m.begin(), m.end());
	for (Myarray<person>::iterator it = m.begin(); it != m.end(); it++) {
		cout << *it << endl;
	}	
}

int main() {

	Myarray<int> m(6);
	Myarray<int> x(7);
	Myarray<int> a(m);
	int i;
	for(i = 0; i < 5; i++) {
		x.add(i);
	}
	m = a = x;
	m.del();
	m.del();
	cout << m.getsize() << endl;
	cout << m.getcap() << endl;
	printfarray(x);
	printfarray(m);

	Myarray<string> s(5);
	s.add("hbk");
	s.add("ut");
	s.add("cena");

	//s[3] = "rko";
	printfarray(s);

	person p1("abc", 2);
	person p2("edf", 3);
	person p3("cnd", 4);
	Myarray<person> arr(7);
	arr.add(p1);
	arr.add(p2);
	arr.add(p3);
	arr.del();
	//Myarray<person> arr1(0);
	//arr1 = arr;
	arr[1] = p3;
	arr.add(person("ooo", 7));
	printfpersonarray(arr);
}
