# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <assert.h>
# include "Calculator.h"
# include "OccupationStrategy.h"
# include "PayStrategy.h"


using namespace std;

int main() {
	string occupationStrategy, payStrategy;
	cin >> occupationStrategy >> payStrategy;

	OccupationStrategy* m_occupationStrategy;

	if (occupationStrategy=="Salesman")
		m_occupationStrategy = new SalesmanStrategy();
	else if (occupationStrategy=="Developer")
		m_occupationStrategy = new DeveloperStrategy();
	else 
		assert(false);

	PayStrategy* m_payStrategy;

	if (payStrategy=="Normal")
		m_payStrategy = new NormalStrategy();
	else if (payStrategy=="Swift")
		m_payStrategy = new SwiftStrategy();
	else if (payStrategy=="Bitcoin")
		m_payStrategy = new BitcoinStrategy();		
	else 
		assert(false);

	Calculator calculator = Calculator(m_occupationStrategy, m_payStrategy);


	string name;
	double base, bonus, level;

	while (cin >> name >> base >> bonus >> level) {
		double salary = calculator.getSalary(base, bonus, level);	
		double onhandSalary = calculator.pay(name, salary);
		printf("%.2f\n", onhandSalary);
	}


	delete m_occupationStrategy;
	delete m_payStrategy;
	return 0;
}