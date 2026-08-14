// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// vn-incl/config.hpp

#pragma once

#include <concepts>
#include <charconv>
#include <cstring>
#include <cstdint>
#include <limits>
#include <array>
#include <bit>

namespace vn {

	namespace detail {

		using true_type	 = std::integral_constant<bool, true>;
		using false_type = std::integral_constant<bool, false>;

		enum class conversion_classes {
			i_to_str,
			d_to_str,
			str_to_i,
			str_to_d,
		};

	}

}
