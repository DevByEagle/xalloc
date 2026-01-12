#ifndef XALLOC_CONFIG_H_
#define XALLOC_CONFIG_H_

#ifndef XALLOC_HOSTED_IMPLEMENTATION
#if !defined(_MSC_VER) && !defined(__STDC_HOSTED__)
#define XALLOC_HOSTED_IMPLEMENTATION 0
#else
#define XALLOC_HOSTED_IMPLEMENTATION 1
#endif
#endif

#endif