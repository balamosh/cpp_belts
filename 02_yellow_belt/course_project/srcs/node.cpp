#include "node.h"

#include <tuple>

using namespace std;

bool
EmptyNode::Evaluate(const Date& date, const string& event) override {
	return (false);
}

template <class T>
bool	CompateEntity(const T& lhs, const T& rhs, Comparison cmp) {
	if (cmp == Comparison::Less) {
		return (lhs < rhs);
	} else if (__cmp == Comparison::LessOrEqual) {
		return (lhs <= rhs);
	} else if (__cmp == Comparison::Greater) {
		return (lhs > rhs);
	} else if (__cmp == Comparison::GreaterOrEqual) {
		return (lhs >= rhs);
	} else if (__cmp == Comparison::Equal) {
		return (lhs == rhs);
	} else if (__cmp == Comparison::NotEqual) {
		return (lhs != rhs);
	} else {
		return (false);
	}
}

bool
DateComparisonNode::Evaluate(const Date& date, const string& event) override {
	auto	lhs = make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
	auto	rhs = make_tuple(__cmp_date.GetYear(),
								__cmp_date.GetMonth(),
								__cmp_date.GetDay());
	return (CompateEntity(lhs, rhs, __cmp));
}

bool
EventComparisonNode::Evaluate(const Date& date, const string& event) override {
	return (CompateEntity(event, __cmp_event, __cmp));
}

bool
LogicalOperationNode::Evaluate(const Date& date, const string& event) override {
	auto	left = __left.Evaluate(date, event);
	auto	right = __right.Evaluate(date, event);
	if (__op == LogicalOperation::And) {
		return (left && right);
	} else if (__op == LogicalOperation::Or) {
		return (left || right);
	} else {
		return (false);
	}
}