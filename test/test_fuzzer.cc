#include <stdint.h>
#include <stddef.h>

bool FuzzMe(const uint8_t *data,
            size_t size) {
  if (size > 64)
    return false;
  uint8_t r = 0;
  for (size_t i = 0; i <= size; ++i) // :(
    r |= data[i];
  return r;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  FuzzMe(Data, Size);
  return 0;
}
