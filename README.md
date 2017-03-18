libfuzzer-exercise-macos
========================

This repo holds the scripts to setup
[libFuzzer](http://llvm.org/docs/LibFuzzer.html) on macOS.

### Setup

```
$ make install
$ make check # to make sure libFuzzer can be used
```

### Fuzz target

Write a function to do fuzzing your API.

```
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  TestYourAPI(Data, Size);
  return 0;
}
```


Compile with `-fsanitize=address -fsanitize-coverage=trace-pc-guard`,
linking with `libFuzzer.a`.

```
$ ./clang-driver -std=c++11 -g -fno-omit-frame-pointer -fsanitize=address -fsanitize-coverage=trace-pc-guard //path/to/your_fuzzer.cc libFuzzer.a -o your_fuzzer
$ ./your_fuzzer -max_total_time=300 # the fuzzer will run indefinitely if without bugs
```

See test/test_fuzzer.cc as an example.


See <http://llvm.org/docs/LibFuzzer.html> for more details.
