# include <iostream>
# include <cstring>
# include <string>
# include <assert.h>
# include "Calculator.h"
# include "LoadStrategy.h"
# include "PayStrategy.h"


using namespace std;

int main() {
	string loadStrategy, payStrategy;
	cin >> loadStrategy >> payStrategy;

	LoadStrategy* m_loadStrategy;

	if (loadStrategy=="Number")
		m_loadStrategy = new NumberLoadStrategy();
	else if (loadStrategy=="Word")
		m_loadStrategy = new WordLoadStrategy();
	else 
		assert(false);

	PayStrategy* m_payStrategy;

	if (payStrategy=="Normal")
		m_payStrategy = new NormalStrategy();
	else if (payStrategy=="Rebate")
		m_payStrategy = new RebateStrategy();
	else if (payStrategy=="Return")
		m_payStrategy = new ReturnStrategy();		
	else 
		assert(false);

	Calculator calculator = Calculator(m_loadStrategy, m_payStrategy);

	float money = calculator.load();
	float payment = calculator.pay(money);
	cout << payment << endl;

	return 0;
}