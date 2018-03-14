#!/bin/bash

declare -a arr=("lab00" "lab01" "lab01x" "lab02" "lab02x")
current_dir=$PWD

for i in "${arr[@]}"
do
	cd $i
	make $1
	cd $current_dir
done