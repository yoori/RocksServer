#!/bin/bash


cd $(dirname $0)

#
# compile rocksdb
#
pushd rocksdb
export LUA_PATH=
export LUA_INCLUDE=
# make clean
make static_lib DISABLE_WARNING_AS_ERROR=1 -j$(nproc)
#make shared_lib
# make check
popd
