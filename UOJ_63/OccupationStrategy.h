#pragma once

class OccupationStrategy {
public:								
	virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {
public:
	virtual double getSalary(double base, double bonus, double level) override {
		if (level < 60) return base;
		else if (level >= 60 && level < 70) return base + 0.6 * bonus;
		else if (level >= 70 && level < 80) return base + 0.7 * bonus;
		else if (level >= 80 && level <= 100) return base + bonus;
		else return -1;
	}
};

class DeveloperStrategy : public OccupationStrategy {	
public:
	virtual double getSalary(double base, double bonus, double level) override {
		return base + level / 100 * bonus;
	}
};