#!/usr/bin/env bash

[[ -d classes ]] || mkdir -p classes

ls **/*.java > all.cls

# compile
javac -bootclasspath /usr/local/classpath/share/classpath/glibj.zip -d classes @all.cls

# zip
rm -rf classes.zip
cd classes && zip -r ../classes.zip * && cd ../

# install
mkdir -p /usr/local/app/neojam/
rm -rf /usr/local/app/neojam/*
mkdir -p /usr/local/app/neojam/share/jamvm
mkdir -p /usr/local/app/neojam/share/classes

cp -r classes/* /usr/local/app/neojam/share/classes
cp classes.zip /usr/local/app/neojam/share/jamvm

