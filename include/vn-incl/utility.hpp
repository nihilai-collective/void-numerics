// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// vn-incl/utility.hpp

#pragma once

#include <vn-incl/concepts.hpp>

namespace vn {

	namespace detail {

		template<vn::detail::integer_types v_type> struct max_digits {
		  private:
			using limits = std::numeric_limits<v_type>;
			using U		 = std::make_unsigned_t<v_type>;

			static consteval uint64_t count_digits(U value_new) {
				uint64_t digits = 0;
				do {
					value_new /= 10;
					++digits;
				} while (value_new != 0);
				return digits;
			}

		  public:
			static constexpr uint64_t value = count_digits(static_cast<U>(limits::max()));
		};

		template<vn::detail::integer_types v_type> static constexpr uint64_t max_digits_v = max_digits<v_type>::value;

		template<uint8_types auto repeat, uint_types v_type> static constexpr uint64_t repeat_bytes_v = static_cast<v_type>(0x0101010101010101ull) * static_cast<v_type>(repeat);

		template<bool negative> static constexpr uint64_t comp_val_addition{ [] {
			if constexpr (negative) {
				return 1ULL;
			} else {
				return 0ULL;
			}
		}() };

		template<integer_types v_type> using next_higher_int_t = decltype([]<integer_types v_type_new> {
			if constexpr (uint8_types<v_type_new>) {
				return uint16_t{};
			} else if constexpr (uint16_types<v_type_new>) {
				return uint32_t{};
			} else if constexpr (uint32_types<v_type_new>) {
				return uint64_t{};
			} else if constexpr (uint64_types<v_type_new>) {
				return uint64_t{};
			} else if constexpr (int8_types<v_type_new>) {
				return int16_t{};
			} else if constexpr (int16_types<v_type_new>) {
				return int32_t{};
			} else if constexpr (int32_types<v_type_new>) {
				return int64_t{};
			} else if constexpr (int64_types<v_type_new>) {
				return int64_t{};
			} 
		}.template operator()<v_type>());

		template<typename v_type, bool negative> static constexpr std::array<std::make_unsigned_t<v_type>, 256> gen_raw_comp_vals() {
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

		template<typename v_type, bool negative> VN_ALIGN(64) static constexpr std::array<std::make_unsigned_t<v_type>, 256> raw_comp_vals{ gen_raw_comp_vals<v_type, negative>() };

		template<typename v_type, bool negative> VN_ALIGN(64) static constexpr const std::make_unsigned_t<v_type>* __restrict comp_vals{ raw_comp_vals<v_type, negative>.data() };

		VN_ALIGN(64) inline constexpr uint8_t zero{ static_cast<uint8_t>('0') };

		template<uint8_types v_type> VN_FORCE_INLINE static constexpr bool is_digit(v_type c) noexcept {
			return c - static_cast<uint8_t>(zero) < 10;
		}

		template<std::endian, uint64_t size = 0> struct int_tables_impl {};

		template<uint64_t size> struct char_array {
			VN_FORCE_INLINE operator const char*() const VN_LIFETIME_BOUND {
				return values;
			}

			VN_FORCE_INLINE constexpr char& operator[](uint64_t index) noexcept VN_LIFETIME_BOUND {
				return values[index];
			}
			char values[size];
		};

		template<std::endian endianness> static constexpr std::array<uint16_t, 100> gen_2() {
			std::array<uint16_t, 100> t{};
			for (uint32_t i = 0; i < 100; ++i) {
				if constexpr (endianness == std::endian::little) {
					t[i] |= static_cast<uint16_t>(zero + (i / 10));
					t[i] |= static_cast<uint16_t>(zero + (i % 10)) << 8;
				} else {
					t[i] |= static_cast<uint16_t>(zero + (i / 10)) << 8;
					t[i] |= static_cast<uint16_t>(zero + (i % 10));
				}
			}
			return t;
		}

		template<std::endian endianness> static constexpr std::array<char_array<3>, 1000> gen_3() {
			std::array<char_array<3>, 1000> t{};
			for (uint32_t i = 0; i < 1000; ++i) {
				if constexpr (endianness == std::endian::little) {
					t[i][0] = static_cast<char>(zero + (i / 100));
					t[i][1] = static_cast<char>(zero + (i / 10 % 10));
					t[i][2] = static_cast<char>(zero + (i % 10));
				} else {
					t[i][2] = static_cast<char>(zero + (i / 100));
					t[i][1] = static_cast<char>(zero + (i / 10 % 10));
					t[i][0] = static_cast<char>(zero + (i % 10));
				}
			}
			return t;
		}

		template<std::endian endianness> static constexpr std::array<uint32_t, 10000> gen_4() {
			std::array<uint32_t, 10000> t{};
			for (uint32_t i = 0; i < 10000; ++i) {
				if constexpr (endianness == std::endian::little) {
					t[i] |= static_cast<uint32_t>(zero + (i / 1000));
					t[i] |= static_cast<uint32_t>(zero + (i / 100 % 10)) << 8;
					t[i] |= static_cast<uint32_t>(zero + (i / 10 % 10)) << 16;
					t[i] |= static_cast<uint32_t>(zero + (i % 10)) << 24;
				} else {
					t[i] |= static_cast<uint32_t>(zero + (i / 1000)) << 24;
					t[i] |= static_cast<uint32_t>(zero + (i / 100 % 10)) << 16;
					t[i] |= static_cast<uint32_t>(zero + (i / 10 % 10)) << 8;
					t[i] |= static_cast<uint32_t>(zero + (i % 10));
				}
			}
			return t;
		}

		template<std::endian endianness> struct int_tables_impl<endianness, 2> {
			VN_ALIGN(64) static constexpr std::array<uint16_t, 100> table{ gen_2<endianness>() };
			VN_ALIGN(64) static constexpr const uint16_t* __restrict values{ table.data() };
		};

		template<std::endian endianness> struct int_tables_impl<endianness, 3> {
			VN_ALIGN(64) static constexpr std::array<char_array<3>, 1000> table{ gen_3<endianness>() };
			VN_ALIGN(64) static constexpr const char_array<3>* __restrict values{ table.data() };
		};

		template<std::endian endianness> struct int_tables_impl<endianness, 4> {
			VN_ALIGN(64) static constexpr std::array<uint32_t, 10000> table{ gen_4<endianness>() };
			VN_ALIGN(64) static constexpr const uint32_t* __restrict values{ table.data() };
		};

		template<uint64_t size> using int_tables = int_tables_impl<std::endian::native, size>;

#if !VN_COMPILER_CLANG && !VN_COMPILER_GCC && !VN_COMPILER_MSVC

		template<uint_types v_type_new> VN_FORCE_INLINE static v_type_new mulhi_portable(v_type_new a, v_type_new b) noexcept {
			using v_type						 = next_higher_int_t<v_type_new>;
			static constexpr uint64_t total_bits = sizeof(v_type_new) * 8;
			static constexpr uint64_t half_bits	 = total_bits / 2;
			static constexpr v_type mask		 = (static_cast<v_type>(1) << half_bits) - 1;
			const v_type a_lo					 = static_cast<v_type>(a) & mask;
			const v_type a_hi					 = static_cast<v_type>(a) >> half_bits;
			const v_type b_lo					 = static_cast<v_type>(b) & mask;
			const v_type b_hi					 = static_cast<v_type>(b) >> half_bits;
			const v_type lo_lo					 = a_lo * b_lo;
			const v_type hi_lo					 = a_hi * b_lo;
			const v_type lo_hi					 = a_lo * b_hi;
			const v_type hi_hi					 = a_hi * b_hi;
			const v_type cross					 = (lo_lo >> half_bits) + (hi_lo & mask) + (lo_hi & mask);
			return static_cast<v_type_new>(hi_hi + (hi_lo >> half_bits) + (lo_hi >> half_bits) + (cross >> half_bits));
		}

#endif

		struct multiply_and_shift {
			VN_FORCE_INLINE static uint64_t impl(uint64_t  value) noexcept {
#if VN_COMPILER_CLANG || VN_COMPILER_GCC
				return static_cast<uint64_t>(static_cast<__uint128_t>(value) * 12379400392853802749ULL >> 90);
#elif VN_COMPILER_MSVC
				uint64_t high_part;
				_umul128(12379400392853802749ULL, value, &high_part);
				return static_cast<uint64_t>(high_part >> (90 - 64ULL));
#else
				return static_cast<uint64_t>(mulhi_portable(value, 12379400392853802749ULL) >> (90 - 64ULL));
#endif
			}
		};

	}

}
