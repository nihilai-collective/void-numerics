/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * include/vn-incl/config.hpp
 */

#pragma once

#include <concepts>
#include <charconv>
#include <cstring>
#include <cstdint>
#include <limits>
#include <array>
#include <bit>

template<typename... arg_types> void vn_fail_memcpy_impl(arg_types&&...) {
	static_assert(sizeof...(arg_types) == 0,
		"Sorry, but un-constrained memcpy is banned in this library! Only use our public-facing include <void-numerics> in your code! Or, if you're inside our own headers, remove "
		"the std library include you just added.");
}

namespace std {

	template<typename... arg_types> void vn_fail_memcpy_impl(arg_types&&... args) {
		::vn_fail_memcpy_impl(args...);
	}

}

namespace vn {

	template<uint64_t n, typename value_type_01, typename value_type_02> VN_INLINE constexpr void pow2_memcpy_wrapper(value_type_01* dst, const value_type_02* src) noexcept {
		constexpr uint64_t src_size = sizeof(value_type_02);
		constexpr uint64_t dst_size = sizeof(value_type_01);
		static_assert(n % dst_size == 0);
		if consteval {
			std::array<unsigned char, n> bytes{};
			for (uint64_t x = 0; x < n; x += src_size) {
				const auto chunk = std::bit_cast<std::array<unsigned char, src_size>>(src[x / src_size]);
				for (uint64_t y = 0; y < src_size && x + y < n; ++y) {
					bytes[x + y] = chunk[y];
				}
			}
			for (uint64_t x = 0; x < n / dst_size; ++x) {
				std::array<unsigned char, dst_size> chunk{};
				for (uint64_t y = 0; y < dst_size; ++y) {
					chunk[y] = bytes[x * dst_size + y];
				}
				dst[x] = std::bit_cast<value_type_01>(chunk);
			}
		} else {
			std::memcpy(dst, src, n);
		}
	}

	template<typename... arg_types> struct banned_reinterpret_cast {
		static_assert(sizeof...(arg_types) == 0,
			"Sorry, but reinterpret_cast is banned in this library! Only use our public-facing include <void-numerics> in your code! Or, if you're inside our own headers, remove "
			"the std library include you just added.");
	};

	template<typename... arg_types> struct banned_const_cast {
		static_assert(sizeof...(arg_types) == 0,
			"Sorry, but const_cast is banned in this library! Only use our public-facing include <void-numerics> in your code! Or, if you're inside our own headers, remove "
			"the std library include you just added.");
	};

	template<typename... arg_types> struct banned_dynamic_cast {
		static_assert(sizeof...(arg_types) == 0,
			"Sorry, but dynamic_cast is banned in this library! Only use our public-facing include <void-numerics> in your code! Or, if you're inside our own headers, remove "
			"the std library include you just added.");
	};

#define reinterpret_cast vn::banned_reinterpret_cast
#define const_cast vn::banned_const_cast
#define dynamic_cast vn::banned_dynamic_cast
#define memcpy(...) vn_fail_memcpy_impl(__VA_ARGS__)

}
