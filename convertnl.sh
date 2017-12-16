#!/usr/bin/env bash

echo "Converting line endings..."
find Inc -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q
find Src -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q
find Middlewares -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q
find Drivers -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q
find User -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q
dos2unix -q Makefile

find Patches -type f -print0 | xargs -0 -n 10 -P 4 dos2unix -q

