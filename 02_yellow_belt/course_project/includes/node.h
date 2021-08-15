#pragma once

#include "date.h"

#include <memory>

using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	And,
	Or,
};

class Node {
public:
	virtual
	bool	Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node {
	bool	Evaluate(const Date& date, const string& event) override ;	
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& cmp_date);
	bool	Evaluate(const Date& date, const string& event) override ;
private:
	Comparison	__cmp;
	Date		__cmp_date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& cmp_event);
	bool	Evaluate(const Date& date, const string& event) override ;
private:
	Comparison	__cmp;
	string		__cmp_event;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(
		const LogicalOperation& op, 
		shared_ptr<Node> left, shared_ptr<Node> right);
	bool	Evaluate(const Date& date, const string& event) override ;
private:
	LogicalOperation	__op;
	shared_ptr<Node>	__left;
	shared_ptr<Node>	__right;
};
