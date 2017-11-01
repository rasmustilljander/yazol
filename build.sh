#! /bin/bash

function help
{
	echo "No help currently available."
}

function clean
{
	if [ -d 'yazol' ] && [ -d 'build' ]; then
		echo CLEANING
		commandToExecute="rm -r $DIR/build"
		echo $commandToExecute
		`$commandToExecute`
	fi
}

function build
{
	cd $DIR
	mkdir -p build
	if [ $? -ne 0 ]; then exit 1; fi
	cd build
	if [ $? -ne 0 ]; then exit 1; fi
	cmake ..
	if [ $? -ne 0 ]; then exit 1; fi
	make -j 4
}

## Entrypoint
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
if [ ! -z "$1" ]; then

	if [ "$1" = 'build' ] || [ "$1" = '-b' ] || [ "$1" = '--build' ]; then
		build
		exit 0
	fi

	if [ "$1" = 'clean' ] || [ "$1" = '-c' ] || [ "$1" = '--clean' ]; then
		clean
		exit 0
	fi

	if [ "$1" = 'help' ] || [ "$1" = '-h' ] || [ "$1" = '--help' ]; then
		help
		exit 0
	fi
fi

build
exit 0