#!/bin/bash -x
ROOT=$(dirname "$BASH_SOURCE")
SDK="$(xcrun --show-sdk-path --sdk macosx)"
$ROOT/../clang-driver -std=c++11 -g \
                      -fno-omit-frame-pointer -fsanitize=address \
                      -fsanitize-coverage=trace-pc-guard \
                      -framework CoreFoundation \
                      -isysroot "$SDK" \
                      $ROOT/cfstringtokenizer_fuzzer.cc libFuzzer.a -o cfstringtokenizer_fuzzer
