# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** GNU 16.0.1

---

## str-to-int-leading-zeros

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **48** | - | - |
| strtoll/strtoull | - | 1 | - |
| std::from_chars | - | 47 | - |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 66 MB/s** (+20.6% over std::from_chars) | std::from_chars 55 MB/s | strtoll/strtoull 42 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 67 MB/s** (+21.1% over std::from_chars) | std::from_chars 55 MB/s | strtoll/strtoull 44 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 67 MB/s** (+24.1% over std::from_chars) | std::from_chars 54 MB/s | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 68 MB/s** (+24.7% over std::from_chars) | std::from_chars 54 MB/s | strtoll/strtoull 42 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 69 MB/s** (+20.6% over std::from_chars) | std::from_chars 57 MB/s | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 67 MB/s** (+23.0% over std::from_chars) | std::from_chars 54 MB/s | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 65 MB/s** (+17.4% over std::from_chars) | std::from_chars 55 MB/s | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 67 MB/s** (+24.3% over std::from_chars) | std::from_chars 54 MB/s | strtoll/strtoull 43 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 78 MB/s** (+13.6% over std::from_chars) | std::from_chars 68 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 79 MB/s** (+12.7% over std::from_chars) | std::from_chars 70 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 77 MB/s** (+11.6% over std::from_chars) | std::from_chars 69 MB/s | strtoll/strtoull 48 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 79 MB/s** (+18.1% over std::from_chars) | std::from_chars 67 MB/s | strtoll/strtoull 49 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 128 MB/s** (+35.0% over std::from_chars) | std::from_chars 95 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 133 MB/s** (+38.0% over std::from_chars) | std::from_chars 97 MB/s | strtoll/strtoull 81 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 131 MB/s** (+36.7% over std::from_chars) | std::from_chars 96 MB/s | strtoll/strtoull 82 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 136 MB/s** (+43.9% over std::from_chars) | std::from_chars 95 MB/s | strtoll/strtoull 79 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 137 MB/s** (+42.9% over std::from_chars) | std::from_chars 96 MB/s | strtoll/strtoull 82 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 132 MB/s** (+36.2% over std::from_chars) | std::from_chars 97 MB/s | strtoll/strtoull 80 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 131 MB/s** (+39.5% over std::from_chars) | std::from_chars 94 MB/s | strtoll/strtoull 82 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 136 MB/s** (+45.3% over std::from_chars) | std::from_chars 94 MB/s | strtoll/strtoull 80 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 203 MB/s** (+80.2% over std::from_chars) | std::from_chars 113 MB/s | strtoll/strtoull 89 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 199 MB/s** (+65.7% over std::from_chars) | std::from_chars 120 MB/s | strtoll/strtoull 94 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 195 MB/s** (+69.4% over std::from_chars) | std::from_chars 115 MB/s | strtoll/strtoull 92 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 200 MB/s** (+71.5% over std::from_chars) | std::from_chars 117 MB/s | strtoll/strtoull 93 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 267 MB/s** (+61.8% over std::from_chars) | std::from_chars 165 MB/s | strtoll/strtoull 152 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 269 MB/s** (+53.8% over std::from_chars) | std::from_chars 175 MB/s | strtoll/strtoull 156 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 263 MB/s** (+50.2% over std::from_chars) | std::from_chars 175 MB/s | strtoll/strtoull 148 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 258 MB/s** (+48.2% over std::from_chars) | std::from_chars 174 MB/s | strtoll/strtoull 143 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 258 MB/s** (+49.5% over std::from_chars) | std::from_chars 173 MB/s | strtoll/strtoull 146 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 253 MB/s** (+43.0% over std::from_chars) | std::from_chars 177 MB/s | strtoll/strtoull 146 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 269 MB/s** (+56.1% over std::from_chars) | std::from_chars 173 MB/s | strtoll/strtoull 146 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 253 MB/s** (+46.7% over std::from_chars) | std::from_chars 172 MB/s | strtoll/strtoull 146 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 363 MB/s** (+73.9% over std::from_chars) | std::from_chars 209 MB/s | strtoll/strtoull 171 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 355 MB/s** (+61.5% over std::from_chars) | std::from_chars 220 MB/s | strtoll/strtoull 169 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 342 MB/s** (+61.0% over std::from_chars) | std::from_chars 212 MB/s | strtoll/strtoull 166 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 366 MB/s** (+69.3% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 168 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 512 MB/s** (+57.4% over std::from_chars) | std::from_chars 326 MB/s | strtoll/strtoull 262 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 513 MB/s** (+56.4% over std::from_chars) | std::from_chars 328 MB/s | strtoll/strtoull 261 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 508 MB/s** (+57.9% over std::from_chars) | std::from_chars 321 MB/s | strtoll/strtoull 256 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 518 MB/s** (+59.8% over std::from_chars) | std::from_chars 324 MB/s | strtoll/strtoull 255 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 499 MB/s** (+101.9% over strtoll/strtoull) | strtoll/strtoull 247 MB/s | std::from_chars 183 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 522 MB/s** (+56.8% over std::from_chars) | std::from_chars 333 MB/s | strtoll/strtoull 263 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 483 MB/s** (+48.7% over std::from_chars) | std::from_chars 325 MB/s | strtoll/strtoull 247 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 494 MB/s** (+55.8% over std::from_chars) | std::from_chars 317 MB/s | strtoll/strtoull 240 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 512 MB/s** (+47.4% over std::from_chars) | std::from_chars 348 MB/s | strtoll/strtoull 276 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 539 MB/s** (+48.0% over std::from_chars) | std::from_chars 364 MB/s | strtoll/strtoull 267 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 534 MB/s** (+52.4% over std::from_chars) | std::from_chars 350 MB/s | strtoll/strtoull 277 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 531 MB/s** (+50.4% over std::from_chars) | std::from_chars 353 MB/s | strtoll/strtoull 274 MB/s |
