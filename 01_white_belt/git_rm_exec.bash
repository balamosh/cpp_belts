#!/bin/bash
find . -executable -type f -exec git rm --cached {} \;