// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// src/benchmarks/i_to_str.hpp

#pragma once

#include "utility.hpp"

namespace i_to_str_tests {

	template<vn::detail::uint_types v_type, uint64_t size> VN_FORCE_INLINE static char* jeaiii_impl_internal(char* buf, char* end, v_type value) noexcept {
		return (static_cast<uint64_t>(end - buf) >= size) ? jeaiii::to_text(buf, value) : end;
	}

	template<vn::detail::uint8_types v_type> VN_FORCE_INLINE char* jeaiii_to_text_checked(char* buf, char* end, v_type value) noexcept {
		return value < 10U ? jeaiii_impl_internal<v_type, 1ULL>(buf, end, value)
			: value < 100U ? jeaiii_impl_internal<v_type, 2ULL>(buf, end, value)
						   : jeaiii_impl_internal<v_type, 3ULL>(buf, end, value);
	}

	template<vn::detail::uint16_types v_type> VN_FORCE_INLINE char* jeaiii_to_text_checked(char* buf, char* end, v_type value) noexcept {
		return value < 100U	 ? value < 10U ? jeaiii_impl_internal<v_type, 1ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 2ULL>(buf, end, value)
			 : value < 10000U ? value < 1000U ? jeaiii_impl_internal<v_type, 3ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 4ULL>(buf, end, value)
							  : jeaiii_impl_internal<v_type, 5ULL>(buf, end, value);
	}

	template<vn::detail::uint32_types v_type> VN_FORCE_INLINE char* jeaiii_to_text_checked(char* buf, char* end, v_type value) noexcept {
		return value < 100000U	  ? value < 1000U ? value < 100U
					   ? value < 10U ? jeaiii_impl_internal<v_type, 1ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 2ULL>(buf, end, value)
					   : jeaiii_impl_internal<v_type, 3ULL>(buf, end, value)
				   : value < 10000U ? jeaiii_impl_internal<v_type, 4ULL>(buf, end, value)
												  : jeaiii_impl_internal<v_type, 5ULL>(buf, end, value)
			   : value < 10000000U ? value < 1000000U ? jeaiii_impl_internal<v_type, 6ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 7ULL>(buf, end, value)
			   : value < 1000000000U ? value < 100000000U ? jeaiii_impl_internal<v_type, 8ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 9ULL>(buf, end, value)
									 : jeaiii_impl_internal<v_type, 10ULL>(buf, end, value);
	}

	template<vn::detail::uint64_types v_type> VN_FORCE_INLINE char* jeaiii_to_text_checked(char* buf, char* end, v_type value) noexcept {
		return value < 100000000ULL		   ? value < 10000ULL ? value < 100ULL
						   ? value < 10ULL ? jeaiii_impl_internal<v_type, 1ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 2ULL>(buf, end, value)
						   : value < 1000ULL ? jeaiii_impl_internal<v_type, 3ULL>(buf, end, value)
											 : jeaiii_impl_internal<v_type, 4ULL>(buf, end, value)
					   : value < 1000000ULL	 ? value < 100000ULL ? jeaiii_impl_internal<v_type, 5ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 6ULL>(buf, end, value)
						: value < 10000000ULL ? jeaiii_impl_internal<v_type, 7ULL>(buf, end, value)
											 : jeaiii_impl_internal<v_type, 8ULL>(buf, end, value)
				   : value < 1000000000000ULL ? value < 10000000000ULL
					   ? value < 1000000000ULL ? jeaiii_impl_internal<v_type, 9ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 10ULL>(buf, end, value)
					   : value < 100000000000ULL ? jeaiii_impl_internal<v_type, 11ULL>(buf, end, value)
												 : jeaiii_impl_internal<v_type, 12ULL>(buf, end, value)
				   : value < 10000000000000000ULL ? value < 100000000000000ULL
					   ? value < 10000000000000ULL ? jeaiii_impl_internal<v_type, 13ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 14ULL>(buf, end, value)
					   : value < 1000000000000000ULL ? jeaiii_impl_internal<v_type, 15ULL>(buf, end, value)
													 : jeaiii_impl_internal<v_type, 16ULL>(buf, end, value)
				   : value < 1000000000000000000ULL
			? value < 100000000000000000ULL ? jeaiii_impl_internal<v_type, 17ULL>(buf, end, value) : jeaiii_impl_internal<v_type, 18ULL>(buf, end, value)
			: value < 10000000000000000000ULL ? jeaiii_impl_internal<v_type, 19ULL>(buf, end, value)
											  : jeaiii_impl_internal<v_type, 20ULL>(buf, end, value);
	}

	template<vn::detail::int_types v_type> VN_FORCE_INLINE char* jeaiii_to_text_checked(char* buf, char* end, v_type value) noexcept {
		using unsigned_type					 = std::make_unsigned_t<v_type>;
		constexpr unsigned_type shift_amount = static_cast<unsigned_type>(sizeof(v_type) * 8ULL - 1ULL);
		const unsigned_type uval = (static_cast<unsigned_type>(value) ^ static_cast<unsigned_type>(value >> shift_amount)) - static_cast<unsigned_type>(value >> shift_amount);
		return (value < 0) ? ((end - buf > 0) ? (*buf = '-', jeaiii_to_text_checked<unsigned_type>(buf + 1, end, uval)) : end)
						   : jeaiii_to_text_checked<unsigned_type>(buf, end, uval);
	}

	template<typename v_type_new> struct integer_entry {
		using v_type = v_type_new;
		char buf[vn::detail::max_digits_v<v_type> + 1]{};
		char* end{ buf + vn::detail::max_digits_v<v_type> + 1 };
	};

	template<uint64_t total_size, typename int_type, bool negative> struct digit_generator {
		using entry_type	   = integer_entry<int_type>;
		using test_data_type   = std::vector<int_type>;
		using output_data_type = std::vector<entry_type>;
		static test_data_type impl() {
			test_data_type data{};
			data.resize(total_size);
			bnch_swt::random_generator<int_type> rg{};
			bnch_swt::random_generator<bool> rg_neg{};
			for (uint64_t x = 0; x < data.size(); ++x) {
				int_type value = rg.impl();
				if constexpr (vn::detail::int_types<int_type>) {
					value *= (negative ? rg_neg.impl() ? -1 : 1 : 1);
				}
				data[x] = value;
			}
			return data;
		}
	};

	struct vn_op {
		template<typename v_type> VN_FORCE_INLINE static char* convert(v_type v, char* buf) noexcept {
			return const_cast<char*>(vn::to_chars(buf, buf + 32, v).ptr);
		}
	};

	struct std_op {
		template<typename v_type> VN_FORCE_INLINE static char* convert(v_type v, char* buf) noexcept {
			return std::to_chars(buf, buf + 32, v).ptr;
		}
	};

	struct fmt_format_to_op {
		template<typename v_type> VN_FORCE_INLINE static char* convert(v_type v, char* buf) noexcept {
			return fmt::format_to(buf, FMT_COMPILE("{}"), v);
		}
	};

	struct jeaiii_op {
		template<typename v_type> VN_FORCE_INLINE static char* convert(v_type v, char* buf) noexcept {
			return jeaiii_to_text_checked(buf, buf + 32, v);
		}
	};

	template<typename Op> struct conversion_benchmark {
		template<typename size_type_01, typename vector_type, typename output_data_type, typename index_type>
		VN_FORCE_INLINE static uint64_t impl(size_type_01 test_size, const vector_type& test_data, output_data_type& output_buffer, index_type& current_index) {
			using out_type		  = typename output_data_type::value_type;
			using input_type	  = typename vector_type::value_type;
			const auto* entries	  = test_data.data() + test_size * current_index;
			out_type* const begin = output_buffer.data() + test_size * current_index;
			out_type* p			  = begin;
			for (uint64_t x = 0; x < test_size; ++x) {
				Op::template convert<input_type>(entries[x], p->buf);
				bnch_swt::do_not_optimize_away(p->buf);
				++p;
			}
			++current_index;
			return static_cast<uint64_t>(p - begin) * sizeof(input_type);
		}
	};

	struct verify_correctness {
		template<typename int_type> static void impl(const std::vector<int_type>& test_data, const char* test_label) {
			uint64_t vn_correct{}, vn_incorrect{};
			uint64_t jeaiii_incorrect{};
			uint64_t fmt_format_to_incorrect{}, total_incorrect{};
			int_type first_bad_value{};
			bool found_bad{ false };
			for (uint64_t x = 0; x < test_data.size(); ++x) {
				auto& v = test_data[x];
				char buf_std[32]{};
				char buf_vn[32]{};
				char buf_jeaiii[32]{};
				char buf_fmt_format_to[32]{};
				char* std_end			= std_op::convert(v, buf_std);
				char* vn_end			= vn_op::convert(v, buf_vn);
				char* jeaiii_end		= jeaiii_op::convert(v, buf_jeaiii);
				char* fmt_format_to_end = fmt_format_to_op::convert(v, buf_fmt_format_to);
				const uint64_t std_len	= static_cast<uint64_t>(std_end - buf_std);
				auto same				= [&](char* end, char* buf) {
					  return static_cast<uint64_t>(end - buf) == std_len && std::memcmp(buf, buf_std, std_len) == 0;
				};
				if (same(vn_end, buf_vn)) {
					++vn_correct;
				} else {
					++vn_incorrect;
					++total_incorrect;
					if (!found_bad) {
						first_bad_value = v;
						found_bad		= true;
					}
				}
				if (!same(jeaiii_end, buf_jeaiii)) {
					++jeaiii_incorrect;
					++total_incorrect;
				} 
				if (!same(fmt_format_to_end, buf_fmt_format_to)) {
					++fmt_format_to_incorrect;
					++total_incorrect;
				} 
			}
			if (total_incorrect > 0) {
				std::cout << "[" << test_label << "] vn correct: " << vn_correct << " | incorrect: " << vn_incorrect << " | jeaiii incorrect: " << jeaiii_incorrect
						  << " | fmt format_to incorrect: " << fmt_format_to_incorrect << std::endl;
			}
			if (vn_incorrect > 0) {
				std::cout << "  FIRST BAD vn VALUE: " << static_cast<int64_t>(first_bad_value) << std::endl;
			}
		}
	};

}