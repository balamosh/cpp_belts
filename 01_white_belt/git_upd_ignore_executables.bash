#!/bin/bash
find . -executable -type f | sed 's#^./##' | sort | diff -u .gitignore - > tmp_diff
patch .gitignore tmp_diff
rm tmp_diff