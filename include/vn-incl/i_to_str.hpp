// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// vn-incl/i_to_str.hpp

#pragma once

#include <vn-incl/utility.hpp>

namespace vn {

	namespace detail {

		static constexpr const auto* __restrict char_table_2_digit_data = int_tables<2>::values;
		static constexpr const auto* __restrict char_table_3_digit_data = int_tables<3>::values;
		static constexpr const auto* __restrict char_table_4_digit_data = int_tables<4>::values;

		template<typename v_type, uint64_t digit_length> struct to_chars_internal;

		template<typename v_type> struct to_chars_impl;

		template<uint_types v_type> struct to_chars_internal<v_type, 5ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type a																 = value * 3518437209ULL >> 45;
				*buf																		 = static_cast<char>(a) + zero;
				std::memcpy(buf + 1, char_table_4_digit_data + value - a * 10000, 4ULL);
				return buf + 5;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 6ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type ab																 = value * 3518437209ULL >> 45;
				std::memcpy(buf, char_table_2_digit_data + ab, 2ULL);
				std::memcpy(buf + 2, char_table_4_digit_data + value - (ab * 10000U), 4ULL);
				return buf + 6;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 7ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abc															 = value * 3518437209ULL >> 45;
				std::memcpy(buf, char_table_3_digit_data + abc, 3ULL);
				std::memcpy(buf + 3, char_table_4_digit_data + value - (abc * 10000U), 4ULL);
				return buf + 7;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 8ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcd															 = value * 3518437209ULL >> 45;
				std::memcpy(buf, char_table_4_digit_data + abcd, 4ULL);
				std::memcpy(buf + 4, char_table_4_digit_data + value - (abcd * 10000U), 4ULL);
				return buf + 8;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 9ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type a																 = static_cast<v_type>(multiply_and_shift::impl(value));
				const v_type bcdefghi														 = value - a * 100000000ULL;
				const v_type bcde															 = bcdefghi * 3518437209ULL >> 45;
				const v_type fghi															 = bcdefghi - (bcde * 10000U);
				*buf																		 = static_cast<char>(a) + zero;
				std::memcpy(buf + 1, char_table_4_digit_data + bcde, 4ULL);
				std::memcpy(buf + 5, char_table_4_digit_data + fghi, 4ULL);
				return buf + 9;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 10ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type ab																 = static_cast<v_type>(multiply_and_shift::impl(value));
				const v_type cdefghij														 = value - ab * 100000000ULL;
				const v_type cdef															 = cdefghij * 3518437209ULL >> 45;
				const v_type ghij															 = cdefghij - (cdef * 10000U);
				std::memcpy(buf, char_table_2_digit_data + ab, 2ULL);
				std::memcpy(buf + 2, char_table_4_digit_data + cdef, 4ULL);
				std::memcpy(buf + 6, char_table_4_digit_data + ghij, 4ULL);
				return buf + 10;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 11ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abc															 = multiply_and_shift::impl(value);
				const v_type defghijk														 = value - abc * 100000000ULL;
				const v_type defg															 = defghijk * 3518437209U >> 45;
				const v_type hijk															 = defghijk - (defg * 10000U);
				std::memcpy(buf, char_table_3_digit_data + abc, 3ULL);
				std::memcpy(buf + 3, char_table_4_digit_data + defg, 4ULL);
				std::memcpy(buf + 7, char_table_4_digit_data + hijk, 4ULL);
				return buf + 11;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 12ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcd															 = multiply_and_shift::impl(value);
				const v_type efghijkl														 = value - abcd * 100000000ULL;
				const v_type efgh															 = efghijkl * 3518437209U >> 45;
				const v_type ijkl															 = efghijkl - (efgh * 10000U);
				std::memcpy(buf, char_table_4_digit_data + abcd, 4ULL);
				std::memcpy(buf + 4, char_table_4_digit_data + efgh, 4ULL);
				std::memcpy(buf + 8, char_table_4_digit_data + ijkl, 4ULL);
				return buf + 12;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 13ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcde															 = multiply_and_shift::impl(value);
				const v_type fghijklm														 = value - abcde * 100000000ULL;
				const v_type a																 = abcde * 3518437209U >> 45;
				const v_type bcde															 = abcde - (a * 10000U);
				const v_type fghi															 = fghijklm * 3518437209U >> 45;
				const v_type jklm															 = fghijklm - (fghi * 10000U);
				*buf																		 = static_cast<char>(a) + zero;
				std::memcpy(buf + 1, char_table_4_digit_data + bcde, 4ULL);
				std::memcpy(buf + 5, char_table_4_digit_data + fghi, 4ULL);
				std::memcpy(buf + 9, char_table_4_digit_data + jklm, 4ULL);
				return buf + 13;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 14ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdef															 = multiply_and_shift::impl(value);
				const v_type ghijklmn														 = value - abcdef * 100000000ULL;
				const v_type ab																 = abcdef * 3518437209U >> 45;
				const v_type cdef															 = abcdef - (ab * 10000U);
				const v_type ghij															 = ghijklmn * 3518437209U >> 45;
				const v_type klmn															 = ghijklmn - (ghij * 10000U);
				std::memcpy(buf, char_table_2_digit_data + ab, 2ULL);
				std::memcpy(buf + 2, char_table_4_digit_data + cdef, 4ULL);
				std::memcpy(buf + 6, char_table_4_digit_data + ghij, 4ULL);
				std::memcpy(buf + 10, char_table_4_digit_data + klmn, 4ULL);
				return buf + 14;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 15ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefg														 = multiply_and_shift::impl(value);
				const v_type hijklmno														 = value - abcdefg * 100000000ULL;
				const v_type abc															 = abcdefg * 3518437209U >> 45;
				const v_type defg															 = abcdefg - (abc * 10000U);
				const v_type hijk															 = hijklmno * 3518437209U >> 45;
				const v_type lmno															 = hijklmno - (hijk * 10000U);
				std::memcpy(buf, char_table_3_digit_data + abc, 3ULL);
				std::memcpy(buf + 3, char_table_4_digit_data + defg, 4ULL);
				std::memcpy(buf + 7, char_table_4_digit_data + hijk, 4ULL);
				std::memcpy(buf + 11, char_table_4_digit_data + lmno, 4ULL);
				return buf + 15;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 16ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefgh														 = multiply_and_shift::impl(value);
				const v_type ijklmnop														 = value - abcdefgh * 100000000ULL;
				const v_type abcd															 = abcdefgh * 3518437209U >> 45;
				const v_type efgh															 = abcdefgh - (abcd * 10000U);
				const v_type ijkl															 = ijklmnop * 3518437209U >> 45;
				const v_type mnop															 = ijklmnop - (ijkl * 10000U);
				std::memcpy(buf, char_table_4_digit_data + abcd, 4ULL);
				std::memcpy(buf + 4, char_table_4_digit_data + efgh, 4ULL);
				std::memcpy(buf + 8, char_table_4_digit_data + ijkl, 4ULL);
				std::memcpy(buf + 12, char_table_4_digit_data + mnop, 4ULL);
				return buf + 16;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 17ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefghi														 = multiply_and_shift::impl(value);
				const v_type jklmnopq														 = value - abcdefghi * 100000000ULL;
				const v_type a																 = multiply_and_shift::impl(abcdefghi);
				const v_type bcdefghi														 = abcdefghi - a * 100000000ULL;
				const v_type bcde															 = bcdefghi * 3518437209U >> 45;
				const v_type fghi															 = bcdefghi - (bcde * 10000U);
				const v_type jklm															 = jklmnopq * 3518437209U >> 45;
				const v_type nopq															 = jklmnopq - (jklm * 10000U);
				*buf																		 = static_cast<char>(a) + zero;
				std::memcpy(buf + 1, char_table_4_digit_data + bcde, 4ULL);
				std::memcpy(buf + 5, char_table_4_digit_data + fghi, 4ULL);
				std::memcpy(buf + 9, char_table_4_digit_data + jklm, 4ULL);
				std::memcpy(buf + 13, char_table_4_digit_data + nopq, 4ULL);
				return buf + 17;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 18ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefghij														 = multiply_and_shift::impl(value);
				const v_type klmnopqr														 = value - abcdefghij * 100000000ULL;
				const v_type ab																 = multiply_and_shift::impl(abcdefghij);
				const v_type cdefghij														 = abcdefghij - ab * 100000000ULL;
				const v_type cdef															 = cdefghij * 3518437209U >> 45;
				const v_type ghij															 = cdefghij - (cdef * 10000U);
				const v_type klmn															 = klmnopqr * 3518437209U >> 45;
				const v_type opqr															 = klmnopqr - (klmn * 10000U);
				std::memcpy(buf, char_table_2_digit_data + ab, 2ULL);
				std::memcpy(buf + 2, char_table_4_digit_data + cdef, 4ULL);
				std::memcpy(buf + 6, char_table_4_digit_data + ghij, 4ULL);
				std::memcpy(buf + 10, char_table_4_digit_data + klmn, 4ULL);
				std::memcpy(buf + 14, char_table_4_digit_data + opqr, 4ULL);
				return buf + 18;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 19ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefghijk													 = multiply_and_shift::impl(value);
				const v_type lmnopqrs														 = value - abcdefghijk * 100000000ULL;
				const v_type abc															 = multiply_and_shift::impl(abcdefghijk);
				const v_type defghijk														 = abcdefghijk - abc * 100000000ULL;
				const v_type defg															 = defghijk * 3518437209U >> 45;
				const v_type hijk															 = defghijk - (defg * 10000U);
				const v_type lmno															 = lmnopqrs * 3518437209U >> 45;
				const v_type pqrs															 = lmnopqrs - (lmno * 10000U);
				std::memcpy(buf, char_table_3_digit_data + abc, 3ULL);
				std::memcpy(buf + 3, char_table_4_digit_data + defg, 4ULL);
				std::memcpy(buf + 7, char_table_4_digit_data + hijk, 4ULL);
				std::memcpy(buf + 11, char_table_4_digit_data + lmno, 4ULL);
				std::memcpy(buf + 15, char_table_4_digit_data + pqrs, 4ULL);
				return buf + 19;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 20ULL> {
			inline static char* impl(char* __restrict buf, const v_type value) noexcept {
				const v_type abcdefghijkl													 = multiply_and_shift::impl(value);
				const v_type mnopqrst														 = value - abcdefghijkl * 100000000ULL;
				const v_type abcd															 = multiply_and_shift::impl(abcdefghijkl);
				const v_type efghijkl														 = abcdefghijkl - abcd * 100000000ULL;
				const v_type efgh															 = efghijkl * 3518437209U >> 45;
				const v_type ijkl															 = efghijkl - (efgh * 10000U);
				const v_type mnop															 = mnopqrst * 3518437209U >> 45;
				const v_type qrst															 = mnopqrst - (mnop * 10000U);
				std::memcpy(buf, char_table_4_digit_data + abcd, 4ULL);
				std::memcpy(buf + 4, char_table_4_digit_data + efgh, 4ULL);
				std::memcpy(buf + 8, char_table_4_digit_data + ijkl, 4ULL);
				std::memcpy(buf + 12, char_table_4_digit_data + mnop, 4ULL);
				std::memcpy(buf + 16, char_table_4_digit_data + qrst, 4ULL);
				return buf + 20;
			}
		};

		template<uint64_types auto size, uint_types v_type> VN_FORCE_INLINE static char* impl_internal(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
			return (static_cast<uint64_t>(end - buf) >= size ? to_chars_internal<v_type, size>::impl(buf, value) : nullptr);
		}

		template<uint64_types v_type> struct to_chars_impl<v_type> {
			VN_FORCE_INLINE static char* impl(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				return value < 100000000ULL			 ? value < 10000ULL ? value < 100ULL ? value < 10U
										 ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + zero), buf + 1) : nullptr)
										 : (end - buf >= 2 ? (static_cast<void>(std::memcpy(buf, char_table_2_digit_data + value, 2ULL)), buf + 2) : nullptr)
									 : value < 1000U ? (end - buf >= 3 ? (static_cast<void>(std::memcpy(buf, char_table_3_digit_data + value, 3ULL)), buf + 3) : nullptr)
													 : (end - buf >= 4 ? (static_cast<void>(std::memcpy(buf, char_table_4_digit_data + value, 4ULL)), buf + 4) : nullptr)
								 : value < 1000000ULL					? value < 100000ULL ? impl_internal<5ULL>(buf, end, value) : impl_internal<6ULL>(buf, end, value)
												   : value < 10000000ULL ? impl_internal<7ULL>(buf, end, value)
																		: impl_internal<8ULL>(buf, end, value)
							 : value < 1000000000000ULL ? value < 10000000000ULL ? value < 1000000000ULL ? impl_internal<9ULL>(buf, end, value) : impl_internal<10ULL>(buf, end, value)
								 : value < 100000000000ULL ? impl_internal<11ULL>(buf, end, value)
																				 : impl_internal<12ULL>(buf, end, value)
							 : value < 10000000000000000ULL ? value < 100000000000000ULL
								 ? value < 10000000000000ULL ? impl_internal<13ULL>(buf, end, value) : impl_internal<14ULL>(buf, end, value)
								 : value < 1000000000000000ULL ? impl_internal<15ULL>(buf, end, value)
															   : impl_internal<16ULL>(buf, end, value)
							 : value < 1000000000000000000ULL ? value < 100000000000000000ULL ? impl_internal<17ULL>(buf, end, value) : impl_internal<18ULL>(buf, end, value)
					: value < 10000000000000000000ULL ? impl_internal<19ULL>(buf, end, value)
													  : impl_internal<20ULL>(buf, end, value);
			}
		};

		template<uint32_types v_type> struct to_chars_impl<v_type> {
			VN_FORCE_INLINE static char* impl(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				return value < 100000U	  ? value < 1000U ? value < 100U
							   ? value < 10U ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + zero), buf + 1) : nullptr)
											 : (end - buf >= 2 ? (static_cast<void>(std::memcpy(buf, char_table_2_digit_data + value, 2ULL)), buf + 2) : nullptr)
							   : (end - buf >= 3 ? (static_cast<void>(std::memcpy(buf, char_table_3_digit_data + value, 3ULL)), buf + 3) : nullptr)
						   : value < 10000U				  ? (end - buf >= 4 ? (static_cast<void>(std::memcpy(buf, char_table_4_digit_data + value, 4ULL)), buf + 4) : nullptr)
														  : impl_internal<5ULL>(buf, end, value)
					   : value < 10000000U ? value < 1000000U ? impl_internal<6ULL>(buf, end, value) : impl_internal<7ULL>(buf, end, value)
					   : value < 1000000000U ? value < 100000000U ? impl_internal<8ULL>(buf, end, value) : impl_internal<9ULL>(buf, end, value)
											 : impl_internal<10ULL>(buf, end, value);
			}
		};

		template<uint16_types v_type> struct to_chars_impl<v_type> {
			VN_FORCE_INLINE static char* impl(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				return value < 1000U ? value < 100U ? value < 10U ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + zero), buf + 1) : nullptr)
																  : (end - buf >= 2 ? (static_cast<void>(std::memcpy(buf, char_table_2_digit_data + value, 2ULL)), buf + 2) : nullptr)
													: (end - buf >= 3 ? (static_cast<void>(std::memcpy(buf, char_table_3_digit_data + value, 3ULL)), buf + 3) : nullptr)
					: value < 10000U ? (end - buf >= 4 ? (static_cast<void>(std::memcpy(buf, char_table_4_digit_data + value, 4ULL)), buf + 4) : nullptr)
									 : impl_internal<5ULL>(buf, end, value);
			}
		};

		template<uint8_types v_type> struct to_chars_impl<v_type> {
			VN_FORCE_INLINE static char* impl(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				return value < 100 ? value < 10 ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + zero), buf + 1) : nullptr)
												: (end - buf >= 2 ? (static_cast<void>(std::memcpy(buf, &char_table_2_digit_data[value], 2)), buf + 2) : nullptr)
								   : (end - buf >= 3 ? (static_cast<void>(std::memcpy(buf, &char_table_3_digit_data[value], 3)), buf + 3) : nullptr);
			}
		};

		template<int_types v_type> struct to_chars_impl<v_type> {

			VN_FORCE_INLINE static char* impl_negative(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				using unsigned_type					 = std::make_unsigned_t<v_type>;
				constexpr unsigned_type shift_amount = static_cast<unsigned_type>(sizeof(v_type) * 8ULL - 1ULL);
				return (end - buf > 0)
					? (*buf = '-',
						  to_chars_impl<unsigned_type>::impl(buf + 1, end,
							  (static_cast<unsigned_type>(value) ^ static_cast<unsigned_type>(value >> shift_amount)) - static_cast<unsigned_type>(value >> shift_amount)))
					: nullptr;
			}

			VN_FORCE_INLINE static char* impl(char* __restrict buf, char* __restrict end, const v_type value) noexcept {
				using unsigned_type					 = std::make_unsigned_t<v_type>;
				constexpr unsigned_type shift_amount = static_cast<unsigned_type>(sizeof(v_type) * 8ULL - 1ULL);
				return (value < 0)
					? impl_negative(buf, end, value)
					: to_chars_impl<unsigned_type>::impl(buf, end,
						  (static_cast<unsigned_type>(value) ^ static_cast<unsigned_type>(value >> shift_amount)) - static_cast<unsigned_type>(value >> shift_amount));
			}
		};
	}

	template<detail::integer_types v_type> VN_FORCE_INLINE std::to_chars_result to_chars(char* first, char* last, v_type value, int32_t base = 10) noexcept {
		if (base == 10) {
			char* end = detail::to_chars_impl<v_type>::impl(first, last, value);
			return (end != nullptr) ? std::to_chars_result{ end, std::errc{} } : std::to_chars_result{ last, std::errc::value_too_large };
		} else {
			auto r = std::to_chars(first, last, value, base);
			return { r.ptr, r.ec };
		}
	}

}
