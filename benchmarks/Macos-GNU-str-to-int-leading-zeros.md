
# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

---

## str-to-int-leading-zeros

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **43** | 1 | 4 |
| std::from_chars | 1 | 40 | 3 |
| strtoll/strtoull | - | 2 | 3 |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 52 MB/s** (+10.0% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 32 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 56 MB/s** (+17.6% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 34 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 55 MB/s** (+10.9% over std::from_chars) | std::from_chars 49 MB/s | strtoll/strtoull 35 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 55 MB/s** (+15.4% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 35 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 52 MB/s** (+10.0% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 32 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 56 MB/s** (+17.6% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 35 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 55 MB/s** (+13.4% over std::from_chars) | std::from_chars 48 MB/s | strtoll/strtoull 34 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 50 MB/s** (+5.5% over std::from_chars) | std::from_chars 47 MB/s | strtoll/strtoull 34 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 67 MB/s `[TIE]` | strtoll/strtoull 38 MB/s `[TIE]` | std::from_chars 48 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 64 MB/s** (+26.7% over std::from_chars) | std::from_chars 50 MB/s | strtoll/strtoull 38 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 66 MB/s** (+54.5% over std::from_chars) | std::from_chars 42 MB/s | strtoll/strtoull 39 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 65 MB/s** (+45.7% over std::from_chars) | std::from_chars 45 MB/s `[TIE]` | strtoll/strtoull 39 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 105 MB/s** (+10.0% over std::from_chars) | std::from_chars 95 MB/s | strtoll/strtoull 64 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 114 MB/s** (+45.2% over std::from_chars) | std::from_chars 79 MB/s | strtoll/strtoull 64 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 115 MB/s** (+30.7% over std::from_chars) | std::from_chars 88 MB/s | strtoll/strtoull 61 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 112 MB/s** (+54.0% over std::from_chars) | std::from_chars 73 MB/s `[TIE]` | strtoll/strtoull 56 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[100] | vn::from_chars 114 MB/s `[TIE]` | std::from_chars 79 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 114 MB/s** (+30.4% over std::from_chars) | std::from_chars 87 MB/s | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 117 MB/s** (+34.3% over std::from_chars) | std::from_chars 87 MB/s | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | std::from_chars 85 MB/s `[3-way TIE]` | vn::from_chars 70 MB/s `[3-way TIE]` | strtoll/strtoull 64 MB/s `[3-way TIE]` |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+160.9% over strtoll/strtoull) | strtoll/strtoull 73 MB/s | std::from_chars 32 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 110 MB/s** (+26.6% over std::from_chars) | std::from_chars 87 MB/s | strtoll/strtoull 71 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 154 MB/s** (+74.2% over std::from_chars) | std::from_chars 88 MB/s | strtoll/strtoull 73 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 70 MB/s** (+61.9% over std::from_chars) | std::from_chars 43 MB/s | strtoll/strtoull 28 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+42.9% over std::from_chars) | std::from_chars 134 MB/s | strtoll/strtoull 42 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 201 MB/s** (+42.1% over std::from_chars) | std::from_chars 141 MB/s | strtoll/strtoull 109 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 206 MB/s** (+45.1% over std::from_chars) | std::from_chars 142 MB/s | strtoll/strtoull 110 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 202 MB/s** (+73.1% over std::from_chars) | std::from_chars 116 MB/s | strtoll/strtoull 108 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+50.0% over std::from_chars) | std::from_chars 127 MB/s | strtoll/strtoull 43 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 201 MB/s** (+41.6% over std::from_chars) | std::from_chars 142 MB/s | strtoll/strtoull 109 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 191 MB/s** (+35.1% over std::from_chars) | std::from_chars 141 MB/s | strtoll/strtoull 109 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | vn::from_chars 129 MB/s `[3-way TIE]` | strtoll/strtoull 84 MB/s `[3-way TIE]` | std::from_chars 44 MB/s `[3-way TIE]` |
| uint32-positive-mixed-lengths-test-size[100] | **std::from_chars 146 MB/s** (+15.0% over vn::from_chars) | vn::from_chars 127 MB/s | strtoll/strtoull 45 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 272 MB/s** (+77.8% over std::from_chars) | std::from_chars 153 MB/s | strtoll/strtoull 116 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 271 MB/s** (+82.0% over std::from_chars) | std::from_chars 149 MB/s | strtoll/strtoull 119 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 260 MB/s** (+71.3% over std::from_chars) | std::from_chars 152 MB/s | strtoll/strtoull 107 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+81.8% over std::from_chars) | std::from_chars 210 MB/s | strtoll/strtoull 156 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 363 MB/s** (+104.1% over std::from_chars) | std::from_chars 178 MB/s | strtoll/strtoull 167 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 355 MB/s** (+52.1% over std::from_chars) | std::from_chars 233 MB/s | strtoll/strtoull 166 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 340 MB/s** (+51.1% over std::from_chars) | std::from_chars 225 MB/s | strtoll/strtoull 160 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+50.0% over std::from_chars) | std::from_chars 254 MB/s | strtoll/strtoull 160 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 348 MB/s** (+50.7% over std::from_chars) | std::from_chars 231 MB/s | strtoll/strtoull 166 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 357 MB/s** (+43.0% over std::from_chars) | std::from_chars 250 MB/s | strtoll/strtoull 166 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 330 MB/s** (+40.4% over std::from_chars) | std::from_chars 235 MB/s | strtoll/strtoull 161 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+50.0% over std::from_chars) | std::from_chars 254 MB/s | strtoll/strtoull 191 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 363 MB/s** (+59.9% over std::from_chars) | std::from_chars 227 MB/s | strtoll/strtoull 178 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 328 MB/s** (+40.4% over std::from_chars) | std::from_chars 233 MB/s | strtoll/strtoull 172 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 288 MB/s** (+72.3% over strtoll/strtoull) | strtoll/strtoull 167 MB/s `[TIE]` | std::from_chars 156 MB/s `[TIE]` |
