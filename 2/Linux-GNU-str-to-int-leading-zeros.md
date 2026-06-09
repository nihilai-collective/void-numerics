# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** GNU 16.0.1  

---

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
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 65 MB/s** (+14.3% over std::from_chars) | std::from_chars 57 MB/s | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 60 MB/s** (+3.2% over std::from_chars) | std::from_chars 58 MB/s | strtoll/strtoull 43 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 67 MB/s** (+14.2% over std::from_chars) | std::from_chars 59 MB/s | strtoll/strtoull 44 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 66 MB/s** (+13.6% over std::from_chars) | std::from_chars 58 MB/s | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 67 MB/s** (+16.1% over std::from_chars) | std::from_chars 58 MB/s | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 69 MB/s** (+18.7% over std::from_chars) | std::from_chars 58 MB/s | strtoll/strtoull 43 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 67 MB/s** (+18.2% over std::from_chars) | std::from_chars 57 MB/s | strtoll/strtoull 44 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 68 MB/s** (+16.8% over std::from_chars) | std::from_chars 58 MB/s | strtoll/strtoull 44 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 77 MB/s** (+11.6% over std::from_chars) | std::from_chars 69 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 72 MB/s** (+4.7% over std::from_chars) | std::from_chars 69 MB/s | strtoll/strtoull 50 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 76 MB/s** (+10.6% over std::from_chars) | std::from_chars 69 MB/s | strtoll/strtoull 49 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 79 MB/s** (+13.7% over std::from_chars) | std::from_chars 69 MB/s | strtoll/strtoull 50 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 130 MB/s** (+28.1% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 81 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 135 MB/s** (+27.8% over std::from_chars) | std::from_chars 105 MB/s | strtoll/strtoull 83 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 136 MB/s** (+29.8% over std::from_chars) | std::from_chars 105 MB/s | strtoll/strtoull 82 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 134 MB/s** (+29.9% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 80 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 131 MB/s** (+28.0% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 83 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 134 MB/s** (+28.3% over std::from_chars) | std::from_chars 104 MB/s | strtoll/strtoull 83 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 137 MB/s** (+31.6% over std::from_chars) | std::from_chars 104 MB/s | strtoll/strtoull 81 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 136 MB/s** (+31.9% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 80 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 199 MB/s** (+67.6% over std::from_chars) | std::from_chars 119 MB/s | strtoll/strtoull 92 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 197 MB/s** (+60.7% over std::from_chars) | std::from_chars 123 MB/s | strtoll/strtoull 62 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 203 MB/s** (+69.0% over std::from_chars) | std::from_chars 120 MB/s | strtoll/strtoull 95 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 203 MB/s** (+69.6% over std::from_chars) | std::from_chars 119 MB/s | strtoll/strtoull 95 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 260 MB/s** (+83.8% over strtoll/strtoull) | strtoll/strtoull 141 MB/s | std::from_chars 115 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 267 MB/s** (+43.3% over std::from_chars) | std::from_chars 187 MB/s | strtoll/strtoull 105 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 273 MB/s** (+50.1% over std::from_chars) | std::from_chars 182 MB/s | strtoll/strtoull 152 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 272 MB/s** (+45.5% over std::from_chars) | std::from_chars 187 MB/s | strtoll/strtoull 147 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 270 MB/s** (+40.9% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 91 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 273 MB/s** (+45.8% over std::from_chars) | std::from_chars 187 MB/s | strtoll/strtoull 147 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 275 MB/s** (+46.0% over std::from_chars) | std::from_chars 189 MB/s | strtoll/strtoull 152 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 269 MB/s** (+43.8% over std::from_chars) | std::from_chars 187 MB/s | strtoll/strtoull 147 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 388 MB/s** (+81.0% over std::from_chars) | std::from_chars 214 MB/s | strtoll/strtoull 172 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 378 MB/s** (+74.9% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 175 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 377 MB/s** (+73.0% over std::from_chars) | std::from_chars 218 MB/s | strtoll/strtoull 167 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 375 MB/s** (+73.2% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 170 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 499 MB/s** (+52.9% over std::from_chars) | std::from_chars 327 MB/s | strtoll/strtoull 260 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 525 MB/s** (+57.6% over std::from_chars) | std::from_chars 333 MB/s | strtoll/strtoull 257 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 526 MB/s** (+63.0% over std::from_chars) | std::from_chars 323 MB/s | strtoll/strtoull 254 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 515 MB/s** (+61.4% over std::from_chars) | std::from_chars 319 MB/s | strtoll/strtoull 248 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 511 MB/s** (+60.4% over std::from_chars) | std::from_chars 319 MB/s | strtoll/strtoull 245 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 511 MB/s** (+54.0% over std::from_chars) | std::from_chars 332 MB/s | strtoll/strtoull 249 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 505 MB/s** (+57.5% over std::from_chars) | std::from_chars 321 MB/s | strtoll/strtoull 248 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 520 MB/s** (+60.8% over std::from_chars) | std::from_chars 323 MB/s | strtoll/strtoull 247 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 522 MB/s** (+47.2% over std::from_chars) | std::from_chars 355 MB/s | strtoll/strtoull 283 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 540 MB/s** (+47.2% over std::from_chars) | std::from_chars 367 MB/s | strtoll/strtoull 276 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 528 MB/s** (+47.1% over std::from_chars) | std::from_chars 359 MB/s | strtoll/strtoull 278 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 527 MB/s** (+47.5% over std::from_chars) | std::from_chars 358 MB/s | strtoll/strtoull 271 MB/s |
