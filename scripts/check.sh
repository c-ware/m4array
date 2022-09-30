#!/bin/sh
# Run checks

echo Running test tests/init
$1 tests/init
echo Ran test tests/init

echo Running test tests/free
$1 tests/free
echo Ran test tests/free

echo Running test tests/resize
$1 tests/resize
echo Ran test tests/resize

echo Running test tests/append
$1 tests/append
echo Ran test tests/append

echo Running test tests/insert
$1 tests/insert
echo Ran test tests/insert

echo Running test tests/pop
$1 tests/pop
echo Ran test tests/pop

echo Running test tests/find
$1 tests/find
echo Ran test tests/find

echo Running test tests/map
$1 tests/map
echo Ran test tests/map

echo Running test tests/filter
$1 tests/filter
echo Ran test tests/filter

echo Running test tests/clear
$1 tests/clear
echo Ran test tests/clear

echo Running test tests/foreach
$1 tests/foreach
echo Ran test tests/foreach
