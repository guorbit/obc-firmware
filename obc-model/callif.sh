#!/bin/bash
make clean
make model-check
echo $? > statusfile
