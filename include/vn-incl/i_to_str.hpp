/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * include/vn-incl/i_to_str.hpp
 */

#pragma once

#include <vn-incl/utility.hpp>

namespace vn {

	namespace detail {

		static constexpr const auto* __restrict char_table_1_byte_data	= int_tables<1>::values;
		static constexpr const auto* __restrict char_table_2_digit_data = int_tables<2>::values;
		static constexpr const auto* __restrict char_table_3_digit_data = int_tables<3>::values;
		static constexpr const auto* __restrict char_table_4_digit_data = int_tables<4>::values;

		template<typename v_type, uint64_t digit_length> struct to_chars_internal;

		template<typename v_type> struct to_chars_impl;

		template<uint_types v_type> struct to_chars_internal<v_type, 5ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type a = value * 3518437209ULL >> 45;
				*buf		   = static_cast<char>(a) + static_cast<char>('0');
				pow2_memcpy_wrapper<4ULL>(buf + 1, char_table_4_digit_data + (value - a * 10000));
				return buf + 5;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 6ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type ab = value * 3518437209ULL >> 45;
				pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + ab);
				pow2_memcpy_wrapper<4ULL>(buf + 2, char_table_4_digit_data + (value - (ab * 10000U)));
				return buf + 6;
			}
		};

		template<uint_types v_type> VN_INLINE static constexpr void copy_3_digits(char* __restrict buf, const v_type value) noexcept {
			uint32_t packed;
			pow2_memcpy_wrapper<4ULL>(&packed, &char_table_3_digit_data[value]);
			pow2_memcpy_wrapper<2ULL>(buf, &packed);
			buf[2] = static_cast<char>(packed >> 16);
		}

		template<uint_types v_type> struct to_chars_internal<v_type, 7ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abc = value * 3518437209ULL >> 45;
				copy_3_digits(buf, abc);
				pow2_memcpy_wrapper<4ULL>(buf + 3, char_table_4_digit_data + (value - (abc * 10000U)));
				return buf + 7;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 8ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcd = value * 3518437209ULL >> 45;
				pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + abcd);
				pow2_memcpy_wrapper<4ULL>(buf + 4, char_table_4_digit_data + (value - (abcd * 10000U)));
				return buf + 8;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 9ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type a		  = static_cast<v_type>(multiply_and_shift::impl(value));
				const v_type bcdefghi = value - a * 100000000ULL;
				const v_type bcde	  = bcdefghi * 3518437209ULL >> 45;
				const v_type fghi	  = bcdefghi - (bcde * 10000U);
				*buf				  = static_cast<char>(a) + static_cast<char>('0');
				pow2_memcpy_wrapper<4ULL>(buf + 1, char_table_4_digit_data + bcde);
				pow2_memcpy_wrapper<4ULL>(buf + 5, char_table_4_digit_data + fghi);
				return buf + 9;
			}
		};

		template<uint_types v_type> struct to_chars_internal<v_type, 10ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type ab		  = static_cast<v_type>(multiply_and_shift::impl(value));
				const v_type cdefghij = value - ab * 100000000ULL;
				const v_type cdef	  = cdefghij * 3518437209ULL >> 45;
				const v_type ghij	  = cdefghij - (cdef * 10000U);
				pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + ab);
				pow2_memcpy_wrapper<4ULL>(buf + 2, char_table_4_digit_data + cdef);
				pow2_memcpy_wrapper<4ULL>(buf + 6, char_table_4_digit_data + ghij);
				return buf + 10;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 11ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abc	  = multiply_and_shift::impl(value);
				const v_type defghijk = value - abc * 100000000ULL;
				const v_type defg	  = defghijk * 3518437209U >> 45;
				const v_type hijk	  = defghijk - (defg * 10000U);
				copy_3_digits(buf, abc);
				pow2_memcpy_wrapper<4ULL>(buf + 3, char_table_4_digit_data + defg);
				pow2_memcpy_wrapper<4ULL>(buf + 7, char_table_4_digit_data + hijk);
				return buf + 11;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 12ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcd	  = multiply_and_shift::impl(value);
				const v_type efghijkl = value - abcd * 100000000ULL;
				const v_type efgh	  = efghijkl * 3518437209U >> 45;
				const v_type ijkl	  = efghijkl - (efgh * 10000U);
				pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + abcd);
				pow2_memcpy_wrapper<4ULL>(buf + 4, char_table_4_digit_data + efgh);
				pow2_memcpy_wrapper<4ULL>(buf + 8, char_table_4_digit_data + ijkl);
				return buf + 12;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 13ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcde	  = multiply_and_shift::impl(value);
				const v_type fghijklm = value - abcde * 100000000ULL;
				const v_type a		  = abcde * 3518437209U >> 45;
				const v_type bcde	  = abcde - (a * 10000U);
				const v_type fghi	  = fghijklm * 3518437209U >> 45;
				const v_type jklm	  = fghijklm - (fghi * 10000U);
				*buf				  = static_cast<char>(a) + static_cast<char>('0');
				pow2_memcpy_wrapper<4ULL>(buf + 1, char_table_4_digit_data + bcde);
				pow2_memcpy_wrapper<4ULL>(buf + 5, char_table_4_digit_data + fghi);
				pow2_memcpy_wrapper<4ULL>(buf + 9, char_table_4_digit_data + jklm);
				return buf + 13;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 14ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdef	  = multiply_and_shift::impl(value);
				const v_type ghijklmn = value - abcdef * 100000000ULL;
				const v_type ab		  = abcdef * 3518437209U >> 45;
				const v_type cdef	  = abcdef - (ab * 10000U);
				const v_type ghij	  = ghijklmn * 3518437209U >> 45;
				const v_type klmn	  = ghijklmn - (ghij * 10000U);
				pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + ab);
				pow2_memcpy_wrapper<4ULL>(buf + 2, char_table_4_digit_data + cdef);
				pow2_memcpy_wrapper<4ULL>(buf + 6, char_table_4_digit_data + ghij);
				pow2_memcpy_wrapper<4ULL>(buf + 10, char_table_4_digit_data + klmn);
				return buf + 14;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 15ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefg  = multiply_and_shift::impl(value);
				const v_type hijklmno = value - abcdefg * 100000000ULL;
				const v_type abc	  = abcdefg * 3518437209U >> 45;
				const v_type defg	  = abcdefg - (abc * 10000U);
				const v_type hijk	  = hijklmno * 3518437209U >> 45;
				const v_type lmno	  = hijklmno - (hijk * 10000U);
				copy_3_digits(buf, abc);
				pow2_memcpy_wrapper<4ULL>(buf + 3, char_table_4_digit_data + defg);
				pow2_memcpy_wrapper<4ULL>(buf + 7, char_table_4_digit_data + hijk);
				pow2_memcpy_wrapper<4ULL>(buf + 11, char_table_4_digit_data + lmno);
				return buf + 15;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 16ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefgh = multiply_and_shift::impl(value);
				const v_type ijklmnop = value - abcdefgh * 100000000ULL;
				const v_type abcd	  = abcdefgh * 3518437209U >> 45;
				const v_type efgh	  = abcdefgh - (abcd * 10000U);
				const v_type ijkl	  = ijklmnop * 3518437209U >> 45;
				const v_type mnop	  = ijklmnop - (ijkl * 10000U);
				pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + abcd);
				pow2_memcpy_wrapper<4ULL>(buf + 4, char_table_4_digit_data + efgh);
				pow2_memcpy_wrapper<4ULL>(buf + 8, char_table_4_digit_data + ijkl);
				pow2_memcpy_wrapper<4ULL>(buf + 12, char_table_4_digit_data + mnop);
				return buf + 16;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 17ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefghi = multiply_and_shift::impl(value);
				const v_type jklmnopq  = value - abcdefghi * 100000000ULL;
				const v_type a		   = multiply_and_shift::impl(abcdefghi);
				const v_type bcdefghi  = abcdefghi - a * 100000000ULL;
				const v_type bcde	   = bcdefghi * 3518437209U >> 45;
				const v_type fghi	   = bcdefghi - (bcde * 10000U);
				const v_type jklm	   = jklmnopq * 3518437209U >> 45;
				const v_type nopq	   = jklmnopq - (jklm * 10000U);
				*buf				   = static_cast<char>(a) + static_cast<char>('0');
				pow2_memcpy_wrapper<4ULL>(buf + 1, char_table_4_digit_data + bcde);
				pow2_memcpy_wrapper<4ULL>(buf + 5, char_table_4_digit_data + fghi);
				pow2_memcpy_wrapper<4ULL>(buf + 9, char_table_4_digit_data + jklm);
				pow2_memcpy_wrapper<4ULL>(buf + 13, char_table_4_digit_data + nopq);
				return buf + 17;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 18ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefghij = multiply_and_shift::impl(value);
				const v_type klmnopqr	= value - abcdefghij * 100000000ULL;
				const v_type ab			= multiply_and_shift::impl(abcdefghij);
				const v_type cdefghij	= abcdefghij - ab * 100000000ULL;
				const v_type cdef		= cdefghij * 3518437209U >> 45;
				const v_type ghij		= cdefghij - (cdef * 10000U);
				const v_type klmn		= klmnopqr * 3518437209U >> 45;
				const v_type opqr		= klmnopqr - (klmn * 10000U);
				pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + ab);
				pow2_memcpy_wrapper<4ULL>(buf + 2, char_table_4_digit_data + cdef);
				pow2_memcpy_wrapper<4ULL>(buf + 6, char_table_4_digit_data + ghij);
				pow2_memcpy_wrapper<4ULL>(buf + 10, char_table_4_digit_data + klmn);
				pow2_memcpy_wrapper<4ULL>(buf + 14, char_table_4_digit_data + opqr);
				return buf + 18;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 19ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefghijk = multiply_and_shift::impl(value);
				const v_type lmnopqrs	 = value - abcdefghijk * 100000000ULL;
				const v_type abc		 = multiply_and_shift::impl(abcdefghijk);
				const v_type defghijk	 = abcdefghijk - abc * 100000000ULL;
				const v_type defg		 = defghijk * 3518437209U >> 45;
				const v_type hijk		 = defghijk - (defg * 10000U);
				const v_type lmno		 = lmnopqrs * 3518437209U >> 45;
				const v_type pqrs		 = lmnopqrs - (lmno * 10000U);
				copy_3_digits(buf, abc);
				pow2_memcpy_wrapper<4ULL>(buf + 3, char_table_4_digit_data + defg);
				pow2_memcpy_wrapper<4ULL>(buf + 7, char_table_4_digit_data + hijk);
				pow2_memcpy_wrapper<4ULL>(buf + 11, char_table_4_digit_data + lmno);
				pow2_memcpy_wrapper<4ULL>(buf + 15, char_table_4_digit_data + pqrs);
				return buf + 19;
			}
		};

		template<uint64_types v_type> struct to_chars_internal<v_type, 20ULL> {
			inline static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, const v_type value) noexcept {
				const v_type abcdefghijkl = multiply_and_shift::impl(value);
				const v_type mnopqrst	  = value - abcdefghijkl * 100000000ULL;
				const v_type abcd		  = multiply_and_shift::impl(abcdefghijkl);
				const v_type efghijkl	  = abcdefghijkl - abcd * 100000000ULL;
				const v_type efgh		  = efghijkl * 3518437209U >> 45;
				const v_type ijkl		  = efghijkl - (efgh * 10000U);
				const v_type mnop		  = mnopqrst * 3518437209U >> 45;
				const v_type qrst		  = mnopqrst - (mnop * 10000U);
				pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + abcd);
				pow2_memcpy_wrapper<4ULL>(buf + 4, char_table_4_digit_data + efgh);
				pow2_memcpy_wrapper<4ULL>(buf + 8, char_table_4_digit_data + ijkl);
				pow2_memcpy_wrapper<4ULL>(buf + 12, char_table_4_digit_data + mnop);
				pow2_memcpy_wrapper<4ULL>(buf + 16, char_table_4_digit_data + qrst);
				return buf + 20;
			}
		};

		template<uint64_types auto size, uint_types v_type>
		VN_INLINE static constexpr char* impl_internal(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
			return (static_cast<uint64_t>(end - buf) >= size ? to_chars_internal<v_type, size>::impl(buf, value) : nullptr);
		}

		template<uint64_types v_type> struct to_chars_impl<v_type> {
#if VN_ARCH_X64
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 100U ? value < 10U ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
												  : (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
					: value < 100000000ULL			 ? value < 10000ULL ? value < 1000U
							? (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
							: (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
						: value < 1000000ULL				  ? value < 100000ULL ? impl_internal<5ULL>(buf, end, value) : impl_internal<6ULL>(buf, end, value)
						: value < 10000000ULL				  ? impl_internal<7ULL>(buf, end, value)
															  : impl_internal<8ULL>(buf, end, value)
					: value < 1000000000000ULL		 ? value < 10000000000ULL ? value < 1000000000ULL ? impl_internal<9ULL>(buf, end, value) : impl_internal<10ULL>(buf, end, value)
						: value < 100000000000ULL						? impl_internal<11ULL>(buf, end, value)
																		: impl_internal<12ULL>(buf, end, value)
					: value < 10000000000000000ULL	 ? value < 100000000000000ULL
						? value < 10000000000000ULL ? impl_internal<13ULL>(buf, end, value) : impl_internal<14ULL>(buf, end, value)
						: value < 1000000000000000ULL ? impl_internal<15ULL>(buf, end, value)
													  : impl_internal<16ULL>(buf, end, value)
					: value < 1000000000000000000ULL ? value < 100000000000000000ULL ? impl_internal<17ULL>(buf, end, value) : impl_internal<18ULL>(buf, end, value)
					: value < 10000000000000000000ULL ? impl_internal<19ULL>(buf, end, value)
													  : impl_internal<20ULL>(buf, end, value);
			}
#else
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 100000000ULL			 ? value < 10000ULL ? value < 100ULL ? value < 10U
								? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
								: (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
							: value < 1000U ? (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
											: (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
						: value < 1000000ULL				   ? value < 100000ULL ? impl_internal<5ULL>(buf, end, value) : impl_internal<6ULL>(buf, end, value)
						: value < 10000000ULL				   ? impl_internal<7ULL>(buf, end, value)
															   : impl_internal<8ULL>(buf, end, value)
					: value < 1000000000000ULL		 ? value < 10000000000ULL ? value < 1000000000ULL ? impl_internal<9ULL>(buf, end, value) : impl_internal<10ULL>(buf, end, value)
						: value < 100000000000ULL						? impl_internal<11ULL>(buf, end, value)
																		: impl_internal<12ULL>(buf, end, value)
					: value < 10000000000000000ULL	 ? value < 100000000000000ULL
						? value < 10000000000000ULL ? impl_internal<13ULL>(buf, end, value) : impl_internal<14ULL>(buf, end, value)
						: value < 1000000000000000ULL ? impl_internal<15ULL>(buf, end, value)
													  : impl_internal<16ULL>(buf, end, value)
					: value < 1000000000000000000ULL ? value < 100000000000000000ULL ? impl_internal<17ULL>(buf, end, value) : impl_internal<18ULL>(buf, end, value)
					: value < 10000000000000000000ULL ? impl_internal<19ULL>(buf, end, value)
													  : impl_internal<20ULL>(buf, end, value);
			}
#endif
		};

		template<uint32_types v_type> struct to_chars_impl<v_type> {
#if VN_ARCH_X64
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 100U		  ? value < 10U ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
														: (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
					: value < 1000000U	  ? value < 10000U ? value < 1000U
							? (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
							: (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
						: value < 100000U				? impl_internal<5ULL>(buf, end, value)
														: impl_internal<6ULL>(buf, end, value)
					: value < 100000000U  ? value < 10000000U ? impl_internal<7ULL>(buf, end, value) : impl_internal<8ULL>(buf, end, value)
					: value < 1000000000U ? impl_internal<9ULL>(buf, end, value)
										  : impl_internal<10ULL>(buf, end, value);
			}
#else
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 100000U	  ? value < 1000U ? value < 100U ? value < 10U
								? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
								: (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
																		 : (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
						: value < 10000U			   ? (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
													   : impl_internal<5ULL>(buf, end, value)
					: value < 10000000U	  ? value < 1000000U ? impl_internal<6ULL>(buf, end, value) : impl_internal<7ULL>(buf, end, value)
					: value < 1000000000U ? value < 100000000U ? impl_internal<8ULL>(buf, end, value) : impl_internal<9ULL>(buf, end, value)
										  : impl_internal<10ULL>(buf, end, value);
			}
#endif
		};

		template<uint16_types v_type> struct to_chars_impl<v_type> {
#if VN_ARCH_X64
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 10U	 ? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
					: value < 1000U	 ? value < 100U ? (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
													: (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
					: value < 10000U ? (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
									 : impl_internal<5ULL>(buf, end, value);
			}
#else
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict end, const v_type value) noexcept {
				return value < 1000U ? value < 100U ? value < 10U
							? (end - buf >= 1 ? (static_cast<void>(buf[0] = char(value) + static_cast<char>('0')), buf + 1) : nullptr)
							: (end - buf >= 2 ? (static_cast<void>(pow2_memcpy_wrapper<2ULL>(buf, char_table_2_digit_data + value)), buf + 2) : nullptr)
													: (end - buf >= 3 ? (static_cast<void>(copy_3_digits(buf, value)), buf + 3) : nullptr)
					: value < 10000U ? (end - buf >= 4 ? (static_cast<void>(pow2_memcpy_wrapper<4ULL>(buf, char_table_4_digit_data + value)), buf + 4) : nullptr)
									 : impl_internal<5ULL>(buf, end, value);
			}
#endif
		};

		template<uint8_types v_type> struct to_chars_impl<v_type> {
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* __restrict last, const v_type value) noexcept {
				const uint32_t t = static_cast<uint8_t>(value);
				uint32_t packed;
				pow2_memcpy_wrapper<4ULL>(&packed, &char_table_1_byte_data[t]);
				const uint32_t len{ packed >> 24 };
				if (static_cast<uint64_t>(last - buf) < static_cast<uint64_t>(len)) {
					return nullptr;
				}
				if (len == 3u) {
					pow2_memcpy_wrapper<2ULL>(buf, &packed);
					buf[2] = static_cast<char>(packed >> 16);
				} else if (len == 2u) {
					pow2_memcpy_wrapper<2ULL>(buf, &packed);
				} else {
					buf[0] = static_cast<char>(packed);
				}
				return buf + len;
			}
		};

		template<int_types v_type> struct to_chars_impl<v_type> {
			VN_INLINE static constexpr char* impl(char* __restrict buf VN_LIFETIME_BOUND, char* end, const v_type value) noexcept {
				using unsigned_type	   = std::make_unsigned_t<v_type>;
				unsigned_type uval	   = static_cast<unsigned_type>(value);
				unsigned_type negative = static_cast<unsigned_type>(value < 0);
				*buf				   = '-';
				buf += negative;
				unsigned_type mask = static_cast<unsigned_type>(unsigned_type{ 0 } - negative);
				unsigned_type t	   = static_cast<unsigned_type>((uval ^ mask) + negative);
				return to_chars_impl<unsigned_type>::impl(buf, end, t);
			}
		};
	}

	template<detail::integer_types v_type> VN_INLINE constexpr std::to_chars_result to_chars(char* first, char* last, v_type value, int32_t base = 10) noexcept {
		if (base == 10) {
			char* end = detail::to_chars_impl<v_type>::impl(first, last, value);
			return (end != nullptr) ? std::to_chars_result{ end, std::errc{} } : std::to_chars_result{ last, std::errc::value_too_large };
		} else {
			auto r = std::to_chars(first, last, value, base);
			return { r.ptr, r.ec };
		}
	}

}
