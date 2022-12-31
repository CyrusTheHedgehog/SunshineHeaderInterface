// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___CONFIG
#define _LIBCPP___CONFIG
#include <__config_site>
#if defined(_MSC_VER) && !defined(__clang__)
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#define _LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
#endif
#endif
#ifndef _LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
#pragma GCC system_header
#endif
#if defined(__apple_build_version__)
#define _LIBCPP_COMPILER_CLANG_BASED
#define _LIBCPP_APPLE_CLANG_VER (__apple_build_version__ / 10000)
#elif defined(__clang__)
#define _LIBCPP_COMPILER_CLANG_BASED
#define _LIBCPP_CLANG_VER (__clang_major__ * 100 + __clang_minor__)
#elif defined(__GNUC__)
#define _LIBCPP_COMPILER_GCC
#endif
#ifdef __cplusplus
// _LIBCPP_VERSION represents the version of libc++, which matches the version of LLVM.
// Given a LLVM release LLVM XX.YY.ZZ (e.g. LLVM 16.0.1 == 16.00.01), _LIBCPP_VERSION is
// defined to XXYYZZ.
#define _LIBCPP_VERSION             160000
#define _LIBCPP_CONCAT_IMPL(_X, _Y) _X##_Y
#define _LIBCPP_CONCAT(_X, _Y)      _LIBCPP_CONCAT_IMPL(_X, _Y)
// Valid C++ identifier that revs with every libc++ version. This can be used to
// generate identifiers that must be unique for every released libc++ version.
#define _LIBCPP_VERSIONED_IDENTIFIER _LIBCPP_CONCAT(v, _LIBCPP_VERSION)
#if __STDC_HOSTED__ == 0
#define _LIBCPP_FREESTANDING
#endif
#ifndef _LIBCPP_STD_VER
#if __cplusplus <= 201103L
#define _LIBCPP_STD_VER 11
#elif __cplusplus <= 201402L
#define _LIBCPP_STD_VER 14
#elif __cplusplus <= 201703L
#define _LIBCPP_STD_VER 17
#elif __cplusplus <= 202002L
#define _LIBCPP_STD_VER 20
#else
// Expected release year of the next C++ standard
#define _LIBCPP_STD_VER 23
#endif
#endif  // _LIBCPP_STD_VER
#if defined(__ELF__)
#define _LIBCPP_OBJECT_FORMAT_ELF 1
#elif defined(__MACH__)
#define _LIBCPP_OBJECT_FORMAT_MACHO 1
#elif defined(_WIN32)
#define _LIBCPP_OBJECT_FORMAT_COFF 1
#elif defined(__wasm__)
#define _LIBCPP_OBJECT_FORMAT_WASM 1
#elif defined(_AIX)
#define _LIBCPP_OBJECT_FORMAT_XCOFF 1
#else
// ... add new file formats here ...
#endif
#if _LIBCPP_ABI_VERSION >= 2
// Change short string representation so that string data starts at offset 0,
// improving its alignment in some cases.
#define _LIBCPP_ABI_ALTERNATE_STRING_LAYOUT
// Fix deque iterator type in order to support incomplete types.
#define _LIBCPP_ABI_INCOMPLETE_TYPES_IN_DEQUE
// Fix undefined behavior in how std::list stores its linked nodes.
#define _LIBCPP_ABI_LIST_REMOVE_NODE_POINTER_UB
// Fix undefined behavior in  how __tree stores its end and parent nodes.
#define _LIBCPP_ABI_TREE_REMOVE_NODE_POINTER_UB
// Fix undefined behavior in how __hash_table stores its pointer types.
#define _LIBCPP_ABI_FIX_UNORDERED_NODE_POINTER_UB
#define _LIBCPP_ABI_FORWARD_LIST_REMOVE_NODE_POINTER_UB
#define _LIBCPP_ABI_FIX_UNORDERED_CONTAINER_SIZE_TYPE
// Define a key function for `bad_function_call` in the library, to centralize
// its vtable and typeinfo to libc++ rather than having all other libraries
// using that class define their own copies.
#define _LIBCPP_ABI_BAD_FUNCTION_CALL_KEY_FUNCTION
// Override the default return value of exception::what() for
// bad_function_call::what() with a string that is specific to
// bad_function_call (see http://wg21.link/LWG2233). This is an ABI break
// because it changes the vtable layout of bad_function_call.
#define _LIBCPP_ABI_BAD_FUNCTION_CALL_GOOD_WHAT_MESSAGE
// Enable optimized version of __do_get_(un)signed which avoids redundant copies.
#define _LIBCPP_ABI_OPTIMIZED_LOCALE_NUM_GET
// Give reverse_iterator<T> one data member of type T, not two.
// Also, in C++17 and later, don't derive iterator types from std::iterator.
#define _LIBCPP_ABI_NO_ITERATOR_BASES
// Use the smallest possible integer type to represent the index of the variant.
// Previously libc++ used "unsigned int" exclusively.
#define _LIBCPP_ABI_VARIANT_INDEX_TYPE_OPTIMIZATION
// Unstable attempt to provide a more optimized std::function
#define _LIBCPP_ABI_OPTIMIZED_FUNCTION
// All the regex constants must be distinct and nonzero.
#define _LIBCPP_ABI_REGEX_CONSTANTS_NONZERO
// Re-worked external template instantiations for std::string with a focus on
// performance and fast-path inlining.
#define _LIBCPP_ABI_STRING_OPTIMIZED_EXTERNAL_INSTANTIATION
// Enable clang::trivial_abi on std::unique_ptr.
#define _LIBCPP_ABI_ENABLE_UNIQUE_PTR_TRIVIAL_ABI
// Enable clang::trivial_abi on std::shared_ptr and std::weak_ptr
#define _LIBCPP_ABI_ENABLE_SHARED_PTR_TRIVIAL_ABI
// std::random_device holds some state when it uses an implementation that gets
// entropy from a file (see _LIBCPP_USING_DEV_RANDOM). When switching from this
// implementation to another one on a platform that has already shipped
// std::random_device, one needs to retain the same object layout to remain ABI
// compatible. This switch removes these workarounds for platforms that don't care
// about ABI compatibility.
#define _LIBCPP_ABI_NO_RANDOM_DEVICE_COMPATIBILITY_LAYOUT
// Don't export the legacy __basic_string_common class and its methods from the built library.
#define _LIBCPP_ABI_DO_NOT_EXPORT_BASIC_STRING_COMMON
// Don't export the legacy __vector_base_common class and its methods from the built library.
#define _LIBCPP_ABI_DO_NOT_EXPORT_VECTOR_BASE_COMMON
// According to the Standard, `bitset::operator[] const` returns bool
#define _LIBCPP_ABI_BITSET_VECTOR_BOOL_CONST_SUBSCRIPT_RETURN_BOOL
// Remove the base 10 implementation of std::to_chars from the dylib.
// The implementation moved to the header, but we still export the symbols from
// the dylib for backwards compatibility.
#define _LIBCPP_ABI_DO_NOT_EXPORT_TO_CHARS_BASE_10
#elif _LIBCPP_ABI_VERSION == 1
#if !(defined(_LIBCPP_OBJECT_FORMAT_COFF) || defined(_LIBCPP_OBJECT_FORMAT_XCOFF))
// Enable compiling copies of now inline methods into the dylib to support
// applications compiled against older libraries. This is unnecessary with
// COFF dllexport semantics, since dllexport forces a non-inline definition
// of inline functions to be emitted anyway. Our own non-inline copy would
// conflict with the dllexport-emitted copy, so we disable it. For XCOFF,
// the linker will take issue with the symbols in the shared object if the
// weak inline methods get visibility (such as from -fvisibility-inlines-hidden),
// so disable it.
#define _LIBCPP_DEPRECATED_ABI_LEGACY_LIBRARY_DEFINITIONS_FOR_INLINE_FUNCTIONS
#endif
// Feature macros for disabling pre ABI v1 features. All of these options
// are deprecated.
#if defined(__FreeBSD__)
#define _LIBCPP_DEPRECATED_ABI_DISABLE_PAIR_TRIVIAL_COPY_CTOR
#endif
#endif
#if defined(_LIBCPP_BUILDING_LIBRARY) || _LIBCPP_ABI_VERSION >= 2
// Enable additional explicit instantiations of iostreams components. This
// reduces the number of weak definitions generated in programs that use
// iostreams by providing a single strong definition in the shared library.
#define _LIBCPP_ABI_ENABLE_ADDITIONAL_IOSTREAM_EXPLICIT_INSTANTIATIONS_1
// Define a key function for `bad_function_call` in the library, to centralize
// its vtable and typeinfo to libc++ rather than having all other libraries
// using that class define their own copies.
#define _LIBCPP_ABI_BAD_FUNCTION_CALL_KEY_FUNCTION
#endif
#define _LIBCPP_TOSTRING2(x) #x
#define _LIBCPP_TOSTRING(x)  _LIBCPP_TOSTRING2(x)
#if __cplusplus < 201103L
#define _LIBCPP_CXX03_LANG
#endif
#ifndef __has_attribute
#define __has_attribute(__x) 0
#endif
#ifndef __has_builtin
#define __has_builtin(__x) 0
#endif
#ifndef __has_extension
#define __has_extension(__x) 0
#endif
#ifndef __has_feature
#define __has_feature(__x) 0
#endif
#ifndef __has_cpp_attribute
#define __has_cpp_attribute(__x) 0
#endif
// '__is_identifier' returns '0' if '__x' is a reserved identifier provided by
// the compiler and '1' otherwise.
#ifndef __is_identifier
#define __is_identifier(__x) 1
#endif
#ifndef __has_declspec_attribute
#define __has_declspec_attribute(__x) 0
#endif
#define __has_keyword(__x) !(__is_identifier(__x))
#ifndef __has_include
#define __has_include(...) 0
#endif
#if !defined(_LIBCPP_COMPILER_CLANG_BASED) && __cplusplus < 201103L
#error "libc++ only supports C++03 with Clang-based compilers. Please enable C++11"
#endif
// FIXME: ABI detection should be done via compiler builtin macros. This
// is just a placeholder until Clang implements such macros. For now assume
// that Windows compilers pretending to be MSVC++ target the Microsoft ABI,
// and allow the user to explicitly specify the ABI to handle cases where this
// heuristic falls short.
#if defined(_LIBCPP_ABI_FORCE_ITANIUM) && defined(_LIBCPP_ABI_FORCE_MICROSOFT)
#error "Only one of _LIBCPP_ABI_FORCE_ITANIUM and _LIBCPP_ABI_FORCE_MICROSOFT can be defined"
#elif defined(_LIBCPP_ABI_FORCE_ITANIUM)
#define _LIBCPP_ABI_ITANIUM
#elif defined(_LIBCPP_ABI_FORCE_MICROSOFT)
#define _LIBCPP_ABI_MICROSOFT
#else
#if defined(_WIN32) && defined(_MSC_VER)
#define _LIBCPP_ABI_MICROSOFT
#else
#define _LIBCPP_ABI_ITANIUM
#endif
#endif
#if defined(_LIBCPP_ABI_MICROSOFT) && !defined(_LIBCPP_NO_VCRUNTIME)
#define _LIBCPP_ABI_VCRUNTIME
#endif
#if __has_feature(experimental_library)
#ifndef _LIBCPP_ENABLE_EXPERIMENTAL
#define _LIBCPP_ENABLE_EXPERIMENTAL
#endif
#endif
// Incomplete features get their own specific disabling flags. This makes it
// easier to grep for target specific flags once the feature is complete.
#if !defined(_LIBCPP_ENABLE_EXPERIMENTAL) && !defined(_LIBCPP_BUILDING_LIBRARY)
#define _LIBCPP_HAS_NO_INCOMPLETE_FORMAT
#endif
// Need to detect which libc we're using if we're on Linux.
#if defined(__linux__)
#include <features.h>
#if defined(__GLIBC_PREREQ)
#define _LIBCPP_GLIBC_PREREQ(a, b) __GLIBC_PREREQ(a, b)
#else
#define _LIBCPP_GLIBC_PREREQ(a, b) 0
#endif  // defined(__GLIBC_PREREQ)
#endif  // defined(__linux__)
#if defined(__MVS__)
#include <features.h>  // for __NATIVE_ASCII_F
#endif
#ifdef __LITTLE_ENDIAN__
#if __LITTLE_ENDIAN__
#define _LIBCPP_LITTLE_ENDIAN
#endif  // __LITTLE_ENDIAN__
#endif  // __LITTLE_ENDIAN__
#ifdef __BIG_ENDIAN__
#if __BIG_ENDIAN__
#define _LIBCPP_BIG_ENDIAN
#endif  // __BIG_ENDIAN__
#endif  // __BIG_ENDIAN__
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define _LIBCPP_LITTLE_ENDIAN
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define _LIBCPP_BIG_ENDIAN
#endif  // __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#endif  // __BYTE_ORDER__
#ifdef __FreeBSD__
#include <osreldate.h>
#include <sys/endian.h>
#if _BYTE_ORDER == _LITTLE_ENDIAN
#define _LIBCPP_LITTLE_ENDIAN
#else  // _BYTE_ORDER == _LITTLE_ENDIAN
#define _LIBCPP_BIG_ENDIAN
#endif  // _BYTE_ORDER == _LITTLE_ENDIAN
#endif  // __FreeBSD__
#if defined(__NetBSD__) || defined(__OpenBSD__)
#include <sys/endian.h>
#if _BYTE_ORDER == _LITTLE_ENDIAN
#define _LIBCPP_LITTLE_ENDIAN
#else  // _BYTE_ORDER == _LITTLE_ENDIAN
#define _LIBCPP_BIG_ENDIAN
#endif  // _BYTE_ORDER == _LITTLE_ENDIAN
#endif  // defined(__NetBSD__) || defined(__OpenBSD__)
#if defined(_WIN32)
#define _LIBCPP_WIN32API
#define _LIBCPP_LITTLE_ENDIAN
#define _LIBCPP_SHORT_WCHAR 1
// Both MinGW and native MSVC provide a "MSVC"-like environment
#define _LIBCPP_MSVCRT_LIKE
// If mingw not explicitly detected, assume using MS C runtime only if
// a MS compatibility version is specified.
#if defined(_MSC_VER) && !defined(__MINGW32__)
#define _LIBCPP_MSVCRT  // Using Microsoft's C Runtime library
#endif
#if (defined(_M_AMD64) || defined(__x86_64__)) || (defined(_M_ARM) || defined(__arm__))
#define _LIBCPP_HAS_BITSCAN64
#endif
#define _LIBCPP_HAS_OPEN_WITH_WCHAR
#endif  // defined(_WIN32)
#ifdef __sun__
#include <sys/isa_defs.h>
#ifdef _LITTLE_ENDIAN
#define _LIBCPP_LITTLE_ENDIAN
#else
#define _LIBCPP_BIG_ENDIAN
#endif
#endif  // __sun__
#if defined(_AIX) && !defined(__64BIT__)
// The size of wchar is 2 byte on 32-bit mode on AIX.
#define _LIBCPP_SHORT_WCHAR 1
#endif
// Libc++ supports various implementations of std::random_device.
//
// _LIBCPP_USING_DEV_RANDOM
//      Read entropy from the given file, by default `/dev/urandom`.
//      If a token is provided, it is assumed to be the path to a file
//      to read entropy from. This is the default behavior if nothing
//      else is specified. This implementation requires storing state
//      inside `std::random_device`.
//
// _LIBCPP_USING_ARC4_RANDOM
//      Use arc4random(). This allows obtaining random data even when
//      using sandboxing mechanisms. On some platforms like Apple, this
//      is the recommended source of entropy for user-space programs.
//      When this option is used, the token passed to `std::random_device`'s
//      constructor *must* be "/dev/urandom" -- anything else is an error.
//
// _LIBCPP_USING_GETENTROPY
//      Use getentropy().
//      When this option is used, the token passed to `std::random_device`'s
//      constructor *must* be "/dev/urandom" -- anything else is an error.
//
// _LIBCPP_USING_FUCHSIA_CPRNG
//      Use Fuchsia's zx_cprng_draw() system call, which is specified to
//      deliver high-quality entropy and cannot fail.
//      When this option is used, the token passed to `std::random_device`'s
//      constructor *must* be "/dev/urandom" -- anything else is an error.
//
// _LIBCPP_USING_NACL_RANDOM
//      NaCl's sandbox (which PNaCl also runs in) doesn't allow filesystem access,
//      including accesses to the special files under `/dev`. This implementation
//      uses the NaCL syscall `nacl_secure_random_init()` to get entropy.
//      When this option is used, the token passed to `std::random_device`'s
//      constructor *must* be "/dev/urandom" -- anything else is an error.
//
// _LIBCPP_USING_WIN32_RANDOM
//      Use rand_s(), for use on Windows.
//      When this option is used, the token passed to `std::random_device`'s
//      constructor *must* be "/dev/urandom" -- anything else is an error.
#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||   \
    defined(__DragonFly__) || defined(__sun__)
#define _LIBCPP_USING_ARC4_RANDOM
#elif defined(__wasi__) || defined(__EMSCRIPTEN__)
#define _LIBCPP_USING_GETENTROPY
#elif defined(__Fuchsia__)
#define _LIBCPP_USING_FUCHSIA_CPRNG
#elif defined(__native_client__)
#define _LIBCPP_USING_NACL_RANDOM
#elif defined(_LIBCPP_WIN32API)
#define _LIBCPP_USING_WIN32_RANDOM
#else
#define _LIBCPP_USING_DEV_RANDOM
#endif
#if !defined(_LIBCPP_LITTLE_ENDIAN) && !defined(_LIBCPP_BIG_ENDIAN)
#include <endian.h>
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define _LIBCPP_LITTLE_ENDIAN
#elif __BYTE_ORDER == __BIG_ENDIAN
#define _LIBCPP_BIG_ENDIAN
#else  // __BYTE_ORDER == __BIG_ENDIAN
#error unable to determine endian
#endif
#endif  // !defined(_LIBCPP_LITTLE_ENDIAN) && !defined(_LIBCPP_BIG_ENDIAN)
#if __has_attribute(__no_sanitize__) && !defined(_LIBCPP_COMPILER_GCC)
#define _LIBCPP_NO_CFI __attribute__((__no_sanitize__("cfi")))
#else
#define _LIBCPP_NO_CFI
#endif
#ifndef _LIBCPP_CXX03_LANG
#define _LIBCPP_ALIGNOF(_Tp) alignof(_Tp)
#define _ALIGNAS_TYPE(x)     alignas(x)
#define _ALIGNAS(x)          alignas(x)
#define _LIBCPP_NORETURN     [[noreturn]]
#define _NOEXCEPT            noexcept
#define _NOEXCEPT_(x)        noexcept(x)
#define _LIBCPP_CONSTEXPR    constexpr
#else
#define _LIBCPP_ALIGNOF(_Tp) _Alignof(_Tp)
#define _ALIGNAS_TYPE(x)     __attribute__((__aligned__(_LIBCPP_ALIGNOF(x))))
#define _ALIGNAS(x)          __attribute__((__aligned__(x)))
#define _LIBCPP_NORETURN     __attribute__((__noreturn__))
#define _LIBCPP_HAS_NO_NOEXCEPT
#define nullptr __nullptr
#define _NOEXCEPT throw()
#define _NOEXCEPT_(x)
#define static_assert(...) _Static_assert(__VA_ARGS__)
#define decltype(...) __decltype(__VA_ARGS__)
#define _LIBCPP_CONSTEXPR
                        typedef __char16_t char16_t;
typedef __char32_t char32_t;
#endif
#if !defined(__cpp_exceptions) || __cpp_exceptions < 199711L
#define _LIBCPP_NO_EXCEPTIONS
#endif
#define _LIBCPP_PREFERRED_ALIGNOF(_Tp) __alignof(_Tp)
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
#if defined(__APPLE__) && !defined(__i386__) && !defined(__x86_64__) &&                            \
    (!defined(__arm__) || __ARM_ARCH_7K__ >= 2)
#define _LIBCPP_ABI_ALTERNATE_STRING_LAYOUT
#endif
// Objective-C++ features (opt-in)
#if __has_feature(objc_arc)
#define _LIBCPP_HAS_OBJC_ARC
#endif
#if __has_feature(objc_arc_weak)
#define _LIBCPP_HAS_OBJC_ARC_WEAK
#endif
#if __has_extension(blocks)
#define _LIBCPP_HAS_EXTENSION_BLOCKS
#endif
#if defined(_LIBCPP_HAS_EXTENSION_BLOCKS) && defined(__APPLE__)
#define _LIBCPP_HAS_BLOCKS_RUNTIME
#endif
#if !__has_feature(address_sanitizer)
#define _LIBCPP_HAS_NO_ASAN
#endif
// Allow for build-time disabling of unsigned integer sanitization
#if __has_attribute(no_sanitize)
#define _LIBCPP_DISABLE_UBSAN_UNSIGNED_INTEGER_CHECK                                               \
    __attribute__((__no_sanitize__("unsigned-integer-overflow")))
#endif
#define _LIBCPP_ALWAYS_INLINE             __attribute__((__always_inline__))
#define _LIBCPP_DISABLE_EXTENSION_WARNING __extension__
#elif defined(_LIBCPP_COMPILER_GCC)
#if !defined(__SANITIZE_ADDRESS__)
#define _LIBCPP_HAS_NO_ASAN
#endif
#define _LIBCPP_ALWAYS_INLINE             __attribute__((__always_inline__))
#define _LIBCPP_DISABLE_EXTENSION_WARNING __extension__
#endif  // _LIBCPP_COMPILER_[CLANG|GCC]
#if defined(_LIBCPP_OBJECT_FORMAT_COFF)
#ifdef _DLL
#define _LIBCPP_CRT_FUNC __declspec(dllimport)
#else
#define _LIBCPP_CRT_FUNC
#endif
#if defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS) ||                                             \
    (defined(__MINGW32__) && !defined(_LIBCPP_BUILDING_LIBRARY))
#define _LIBCPP_DLL_VIS
#define _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS
#define _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS
#define _LIBCPP_OVERRIDABLE_FUNC_VIS
#define _LIBCPP_EXPORTED_FROM_ABI
#elif defined(_LIBCPP_BUILDING_LIBRARY)
#define _LIBCPP_DLL_VIS __declspec(dllexport)
#if defined(__MINGW32__)
#define _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS _LIBCPP_DLL_VIS
#define _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS
#else
#define _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS
#define _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS _LIBCPP_DLL_VIS
#endif
#define _LIBCPP_OVERRIDABLE_FUNC_VIS _LIBCPP_DLL_VIS
#define _LIBCPP_EXPORTED_FROM_ABI    __declspec(dllexport)
#else
#define _LIBCPP_DLL_VIS                  __declspec(dllimport)
#define _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS _LIBCPP_DLL_VIS
#define _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS
#define _LIBCPP_OVERRIDABLE_FUNC_VIS
#define _LIBCPP_EXPORTED_FROM_ABI __declspec(dllimport)
#endif
#define _LIBCPP_TYPE_VIS      _LIBCPP_DLL_VIS
#define _LIBCPP_FUNC_VIS      _LIBCPP_DLL_VIS
#define _LIBCPP_EXCEPTION_ABI _LIBCPP_DLL_VIS
#define _LIBCPP_HIDDEN
#define _LIBCPP_METHOD_TEMPLATE_IMPLICIT_INSTANTIATION_VIS
#define _LIBCPP_TEMPLATE_VIS
#define _LIBCPP_TEMPLATE_DATA_VIS
#define _LIBCPP_ENUM_VIS
#else
#if !defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS)
#define _LIBCPP_VISIBILITY(vis) __attribute__((__visibility__(vis)))
#else
#define _LIBCPP_VISIBILITY(vis)
#endif
#define _LIBCPP_HIDDEN                   _LIBCPP_VISIBILITY("hidden")
#define _LIBCPP_FUNC_VIS                 _LIBCPP_VISIBILITY("default")
#define _LIBCPP_TYPE_VIS                 _LIBCPP_VISIBILITY("default")
#define _LIBCPP_TEMPLATE_DATA_VIS        _LIBCPP_VISIBILITY("default")
#define _LIBCPP_EXPORTED_FROM_ABI        _LIBCPP_VISIBILITY("default")
#define _LIBCPP_EXCEPTION_ABI            _LIBCPP_VISIBILITY("default")
#define _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS _LIBCPP_VISIBILITY("default")
#define _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS
// TODO: Make this a proper customization point or remove the option to override it.
#ifndef _LIBCPP_OVERRIDABLE_FUNC_VIS
#define _LIBCPP_OVERRIDABLE_FUNC_VIS _LIBCPP_VISIBILITY("default")
#endif
#if !defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS)
// The inline should be removed once PR32114 is resolved
#define _LIBCPP_METHOD_TEMPLATE_IMPLICIT_INSTANTIATION_VIS inline _LIBCPP_HIDDEN
#else
#define _LIBCPP_METHOD_TEMPLATE_IMPLICIT_INSTANTIATION_VIS
#endif
#if !defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS)
#if __has_attribute(__type_visibility__)
#define _LIBCPP_TEMPLATE_VIS __attribute__((__type_visibility__("default")))
#else
#define _LIBCPP_TEMPLATE_VIS __attribute__((__visibility__("default")))
#endif
#else
#define _LIBCPP_TEMPLATE_VIS
#endif
#if !defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS) && __has_attribute(__type_visibility__)
#define _LIBCPP_ENUM_VIS __attribute__((__type_visibility__("default")))
#else
#define _LIBCPP_ENUM_VIS
#endif
#endif  // defined(_LIBCPP_OBJECT_FORMAT_COFF)
#if __has_attribute(exclude_from_explicit_instantiation)
#define _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION                                                \
    __attribute__((__exclude_from_explicit_instantiation__))
#else
// Try to approximate the effect of exclude_from_explicit_instantiation
// (which is that entities are not assumed to be provided by explicit
// template instantiations in the dylib) by always inlining those entities.
#define _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION _LIBCPP_ALWAYS_INLINE
#endif
// This macro marks a symbol as being hidden from libc++'s ABI. This is achieved
// on two levels:
// 1. The symbol is given hidden visibility, which ensures that users won't start exporting
//    symbols from their dynamic library by means of using the libc++ headers. This ensures
//    that those symbols stay private to the dynamic library in which it is defined.
//
// 2. The symbol is given an ABI tag that changes with each version of libc++. This ensures
//    that no ODR violation can arise from mixing two TUs compiled with different versions
//    of libc++ where we would have changed the definition of a symbol. If the symbols shared
//    the same name, the ODR would require that their definitions be token-by-token equivalent,
//    which basically prevents us from being able to make any change to any function in our
//    headers. Using this ABI tag ensures that the symbol name is "bumped" artificially at
//    each release, which lets us change the definition of these symbols at our leisure.
//    Note that historically, this has been achieved in various ways, including force-inlining
//    all functions or giving internal linkage to all functions. Both these (previous) solutions
//    suffer from drawbacks that lead notably to code bloat.
//
// Note that we use _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION to ensure that we don't depend
// on _LIBCPP_HIDE_FROM_ABI methods of classes explicitly instantiated in the dynamic library.
//
// TODO: We provide a escape hatch with _LIBCPP_NO_ABI_TAG for folks who want to avoid increasing
//       the length of symbols with an ABI tag. In practice, we should remove the escape hatch and
//       use compression mangling instead, see https://github.com/itanium-cxx-abi/cxx-abi/issues/70.
#ifndef _LIBCPP_NO_ABI_TAG
#define _LIBCPP_HIDE_FROM_ABI                                                                      \
    _LIBCPP_HIDDEN _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION                                     \
        __attribute__((__abi_tag__(_LIBCPP_TOSTRING(_LIBCPP_VERSIONED_IDENTIFIER))))
#else
#define _LIBCPP_HIDE_FROM_ABI _LIBCPP_HIDDEN _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION
#endif
#ifdef _LIBCPP_BUILDING_LIBRARY
#if _LIBCPP_ABI_VERSION > 1
#define _LIBCPP_HIDE_FROM_ABI_AFTER_V1 _LIBCPP_HIDE_FROM_ABI
#else
#define _LIBCPP_HIDE_FROM_ABI_AFTER_V1
#endif
#else
#define _LIBCPP_HIDE_FROM_ABI_AFTER_V1 _LIBCPP_HIDE_FROM_ABI
#endif
// Just so we can migrate to the new macros gradually.
#define _LIBCPP_INLINE_VISIBILITY _LIBCPP_HIDE_FROM_ABI
// Inline namespaces are available in Clang/GCC/MSVC regardless of C++ dialect.
// clang-format off
#  define _LIBCPP_BEGIN_NAMESPACE_STD namespace std { inline namespace _LIBCPP_ABI_NAMESPACE {
#  define _LIBCPP_END_NAMESPACE_STD }}
#  define _VSTD std
_LIBCPP_BEGIN_NAMESPACE_STD _LIBCPP_END_NAMESPACE_STD
#  if _LIBCPP_STD_VER > 14
#    define _LIBCPP_BEGIN_NAMESPACE_FILESYSTEM                                                                         \
       _LIBCPP_BEGIN_NAMESPACE_STD inline namespace __fs { namespace filesystem {
#  else
#    define _LIBCPP_BEGIN_NAMESPACE_FILESYSTEM                                                                         \
      _LIBCPP_BEGIN_NAMESPACE_STD namespace __fs { namespace filesystem {
#  endif
#  define _LIBCPP_END_NAMESPACE_FILESYSTEM _LIBCPP_END_NAMESPACE_STD }}
// clang-format on
#define _VSTD_FS std::__fs::filesystem
#if __has_attribute(__enable_if__)
#define _LIBCPP_PREFERRED_OVERLOAD __attribute__((__enable_if__(true, "")))
#endif
#ifndef __SIZEOF_INT128__
#define _LIBCPP_HAS_NO_INT128
#endif
#ifndef __cpp_consteval
#define _LIBCPP_CONSTEVAL _LIBCPP_CONSTEXPR
#else
#define _LIBCPP_CONSTEVAL consteval
#endif
#if __has_attribute(__malloc__)
#define _LIBCPP_NOALIAS __attribute__((__malloc__))
#else
#define _LIBCPP_NOALIAS
#endif
#if __has_attribute(__using_if_exists__)
#define _LIBCPP_USING_IF_EXISTS __attribute__((__using_if_exists__))
#else
#define _LIBCPP_USING_IF_EXISTS
#endif
#ifdef _LIBCPP_CXX03_LANG
#define _LIBCPP_DECLARE_STRONG_ENUM(x)                                                             \
    struct _LIBCPP_TYPE_VIS x {                                                                    \
        enum __lx
// clang-format off
#    define _LIBCPP_DECLARE_STRONG_ENUM_EPILOG(x)                                                                      \
      __lx __v_;                                                                                                       \
      _LIBCPP_INLINE_VISIBILITY x(__lx __v) : __v_(__v) {}                                                             \
      _LIBCPP_INLINE_VISIBILITY explicit x(int __v) : __v_(static_cast<__lx>(__v)) {}                                  \
      _LIBCPP_INLINE_VISIBILITY operator int() const { return __v_; }                                                  \
      };
// clang-format on
#else  // _LIBCPP_CXX03_LANG
#define _LIBCPP_DECLARE_STRONG_ENUM(x) enum class _LIBCPP_ENUM_VIS x
#define _LIBCPP_DECLARE_STRONG_ENUM_EPILOG(x)
#endif  // _LIBCPP_CXX03_LANG
#if defined(__APPLE__) || defined(__FreeBSD__) || defined(_LIBCPP_MSVCRT_LIKE) ||                  \
    defined(__sun__) || defined(__NetBSD__)
#define _LIBCPP_LOCALE__L_EXTENSIONS 1
#endif
#ifdef __FreeBSD__
#define _DECLARE_C99_LDBL_MATH 1
#endif
// If we are getting operator new from the MSVC CRT, then allocation overloads
// for align_val_t were added in 19.12, aka VS 2017 version 15.3.
#if defined(_LIBCPP_MSVCRT) && defined(_MSC_VER) && _MSC_VER < 1912
#define _LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION
#elif defined(_LIBCPP_ABI_VCRUNTIME) && !defined(__cpp_aligned_new)
// We're deferring to Microsoft's STL to provide aligned new et al. We don't
// have it unless the language feature test macro is defined.
#define _LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION
#elif defined(__MVS__)
#define _LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION
#endif
#if defined(_LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION) ||                                          \
    (!defined(__cpp_aligned_new) || __cpp_aligned_new < 201606)
#define _LIBCPP_HAS_NO_ALIGNED_ALLOCATION
#endif
#if defined(__APPLE__) || defined(__FreeBSD__)
#define _LIBCPP_HAS_DEFAULTRUNELOCALE
#endif
#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun__)
#define _LIBCPP_WCTYPE_IS_MASK
#endif
#if _LIBCPP_STD_VER <= 17 || !defined(__cpp_char8_t)
#define _LIBCPP_HAS_NO_CHAR8_T
#endif
// Deprecation macros.
//
// Deprecations warnings are always enabled, except when users explicitly opt-out
// by defining _LIBCPP_DISABLE_DEPRECATION_WARNINGS.
#if !defined(_LIBCPP_DISABLE_DEPRECATION_WARNINGS)
#if __has_attribute(deprecated)
#define _LIBCPP_DEPRECATED     __attribute__((deprecated))
#define _LIBCPP_DEPRECATED_(m) __attribute__((deprecated(m)))
#elif _LIBCPP_STD_VER > 11
#define _LIBCPP_DEPRECATED     [[deprecated]]
#define _LIBCPP_DEPRECATED_(m) [[deprecated(m)]]
#else
#define _LIBCPP_DEPRECATED
#define _LIBCPP_DEPRECATED_(m)
#endif
#else
#define _LIBCPP_DEPRECATED
#define _LIBCPP_DEPRECATED_(m)
#endif
#if !defined(_LIBCPP_CXX03_LANG)
#define _LIBCPP_DEPRECATED_IN_CXX11 _LIBCPP_DEPRECATED
#else
#define _LIBCPP_DEPRECATED_IN_CXX11
#endif
#if _LIBCPP_STD_VER > 11
#define _LIBCPP_DEPRECATED_IN_CXX14 _LIBCPP_DEPRECATED
#else
#define _LIBCPP_DEPRECATED_IN_CXX14
#endif
#if _LIBCPP_STD_VER > 14
#define _LIBCPP_DEPRECATED_IN_CXX17 _LIBCPP_DEPRECATED
#else
#define _LIBCPP_DEPRECATED_IN_CXX17
#endif
#if _LIBCPP_STD_VER > 17
#define _LIBCPP_DEPRECATED_IN_CXX20 _LIBCPP_DEPRECATED
#else
#define _LIBCPP_DEPRECATED_IN_CXX20
#endif
#if !defined(_LIBCPP_HAS_NO_CHAR8_T)
#define _LIBCPP_DEPRECATED_WITH_CHAR8_T _LIBCPP_DEPRECATED
#else
#define _LIBCPP_DEPRECATED_WITH_CHAR8_T
#endif
// Macros to enter and leave a state where deprecation warnings are suppressed.
#if defined(_LIBCPP_COMPILER_CLANG_BASED) || defined(_LIBCPP_COMPILER_GCC)
#define _LIBCPP_SUPPRESS_DEPRECATED_PUSH                                                           \
    _Pragma("GCC diagnostic push") _Pragma("GCC diagnostic ignored \"-Wdeprecated\"")              \
        _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#define _LIBCPP_SUPPRESS_DEPRECATED_POP _Pragma("GCC diagnostic pop")
#else
#define _LIBCPP_SUPPRESS_DEPRECATED_PUSH
#define _LIBCPP_SUPPRESS_DEPRECATED_POP
#endif
#if _LIBCPP_STD_VER <= 11
#define _LIBCPP_EXPLICIT_AFTER_CXX11
#else
#define _LIBCPP_EXPLICIT_AFTER_CXX11 explicit
#endif
#if _LIBCPP_STD_VER > 11
#define _LIBCPP_CONSTEXPR_SINCE_CXX14 constexpr
#else
#define _LIBCPP_CONSTEXPR_SINCE_CXX14
#endif
#if _LIBCPP_STD_VER > 14
#define _LIBCPP_CONSTEXPR_SINCE_CXX17 constexpr
#else
#define _LIBCPP_CONSTEXPR_SINCE_CXX17
#endif
#if _LIBCPP_STD_VER > 17
#define _LIBCPP_CONSTEXPR_SINCE_CXX20 constexpr
#else
#define _LIBCPP_CONSTEXPR_SINCE_CXX20
#endif
#if _LIBCPP_STD_VER > 20
#define _LIBCPP_CONSTEXPR_SINCE_CXX23 constexpr
#else
#define _LIBCPP_CONSTEXPR_SINCE_CXX23
#endif
#if __has_cpp_attribute(nodiscard)
#define _LIBCPP_NODISCARD [[nodiscard]]
#else
// We can't use GCC's [[gnu::warn_unused_result]] and
// __attribute__((warn_unused_result)), because GCC does not silence them via
// (void) cast.
#define _LIBCPP_NODISCARD
#endif
// _LIBCPP_NODISCARD_EXT may be used to apply [[nodiscard]] to entities not
// specified as such as an extension.
#if !defined(_LIBCPP_DISABLE_NODISCARD_EXT)
#define _LIBCPP_NODISCARD_EXT _LIBCPP_NODISCARD
#else
#define _LIBCPP_NODISCARD_EXT
#endif
#if _LIBCPP_STD_VER > 17 || !defined(_LIBCPP_DISABLE_NODISCARD_EXT)
#define _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_NODISCARD
#else
#define _LIBCPP_NODISCARD_AFTER_CXX17
#endif
#if __has_attribute(__no_destroy__)
#define _LIBCPP_NO_DESTROY __attribute__((__no_destroy__))
#else
#define _LIBCPP_NO_DESTROY
#endif
#ifndef _LIBCPP_HAS_NO_ASAN
                        extern "C" _LIBCPP_FUNC_VIS void
                        __sanitizer_annotate_contiguous_container(const void *, const void *,
                                                                  const void *, const void *);
#endif
// Try to find out if RTTI is disabled.
#if !defined(__cpp_rtti) || __cpp_rtti < 199711L
#define _LIBCPP_NO_RTTI
#endif
#ifndef _LIBCPP_WEAK
#define _LIBCPP_WEAK __attribute__((__weak__))
#endif
// Thread API
// clang-format off
#  if !defined(_LIBCPP_HAS_NO_THREADS) &&                                                                              \
      !defined(_LIBCPP_HAS_THREAD_API_PTHREAD) &&                                                                      \
      !defined(_LIBCPP_HAS_THREAD_API_WIN32) &&                                                                        \
      !defined(_LIBCPP_HAS_THREAD_API_EXTERNAL)
#    if defined(__FreeBSD__) ||                                                                                        \
        defined(__wasi__) ||                                                                                           \
        defined(__NetBSD__) ||                                                                                         \
        defined(__OpenBSD__) ||                                                                                        \
        defined(__NuttX__) ||                                                                                          \
        defined(__linux__) ||                                                                                          \
        defined(__GNU__) ||                                                                                            \
        defined(__APPLE__) ||                                                                                          \
        defined(__sun__) ||                                                                                            \
        defined(__MVS__) ||                                                                                            \
        defined(_AIX) ||                                                                                               \
        defined(__EMSCRIPTEN__)
// clang-format on
#define _LIBCPP_HAS_THREAD_API_PTHREAD
#elif defined(__Fuchsia__)
// TODO(44575): Switch to C11 thread API when possible.
#define _LIBCPP_HAS_THREAD_API_PTHREAD
#elif defined(_LIBCPP_WIN32API)
#define _LIBCPP_HAS_THREAD_API_WIN32
#else
#error "No thread API"
#endif  // _LIBCPP_HAS_THREAD_API
#endif  // _LIBCPP_HAS_NO_THREADS
#if defined(_LIBCPP_HAS_THREAD_API_PTHREAD)
#if defined(__ANDROID__) && __ANDROID_API__ >= 30
#define _LIBCPP_HAS_COND_CLOCKWAIT
#elif defined(_LIBCPP_GLIBC_PREREQ)
#if _LIBCPP_GLIBC_PREREQ(2, 30)
#define _LIBCPP_HAS_COND_CLOCKWAIT
#endif
#endif
#endif
#if defined(_LIBCPP_HAS_NO_THREADS) && defined(_LIBCPP_HAS_THREAD_API_PTHREAD)
#error _LIBCPP_HAS_THREAD_API_PTHREAD may only be defined when \
       _LIBCPP_HAS_NO_THREADS is not defined.
#endif
#if defined(_LIBCPP_HAS_NO_THREADS) && defined(_LIBCPP_HAS_THREAD_API_EXTERNAL)
#error _LIBCPP_HAS_THREAD_API_EXTERNAL may not be defined when \
       _LIBCPP_HAS_NO_THREADS is defined.
#endif
#if defined(_LIBCPP_HAS_NO_MONOTONIC_CLOCK) && !defined(_LIBCPP_HAS_NO_THREADS)
#error _LIBCPP_HAS_NO_MONOTONIC_CLOCK may only be defined when \
       _LIBCPP_HAS_NO_THREADS is defined.
#endif
#if !defined(_LIBCPP_HAS_NO_THREADS) && !defined(__STDCPP_THREADS__)
#define __STDCPP_THREADS__ 1
#endif
// The glibc and Bionic implementation of pthreads implements
// pthread_mutex_destroy as nop for regular mutexes. Additionally, Win32
// mutexes have no destroy mechanism.
//
// This optimization can't be performed on Apple platforms, where
// pthread_mutex_destroy can allow the kernel to release resources.
// See https://llvm.org/D64298 for details.
//
// TODO(EricWF): Enable this optimization on Bionic after speaking to their
//               respective stakeholders.
// clang-format off
#  if (defined(_LIBCPP_HAS_THREAD_API_PTHREAD) && defined(__GLIBC__)) ||                                               \
      (defined(_LIBCPP_HAS_THREAD_API_C11) && defined(__Fuchsia__)) ||                                                 \
       defined(_LIBCPP_HAS_THREAD_API_WIN32)
// clang-format on
#define _LIBCPP_HAS_TRIVIAL_MUTEX_DESTRUCTION
#endif
// Destroying a condvar is a nop on Windows.
//
// This optimization can't be performed on Apple platforms, where
// pthread_cond_destroy can allow the kernel to release resources.
// See https://llvm.org/D64298 for details.
//
// TODO(EricWF): This is potentially true for some pthread implementations
// as well.
#if (defined(_LIBCPP_HAS_THREAD_API_C11) && defined(__Fuchsia__)) ||                               \
    defined(_LIBCPP_HAS_THREAD_API_WIN32)
#define _LIBCPP_HAS_TRIVIAL_CONDVAR_DESTRUCTION
#endif
// Some systems do not provide gets() in their C library, for security reasons.
#if defined(_LIBCPP_MSVCRT) || (defined(__FreeBSD_version) && __FreeBSD_version >= 1300043) ||     \
    defined(__OpenBSD__)
#define _LIBCPP_C_HAS_NO_GETS
#endif
#if defined(__BIONIC__) || defined(__NuttX__) || defined(__Fuchsia__) || defined(__wasi__) ||      \
    defined(_LIBCPP_HAS_MUSL_LIBC) || defined(__OpenBSD__)
#define _LIBCPP_PROVIDES_DEFAULT_RUNE_TABLE
#endif
#if __has_feature(cxx_atomic) || __has_extension(c_atomic) || __has_keyword(_Atomic)
#define _LIBCPP_HAS_C_ATOMIC_IMP
#elif defined(_LIBCPP_COMPILER_GCC)
#define _LIBCPP_HAS_GCC_ATOMIC_IMP
#endif
#if !defined(_LIBCPP_HAS_C_ATOMIC_IMP) && !defined(_LIBCPP_HAS_GCC_ATOMIC_IMP) &&                  \
    !defined(_LIBCPP_HAS_EXTERNAL_ATOMIC_IMP)
#define _LIBCPP_HAS_NO_ATOMIC_HEADER
#else
#ifndef _LIBCPP_ATOMIC_FLAG_TYPE
#define _LIBCPP_ATOMIC_FLAG_TYPE bool
#endif
#ifdef _LIBCPP_FREESTANDING
#define _LIBCPP_ATOMIC_ONLY_USE_BUILTINS
#endif
#endif
#ifndef _LIBCPP_DISABLE_UBSAN_UNSIGNED_INTEGER_CHECK
#define _LIBCPP_DISABLE_UBSAN_UNSIGNED_INTEGER_CHECK
#endif
#if defined(_LIBCPP_ENABLE_THREAD_SAFETY_ANNOTATIONS)
#if defined(__clang__) && __has_attribute(acquire_capability)
// Work around the attribute handling in clang.  When both __declspec and
// __attribute__ are present, the processing goes awry preventing the definition
// of the types. In MinGW mode, __declspec evaluates to __attribute__, and thus
// combining the two does work.
#if !defined(_MSC_VER)
#define _LIBCPP_HAS_THREAD_SAFETY_ANNOTATIONS
#endif
#endif
#endif
#ifdef _LIBCPP_HAS_THREAD_SAFETY_ANNOTATIONS
#define _LIBCPP_THREAD_SAFETY_ANNOTATION(x) __attribute__((x))
#else
#define _LIBCPP_THREAD_SAFETY_ANNOTATION(x)
#endif
#if _LIBCPP_STD_VER > 17
#define _LIBCPP_CONSTINIT constinit
#elif __has_attribute(__require_constant_initialization__)
#define _LIBCPP_CONSTINIT __attribute__((__require_constant_initialization__))
#else
#define _LIBCPP_CONSTINIT
#endif
#if __has_attribute(__diagnose_if__) && !defined(_LIBCPP_DISABLE_ADDITIONAL_DIAGNOSTICS)
#define _LIBCPP_DIAGNOSE_WARNING(...) __attribute__((__diagnose_if__(__VA_ARGS__, "warning")))
#else
#define _LIBCPP_DIAGNOSE_WARNING(...)
#endif
// Use a function like macro to imply that it must be followed by a semicolon
#if __has_cpp_attribute(fallthrough)
#define _LIBCPP_FALLTHROUGH() [[fallthrough]]
#elif __has_attribute(__fallthrough__)
#define _LIBCPP_FALLTHROUGH() __attribute__((__fallthrough__))
#else
#define _LIBCPP_FALLTHROUGH() ((void)0)
#endif
#if __has_attribute(__nodebug__)
#define _LIBCPP_NODEBUG __attribute__((__nodebug__))
#else
#define _LIBCPP_NODEBUG
#endif
#if __has_attribute(__standalone_debug__)
#define _LIBCPP_STANDALONE_DEBUG __attribute__((__standalone_debug__))
#else
#define _LIBCPP_STANDALONE_DEBUG
#endif
#if __has_attribute(__preferred_name__)
#define _LIBCPP_PREFERRED_NAME(x) __attribute__((__preferred_name__(x)))
#else
#define _LIBCPP_PREFERRED_NAME(x)
#endif
// We often repeat things just for handling wide characters in the library.
// When wide characters are disabled, it can be useful to have a quick way of
// disabling it without having to resort to #if-#endif, which has a larger
// impact on readability.
#if defined(_LIBCPP_HAS_NO_WIDE_CHARACTERS)
#define _LIBCPP_IF_WIDE_CHARACTERS(...)
#else
#define _LIBCPP_IF_WIDE_CHARACTERS(...) __VA_ARGS__
#endif
#if defined(_LIBCPP_ABI_MICROSOFT) && __has_declspec_attribute(empty_bases)
#define _LIBCPP_DECLSPEC_EMPTY_BASES __declspec(empty_bases)
#else
#define _LIBCPP_DECLSPEC_EMPTY_BASES
#endif
#if defined(_LIBCPP_ENABLE_CXX17_REMOVED_FEATURES)
#define _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR
#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS
#define _LIBCPP_ENABLE_CXX17_REMOVED_RANDOM_SHUFFLE
#define _LIBCPP_ENABLE_CXX17_REMOVED_UNEXPECTED_FUNCTIONS
#define _LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
#endif  // _LIBCPP_ENABLE_CXX17_REMOVED_FEATURES
#if defined(_LIBCPP_ENABLE_CXX20_REMOVED_FEATURES)
#define _LIBCPP_ENABLE_CXX20_REMOVED_ALLOCATOR_MEMBERS
#define _LIBCPP_ENABLE_CXX20_REMOVED_ALLOCATOR_VOID_SPECIALIZATION
#define _LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS
#define _LIBCPP_ENABLE_CXX20_REMOVED_NEGATORS
#define _LIBCPP_ENABLE_CXX20_REMOVED_RAW_STORAGE_ITERATOR
#define _LIBCPP_ENABLE_CXX20_REMOVED_TYPE_TRAITS
#endif  // _LIBCPP_ENABLE_CXX20_REMOVED_FEATURES
#define _LIBCPP_PUSH_MACROS _Pragma("push_macro(\"min\")") _Pragma("push_macro(\"max\")")
#define _LIBCPP_POP_MACROS  _Pragma("pop_macro(\"min\")") _Pragma("pop_macro(\"max\")")
#ifndef _LIBCPP_NO_AUTO_LINK
#if defined(_LIBCPP_ABI_MICROSOFT) && !defined(_LIBCPP_BUILDING_LIBRARY)
#if !defined(_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS)
#pragma comment(lib, "c++.lib")
#else
#pragma comment(lib, "libc++.lib")
#endif
#endif  // defined(_LIBCPP_ABI_MICROSOFT) && !defined(_LIBCPP_BUILDING_LIBRARY)
#endif  // _LIBCPP_NO_AUTO_LINK
// Configures the fopen close-on-exec mode character, if any. This string will
// be appended to any mode string used by fstream for fopen/fdopen.
//
// Not all platforms support this, but it helps avoid fd-leaks on platforms that
// do.
#if defined(__BIONIC__)
#define _LIBCPP_FOPEN_CLOEXEC_MODE "e"
#else
#define _LIBCPP_FOPEN_CLOEXEC_MODE
#endif
// Support for _FILE_OFFSET_BITS=64 landed gradually in Android, so the full set
// of functions used in cstdio may not be available for low API levels when
// using 64-bit file offsets on LP32.
#if defined(__BIONIC__) && defined(__USE_FILE_OFFSET64) && __ANDROID_API__ < 24
#define _LIBCPP_HAS_NO_FGETPOS_FSETPOS
#endif
#if __has_attribute(__init_priority__)
#define _LIBCPP_INIT_PRIORITY_MAX __attribute__((__init_priority__(100)))
#else
#define _LIBCPP_INIT_PRIORITY_MAX
#endif
#if __has_attribute(__format__)
// The attribute uses 1-based indices for ordinary and static member functions.
// The attribute uses 2-based indices for non-static member functions.
#define _LIBCPP_ATTRIBUTE_FORMAT(archetype, format_string_index, first_format_arg_index)           \
    __attribute__((__format__(archetype, format_string_index, first_format_arg_index)))
#else
#define _LIBCPP_ATTRIBUTE_FORMAT(archetype, format_string_index,                                   \
                                 first_format_arg_index) /* nothing */
#endif
#if __has_cpp_attribute(msvc::no_unique_address)
// MSVC implements [[no_unique_address]] as a silent no-op currently.
// (If/when MSVC breaks its C++ ABI, it will be changed to work as intended.)
// However, MSVC implements [[msvc::no_unique_address]] which does what
// [[no_unique_address]] is supposed to do, in general.
// Clang-cl does not yet (14.0) implement either [[no_unique_address]] or
// [[msvc::no_unique_address]] though. If/when it does implement
// [[msvc::no_unique_address]], this should be preferred though.
#define _LIBCPP_NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#elif __has_cpp_attribute(no_unique_address)
#define _LIBCPP_NO_UNIQUE_ADDRESS [[no_unique_address]]
#else
#define _LIBCPP_NO_UNIQUE_ADDRESS /* nothing */
// Note that this can be replaced by #error as soon as clang-cl
// implements msvc::no_unique_address, since there should be no C++20
// compiler that doesn't support one of the two attributes at that point.
// We generally don't want to use this macro outside of C++20-only code,
// because using it conditionally in one language version only would make
// the ABI inconsistent.
#endif
#ifdef _LIBCPP_COMPILER_CLANG_BASED
#define _LIBCPP_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#define _LIBCPP_DIAGNOSTIC_POP  _Pragma("clang diagnostic pop")
#define _LIBCPP_CLANG_DIAGNOSTIC_IGNORED(str)                                                      \
    _Pragma(_LIBCPP_TOSTRING(clang diagnostic ignored str))
#define _LIBCPP_GCC_DIAGNOSTIC_IGNORED(str)
#elif defined(_LIBCPP_COMPILER_GCC)
#define _LIBCPP_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#define _LIBCPP_DIAGNOSTIC_POP  _Pragma("GCC diagnostic pop")
#define _LIBCPP_CLANG_DIAGNOSTIC_IGNORED(str)
#define _LIBCPP_GCC_DIAGNOSTIC_IGNORED(str) _Pragma(_LIBCPP_TOSTRING(GCC diagnostic ignored str))
#else
#define _LIBCPP_DIAGNOSTIC_PUSH
#define _LIBCPP_DIAGNOSTIC_POP
#define _LIBCPP_CLANG_DIAGNOSTIC_IGNORED(str)
#define _LIBCPP_GCC_DIAGNOSTIC_IGNORED(str)
#endif
#if defined(_AIX) && !defined(_LIBCPP_COMPILER_GCC)
#define _LIBCPP_PACKED_BYTE_FOR_AIX     _Pragma("pack(1)")
#define _LIBCPP_PACKED_BYTE_FOR_AIX_END _Pragma("pack(pop)")
#else
#define _LIBCPP_PACKED_BYTE_FOR_AIX     /* empty */
#define _LIBCPP_PACKED_BYTE_FOR_AIX_END /* empty */
#endif
#if __has_attribute(__packed__)
#define _LIBCPP_PACKED __attribute__((__packed__))
#else
#define _LIBCPP_PACKED
#endif
// c8rtomb() and mbrtoc8() were added in C++20 and C23. Support for these
// functions is gradually being added to existing C libraries. The conditions
// below check for known C library versions and conditions under which these
// functions are declared by the C library.
#define _LIBCPP_HAS_NO_C8RTOMB_MBRTOC8
// GNU libc 2.36 and newer declare c8rtomb() and mbrtoc8() in C++ modes if
// __cpp_char8_t is defined or if C2X extensions are enabled. Unfortunately,
// determining the latter depends on internal GNU libc details. If the
// __cpp_char8_t feature test macro is not defined, then a char8_t typedef
// will be declared as well.
#if defined(_LIBCPP_GLIBC_PREREQ) && defined(__GLIBC_USE)
#if _LIBCPP_GLIBC_PREREQ(2, 36) && (defined(__cpp_char8_t) || __GLIBC_USE(ISOC2X))
#undef _LIBCPP_HAS_NO_C8RTOMB_MBRTOC8
#endif
#endif
// There are a handful of public standard library types that are intended to
// support CTAD but don't need any explicit deduction guides to do so. This
// macro is used to mark them as such, which suppresses the
// '-Wctad-maybe-unsupported' compiler warning when CTAD is used in user code
// with these classes.
#if _LIBCPP_STD_VER >= 17
#define _LIBCPP_CTAD_SUPPORTED_FOR_TYPE(_ClassName)                                                \
    template <class... _Tag> _ClassName(typename _Tag::__allow_ctad...)->_ClassName<_Tag...>
#else
#define _LIBCPP_CTAD_SUPPORTED_FOR_TYPE(_ClassName) static_assert(true, "")
#endif
#endif  // __cplusplus
#endif  // _LIBCPP___CONFIG