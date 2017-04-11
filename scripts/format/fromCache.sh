#! /bin/bash
clangFormat=""

if [[ "$OSTYPE" == "linux-gnu" ]]; then
	clangFormat="clang-format-3.8"
elif [[ "$OSTYPE" == "msys" ]]; then
	clangFormat="clang-format.exe"
else
	echo "Unsupported OS: $$OSTPYE"
        exit 1
fi

while read entry
do
	file=$(echo $entry | cut -d"," -f1)
	startLine=$(echo $entry | cut -d"," -f2)
	endLine=$(echo $entry | cut -d"," -f3)
	$clangFormat -lines=$startLine:$endLine -i $file
done < .formatCache



for entry in $(cut -d"," -f1 .formatCache | sort | uniq)
do
	git add -p $entry
done
