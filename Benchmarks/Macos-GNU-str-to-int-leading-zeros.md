# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

---
### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **44** | - | 4 |
| std::from_chars | - | 41 | 4 |
| strtoll/strtoull | - | 4 | - |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[TIE]` | std::from_chars 95 MB/s `[TIE]` | strtoll/strtoull 48 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 159 MB/s** (+100.0% over std::from_chars) | std::from_chars 79 MB/s | strtoll/strtoull 48 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 171 MB/s** (+109.3% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 47 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 168 MB/s** (+107.3% over std::from_chars) | std::from_chars 81 MB/s | strtoll/strtoull 48 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[TIE]` | std::from_chars 95 MB/s `[TIE]` | strtoll/strtoull 48 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 191 MB/s** (+133.6% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 49 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 191 MB/s** (+127.8% over std::from_chars) | std::from_chars 84 MB/s | strtoll/strtoull 49 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 190 MB/s** (+128.1% over std::from_chars) | std::from_chars 83 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[TIE]` | std::from_chars 95 MB/s `[TIE]` | strtoll/strtoull 48 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 191 MB/s** (+113.6% over std::from_chars) | std::from_chars 89 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 195 MB/s** (+122.4% over std::from_chars) | std::from_chars 88 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 196 MB/s** (+123.4% over std::from_chars) | std::from_chars 88 MB/s | strtoll/strtoull 49 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+53.8% over std::from_chars) | std::from_chars 124 MB/s `[TIE]` | strtoll/strtoull 76 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 272 MB/s** (+109.8% over std::from_chars) | std::from_chars 130 MB/s | strtoll/strtoull 84 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 285 MB/s** (+110.6% over std::from_chars) | std::from_chars 135 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 285 MB/s** (+113.5% over std::from_chars) | std::from_chars 133 MB/s | strtoll/strtoull 83 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+53.8% over std::from_chars) | std::from_chars 124 MB/s `[TIE]` | strtoll/strtoull 73 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 318 MB/s** (+133.3% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 84 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 300 MB/s** (+119.8% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 85 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 308 MB/s** (+125.8% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 85 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+42.9% over std::from_chars) | std::from_chars 134 MB/s `[TIE]` | strtoll/strtoull 76 MB/s `[TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 324 MB/s** (+136.2% over std::from_chars) | std::from_chars 137 MB/s | strtoll/strtoull 84 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 341 MB/s** (+130.0% over std::from_chars) | std::from_chars 148 MB/s | strtoll/strtoull 86 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 341 MB/s** (+131.9% over std::from_chars) | std::from_chars 147 MB/s | strtoll/strtoull 86 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+100.0% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 127 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 390 MB/s** (+100.1% over std::from_chars) | std::from_chars 195 MB/s | strtoll/strtoull 129 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 406 MB/s** (+106.1% over std::from_chars) | std::from_chars 197 MB/s | strtoll/strtoull 131 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 397 MB/s** (+100.9% over std::from_chars) | std::from_chars 197 MB/s | strtoll/strtoull 130 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+100.0% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 127 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 424 MB/s** (+108.8% over std::from_chars) | std::from_chars 203 MB/s | strtoll/strtoull 133 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 424 MB/s** (+110.4% over std::from_chars) | std::from_chars 201 MB/s | strtoll/strtoull 133 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 420 MB/s** (+110.4% over std::from_chars) | std::from_chars 200 MB/s | strtoll/strtoull 133 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+100.0% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 127 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 477 MB/s** (+123.7% over std::from_chars) | std::from_chars 213 MB/s | strtoll/strtoull 135 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 471 MB/s** (+129.6% over std::from_chars) | std::from_chars 205 MB/s | strtoll/strtoull 136 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 468 MB/s** (+117.5% over std::from_chars) | std::from_chars 215 MB/s | strtoll/strtoull 135 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 534 MB/s** (+110.0% over std::from_chars) | std::from_chars 254 MB/s | strtoll/strtoull 191 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 545 MB/s** (+84.2% over std::from_chars) | std::from_chars 296 MB/s | strtoll/strtoull 187 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 535 MB/s** (+82.6% over std::from_chars) | std::from_chars 293 MB/s | strtoll/strtoull 187 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 518 MB/s** (+76.9% over std::from_chars) | std::from_chars 293 MB/s | strtoll/strtoull 186 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 763 MB/s** (+172.7% over std::from_chars) | std::from_chars 280 MB/s | strtoll/strtoull 191 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 545 MB/s** (+85.0% over std::from_chars) | std::from_chars 295 MB/s | strtoll/strtoull 187 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 549 MB/s** (+85.5% over std::from_chars) | std::from_chars 296 MB/s | strtoll/strtoull 188 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 532 MB/s** (+91.0% over std::from_chars) | std::from_chars 279 MB/s | strtoll/strtoull 184 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | vn::from_chars 572 MB/s `[TIE]` | std::from_chars 280 MB/s `[TIE]` | strtoll/strtoull 191 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 587 MB/s** (+89.2% over std::from_chars) | std::from_chars 310 MB/s | strtoll/strtoull 192 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 578 MB/s** (+86.1% over std::from_chars) | std::from_chars 311 MB/s | strtoll/strtoull 195 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 560 MB/s** (+81.1% over std::from_chars) | std::from_chars 309 MB/s | strtoll/strtoull 194 MB/s |
