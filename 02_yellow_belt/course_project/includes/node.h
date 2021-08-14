#pragma once

#include "date.h"

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
	bool	Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node {	
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& cmp_date);
private:
	Comparison	__cmp;
	Date		__cmp_date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& cmp_event);
private:
	Comparison	__cmp;
	string		__cmp_event;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(
		const LogicalOperation& op, 
		const Node& left, const Node& right);
private:
	LogicalOperation	__op;
	Node				__left;
	Node				__right;
};
