#!/bin/bash
if [ -e Fuzzer ]; then
  (cd Fuzzer && git pull)
else
  git clone https://chromium.googlesource.com/chromium/llvm-project/llvm/lib/Fuzzer
fi

./Fuzzer/build.sh
