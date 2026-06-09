# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** Clang 23.0.0  

---

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **45** | - | 3 |
| std::from_chars | - | 45 | 3 |
| strtoll/strtoull | - | 3 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 151 MB/s `[TIE]` | std::from_chars 138 MB/s `[TIE]` | strtoll/strtoull 92 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 165 MB/s** (+10.3% over std::from_chars) | std::from_chars 149 MB/s | strtoll/strtoull 94 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 174 MB/s** (+18.9% over std::from_chars) | std::from_chars 146 MB/s | strtoll/strtoull 93 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 171 MB/s** (+15.6% over std::from_chars) | std::from_chars 148 MB/s | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 164 MB/s** (+17.8% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 88 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 171 MB/s** (+12.6% over std::from_chars) | std::from_chars 152 MB/s | strtoll/strtoull 93 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 173 MB/s** (+16.5% over std::from_chars) | std::from_chars 149 MB/s | strtoll/strtoull 93 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 170 MB/s** (+14.8% over std::from_chars) | std::from_chars 148 MB/s | strtoll/strtoull 91 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 236 MB/s `[TIE]` | std::from_chars 221 MB/s `[TIE]` | strtoll/strtoull 105 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 262 MB/s** (+11.8% over std::from_chars) | std::from_chars 234 MB/s | strtoll/strtoull 111 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 252 MB/s** (+5.7% over std::from_chars) | std::from_chars 239 MB/s | strtoll/strtoull 114 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 259 MB/s** (+8.6% over std::from_chars) | std::from_chars 239 MB/s | strtoll/strtoull 118 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 277 MB/s** (+13.9% over std::from_chars) | std::from_chars 243 MB/s | strtoll/strtoull 138 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 279 MB/s** (+12.0% over std::from_chars) | std::from_chars 249 MB/s | strtoll/strtoull 154 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 286 MB/s** (+13.9% over std::from_chars) | std::from_chars 251 MB/s | strtoll/strtoull 154 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 282 MB/s** (+13.7% over std::from_chars) | std::from_chars 248 MB/s | strtoll/strtoull 154 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 281 MB/s** (+17.4% over std::from_chars) | std::from_chars 240 MB/s | strtoll/strtoull 152 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 279 MB/s** (+13.9% over std::from_chars) | std::from_chars 245 MB/s | strtoll/strtoull 161 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 285 MB/s** (+13.3% over std::from_chars) | std::from_chars 252 MB/s | strtoll/strtoull 152 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 277 MB/s** (+12.5% over std::from_chars) | std::from_chars 246 MB/s | strtoll/strtoull 152 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::from_chars 571 MB/s `[TIE]` | std::from_chars 520 MB/s `[TIE]` | strtoll/strtoull 199 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 617 MB/s** (+9.6% over std::from_chars) | std::from_chars 563 MB/s | strtoll/strtoull 213 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 623 MB/s** (+14.0% over std::from_chars) | std::from_chars 546 MB/s | strtoll/strtoull 210 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 611 MB/s** (+9.9% over std::from_chars) | std::from_chars 556 MB/s | strtoll/strtoull 209 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 421 MB/s** (+19.4% over std::from_chars) | std::from_chars 353 MB/s | strtoll/strtoull 233 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 436 MB/s** (+27.3% over std::from_chars) | std::from_chars 343 MB/s | strtoll/strtoull 247 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 430 MB/s** (+23.2% over std::from_chars) | std::from_chars 349 MB/s | strtoll/strtoull 239 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 419 MB/s** (+21.6% over std::from_chars) | std::from_chars 345 MB/s | strtoll/strtoull 238 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 420 MB/s** (+20.3% over std::from_chars) | std::from_chars 349 MB/s | strtoll/strtoull 235 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 428 MB/s** (+21.2% over std::from_chars) | std::from_chars 353 MB/s | strtoll/strtoull 225 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 428 MB/s** (+22.8% over std::from_chars) | std::from_chars 348 MB/s | strtoll/strtoull 244 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 428 MB/s** (+25.3% over std::from_chars) | std::from_chars 342 MB/s | strtoll/strtoull 243 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 710 MB/s** (+22.4% over std::from_chars) | std::from_chars 580 MB/s | strtoll/strtoull 201 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 762 MB/s** (+21.5% over std::from_chars) | std::from_chars 628 MB/s | strtoll/strtoull 305 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 709 MB/s** (+13.0% over std::from_chars) | std::from_chars 627 MB/s | strtoll/strtoull 235 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 752 MB/s** (+22.4% over std::from_chars) | std::from_chars 615 MB/s | strtoll/strtoull 231 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 764 MB/s** (+41.7% over std::from_chars) | std::from_chars 539 MB/s | strtoll/strtoull 384 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 775 MB/s** (+39.2% over std::from_chars) | std::from_chars 557 MB/s | strtoll/strtoull 366 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 723 MB/s** (+30.8% over std::from_chars) | std::from_chars 553 MB/s | strtoll/strtoull 341 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 773 MB/s** (+42.7% over std::from_chars) | std::from_chars 541 MB/s | strtoll/strtoull 350 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 752 MB/s** (+57.6% over std::from_chars) | std::from_chars 477 MB/s | strtoll/strtoull 364 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 763 MB/s** (+98.3% over std::from_chars) | std::from_chars 385 MB/s | strtoll/strtoull 225 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 774 MB/s** (+39.4% over std::from_chars) | std::from_chars 555 MB/s | strtoll/strtoull 364 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 750 MB/s** (+35.3% over std::from_chars) | std::from_chars 555 MB/s | strtoll/strtoull 404 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 752 MB/s** (+37.2% over std::from_chars) | std::from_chars 548 MB/s | strtoll/strtoull 342 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 762 MB/s** (+17.0% over std::from_chars) | std::from_chars 651 MB/s | strtoll/strtoull 358 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 761 MB/s** (+21.4% over std::from_chars) | std::from_chars 627 MB/s | strtoll/strtoull 339 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 764 MB/s** (+20.1% over std::from_chars) | std::from_chars 636 MB/s | strtoll/strtoull 347 MB/s |
