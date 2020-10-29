/**********************************************
# Author: guojunfeng
# GitHub: https://github.com/guojunfengcode
# Last modified: 2020-10-29 15:42
# Filename: typetraits.hpp
# Description: 
**********************************************/
#pragma once
#include <iostream>

using namespace std;

template<class T>
struct typeTraits {
	static bool isPODtype(){
		return false;
	}
};

template<>
struct typeTraits<int> {
	static bool isPODtype(){
		return true;
	}
};

template<>
struct typeTraits<char> {
	static bool isPODtype(){
		return true;
	}
};

template<>
struct typeTraits<short> {
	static bool isPODtype(){
		return true;
	}
};

template<>
struct typeTraits<float> {
	static bool isPODtype(){
		return true;
	}
};

template<>
struct typeTraits<double> {
	static bool isPODtype(){
		return true;
	}
};
