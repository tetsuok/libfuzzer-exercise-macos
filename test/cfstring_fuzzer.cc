#include <CoreFoundation/CoreFoundation.h>

static bool Fuzz(const uint8_t *data, size_t size) {
  auto cfstr = CFStringCreateWithBytesNoCopy(
      nullptr, data, size, kCFStringEncodingASCII, true, kCFAllocatorNull);
  if (!cfstr)
    return false;
  auto lang = CFStringTokenizerCopyBestStringLanguage(
      cfstr, CFRangeMake(0, CFStringGetLength(cfstr)));
  if (lang)
    CFRelease(lang);
  CFRelease(cfstr);
  return true;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  Fuzz(Data, Size);
  return 0;
}
