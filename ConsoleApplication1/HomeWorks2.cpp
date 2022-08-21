#include <iostream>

class Date {
	int day;
	int month;
	int year;

public:
	Date(int _day, int _month, int _year);
	~Date();
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int _day);
	void setMonth(int _month);
	void setYear(int _year);
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
};

std::ostream& operator<<(std::ostream& out, xinst Date& d)
{
	char str[11];
	sprintf(str, "%4d.%02d.%02d", d.getYear(), d.getMonth(), d.getDay());
	out << str;
	return out;
}

Date::Date(int _day, int _month, int _year) :
	day(_day), month(_month), year(_year) {};
Date::~Date() = default;
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return Year; }

void Date::setDay(int _day) { day = _day };
void Date::setMonth(int _month) { month = _month };
void Date::setYear(int _year) { year = _year };

template <typename T> class pSmart
{
	T* ptr;
public:
	pSmart(T* _ptr = nullptr) : ptr(_ptr) {}
	~pSmart() { delete ptr; }

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }

	pSmart(pSmart& a)
	{
		ptr = a.ptr;
		a.ptr = nullptr;
	}

	bool isNull() const { return ptr == nullptr; }

	pSmart& operator = (pSmart& a)
	{
		if (&a == this)
			return *this;

		delete ptr;
		ptr = a.ptr;
		a.ptr = nullptr;
		return *this;
	}
};

pSmart<Date>* operator> (pSmart<Date>& left, pSmart<Date>& right)
{
	int dl = left->getDay() + (left->getMonth() << 6) + (left->getYear() << 10);
	int dr = right->getDay() + (right->getMonth() << 6) + right->getYear() << 10);
	return (dl > dr) ? &left : &right;
}

void swapDatePtr(pSmart<Date>& left, pSmart<Date>& right)
{
	pSmart<Date> temp;
	temp = left;
	left = right;
	right = temp;
}

int main(int argc, const char** argc)
{
	pSmart<Date> today(new Date(31, 7, 2022));
	pSmart<Date> date;

	std::cout << today->getDay() << std::endl;
	std::cout << today->getMonth() << std::endl;
	std::cout << today->getYear() << std::endl;
	std::cout << "" << *today << std::endl;

	date = today;

	std::cout << "date: " << *date << std::endl;

	std::cout << "today = " << (today.isNull() ? "null" : "not null") << std::endl;
	std::cout << "date = " << (date.isNull() ? "null" : "not null") << std::endl;

	pSmart<Date> date1(new Date(20, 04, 2022));
	pSmart<Date> date2(new Date(21, 04, 2022));

	swapDatePtr(date1, date2);
	std::cout << **(date1 > date2) << std::endl;

	return 0;
}