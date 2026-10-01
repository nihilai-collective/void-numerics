/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * include/vn-incl/defines.hpp
 */

#pragma once

#ifndef VN_ARCH_X64
	#if defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
		#define VN_ARCH_X64 1
	#else
		#define VN_ARCH_X64 0
	#endif
#endif

#ifndef VN_ARCH_ARM64
	#if defined(__aarch64__) || defined(_M_ARM64)
		#define VN_ARCH_ARM64 1
	#else
		#define VN_ARCH_ARM64 0
	#endif
#endif

#ifndef VN_COMPILER_CLANG
	#if defined(__clang__)
		#define VN_COMPILER_CLANG 1
	#else
		#define VN_COMPILER_CLANG 0
	#endif
#endif

#ifndef VN_COMPILER_MSVC
	#if defined(_MSC_VER) && !defined(__clang__)
		#define VN_COMPILER_MSVC 1
	#else
		#define VN_COMPILER_MSVC 0
	#endif
#endif

#ifndef VN_COMPILER_GCC
	#if defined(__GNUC__) && !defined(__clang__)
		#define VN_COMPILER_GCC 1
	#else
		#define VN_COMPILER_GCC 0
	#endif
#endif

#ifndef VN_INLINE
	#if defined(NDEBUG)
		#if VN_COMPILER_MSVC
			#define VN_INLINE [[msvc::forceinline]] inline
		#else
			#define VN_INLINE inline __attribute__((always_inline))
		#endif
	#else
		#if VN_COMPILER_MSVC
			#define VN_INLINE [[msvc::noinline]]
		#else
			#define VN_INLINE __attribute__((noinline))
		#endif
	#endif
#endif

#ifndef VN_LIFETIME_BOUND
	#if VN_COMPILER_CLANG
		#define VN_LIFETIME_BOUND [[clang::lifetimebound]]
	#elif VN_COMPILER_MSVC
		#define VN_LIFETIME_BOUND [[msvc::lifetimebound]]
	#else
		#define VN_LIFETIME_BOUND
	#endif
#endif
