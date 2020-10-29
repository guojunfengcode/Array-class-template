/**********************************************
# Author: guojunfeng
# GitHub: https://github.com/guojunfengcode
# Last modified: 2020-10-29 14:16
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

template<class T>
class Myarray{
public:
	Myarray(int cap) {
		this->cap = cap;
		this->size = 0;
		this->arr = new T[this->cap];
	}

	Myarray(const Myarray &m) {
		this->cap = m.cap;
		this->size = m.size;
		this->arr = new T[this->cap];
		int i;
		for(i = 0; i < this->size; i++) {
			this->arr[i] = m.arr[i];
		}

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
		return *this;
		
	}

	void add(const T &value) {
		if (this->cap == this->size) {
			return;
		}
		this->arr[this->size] = value;
		this->size++;
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
	}

	T& operator[](int index) const{
		assert(index < this->size);
		return this->arr[index];
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
	}


private:
	T *arr;
	int size;
	int cap;
};

