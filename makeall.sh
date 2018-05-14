#!/bin/bash

declare -a arr=("lab00" "lab01" "lab01x" "lab02" "lab02x" "lab02gt" "lab03" "lab03x" "lab03dz" "lab04" "lab04x" "lab04ma" "lab08")
current_dir=$PWD

for i in "${arr[@]}"
do
	cd $i
	make $1
	cd $current_dir
done