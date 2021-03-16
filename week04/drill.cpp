#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf() const {cout << "B1::vf()\n";}
	void f() const {cout << "B1::f()\n";}
	virtual void pvf() {}
};

class D1 : public B1
{
public:
	void vf() const override {cout << "D1::vf()\n";}
	void f() const {cout << "D1::f()\n";}
};

class D2 : public D1
{
public:
	void pvf() override {cout << "D2::pvf()\n";}
};

class B2
{
public:
	virtual void pvf() {}
};

class D21 : public B2
{
public:
	string s = "Text";
	void pvf() override {cout << s << endl;}
};

class D22 : public B2
{
public:
	int n = 73;
	void pvf() override {cout << n << endl;}
};

void f(B2 &ref)
{
	ref.pvf();
}

int main()
{
	B1 b;
	b.vf();
	b.f();

	D1 d;
	d.vf();
	d.f();
	cout << "\n";

	B1& r = d;
	r.vf();
	r.f();
	cout << "\n";

	D2 dd;
	dd.vf();
	dd.f();
	dd.pvf();
	cout << "\n";

	D21 bbd;
	D22 bbdd;
	f(bbd);
	f(bbdd);
}