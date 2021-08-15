#!/bin/bash
diff <(cat 01_test | ./project.out) 01_out
diff <(cat 02_test | ./project.out) 02_out
diff <(cat 03_test | ./project.out) 03_out
diff <(cat 04_test | ./project.out) 04_out
diff <(cat 05_test | ./project.out) 05_out
