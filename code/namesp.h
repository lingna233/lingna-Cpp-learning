// namesp.h
#include <string>
// create the pers and debts nmaespaces

namespace pers {
	struct Person {
		std::string fname;
		std::string lname;
	};
	void getPerson(Person &);
	void showPerson(const Person &);
}
namespace debts {
	using namespace pers;
	struct Debt {
		Person nmae;
		double amount;
	};
	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[], int n);
}