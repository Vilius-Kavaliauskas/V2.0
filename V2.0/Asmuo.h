#pragma once
#include <string>

using std::string;
class Asmuo
{
protected:
	string vardas, pavarde;
public:
	Asmuo(string var = "", string pav = "") : vardas{ var }, pavarde{ pav } {};
	virtual string Getvardas() const = 0;
	virtual string Getpavarde() const = 0;
	virtual void kas_as() = 0;
};
