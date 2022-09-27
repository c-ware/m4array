#!/bin/sh
# Run checks

echo Running test tests/init
tests/init
echo Ran test tests/init

echo Running test tests/free
tests/free
echo Ran test tests/free

echo Running test tests/append
tests/append
echo Ran test tests/append

echo Running test tests/insert
tests/insert
echo Ran test tests/insert

echo Running test tests/pop
tests/pop
echo Ran test tests/pop

echo Running test tests/find
tests/find
echo Ran test tests/find

echo Running test tests/foreach
tests/foreach
echo Ran test tests/foreach

echo Running test tests/map
tests/map
echo Ran test tests/map
