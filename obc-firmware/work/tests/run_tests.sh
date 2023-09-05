#!/bin/bash
pattern="*test*.py"
gui_bin_path="../binaries/gs_gui_GUI"

cp $pattern $gui_bin_path
cd $gui_bin_path || exit

declare -a test_files
readarray -d '' test_files < <(find . -name "$pattern" -print0)

echo "found ${#test_files[@]} test files:"
for test_file in ${test_files[@]};
do
	echo "$test_file"
done
echo ""

for test_file in ${test_files[@]};
do
	echo "running test fie $test_file:"
	python3 "$test_file"
	echo ""
done
