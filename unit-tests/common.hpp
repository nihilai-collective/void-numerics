/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/void-numerics
 * unit-tests/common.hpp
 */

#pragma once

#include <void-numerics>
#include <random>
#include <rt-ut>
#include <assert.h>
#include <numeric>

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
