# Contributing to void-numerics

Thanks for your interest in improving void-numerics. This guide covers how to report problems, propose changes, and get a pull request merged.

## Reporting Bugs

Open an issue and include:

- The input value or string, the integer type, and the call that reproduce the problem.
- Compiler and version, operating system, and target architecture.
- Expected behavior (what `std::to_chars` / `std::from_chars` produce) versus actual behavior.
- For performance regressions, the benchmark used and the numbers before and after.

## Proposing Changes

For anything larger than a small fix, open an issue first so the approach can be discussed before you invest time in it.

1. Fork the repository and create a branch from `main`.
2. Make your change.
3. Build and run the unit tests locally (see below).
4. Open a pull request against `main` describing what changed and why.

## Building and Testing

void-numerics is built with CMake; presets are in `CMakePresets.json`. Tests live in `unit-tests` and are enabled with `-DVN_UNIT_TESTS=TRUE`. CI runs them with `-DVN_ASAN=TRUE -DVN_UBSAN=TRUE`, so please do the same locally.

Every pull request is built by CI on the following matrix, and all of it must pass:

| OS      | Compilers |
|---------|-----------|
| Ubuntu  | Clang, GCC |
| macOS   | Clang, GCC |
| Windows | MSVC |

Every conversion must match `std::to_chars` / `std::from_chars` exactly for all 8-, 16-, 32-, and 64-bit signed and unsigned types. A change that alters a result is a bug, however fast it is.

## Code Style

- Run `run-clang-format.ps1` before committing; formatting follows the repository `.clang-format`.
- Do not add explanatory comments to code. Write self-documenting code instead. Comments that attribute algorithms, techniques, or implementations to their original authors or sources are explicitly permitted. If current-us cannot write self-documenting code, then future-us does not deserve to understand it.
- Keep includes lean. Only include what the file actually uses.
- Keep changes focused. Unrelated refactors belong in their own pull request.

## Performance Changes

void-numerics is performance-sensitive. A change on a hot path (SWAR routines, digit counting, conversion loops) should come with results from [stringint-benchmarks](https://github.com/nihilai-collective/stringint-benchmarks) on at least one compiler, and should state any compiler where it is slower. Changes that win on one compiler but regress another need a per-compiler split to be accepted.

## Pull Request Checklist

- [ ] Builds and passes tests on all CI platforms
- [ ] Formatted with clang-format
- [ ] No added explanatory code comments (source attributions are permitted)
- [ ] Benchmarks included for performance-sensitive changes
- [ ] Linked to the issue it addresses, if any

## Licensing

By contributing, you agree that your contributions are licensed under the project's MIT license (see `License.md`).
