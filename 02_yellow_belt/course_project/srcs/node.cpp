#include "node.h"

#include <tuple>

using namespace std;

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& cmp_date)
: __cmp(cmp), __cmp_date(cmp_date) {}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& cmp_event)
: __cmp(cmp), __cmp_event(cmp_event) {}

LogicalOperationNode::LogicalOperationNode(
		const LogicalOperation& op, 
		shared_ptr<Node> left, shared_ptr<Node> right)
: __op(op), __left(left), __right(right) {}

bool
EmptyNode::Evaluate(const Date& date, const string& event) {
	(void) date;
	(void) event;
	return (true);
}

template <typename T>
bool	CompateEntity(const T& lhs, const T& rhs, Comparison cmp) {
	if (cmp == Comparison::Less) {
		return (lhs < rhs);
	} else if (cmp == Comparison::LessOrEqual) {
		return (lhs <= rhs);
	} else if (cmp == Comparison::Greater) {
		return (lhs > rhs);
	} else if (cmp == Comparison::GreaterOrEqual) {
		return (lhs >= rhs);
	} else if (cmp == Comparison::Equal) {
		return (lhs == rhs);
	} else if (cmp == Comparison::NotEqual) {
		return (lhs != rhs);
	} else {
		return (false);
	}
}

bool
DateComparisonNode::Evaluate(const Date& date, const string& event) {
	(void) event;
	auto	lhs = make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
	auto	rhs = make_tuple(__cmp_date.GetYear(),
								__cmp_date.GetMonth(),
								__cmp_date.GetDay());
	return (CompateEntity(lhs, rhs, __cmp));
}

bool
EventComparisonNode::Evaluate(const Date& date, const string& event) {
	(void) date;
	return (CompateEntity(event, __cmp_event, __cmp));
}

bool
LogicalOperationNode::Evaluate(const Date& date, const string& event) {
	auto	left = __left->Evaluate(date, event);
	auto	right = __right->Evaluate(date, event);
	if (__op == LogicalOperation::And) {
		return (left && right);
	} else if (__op == LogicalOperation::Or) {
		return (left || right);
	} else {
		throw invalid_argument("Invalid logical operation");
	}
}