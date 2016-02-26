#include <iostream>
#include <string>

class B1
{
public:
	virtual void vf() const { std::cout << "B1::vf()\n"; };
	void f() const { std::cout << "B1::f()\n"; };
	virtual void pvf() const = 0;
};

class D1 : public B1
{
public:
	void vf() const override { std::cout << "D1::vf()\n"; };
	void f() const { std::cout << "D1::f()\n"; };
};

class D2 : public D1
{
public:
	void pvf() const override { std::cout << "D2::pvf()"; }
};


class B2
{
public:
	virtual void pvf() const = 0;
};

class D21 : public B2
{
public:
	void pvf() const override { std::cout << str << std::endl; }
private:
	std::string str{"from D21"};
};

class D22 : public B2
{
public:
	void pvf() const override { std::cout << count << std::endl; }
private:
	int count{5};
};

void f(B2& b) { b.pvf(); }

int main()
{
	D21 d21;
	D22 d22;

	f(d21);
	f(d22);

	std::cin.get();

}