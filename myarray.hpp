/**********************************************
# Author: guojunfeng
# GitHub: https://github.com/guojunfengcode
# Last modified: 2020-10-30 15:47
# Filename: myarray.cpp
# Description: 
**********************************************/
#pragma once
#include <iostream>
#include <cstring>
#include <assert.h>
#include "typetraits.hpp"

using namespace std;

class person{
public:
	person(){}
	person(string n, int a):name(n), age(a) {}
	string name;
	int age;
};

ostream& operator<<(ostream &cout, person p) {
	cout << "name=" << p.name << "  " << "age=" << p.age;
	return cout;
}

template<class T>
class Myarray{
public:
	typedef T* iterator;
	Myarray(int cap) {
		this->cap = cap;
		this->size = 0;
		this->arr = new T[this->cap];
		this->start = NULL;
		this->finsh = NULL;
	}

	Myarray(const Myarray &m) {
		this->cap = m.cap;
		this->size = m.size;
		this->arr = new T[this->cap];
		int i;
		for(i = 0; i < this->size; i++) {
			this->arr[i] = m.arr[i];
		}
		this->start = &this->arr[0];
		this->finsh = &this->arr[this->size];

	}

	Myarray& operator=(const Myarray& m) {
		if (this->arr != NULL) {
			delete []this->arr;
			this->arr = NULL;
			this->cap = 0;
			this->size = 0;
		}
		this->cap = m.cap;
		this->size = m.size;
		this->arr = new T[this->cap];
		int i;
		if(typeTraits<T>::isPODtype()) {
			memcpy(this->arr, m.arr, sizeof(T)*this->size);
		} else {
			for(i = 0; i < this->size; i++) {
				this->arr[i] = m.arr[i];
			}
		}
		this->start = m.start;
		this->finsh = m.finsh;
		return *this;
		
	}

	void add(const T &value) {
		if (this->cap == this->size) {
			return;
		}
		this->arr[this->size] = value;
		this->size++;
		if (this->start == NULL) {
			this->start = &this->arr[this->size-1];
			this->finsh = &this->arr[this->size];
		} else {
			this->finsh = &this->arr[this->size];
		}
	}
	void del() {
		if (this->size == 0) {
			return;
		}
		this->size--;
		
		if(typeTraits<T>::isPODtype()) {
			memset(&(this->arr[this->size]), 0, sizeof(T));
			cout << "is pod type" << endl;
		} else {
			cout << "not's pod type" << endl;
		}
		this->finsh = &this->arr[this->size];
	}

	T& operator[](int index) const{
		assert(index < this->size);
		return this->arr[index];
	}
	iterator begin() {
		return this->start;
	}

	iterator end() {
		return this->finsh;
	}
	
	int getsize() const{
		return this->size;
	}
	int getcap() {
		return this->cap;
	}
	~Myarray() {
		
		if (arr != NULL) {
			delete[] arr;
			arr = NULL;
		}
		size = 0;
		cap = 0;
		start = NULL;
		finsh = NULL;
	}


private:
	T *arr;
	iterator start;
	iterator finsh;
	int size;
	int cap;
};

