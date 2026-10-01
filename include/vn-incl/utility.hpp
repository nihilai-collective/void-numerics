/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * include/vn-incl/utility.hpp
 */

#pragma once

#include <vn-incl/concepts.hpp>

namespace vn {

	namespace detail {

		template<integer_types v_type> inline constexpr uint64_t max_digits_v{ []<integer_types v_type_local>() consteval {
			if constexpr (integral8_types<v_type_local>) {
				return 3ULL;
			} else if constexpr (integral16_types<v_type_local>) {
				return 5ULL;
			} else if constexpr (integral32_types<v_type_local>) {
				return 10ULL;
			} else if constexpr (int64_types<v_type_local>) {
				return 19ULL;
			} else if constexpr (uint64_types<v_type_local>) {
				return 20ULL;
			} else {
				static_assert(sizeof(v_type_local) != 0, "Unsupported integer type being passed.");
			}
		}.template operator()<v_type>() };

		template<integer_types v_type> using next_higher_int_t = decltype([]<integer_types v_type_local>() consteval {
			if constexpr (uint8_types<v_type_local>) {
				return uint16_t{};
			} else if constexpr (uint16_types<v_type_local>) {
				return uint32_t{};
			} else if constexpr (uint32_types<v_type_local>) {
				return uint64_t{};
			} else if constexpr (int8_types<v_type_local>) {
				return int16_t{};
			} else if constexpr (int16_types<v_type_local>) {
				return int32_t{};
			} else if constexpr (int32_types<v_type_local>) {
				return int64_t{};
			} else {
				static_assert(sizeof(v_type_local) != 0, "Unsupported integer type being passed.");
			}
		}.template operator()<v_type>());

		template<uint8_types auto repeat, uint_types v_type> inline constexpr uint64_t repeat_bytes_v = static_cast<v_type>(0x0101010101010101ull) * static_cast<v_type>(repeat);

		template<bool negative> inline constexpr uint64_t comp_val_addition{ []() consteval {
			if constexpr (negative) {
				return 1ULL;
			} else {
				return 0ULL;
			}
		}() };

		template<typename v_type, bool negative> consteval std::array<std::make_unsigned_t<v_type>, 256> gen_raw_comp_vals() {
			constexpr auto max_value{ static_cast<std::make_unsigned_t<v_type>>(std::numeric_limits<base_t<v_type>>::max()) + comp_val_addition<negative> };
			std::array<std::make_unsigned_t<v_type>, 256> return_values_interna{};
			return_values_interna['0'] = (max_value - 0) / 10;
			return_values_interna['1'] = (max_value - 1) / 10;
			return_values_interna['2'] = (max_value - 2) / 10;
			return_values_interna['3'] = (max_value - 3) / 10;
			return_values_interna['4'] = (max_value - 4) / 10;
			return_values_interna['5'] = (max_value - 5) / 10;
			return_values_interna['6'] = (max_value - 6) / 10;
			return_values_interna['7'] = (max_value - 7) / 10;
			return_values_interna['8'] = (max_value - 8) / 10;
			return_values_interna['9'] = (max_value - 9) / 10;
			return return_values_interna;
		};

		template<typename v_type, bool negative> alignas(64) inline constexpr std::array<std::make_unsigned_t<v_type>, 256> raw_comp_vals{ gen_raw_comp_vals<v_type, negative>() };

		template<typename v_type, bool negative> alignas(64) inline constexpr const std::make_unsigned_t<v_type>* __restrict comp_vals{ raw_comp_vals<v_type, negative>.data() };

		template<uint8_types v_type> VN_INLINE constexpr bool is_digit(v_type c) noexcept {
			return c - static_cast<uint8_t>('0') < 10;
		}

		template<uint64_t count> consteval uint64_t gen_table_size() {
			uint64_t result = 1;
			for (uint64_t j = 0; j < count; ++j) {
				result *= 10;
			}
			return result;
		}

		template<uint64_t count> using gen_table_value_t = std::conditional_t<(count <= 2ULL), uint16_t, uint32_t>;

		template<uint64_t count> consteval std::array<gen_table_value_t<count>, gen_table_size<count>()> gen_table() {
			using value_type		= gen_table_value_t<count>;
			constexpr uint64_t size = gen_table_size<count>();
			std::array<value_type, size> t{};
			for (uint64_t i = 0; i < size; ++i) {
				uint64_t divisor = size / 10;
				for (uint64_t j = 0; j < count; ++j) {
					const auto digit	 = static_cast<value_type>(static_cast<uint8_t>('0') + (i / divisor % 10));
					const uint64_t shift = (std::endian::native == std::endian::little ? j : sizeof(value_type) - 1 - j) * 8;
					t[i] |= static_cast<value_type>(digit << shift);
					divisor /= 10;
				}
			}
			return t;
		}

		alignas(64) inline constexpr auto table_02{ gen_table<2ULL>() };
		alignas(64) inline constexpr const auto* __restrict char_table_2_digit_data = table_02.data();
		alignas(64) inline constexpr auto table_03{ gen_table<3ULL>() };
		alignas(64) inline constexpr const auto* __restrict char_table_3_digit_data = table_03.data();
		alignas(64) inline constexpr auto table_04{ gen_table<4ULL>() };
		alignas(64) inline constexpr const auto* __restrict char_table_4_digit_data = table_04.data();

		template<uint_types v_type> VN_INLINE constexpr v_type mulhi_portable(v_type a, v_type b) noexcept {
			static constexpr uint64_t half_bits = sizeof(v_type) * 4;
			static constexpr v_type mask		= (static_cast<v_type>(1) << half_bits) - 1;
			const v_type a_lo					= a & mask;
			const v_type a_hi					= a >> half_bits;
			const v_type b_lo					= b & mask;
			const v_type b_hi					= b >> half_bits;
			const v_type lo_lo					= a_lo * b_lo;
			const v_type hi_lo					= a_hi * b_lo;
			const v_type lo_hi					= a_lo * b_hi;
			const v_type hi_hi					= a_hi * b_hi;
			const v_type cross					= (lo_lo >> half_bits) + (hi_lo & mask) + (lo_hi & mask);
			return static_cast<v_type>(hi_hi + (hi_lo >> half_bits) + (lo_hi >> half_bits) + (cross >> half_bits));
		}

		struct multiply_and_shift {
			VN_INLINE static constexpr uint64_t impl(uint64_t value) noexcept {
				if consteval {
					return static_cast<uint64_t>(mulhi_portable<uint64_t>(value, 12379400392853802749ULL) >> (90 - 64ULL));
				} else {
#if VN_COMPILER_CLANG || VN_COMPILER_GCC
					return static_cast<uint64_t>(static_cast<__uint128_t>(value) * 12379400392853802749ULL >> 90);
#elif VN_COMPILER_MSVC
					uint64_t high_part;
					_umul128(12379400392853802749ULL, value, &high_part);
					return static_cast<uint64_t>(high_part >> (90 - 64ULL));
#else
					return static_cast<uint64_t>(mulhi_portable<uint64_t>(value, 12379400392853802749ULL) >> (90 - 64ULL));
#endif
				}
			}
		};

		template<uint_types v_type> VN_INLINE v_type min(v_type val_01, v_type val_02) noexcept {
			return val_01 < val_02 ? val_01 : val_02;
		}

	}

}
