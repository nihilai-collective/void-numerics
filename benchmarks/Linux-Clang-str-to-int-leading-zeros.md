# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** Clang 23.0.0

---

## str-to-int-leading-zeros

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **36** | 4 | 8 |
| std::from_chars | 4 | 35 | 8 |
| strtoll/strtoull | - | 8 | - |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 61 MB/s `[TIE]` | std::from_chars 59 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | std::from_chars 62 MB/s `[TIE]` | vn::from_chars 61 MB/s `[TIE]` | strtoll/strtoull 45 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | std::from_chars 60 MB/s `[TIE]` | vn::from_chars 60 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | vn::from_chars 61 MB/s `[TIE]` | std::from_chars 60 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[100] | std::from_chars 61 MB/s `[TIE]` | vn::from_chars 61 MB/s `[TIE]` | strtoll/strtoull 45 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | vn::from_chars 61 MB/s `[TIE]` | std::from_chars 60 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | std::from_chars 61 MB/s `[TIE]` | vn::from_chars 60 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | std::from_chars 60 MB/s `[TIE]` | vn::from_chars 58 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **std::from_chars 77 MB/s** (+13.9% over vn::from_chars) | vn::from_chars 68 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **std::from_chars 76 MB/s** (+9.6% over vn::from_chars) | vn::from_chars 69 MB/s | strtoll/strtoull 46 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **std::from_chars 72 MB/s** (+5.3% over vn::from_chars) | vn::from_chars 68 MB/s | strtoll/strtoull 45 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **std::from_chars 76 MB/s** (+10.4% over vn::from_chars) | vn::from_chars 69 MB/s | strtoll/strtoull 46 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 122 MB/s** (+23.8% over std::from_chars) | std::from_chars 99 MB/s | strtoll/strtoull 82 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 121 MB/s** (+19.3% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 117 MB/s** (+17.2% over std::from_chars) | std::from_chars 100 MB/s | strtoll/strtoull 82 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 122 MB/s** (+24.2% over std::from_chars) | std::from_chars 99 MB/s | strtoll/strtoull 81 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 119 MB/s** (+16.7% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 79 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 122 MB/s** (+21.6% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 83 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 117 MB/s** (+18.0% over std::from_chars) | std::from_chars 99 MB/s | strtoll/strtoull 81 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 121 MB/s** (+22.2% over std::from_chars) | std::from_chars 99 MB/s | strtoll/strtoull 80 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 152 MB/s** (+17.3% over std::from_chars) | std::from_chars 130 MB/s | strtoll/strtoull 96 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 155 MB/s** (+18.3% over std::from_chars) | std::from_chars 131 MB/s | strtoll/strtoull 97 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 148 MB/s** (+16.5% over std::from_chars) | std::from_chars 127 MB/s | strtoll/strtoull 94 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 153 MB/s** (+21.9% over std::from_chars) | std::from_chars 126 MB/s | strtoll/strtoull 95 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 225 MB/s** (+14.7% over std::from_chars) | std::from_chars 196 MB/s | strtoll/strtoull 146 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 223 MB/s** (+15.9% over std::from_chars) | std::from_chars 192 MB/s | strtoll/strtoull 144 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 219 MB/s** (+13.2% over std::from_chars) | std::from_chars 193 MB/s | strtoll/strtoull 146 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 224 MB/s** (+17.6% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 145 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 224 MB/s** (+15.9% over std::from_chars) | std::from_chars 193 MB/s | strtoll/strtoull 145 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 226 MB/s** (+14.4% over std::from_chars) | std::from_chars 198 MB/s | strtoll/strtoull 145 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 221 MB/s** (+14.9% over std::from_chars) | std::from_chars 192 MB/s | strtoll/strtoull 143 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 218 MB/s** (+16.7% over std::from_chars) | std::from_chars 187 MB/s | strtoll/strtoull 143 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 314 MB/s** (+38.6% over std::from_chars) | std::from_chars 227 MB/s | strtoll/strtoull 154 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 307 MB/s** (+45.2% over std::from_chars) | std::from_chars 211 MB/s | strtoll/strtoull 156 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 297 MB/s** (+31.1% over std::from_chars) | std::from_chars 227 MB/s | strtoll/strtoull 154 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 311 MB/s** (+36.3% over std::from_chars) | std::from_chars 228 MB/s | strtoll/strtoull 155 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 422 MB/s** (+49.4% over std::from_chars) | std::from_chars 283 MB/s | strtoll/strtoull 241 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 448 MB/s** (+62.9% over std::from_chars) | std::from_chars 275 MB/s | strtoll/strtoull 260 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 423 MB/s** (+60.6% over std::from_chars) | std::from_chars 264 MB/s `[TIE]` | strtoll/strtoull 251 MB/s `[TIE]` |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 445 MB/s** (+60.6% over std::from_chars) | std::from_chars 277 MB/s | strtoll/strtoull 248 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 442 MB/s** (+59.7% over std::from_chars) | std::from_chars 276 MB/s | strtoll/strtoull 264 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 448 MB/s** (+57.7% over std::from_chars) | std::from_chars 284 MB/s | strtoll/strtoull 256 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 431 MB/s** (+55.1% over std::from_chars) | std::from_chars 278 MB/s | strtoll/strtoull 254 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 440 MB/s** (+55.4% over std::from_chars) | std::from_chars 283 MB/s | strtoll/strtoull 256 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 444 MB/s** (+23.0% over std::from_chars) | std::from_chars 361 MB/s | strtoll/strtoull 259 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 458 MB/s** (+25.2% over std::from_chars) | std::from_chars 366 MB/s | strtoll/strtoull 263 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 446 MB/s** (+26.9% over std::from_chars) | std::from_chars 351 MB/s | strtoll/strtoull 255 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 442 MB/s** (+23.5% over std::from_chars) | std::from_chars 358 MB/s | strtoll/strtoull 255 MB/s |

