#!/bin/bash
diff <(cat tests/01_test | ./project.out) tests/01_out
diff <(cat tests/02_test | ./project.out) tests/02_out
diff <(cat tests/03_test | ./project.out) tests/03_out
diff <(cat tests/04_test | ./project.out) tests/04_out
diff <(cat tests/05_test | ./project.out) tests/05_out
