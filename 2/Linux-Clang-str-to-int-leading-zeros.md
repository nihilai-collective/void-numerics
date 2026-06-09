# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** Clang 23.0.0  

---

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **38** | 3 | 7 |
| std::from_chars | 3 | 34 | 7 |
| strtoll/strtoull | - | 8 | - |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | std::from_chars 61 MB/s `[TIE]` | vn::from_chars 58 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | std::from_chars 62 MB/s `[TIE]` | vn::from_chars 61 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 64 MB/s** (+3.7% over std::from_chars) | std::from_chars 61 MB/s | strtoll/strtoull 44 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | vn::from_chars 62 MB/s `[TIE]` | std::from_chars 62 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 62 MB/s `[TIE]` | std::from_chars 60 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | std::from_chars 62 MB/s `[TIE]` | vn::from_chars 62 MB/s `[TIE]` | strtoll/strtoull 45 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 63 MB/s** (+1.7% over std::from_chars) | std::from_chars 62 MB/s | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | vn::from_chars 62 MB/s `[TIE]` | std::from_chars 61 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | std::from_chars 76 MB/s `[TIE]` | vn::from_chars 71 MB/s `[TIE]` | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **std::from_chars 77 MB/s** (+8.0% over vn::from_chars) | vn::from_chars 71 MB/s | strtoll/strtoull 51 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **std::from_chars 77 MB/s** (+8.6% over vn::from_chars) | vn::from_chars 71 MB/s | strtoll/strtoull 47 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **std::from_chars 77 MB/s** (+7.3% over vn::from_chars) | vn::from_chars 71 MB/s | strtoll/strtoull 46 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 123 MB/s** (+23.4% over std::from_chars) | std::from_chars 100 MB/s | strtoll/strtoull 80 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 125 MB/s** (+22.5% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 123 MB/s** (+22.7% over std::from_chars) | std::from_chars 100 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 124 MB/s** (+22.7% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 81 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 114 MB/s** (+37.3% over strtoll/strtoull) | strtoll/strtoull 83 MB/s | std::from_chars 76 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 124 MB/s** (+21.9% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 77 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 123 MB/s** (+20.7% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 82 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 124 MB/s** (+23.5% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 83 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 157 MB/s** (+19.8% over std::from_chars) | std::from_chars 131 MB/s | strtoll/strtoull 95 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 159 MB/s** (+30.1% over std::from_chars) | std::from_chars 122 MB/s | strtoll/strtoull 97 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 158 MB/s** (+19.7% over std::from_chars) | std::from_chars 132 MB/s | strtoll/strtoull 95 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 157 MB/s** (+19.4% over std::from_chars) | std::from_chars 132 MB/s | strtoll/strtoull 95 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 230 MB/s** (+35.7% over std::from_chars) | std::from_chars 170 MB/s | strtoll/strtoull 153 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 230 MB/s** (+14.1% over std::from_chars) | std::from_chars 202 MB/s | strtoll/strtoull 146 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 227 MB/s** (+18.6% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 146 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 229 MB/s** (+16.7% over std::from_chars) | std::from_chars 196 MB/s | strtoll/strtoull 142 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 230 MB/s** (+15.3% over std::from_chars) | std::from_chars 199 MB/s | strtoll/strtoull 145 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 229 MB/s** (+33.3% over std::from_chars) | std::from_chars 172 MB/s | strtoll/strtoull 146 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 225 MB/s** (+13.7% over std::from_chars) | std::from_chars 198 MB/s | strtoll/strtoull 147 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 230 MB/s** (+16.4% over std::from_chars) | std::from_chars 197 MB/s | strtoll/strtoull 139 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 303 MB/s** (+35.0% over std::from_chars) | std::from_chars 224 MB/s | strtoll/strtoull 148 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 316 MB/s** (+37.7% over std::from_chars) | std::from_chars 230 MB/s | strtoll/strtoull 148 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 320 MB/s** (+36.4% over std::from_chars) | std::from_chars 235 MB/s | strtoll/strtoull 156 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 314 MB/s** (+39.6% over std::from_chars) | std::from_chars 225 MB/s | strtoll/strtoull 153 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 434 MB/s** (+54.5% over std::from_chars) | std::from_chars 281 MB/s | strtoll/strtoull 244 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 448 MB/s** (+70.7% over std::from_chars) | std::from_chars 263 MB/s `[TIE]` | strtoll/strtoull 262 MB/s `[TIE]` |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 443 MB/s** (+55.8% over std::from_chars) | std::from_chars 284 MB/s | strtoll/strtoull 255 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 447 MB/s** (+58.3% over std::from_chars) | std::from_chars 282 MB/s `[TIE]` | strtoll/strtoull 253 MB/s `[TIE]` |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 438 MB/s** (+53.6% over std::from_chars) | std::from_chars 285 MB/s | strtoll/strtoull 260 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 418 MB/s** (+46.6% over std::from_chars) | std::from_chars 285 MB/s | strtoll/strtoull 260 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 445 MB/s** (+57.4% over std::from_chars) | std::from_chars 283 MB/s | strtoll/strtoull 259 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 447 MB/s** (+58.3% over std::from_chars) | std::from_chars 282 MB/s `[TIE]` | strtoll/strtoull 251 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 442 MB/s** (+23.6% over std::from_chars) | std::from_chars 358 MB/s | strtoll/strtoull 260 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 454 MB/s** (+24.2% over std::from_chars) | std::from_chars 366 MB/s | strtoll/strtoull 259 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 452 MB/s** (+25.8% over std::from_chars) | std::from_chars 359 MB/s | strtoll/strtoull 260 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 451 MB/s** (+25.8% over std::from_chars) | std::from_chars 359 MB/s | strtoll/strtoull 253 MB/s |

