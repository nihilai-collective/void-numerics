// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Nihilai Collective Corp

#include "i_to_str.hpp"
#include "str_to_i.hpp"
#include "llvm_to_chars.hpp"
#include "llvm_roundtrip.hpp"
#include "llvm_integral_pass.hpp"

template<rt_ut::string_literal values> [[maybe_unused]] static constexpr uint64_t value_new{ []() -> uint64_t {
	uint64_t return_value{};
	vn::from_chars(values.data(), values.data() + values.size(), return_value);
	return return_value;
}() };

template<uint64_t value> static constexpr std::array<char, 21> newer_string{ []() -> std::array<char, 21> {
	std::array<char, 21> return_value{};
	vn::to_chars(return_value.data(), return_value.data() + 20, value);
	return return_value;
}() };

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		std::cout << "VALUES: " << newer_string<0ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<100000000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<1000000000000000000ULL>.data() << std::endl;
		std::cout << "VALUES: " << newer_string<10000000000000000000ULL>.data() << std::endl;

		std::cout << "VALUE: " << value_new<"0"> << std::endl;
		std::cout << "VALUE: " << value_new<"10"> << std::endl;
		std::cout << "VALUE: " << value_new<"100"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000"> << std::endl;
		std::cout << "VALUE: " << value_new<"100000"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"100000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"100000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"100000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"100000000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"1000000000000000000"> << std::endl;
		std::cout << "VALUE: " << value_new<"10000000000000000000"> << std::endl;
		integral_pass_llvm_tests::test();
		roundtrip_llvm_tests::test();
		to_chars_llvm_tests::test();
		tests<detail::conversion_classes::i_to_str>::impl();
		tests<detail::conversion_classes::str_to_i>::impl();
	} catch (const rt_ut::rt_ut_exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
