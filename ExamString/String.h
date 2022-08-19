#pragma once
#include <cstring>
#include <fstream>

class String {
private:
	
	void free() {
		delete[] str;
	}
	void copyFrom(const String& other) {
		this->size = other.size;
		str = new char[size+1];
		for (size_t i = 0; i < size; i++)
		{
			str[i] = other.str[i];
		}
		str[size] = '\0';
	}
protected:
	char* str;
	size_t size;
public:
	String() {
		str = new char [1];
		str[0] = '\0';
		size = 0;
	}
	String(const String& other) {
		copyFrom(other);
	}
	String(const char* str) {
		//nullptr check NOT for this
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);
	}
	String(size_t a) {
		size_t temp = a;
		size = 1;
		while (temp > 10) {
			size++;
			temp = temp / 10;
		}
		str = new char[size+1];
		int i = size-1;
		size_t x = 0;
		while (a >= 1) {
			x = a % 10;
			str[i] = (x + '0');
			i--;
			a = a / 10;
		}
		str[size] = '\0';

	}
	String& operator=(const String& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	virtual ~String() {
		free();
	}

	char& operator[](size_t index) {
		if (index >= size)
		{
			throw "Error";
		}

			return str[index];
	}
	const char operator[](size_t index) const {
		if (index >= size)
		{
			throw "Error";
		}

		return str[index];
	}
	virtual String& operator+=(const String& nStr) {
		char* temp = new char(size + nStr.size + 1);
		strcpy(temp, str);
		strcat(temp, nStr.str);
		delete[] str;
		str = temp;
		size = size + nStr.size;
		return *this;
	}

	friend String operator+(const String & nStrOne, const String & nStrTwo) {
		String newString;
		newString += nStrOne;
		newString += nStrTwo;
		return newString;
	}

	friend std::ostream& operator<<(std::ostream& myfile, const String& str) {
		myfile << str.str;

		return myfile;		
	}
	friend std::istream& operator>>(std::istream& myfile, String& str) {

		char buffer[1024];
		myfile.getline(buffer,1024);
		delete[] str.str;
		str.size = strlen(buffer);
		str.str = new char[str.size + 1];
		strcpy(str.str, buffer);

		return myfile;
	}

};