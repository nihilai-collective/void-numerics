// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp
// src/benchmarks/utility.hpp

#pragma once

#include <void-numerics>
#include <bnch_swt/index.hpp>
#include <fmt/format.h>
#include <to_text_from_integer.h>
#include <fmt/compile.h>
#include <charconv>
#include <cstring>
#include <limits>
#include <vector>
#include <memory>
#include <map>
#include <iostream>

namespace benchmarks {

	template<typename v_type> VN_FORCE_INLINE constexpr v_type pow10(uint32_t n) {
		uint64_t r = 1;
		for (uint32_t i = 0; i < n; ++i)
			r *= 10;
		return static_cast<v_type>(r);
	}

	template<bnch_swt::string_literal library_name_new, typename test_type_new> struct test_holder {
		static constexpr bnch_swt::string_literal library_name{ library_name_new };
		using test_type = test_type_new;
	};

	template<typename benchmark_stage_type, bnch_swt::string_literal test_name_new, typename test_type, typename test_data_type, typename output_data_type>
	auto execute_test(uint64_t test_size, test_data_type& test_data, output_data_type& output_buffer, uint64_t& output_buffer_index) {
		static constexpr bnch_swt::string_literal test_name{ test_name_new };
		uint64_t current_index{};
		benchmark_stage_type::template run_benchmark<test_name, test_type::library_name, typename test_type::test_type>(test_size, test_data, output_buffer[output_buffer_index],
			current_index);
		++output_buffer_index;
	}

	template<typename benchmark_stage_type, bnch_swt::string_literal test_name_new, typename test_data_type, typename output_data_type, typename... test_types>
	auto execute_tests(uint64_t test_size, test_data_type& test_data, output_data_type& output_buffer) {
		uint64_t output_buffer_index{};
		(execute_test<benchmark_stage_type, test_name_new, test_types>(test_size, test_data, output_buffer, output_buffer_index), ...);
	}

	template<typename benchmark_stage_type, bnch_swt::string_literal test_name_new, uint64_t test_size, uint64_t total_iters, uint64_t measured_iters,
		vn::detail::integer_types v_type, typename correctness_verifier, template<uint64_t, typename, bool> typename digit_generator_type, bool negative, typename... test_types>
	auto run_one_test() {
		auto test_data		   = digit_generator_type<test_size * total_iters, v_type, negative>::impl();
		using output_data_type = std::vector<typename digit_generator_type<test_size * total_iters, v_type, negative>::output_data_type>;
		output_data_type output_buffer{};
		output_buffer.resize(sizeof...(test_types));
		for (uint64_t x = 0; x < sizeof...(test_types); ++x) {
			output_buffer[x].resize(test_size * total_iters);
		}
		using test_data_type = decltype(test_data);
		static constexpr bnch_swt::string_literal test_name{ test_name_new + "-mixed-lengths" + "-test-size[" + bnch_swt::internal::to_string_literal<test_size>() + "]" };
		std::cout << "Starting benchmark: " << test_name << std::endl;
		execute_tests<benchmark_stage_type, test_name, test_data_type, output_data_type, test_types...>(test_size, test_data, output_buffer);
		correctness_verifier::impl(test_data, test_name.data());
	}

	template<typename benchmark_stage_type, bnch_swt::string_literal test_name, uint64_t total_iters_new, uint64_t measured_iters, vn::detail::integer_types v_type,
		typename correctness_verifier, template<uint64_t, typename, bool> typename digit_generator_type, bool negative, typename... test_types>
	static void mixed_digit_count() {
		run_one_test<benchmark_stage_type, test_name, 100, total_iters_new, measured_iters, v_type, correctness_verifier, digit_generator_type, negative, test_types...>();
		run_one_test<benchmark_stage_type, test_name, 1000, total_iters_new, measured_iters, v_type, correctness_verifier, digit_generator_type, negative, test_types...>();
		run_one_test<benchmark_stage_type, test_name, 10000, total_iters_new, measured_iters, v_type, correctness_verifier, digit_generator_type, negative, test_types...>();
		run_one_test<benchmark_stage_type, test_name, 100000, total_iters_new, measured_iters, v_type, correctness_verifier, digit_generator_type, negative, test_types...>();
	}

	template<typename benchmark_stage_type, bnch_swt::string_literal test_name, uint64_t total_iters, uint64_t measured_iters, vn::detail::integer_types v_type,
		typename correctness_verifier, template<uint64_t, typename, bool> typename digit_generator_type, typename... test_types>
	struct digit_iterator {
		static auto impl() {
			if constexpr (vn::detail::int_types<v_type>) {
				mixed_digit_count<benchmark_stage_type, test_name + "-negative", total_iters, measured_iters, v_type, correctness_verifier, digit_generator_type, true,
					test_types...>();
			}
			mixed_digit_count<benchmark_stage_type, test_name + "-positive", total_iters, measured_iters, v_type, correctness_verifier, digit_generator_type, false,
				test_types...>();
		}
	};

	template<typename benchmark_stage_type, bnch_swt::string_literal stage_name, uint64_t total_iters, uint64_t measured_iters, typename correctness_verifier,
		template<uint64_t, typename, bool> typename digit_generator_type, typename... test_types>
	auto test_function_impl() {
		digit_iterator<benchmark_stage_type, "int8", total_iters, measured_iters, int8_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "uint8", total_iters, measured_iters, uint8_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "int16", total_iters, measured_iters, int16_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "uint16", total_iters, measured_iters, uint16_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "int32", total_iters, measured_iters, int32_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "uint32", total_iters, measured_iters, uint32_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "int64", total_iters, measured_iters, int64_t, correctness_verifier, digit_generator_type, test_types...>::impl();
		digit_iterator<benchmark_stage_type, "uint64", total_iters, measured_iters, uint64_t, correctness_verifier, digit_generator_type, test_types...>::impl();
	}

	template<bnch_swt::string_literal stage_name, vn::detail::conversion_classes conversion_class, uint64_t total_iters, uint64_t measured_iters, typename correctness_verifier,
		template<uint64_t, typename, bool> typename digit_generator_type, typename... test_types>
	struct tests {
		static void impl() {
			static constexpr bnch_swt::stage_config config_data{ .clear_cpu_cache_before_all_executions = true,
				.measured_execution_count																= measured_iters,
				.max_execution_count																	= total_iters };
			using bench_stage_type = bnch_swt::benchmark_stage<stage_name, config_data>;
			test_function_impl<bench_stage_type, stage_name, total_iters, measured_iters, correctness_verifier, digit_generator_type, test_types...>();
			std::cout << bench_stage_type::generate_markdown("void-numerics", "../../../../../Benchmarks") << std::endl;
		}
	};

}
