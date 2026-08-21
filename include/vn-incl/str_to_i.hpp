// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// vn-incl/str_to_i.hpp

#pragma once

#include <vn-incl/utility.hpp>

namespace vn {

	namespace detail {

		template<uint_types v_type> VN_FORCE_INLINE v_type count_zeros(v_type value) noexcept {
			if constexpr (std::endian::native == std::endian::little) {
				return static_cast<v_type>(std::countr_zero(value));
			} else {
				return static_cast<v_type>(std::countl_zero(value));
			}
		}

		enum class parse_status : uint8_t {
			success,
			result_out_of_range,
			invalid_argument,
		};

		static constexpr std::errc parse_status_to_errc[] = {
			std::errc{},
			std::errc::result_out_of_range,
			std::errc::invalid_argument,
			std::errc{},
		};

		static constexpr uint32_t tag_shift	 = 62u;
		static constexpr uintptr_t tag_mask	 = uintptr_t{ 0x3 } << tag_shift;
		static constexpr uintptr_t addr_mask = ~tag_mask;

		static_assert(sizeof(uintptr_t) == 8, "pointer tagging requires 64-bit pointers");

		VN_FORCE_INLINE constexpr const uint8_t* set_tag(const uint8_t* ptr, parse_status status) noexcept {
			const uintptr_t raw = std::bit_cast<uintptr_t>(ptr);
			return std::bit_cast<const uint8_t*>((raw & addr_mask) | (static_cast<uintptr_t>(status) << tag_shift));
		}

		VN_FORCE_INLINE constexpr const char* strip_tag(uintptr_t ptr) noexcept {
			return std::bit_cast<const char*>(ptr & addr_mask);
		}

		VN_FORCE_INLINE constexpr uint64_t get_tag(const uintptr_t ptr) noexcept {
			return (ptr & tag_mask) >> tag_shift;
		}

		template<integer_types v_type> struct parse_chunk_result {
			v_type value;
			uint64_t digits;
		};

		template<uint_types v_type> VN_FORCE_INLINE static v_type load(const uint8_t* __restrict str) noexcept {
			v_type chunk;
			std::memcpy(&chunk, str, sizeof(v_type));
			return chunk;
		}

		template<uint8_types v_type> VN_FORCE_INLINE static v_type load(const uint8_t* __restrict str) noexcept {
			return *str;
		}

		template<uint_types v_type> VN_FORCE_INLINE static v_type mask(v_type raw) noexcept {
			static constexpr v_type high{ repeat_bytes_v<static_cast<uint8_t>(0x80), v_type> };
			static constexpr v_type low{ repeat_bytes_v<static_cast<uint8_t>(0x7F), v_type> };
			static constexpr v_type up{ repeat_bytes_v<static_cast<uint8_t>(0x46), v_type> };
			static constexpr v_type down{ repeat_bytes_v<static_cast<uint8_t>(0x50), v_type> };
			const v_type body{ static_cast<v_type>(raw & low) };
			const v_type above{ static_cast<v_type>((body + up) & high) };
			const v_type at_least{ static_cast<v_type>((body + down) & high) };
			return static_cast<v_type>((raw & high) | above | (~at_least & high));
		}

		VN_FORCE_INLINE static bool incorrect(uint8_t raw) noexcept {
			return static_cast<uint8_t>(raw - static_cast<uint8_t>(0x30)) > 9u;
		}

		template<typename v_type> struct fold;

		template<uint64_types v_type> struct fold<v_type> {
			VN_FORCE_INLINE static uint64_t impl(v_type raw) noexcept {
				const v_type sub{ raw - repeat_bytes_v<static_cast<uint8_t>(0x30), v_type> };
				v_type val = (sub * 10 + (sub >> 8)) & 0x00FF00FF00FF00FFULL;
				val		   = (val * 100 + (val >> 16)) & 0x0000FFFF0000FFFFULL;
				return (val * 10000 + (val >> 32)) & 0x00000000FFFFFFFFULL;
			}
		};

		template<uint32_types v_type> struct fold<v_type> {
			VN_FORCE_INLINE static uint64_t impl(v_type raw) noexcept {
				const v_type sub{ static_cast<v_type>(raw - repeat_bytes_v<static_cast<uint8_t>(0x30), v_type>) };
				v_type val = (sub * 10 + (sub >> 8)) & 0x00FF00FFUL;
				return static_cast<uint64_t>((val * 100 + (val >> 16)) & 0x0000FFFFUL);
			}
		};

		template<uint16_types v_type> struct fold<v_type> {
			VN_FORCE_INLINE static uint64_t impl(v_type raw) noexcept {
				const v_type sub{ static_cast<v_type>(raw - repeat_bytes_v<static_cast<uint8_t>(0x30), v_type>) };
				return static_cast<uint64_t>((sub & 0xFFU) * 10 + (sub >> 8));
			}
		};

		template<uint8_types v_type> struct fold<v_type> {
			VN_FORCE_INLINE static uint64_t impl(v_type raw) noexcept {
				return static_cast<uint64_t>(static_cast<v_type>(raw - static_cast<v_type>(0x30)));
			}
		};

		template<integer_types v_type, uint64_t length> struct parse_fixed;

		template<integer_types v_type> struct parse_fixed<v_type, 1ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint8_t s1 = load<uint8_t>(str);
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 0 };
				}
				return { static_cast<v_type>(fold<uint8_t>::impl(s1)), 1 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 2ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint16_t s2 = load<uint16_t>(str);
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				return { static_cast<v_type>(fold<uint16_t>::impl(s2)), 2 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 3ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint16_t s2 = load<uint16_t>(str);
				const uint8_t s1  = load<uint8_t>(str + 2);
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 2 };
				}
				return { static_cast<v_type>(fold<uint16_t>::impl(s2) * 10ULL + fold<uint8_t>::impl(s1)), 3 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 4ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint32_t s4 = load<uint32_t>(str);
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				return { static_cast<v_type>(fold<uint32_t>::impl(s4)), 4 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 5ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint32_t s4 = load<uint32_t>(str);
				const uint8_t s1  = load<uint8_t>(str + 4);
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 4 };
				}
				return { static_cast<v_type>(fold<uint32_t>::impl(s4) * 10ULL + fold<uint8_t>::impl(s1)), 5 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 6ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint32_t s4 = load<uint32_t>(str);
				const uint16_t s2 = load<uint16_t>(str + 4);
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 4ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				return { static_cast<v_type>(fold<uint32_t>::impl(s4) * 100ULL + fold<uint16_t>::impl(s2)), 6 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 7ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint32_t s4 = load<uint32_t>(str);
				const uint16_t s2 = load<uint16_t>(str + 4);
				const uint8_t s1  = load<uint8_t>(str + 6);
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 4ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 6 };
				}
				return { static_cast<v_type>(fold<uint32_t>::impl(s4) * 1000ULL + fold<uint16_t>::impl(s2) * 10ULL + fold<uint8_t>::impl(s1)), 7 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 8ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8)), 8 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 9ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint8_t s1  = load<uint8_t>(str + 8);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 8 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 10ULL + fold<uint8_t>::impl(s1)), 9 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 10ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint16_t s2 = load<uint16_t>(str + 8);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 100ULL + fold<uint16_t>::impl(s2)), 10 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 11ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint16_t s2 = load<uint16_t>(str + 8);
				const uint8_t s1  = load<uint8_t>(str + 10);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 10 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 1000ULL + fold<uint16_t>::impl(s2) * 10ULL + fold<uint8_t>::impl(s1)), 11 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 12ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint32_t s4 = load<uint32_t>(str + 8);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 10000ULL + fold<uint32_t>::impl(s4)), 12 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 13ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint32_t s4 = load<uint32_t>(str + 8);
				const uint8_t s1  = load<uint8_t>(str + 12);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 12 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 100000ULL + fold<uint32_t>::impl(s4) * 10ULL + fold<uint8_t>::impl(s1)), 13 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 14ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint32_t s4 = load<uint32_t>(str + 8);
				const uint16_t s2 = load<uint16_t>(str + 12);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 12ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 1000000ULL + fold<uint32_t>::impl(s4) * 100ULL + fold<uint16_t>::impl(s2)), 14 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 15ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8 = load<uint64_t>(str);
				const uint32_t s4 = load<uint32_t>(str + 8);
				const uint16_t s2 = load<uint16_t>(str + 12);
				const uint8_t s1  = load<uint8_t>(str + 14);
				const uint64_t m8 = mask(s8);
				if (m8) [[unlikely]] {
					return { 0, count_zeros(m8) >> 3 };
				}
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, 8ULL + static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 12ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 14 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8) * 10000000ULL + fold<uint32_t>::impl(s4) * 1000ULL + fold<uint16_t>::impl(s2) * 10ULL + fold<uint8_t>::impl(s1)), 15 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 16ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8a = load<uint64_t>(str);
				const uint64_t s8b = load<uint64_t>(str + 8);
				const uint64_t m8a = mask(s8a);
				if (m8a) [[unlikely]] {
					return { 0, count_zeros(m8a) >> 3 };
				}
				const uint64_t m8b = mask(s8b);
				if (m8b) [[unlikely]] {
					return { 0, 8ULL + (count_zeros(m8b) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8a) * 100000000ULL + fold<uint64_t>::impl(s8b)), 16 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 17ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8a = load<uint64_t>(str);
				const uint64_t s8b = load<uint64_t>(str + 8);
				const uint8_t s1   = load<uint8_t>(str + 16);
				const uint64_t m8a = mask(s8a);
				if (m8a) [[unlikely]] {
					return { 0, count_zeros(m8a) >> 3 };
				}
				const uint64_t m8b = mask(s8b);
				if (m8b) [[unlikely]] {
					return { 0, 8ULL + (count_zeros(m8b) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 16 };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8a) * 1000000000ULL + fold<uint64_t>::impl(s8b) * 10ULL + fold<uint8_t>::impl(s1)), 17 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 18ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8a = load<uint64_t>(str);
				const uint64_t s8b = load<uint64_t>(str + 8);
				const uint16_t s2  = load<uint16_t>(str + 16);
				const uint64_t m8a = mask(s8a);
				if (m8a) [[unlikely]] {
					return { 0, count_zeros(m8a) >> 3 };
				}
				const uint64_t m8b = mask(s8b);
				if (m8b) [[unlikely]] {
					return { 0, 8ULL + (count_zeros(m8b) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 16ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8a) * 10000000000ULL + fold<uint64_t>::impl(s8b) * 100ULL + fold<uint16_t>::impl(s2)), 18 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 19ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8a = load<uint64_t>(str);
				const uint64_t s8b = load<uint64_t>(str + 8);
				const uint16_t s2  = load<uint16_t>(str + 16);
				const uint8_t s1   = load<uint8_t>(str + 18);
				const uint64_t m8a = mask(s8a);
				if (m8a) [[unlikely]] {
					return { 0, count_zeros(m8a) >> 3 };
				}
				const uint64_t m8b = mask(s8b);
				if (m8b) [[unlikely]] {
					return { 0, 8ULL + (count_zeros(m8b) >> 3) };
				}
				const uint16_t m2 = mask(s2);
				if (m2) [[unlikely]] {
					return { 0, 16ULL + static_cast<uint64_t>(count_zeros(m2) >> 3) };
				}
				if (incorrect(s1)) [[unlikely]] {
					return { 0, 18 };
				}
				return { static_cast<v_type>(
							 fold<uint64_t>::impl(s8a) * 100000000000ULL + fold<uint64_t>::impl(s8b) * 1000ULL + fold<uint16_t>::impl(s2) * 10ULL + fold<uint8_t>::impl(s1)),
					19 };
			}
		};

		template<integer_types v_type> struct parse_fixed<v_type, 20ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str) noexcept {
				const uint64_t s8a = load<uint64_t>(str);
				const uint64_t s8b = load<uint64_t>(str + 8);
				const uint32_t s4  = load<uint32_t>(str + 16);
				const uint64_t m8a = mask(s8a);
				if (m8a) [[unlikely]] {
					return { 0, count_zeros(m8a) >> 3 };
				}
				const uint64_t m8b = mask(s8b);
				if (m8b) [[unlikely]] {
					return { 0, 8ULL + (count_zeros(m8b) >> 3) };
				}
				const uint32_t m4 = mask(s4);
				if (m4) [[unlikely]] {
					return { 0, 16ULL + static_cast<uint64_t>(count_zeros(m4) >> 3) };
				}
				return { static_cast<v_type>(fold<uint64_t>::impl(s8a) * 1000000000000ULL + fold<uint64_t>::impl(s8b) * 10000ULL + fold<uint32_t>::impl(s4)), 20 };
			}
		};

		template<uint64_types auto byte_count> struct first_non_zero_byte;

		template<> struct first_non_zero_byte<1ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				return *str == '0';
			}
		};

		template<> struct first_non_zero_byte<2ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint16_t chunk;
				std::memcpy(&chunk, str, 2);
				uint16_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint16_t>;
				return static_cast<uint64_t>((diff == 0) ? 2 : count_zeros(diff) >> 3);
			}
		};

		template<> struct first_non_zero_byte<3ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint32_t chunk{};
				std::memcpy(&chunk, str, 3);
				uint32_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint32_t>;
				return (diff == 0) ? 3 : count_zeros(diff) >> 3;
			}
		};

		template<> struct first_non_zero_byte<4ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint32_t chunk;
				std::memcpy(&chunk, str, 4);
				uint32_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint32_t>;
				return (diff == 0) ? 4 : count_zeros(diff) >> 3;
			}
		};

		template<> struct first_non_zero_byte<5ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint64_t chunk{};
				std::memcpy(&chunk, str, 5);
				uint64_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint64_t>;
				return (diff == 0) ? 5 : count_zeros(diff) >> 3;
			}
		};

		template<> struct first_non_zero_byte<6ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint64_t chunk{};
				std::memcpy(&chunk, str, 6);
				uint64_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint64_t>;
				return (diff == 0) ? 6 : count_zeros(diff) >> 3;
			}
		};

		template<> struct first_non_zero_byte<7ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint64_t chunk{};
				std::memcpy(&chunk, str, 7);
				uint64_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint64_t>;
				return (diff == 0) ? 7 : count_zeros(diff) >> 3;
			}
		};

		template<> struct first_non_zero_byte<8ULL> {
			VN_FORCE_INLINE static uint64_t impl(const uint8_t* __restrict str) noexcept {
				uint64_t chunk;
				std::memcpy(&chunk, str, 8);
				uint64_t diff = chunk ^ repeat_bytes_v<static_cast<uint8_t>(0x30), uint64_t>;
				return (diff == 0) ? 8 : count_zeros(diff) >> 3;
			}
		};

		template<uint_types v_type> VN_FORCE_INLINE bool vn_is_digit(v_type value) noexcept {
			return ((static_cast<uint8_t>(value - '0')) < 10);
		}

		VN_FORCE_INLINE static const uint8_t* trim_leading_zeros(const uint8_t* __restrict iter VN_LIFETIME_BOUND, const uint8_t* __restrict end) noexcept {
			switch (static_cast<uint64_t>(end - iter)) {
				case 1: {
					return iter + first_non_zero_byte<1ULL>::impl(iter);
				}
				case 2: {
					return iter + first_non_zero_byte<2ULL>::impl(iter);
				}
				case 3: {
					return iter + first_non_zero_byte<3ULL>::impl(iter);
				}
				case 4: {
					return iter + first_non_zero_byte<4ULL>::impl(iter);
				}
				case 5: {
					return iter + first_non_zero_byte<5ULL>::impl(iter);
				}
				case 6: {
					return iter + first_non_zero_byte<6ULL>::impl(iter);
				}
				case 7: {
					return iter + first_non_zero_byte<7ULL>::impl(iter);
				}
				case 8: {
					return iter + first_non_zero_byte<8ULL>::impl(iter);
				}
				default: {
					while (iter + 8 <= end && *iter == '0') {
						iter += first_non_zero_byte<8ULL>::impl(iter);
					}
					while (iter < end && *iter == '0') {
						++iter;
					}
				}
			}
			return iter;
		}

		template<typename v_type> struct from_chars_impl;

		template<bool negative, integer_types v_type, integer_types v_type_local>
		VN_FORCE_INLINE const uint8_t* finish(const uint8_t* it VN_LIFETIME_BOUND, v_type& value_new, v_type_local value) {
			static constexpr v_type_local zero_val{ 0 };
			if constexpr (negative) {
				value_new = static_cast<v_type>(zero_val - value);
			} else {
				value_new = static_cast<v_type>(value);
			}
			return it;
		};

		template<bool negative, typename v_type>
			requires(integral16_types<v_type> || integral8_types<v_type>)
		VN_FORCE_INLINE static const uint8_t* parse_integer(v_type& value_new, const uint8_t* __restrict iter VN_LIFETIME_BOUND, const uint8_t* __restrict end) noexcept {
			using v_type_local = std::make_unsigned_t<v_type>;

			if (iter >= end) [[unlikely]] {
				return set_tag(iter, parse_status::invalid_argument);
			}

			v_type_local value;
			uint8_t c = static_cast<uint8_t>(*iter);

			if (c == '0') {
				iter = trim_leading_zeros(iter, end);
				if (iter < end && vn_is_digit(static_cast<uint8_t>(*iter))) {
					value = static_cast<v_type_local>(*iter - '0');
					++iter;
				} else {
					value_new = 0;
					return iter;
				}
			} else if (vn_is_digit(c)) [[likely]] {
				value = static_cast<v_type_local>(c - '0');
				++iter;
			} else {
				return set_tag(iter, parse_status::invalid_argument);
			}

			if (iter < end && (static_cast<void>(c = static_cast<uint8_t>(*iter)), vn_is_digit(c))) [[likely]] {
				value = static_cast<v_type_local>(value * 10 + (c - '0'));
				++iter;
			} else {
				return finish<negative>(iter, value_new, value);
			}

			if constexpr (sizeof(v_type) > 1) {
				if (iter < end && (static_cast<void>(c = static_cast<uint8_t>(*iter)), vn_is_digit(c))) [[likely]] {
					value = static_cast<v_type_local>(value * 10 + (c - '0'));
					++iter;
				} else {
					return finish<negative>(iter, value_new, value);
				}

				if (iter < end && (static_cast<void>(c = static_cast<uint8_t>(*iter)), vn_is_digit(c))) [[likely]] {
					value = static_cast<v_type_local>(value * 10 + (c - '0'));
					++iter;
				} else {
					return finish<negative>(iter, value_new, value);
				}
			}

			if (iter < end && (static_cast<void>(c = static_cast<uint8_t>(*iter)), vn_is_digit(c))) [[likely]] {
				if (static_cast<uint64_t>(value) > static_cast<uint64_t>(comp_vals<v_type, negative>[c])) [[unlikely]] {
					while (++iter < end && vn_is_digit(static_cast<uint8_t>(*iter))) {
					}
					return set_tag(iter, parse_status::result_out_of_range);
				}
				value = static_cast<v_type_local>(value * 10 + (c - '0'));
				++iter;
			} else {
				return finish<negative>(iter, value_new, value);
			}

			if (iter == end) [[likely]] {
				return finish<negative>(iter, value_new, value);
			} else {
				if (vn_is_digit(static_cast<uint8_t>(*iter))) {
					while (iter < end && vn_is_digit(static_cast<uint8_t>(*iter))) {
						++iter;
					}
					return set_tag(iter, parse_status::result_out_of_range);					
				} else {
					return finish<negative>(iter, value_new, value);
				}
			}
		}

		template<integer_types v_type, uint64_t max_length> struct dispatch_table;

		template<integer_types v_type> struct dispatch_table<v_type, 10ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str, uint64_t length) noexcept {
				switch (length) {
					case 1:
						return parse_fixed<v_type, 1ULL>::impl(str);
					case 2:
						return parse_fixed<v_type, 2ULL>::impl(str);
					case 3:
						return parse_fixed<v_type, 3ULL>::impl(str);
					case 4:
						return parse_fixed<v_type, 4ULL>::impl(str);
					case 5:
						return parse_fixed<v_type, 5ULL>::impl(str);
					case 6:
						return parse_fixed<v_type, 6ULL>::impl(str);
					case 7:
						return parse_fixed<v_type, 7ULL>::impl(str);
					case 8:
						return parse_fixed<v_type, 8ULL>::impl(str);
					case 9:
						return parse_fixed<v_type, 9ULL>::impl(str);
					default:
						return parse_fixed<v_type, 10ULL>::impl(str);
				}
			}
		};

		template<integer_types v_type> struct dispatch_table<v_type, 19ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str, uint64_t length) noexcept {
				switch (length) {
					case 1:
						return parse_fixed<v_type, 1ULL>::impl(str);
					case 2:
						return parse_fixed<v_type, 2ULL>::impl(str);
					case 3:
						return parse_fixed<v_type, 3ULL>::impl(str);
					case 4:
						return parse_fixed<v_type, 4ULL>::impl(str);
					case 5:
						return parse_fixed<v_type, 5ULL>::impl(str);
					case 6:
						return parse_fixed<v_type, 6ULL>::impl(str);
					case 7:
						return parse_fixed<v_type, 7ULL>::impl(str);
					case 8:
						return parse_fixed<v_type, 8ULL>::impl(str);
					case 9:
						return parse_fixed<v_type, 9ULL>::impl(str);
					case 10:
						return parse_fixed<v_type, 10ULL>::impl(str);
					case 11:
						return parse_fixed<v_type, 11ULL>::impl(str);
					case 12:
						return parse_fixed<v_type, 12ULL>::impl(str);
					case 13:
						return parse_fixed<v_type, 13ULL>::impl(str);
					case 14:
						return parse_fixed<v_type, 14ULL>::impl(str);
					case 15:
						return parse_fixed<v_type, 15ULL>::impl(str);
					case 16:
						return parse_fixed<v_type, 16ULL>::impl(str);
					case 17:
						return parse_fixed<v_type, 17ULL>::impl(str);
					case 18:
						return parse_fixed<v_type, 18ULL>::impl(str);
					default:
						return parse_fixed<v_type, 19ULL>::impl(str);
				}
			}
		};

		template<integer_types v_type> struct dispatch_table<v_type, 20ULL> {
			VN_FORCE_INLINE static parse_chunk_result<v_type> impl(const uint8_t* __restrict str, uint64_t length) noexcept {
				switch (length) {
					case 1:
						return parse_fixed<v_type, 1ULL>::impl(str);
					case 2:
						return parse_fixed<v_type, 2ULL>::impl(str);
					case 3:
						return parse_fixed<v_type, 3ULL>::impl(str);
					case 4:
						return parse_fixed<v_type, 4ULL>::impl(str);
					case 5:
						return parse_fixed<v_type, 5ULL>::impl(str);
					case 6:
						return parse_fixed<v_type, 6ULL>::impl(str);
					case 7:
						return parse_fixed<v_type, 7ULL>::impl(str);
					case 8:
						return parse_fixed<v_type, 8ULL>::impl(str);
					case 9:
						return parse_fixed<v_type, 9ULL>::impl(str);
					case 10:
						return parse_fixed<v_type, 10ULL>::impl(str);
					case 11:
						return parse_fixed<v_type, 11ULL>::impl(str);
					case 12:
						return parse_fixed<v_type, 12ULL>::impl(str);
					case 13:
						return parse_fixed<v_type, 13ULL>::impl(str);
					case 14:
						return parse_fixed<v_type, 14ULL>::impl(str);
					case 15:
						return parse_fixed<v_type, 15ULL>::impl(str);
					case 16:
						return parse_fixed<v_type, 16ULL>::impl(str);
					case 17:
						return parse_fixed<v_type, 17ULL>::impl(str);
					case 18:
						return parse_fixed<v_type, 18ULL>::impl(str);
					case 19:
						return parse_fixed<v_type, 19ULL>::impl(str);
					default:
						return parse_fixed<v_type, 20ULL>::impl(str);
				}
			}
		};

		template<bool negative, integer_types v_type> VN_FORCE_INLINE static bool exceeds_limit(v_type value, uint8_t last) noexcept {
			return static_cast<uint64_t>(value) > static_cast<uint64_t>(comp_vals<v_type, negative>[last]);
		}

		template<typename v_type> struct from_chars_impl;

		template<bool negative, integer_types v_type>
		VN_FORCE_INLINE static const uint8_t* parse_integer(v_type& value_new, const uint8_t* __restrict iter VN_LIFETIME_BOUND, const uint8_t* __restrict end) noexcept {
			using v_type_local = std::make_unsigned_t<v_type>;

			if (iter >= end) [[unlikely]] {
				return set_tag(iter, parse_status::invalid_argument);
			}

			if (!vn_is_digit(*iter)) [[unlikely]] {
				return set_tag(iter, parse_status::invalid_argument);
			}

			if (*iter == static_cast<uint8_t>('0')) {
				iter = trim_leading_zeros(iter, end);
				if (iter >= end || !vn_is_digit(*iter)) {
					value_new = 0;
					return iter;
				}
			}

			const uint64_t avail{ static_cast<uint64_t>(end - iter) };
			const uint64_t length{ (avail < max_digits_v<v_type>) ? avail : max_digits_v<v_type> };

			parse_chunk_result<v_type> res{};

			if (length == max_digits_v<v_type>) {
				res = dispatch_table<v_type, max_digits_v<v_type>>::impl(iter, length - 1);

				if (res.digits == length - 1) {
					const uint8_t last{ *(iter + length - 1) };

					if (!incorrect(last)) {
						if (exceeds_limit<negative, v_type>(res.value, last)) [[unlikely]] {
							const uint8_t* over{ iter + length };
							while (over < end && vn_is_digit(*over)) {
								++over;
							}
							return set_tag(over, parse_status::result_out_of_range);
						}

						res.value =
							static_cast<v_type>(static_cast<v_type_local>(res.value) * static_cast<v_type_local>(10) + static_cast<v_type_local>(last - static_cast<uint8_t>('0')));
						res.digits = length;
					}
				}
			} else {
				res = dispatch_table<v_type, max_digits_v<v_type>>::impl(iter, length);
			}

			if (res.digits == 0) [[unlikely]] {
				return set_tag(iter, parse_status::invalid_argument);
			}

			if (res.digits != length) [[unlikely]] {
				res		  = dispatch_table<v_type, max_digits_v<v_type>>::impl(iter, res.digits);
				value_new = static_cast<v_type>(negative ? static_cast<v_type_local>(0) - static_cast<v_type_local>(res.value) : static_cast<v_type_local>(res.value));
				return iter + res.digits;
			}

			const uint8_t* const tail{ iter + length };

			if (tail < end && vn_is_digit(*tail)) [[unlikely]] {
				const uint8_t* over{ tail };
				while (over < end && vn_is_digit(*over)) {
					++over;
				}
				return set_tag(over, parse_status::result_out_of_range);
			}

			value_new = static_cast<v_type>(negative ? static_cast<v_type_local>(0) - static_cast<v_type_local>(res.value) : static_cast<v_type_local>(res.value));
			return tail;
		}

		template<int_types v_type> struct from_chars_impl<v_type> {
			VN_FORCE_INLINE static const uint8_t* impl(v_type& value, const uint8_t* __restrict iter VN_LIFETIME_BOUND, const uint8_t* __restrict end VN_LIFETIME_BOUND) noexcept {
				if (iter >= end) [[unlikely]] {
					return set_tag(iter, parse_status::invalid_argument);
				}
				if (*iter == static_cast<uint8_t>('-')) {
					if (iter + 1 >= end || !vn_is_digit(*(iter + 1))) [[unlikely]] {
						return set_tag(iter, parse_status::invalid_argument);
					}
					return parse_integer<true>(value, iter + 1, end);
				}
				return parse_integer<false>(value, iter, end);
			}
		};

		template<uint_types v_type> struct from_chars_impl<v_type> {
			VN_FORCE_INLINE static const uint8_t* impl(v_type& value, const uint8_t* __restrict iter VN_LIFETIME_BOUND, const uint8_t* __restrict end VN_LIFETIME_BOUND) noexcept {
				if (iter >= end || *iter == static_cast<uint8_t>('-')) [[unlikely]] {
					return set_tag(iter, parse_status::invalid_argument);
				}
				return parse_integer<false>(value, iter, end);
			}
		};

	}

	template<detail::integer_types v_type>
	VN_FORCE_INLINE std::from_chars_result from_chars(const char* __restrict first, const char* __restrict last, v_type& value, int32_t base = 10) noexcept {
		if (base != 10) [[unlikely]] {
			return std::from_chars(first, last, value, base);
		}
		const uintptr_t raw = std::bit_cast<uintptr_t>(detail::from_chars_impl<v_type>::impl(value, std::bit_cast<const uint8_t*>(first), std::bit_cast<const uint8_t*>(last)));
		return { detail::strip_tag(raw), detail::parse_status_to_errc[detail::get_tag(raw)] };
	}

}
