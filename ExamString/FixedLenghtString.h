#pragma once
#include "String.h"

class FixedLenghtString : public String {

public:
	FixedLenghtString(size_t size) {
		delete[] str;
		this->size = size;
		this->str = new char[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			str[i] = ' ';
		}
		str[size] = '\0';
	};
	FixedLenghtString(size_t size, const char* str) {
		delete[] str;
		if (size == strlen(str) && str != nullptr) {
			this->str = new char[size + 1];
			strcpy(this->str, str);
		}
		else {this->size = size;
		this->str = new char[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = ' ';
		}
		this->str[size] = '\0';}
	}

	String& operator+=(const String& nStr) override {
		throw "Not allowed action";
	}

};