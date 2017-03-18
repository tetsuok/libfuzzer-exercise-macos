#!/bin/bash
mkdir -p TMP_CLANG
cd TMP_CLANG
if [ -e clang ]; then
  (cd clang && git pull)
else
  git clone https://chromium.googlesource.com/chromium/src/tools/clang
fi
cd ..
TMP_CLANG/clang/scripts/update.py
mkdir -p local
cp -fr third_party/llvm-build/Release+Asserts/* local

TARGET=$(find third_party -name "libclang_rt.asan_osx_dynamic.dylib")
ln -sf $TARGET .
