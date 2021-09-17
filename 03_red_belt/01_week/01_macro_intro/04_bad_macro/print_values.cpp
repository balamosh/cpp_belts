#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y)			\
	out << (x) << endl << (y) << endl	\

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");

  tr.RunTest([] {
    ostringstream output;
	for (int i = 0; i < 3; i++)
    	PRINT_VALUES(output, i, "red belt");
    ASSERT_EQUAL(output.str(), "0\nred belt\n1\nred belt\n2\nred belt\n");
  }, "PRINT_VALUES range based for example");

  tr.RunTest([] {
    ostringstream output;
	int	x = 5;
	if (x < 5)
    	PRINT_VALUES(output, x, "x < 5");
	else if (x == 5)
		PRINT_VALUES(output, x, "x == 5");
	else
		PRINT_VALUES(output, x, "x > 5");
    ASSERT_EQUAL(output.str(), "5\nx == 5\n");
  }, "PRINT_VALUES if else example 1");

  tr.RunTest([] {
    ostringstream output;
	int	x = 2;
	if (x < 5)
    	PRINT_VALUES(output, x, "x < 5");
	else if (x == 5)
		PRINT_VALUES(output, x, "x == 5");
	else
		PRINT_VALUES(output, x, "x > 5");
    ASSERT_EQUAL(output.str(), "2\nx < 5\n");
  }, "PRINT_VALUES if else example 2");

  tr.RunTest([] {
    ostringstream output;
	int	x = 7;
	if (x < 5)
    	PRINT_VALUES(output, x, "x < 5");
	else if (x == 5)
		PRINT_VALUES(output, x, "x == 5");
	else
		PRINT_VALUES(output, x, "x > 5");
    ASSERT_EQUAL(output.str(), "7\nx > 5\n");
  }, "PRINT_VALUES if else example 3");


  return 0;
}
