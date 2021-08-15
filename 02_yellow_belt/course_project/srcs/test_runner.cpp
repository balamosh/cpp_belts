#include "test_runner.h"

using namespace std;

void	Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}
