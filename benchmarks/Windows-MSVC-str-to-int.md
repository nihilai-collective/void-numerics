# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Windows 10.0.26200
**Compiler:** MSVC 19.44.35227.0

---

## str-to-int

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **34** | 1 | 13 |
| std::from_chars | 1 | 34 | 13 |
| strtoll/strtoull | - | 13 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 119 MB/s** (+11.1% over std::from_chars) | std::from_chars 107 MB/s | strtoll/strtoull 48 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 126 MB/s** (+9.3% over std::from_chars) | std::from_chars 115 MB/s | strtoll/strtoull 48 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 127 MB/s** (+11.5% over std::from_chars) | std::from_chars 114 MB/s | strtoll/strtoull 47 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 124 MB/s** (+9.3% over std::from_chars) | std::from_chars 113 MB/s | strtoll/strtoull 47 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 121 MB/s** (+12.7% over std::from_chars) | std::from_chars 107 MB/s | strtoll/strtoull 48 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 127 MB/s** (+10.0% over std::from_chars) | std::from_chars 115 MB/s | strtoll/strtoull 49 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 129 MB/s** (+11.8% over std::from_chars) | std::from_chars 115 MB/s | strtoll/strtoull 47 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 127 MB/s** (+12.3% over std::from_chars) | std::from_chars 113 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 165 MB/s** (+4.0% over std::from_chars) | std::from_chars 159 MB/s | strtoll/strtoull 56 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 186 MB/s** (+5.6% over std::from_chars) | std::from_chars 176 MB/s | strtoll/strtoull 58 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 185 MB/s** (+4.7% over std::from_chars) | std::from_chars 177 MB/s | strtoll/strtoull 57 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 185 MB/s** (+8.4% over std::from_chars) | std::from_chars 171 MB/s | strtoll/strtoull 56 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 193 MB/s** (+11.2% over std::from_chars) | std::from_chars 173 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 193 MB/s** (+7.7% over std::from_chars) | std::from_chars 179 MB/s | strtoll/strtoull 81 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 198 MB/s** (+11.2% over std::from_chars) | std::from_chars 178 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 192 MB/s** (+6.3% over std::from_chars) | std::from_chars 180 MB/s | strtoll/strtoull 80 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+8.9% over std::from_chars) | std::from_chars 175 MB/s | strtoll/strtoull 83 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 196 MB/s** (+9.0% over std::from_chars) | std::from_chars 180 MB/s | strtoll/strtoull 84 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | vn::from_chars 195 MB/s `[TIE]` | std::from_chars 179 MB/s `[TIE]` | strtoll/strtoull 80 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 192 MB/s** (+11.4% over std::from_chars) | std::from_chars 172 MB/s | strtoll/strtoull 80 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+20.0% over std::from_chars) | std::from_chars 318 MB/s | strtoll/strtoull 106 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 355 MB/s** (+9.1% over std::from_chars) | std::from_chars 326 MB/s | strtoll/strtoull 106 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 353 MB/s** (+7.2% over std::from_chars) | std::from_chars 329 MB/s | strtoll/strtoull 105 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 351 MB/s** (+8.3% over std::from_chars) | std::from_chars 324 MB/s | strtoll/strtoull 105 MB/s |
| int32-negative-mixed-lengths-test-size[100] | std::from_chars 293 MB/s `[TIE]` | vn::from_chars 293 MB/s `[TIE]` | strtoll/strtoull 117 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | std::from_chars 299 MB/s `[TIE]` | vn::from_chars 296 MB/s `[TIE]` | strtoll/strtoull 119 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | vn::from_chars 292 MB/s `[TIE]` | std::from_chars 286 MB/s `[TIE]` | strtoll/strtoull 120 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | vn::from_chars 293 MB/s `[TIE]` | std::from_chars 292 MB/s `[TIE]` | strtoll/strtoull 113 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **std::from_chars 296 MB/s** (+0.8% over vn::from_chars) | vn::from_chars 293 MB/s | strtoll/strtoull 116 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | vn::from_chars 298 MB/s `[TIE]` | std::from_chars 292 MB/s `[TIE]` | strtoll/strtoull 119 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | std::from_chars 294 MB/s `[TIE]` | vn::from_chars 288 MB/s `[TIE]` | strtoll/strtoull 118 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | vn::from_chars 291 MB/s `[TIE]` | std::from_chars 291 MB/s `[TIE]` | strtoll/strtoull 112 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 424 MB/s** (+22.2% over std::from_chars) | std::from_chars 347 MB/s | strtoll/strtoull 147 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 447 MB/s** (+31.6% over std::from_chars) | std::from_chars 339 MB/s | strtoll/strtoull 146 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 453 MB/s** (+35.2% over std::from_chars) | std::from_chars 335 MB/s | strtoll/strtoull 144 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 444 MB/s** (+33.1% over std::from_chars) | std::from_chars 334 MB/s | strtoll/strtoull 140 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 449 MB/s** (+11.1% over std::from_chars) | std::from_chars 404 MB/s | strtoll/strtoull 177 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 452 MB/s** (+12.2% over std::from_chars) | std::from_chars 403 MB/s | strtoll/strtoull 174 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | vn::from_chars 437 MB/s `[TIE]` | std::from_chars 397 MB/s `[TIE]` | strtoll/strtoull 171 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 448 MB/s** (+16.9% over std::from_chars) | std::from_chars 383 MB/s | strtoll/strtoull 175 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 449 MB/s** (+11.8% over std::from_chars) | std::from_chars 402 MB/s | strtoll/strtoull 178 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 452 MB/s** (+15.0% over std::from_chars) | std::from_chars 393 MB/s | strtoll/strtoull 176 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | vn::from_chars 436 MB/s `[TIE]` | std::from_chars 398 MB/s `[TIE]` | strtoll/strtoull 173 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | vn::from_chars 425 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 176 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 477 MB/s** (+6.3% over std::from_chars) | std::from_chars 449 MB/s | strtoll/strtoull 177 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 482 MB/s** (+2.7% over std::from_chars) | std::from_chars 469 MB/s | strtoll/strtoull 179 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | vn::from_chars 469 MB/s `[TIE]` | std::from_chars 455 MB/s `[TIE]` | strtoll/strtoull 177 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | vn::from_chars 472 MB/s `[TIE]` | std::from_chars 451 MB/s `[TIE]` | strtoll/strtoull 177 MB/s |

