#! /bin/bash

exitSignal=1
function exitAndWait {
	if [ $exitSignal -eq 1 ];  then
		echo "Copying git hooks - Failed"
		echo "Preparing code environment - Failed"
	fi

	read -rsp $'Press any key to exit...\n' -n 1 key
	exit $exitSignal
}

echo "Preparing code environment"

# Hooks
echo "Copying git hooks"
for folder in scripts/githooks/*;
do
	if test -d $folder; then
		scriptName=`echo $folder | rev | cut -d"/" -f1 | rev`;
		scriptName=${scriptName%-*} # Remove everything after the last -
		scriptPath="$folder/$scriptName";
		echo "Copying githook: $scriptName"
		echo -e  "\t$scriptPath -> .git/hooks/$scriptName"
		cp $scriptPath .git/hooks/
		if [ $? -ne 0 ]; then
			echo "Copying githook: $scriptName - Failed"
			exitAndWait
		else
			echo "Copying githook: $scriptName - Success"
		fi

		echo "Making the githook executable: .git/hooks/$scriptName"
		echo -e  "chmod 744 .git/hooks/$scriptName"
		chmod 744 .git/hooks/$scriptName
		if [ $? -ne 0 ]; then
			echo "Making the githook executable: .git/hooks/$scriptName - Failed"
			exitAndWait
		else
			echo "Making the githook executable: .git/hooks/$scriptName - Success"
		fi
	fi
done
echo "Copying git hooks - Success"

exitSignal=0
echo "Preparing code environment - Success"
exitAndWait
