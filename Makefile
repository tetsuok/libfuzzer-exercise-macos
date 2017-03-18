
install: install-clang install-libfuzzer

install-clang:
	./install_clang.sh

install-libfuzzer:
	./install_libfuzzer.sh

check:
	./test.sh

clean:
	rm -fr ./libFuzzer.a Fuzzer third_party TMP_CLANG
