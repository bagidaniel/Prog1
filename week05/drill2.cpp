#include "std_lib_facilities.h"

struct Person
{
	Person(string fn, string sn, int a) : first_name(fn), second_name(sn), age(a) {
		if(a < 0 || a > 150)
		{
			error("Error in age");
		}
		string f{"; : \" \' [ ] * & ^ % $ # @ !"};
		for(auto i : f){
			for(auto j : fn+sn){
				if(i == j)
				{
					error("Error in name");
				}
			}
		}
	}

	string fn() const { return first_name; }
	string sn() const { return second_name; }
	int a() const { return age; } 

private:
	string first_name;
	string second_name;
	int age;
};

ostream& operator<<(ostream& os, Person p)
{
	os << p.fn() << " " << p.sn() << " " << p.a() << endl;
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	string tmp_first_name;
	string tmp_second_name;
	int tmp_age;
	is >> tmp_first_name;
	is >> tmp_second_name;
	is >> tmp_age;

	p = Person{tmp_first_name, tmp_second_name, tmp_age};

	return is;
}

int main(){
	vector<Person> v;
	Person p("", "", 0);

	while(cin >> p)
	{
		v.push_back(p);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
	}
	
	
	return 0;
}