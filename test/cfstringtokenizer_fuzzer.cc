#include <CoreFoundation/CoreFoundation.h>

static bool Fuzz(const uint8_t *data, size_t size) {
  auto cfstr = CFStringCreateWithBytesNoCopy(
      nullptr, data, size, kCFStringEncodingASCII, true, kCFAllocatorNull);
  if (!cfstr)
    return false;
  auto loc = CFLocaleCreate(nullptr, CFSTR("ar"));
  auto tok = CFStringTokenizerCreate(nullptr,
                                     cfstr, CFRangeMake(0, CFStringGetLength(cfstr)), kCFStringTokenizerUnitWord, loc);
  CFRelease(loc);
  if (!tok)
    return false;

  while (CFStringTokenizerAdvanceToNextToken(tok)) {
    auto r = CFStringTokenizerGetCurrentTokenRange(tok);
  }

  CFRelease(cfstr);
  return true;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  Fuzz(Data, Size);
  return 0;
}
