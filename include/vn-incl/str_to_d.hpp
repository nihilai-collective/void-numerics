/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * include/vn-incl/str_to_d.hpp
 */

#pragma once

#include <vn-incl/utility.hpp>

namespace vn {

	template<detail::float_types v_type>
	VN_INLINE std::from_chars_result from_chars(const char* first, const char* last, v_type& value, std::chars_format format = std::chars_format::general) noexcept {
		return std::from_chars(first, last, value, format);
	}

}
