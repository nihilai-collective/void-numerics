
# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

---

## str-to-int

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **17** | 17 | 14 |
| **std::from_chars** | **17** | 16 | 14 |
| strtoll/strtoull | - | 12 | 2 |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[TIE]` | std::from_chars 95 MB/s `[TIE]` | strtoll/strtoull 76 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **std::from_chars 191 MB/s** (+50.9% over vn::from_chars) | vn::from_chars 126 MB/s | strtoll/strtoull 73 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **std::from_chars 187 MB/s** (+26.9% over vn::from_chars) | vn::from_chars 147 MB/s | strtoll/strtoull 75 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **std::from_chars 185 MB/s** (+24.9% over vn::from_chars) | vn::from_chars 148 MB/s | strtoll/strtoull 76 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[TIE]` | std::from_chars 95 MB/s `[TIE]` | strtoll/strtoull 76 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **std::from_chars 191 MB/s** (+33.3% over vn::from_chars) | vn::from_chars 143 MB/s | strtoll/strtoull 73 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **std::from_chars 187 MB/s** (+29.3% over vn::from_chars) | vn::from_chars 145 MB/s | strtoll/strtoull 78 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **std::from_chars 197 MB/s** (+23.9% over vn::from_chars) | vn::from_chars 159 MB/s | strtoll/strtoull 81 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[3-way TIE]` | strtoll/strtoull 95 MB/s `[3-way TIE]` | std::from_chars 95 MB/s `[3-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 200 MB/s** (+5.0% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 95 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 207 MB/s** (+8.5% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 93 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 210 MB/s** (+10.4% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 94 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[TIE]` | std::from_chars 191 MB/s `[TIE]` | strtoll/strtoull 114 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **std::from_chars 318 MB/s** (+33.3% over vn::from_chars) | vn::from_chars 238 MB/s | strtoll/strtoull 113 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **std::from_chars 309 MB/s** (+34.0% over vn::from_chars) | vn::from_chars 230 MB/s | strtoll/strtoull 118 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **std::from_chars 321 MB/s** (+26.5% over vn::from_chars) | vn::from_chars 254 MB/s | strtoll/strtoull 118 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[TIE]` | std::from_chars 191 MB/s `[TIE]` | strtoll/strtoull 134 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **std::from_chars 318 MB/s** (+33.3% over vn::from_chars) | vn::from_chars 238 MB/s | strtoll/strtoull 127 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **std::from_chars 298 MB/s** (+26.4% over vn::from_chars) | vn::from_chars 236 MB/s | strtoll/strtoull 134 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **std::from_chars 297 MB/s** (+17.5% over vn::from_chars) | vn::from_chars 253 MB/s | strtoll/strtoull 126 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[3-way TIE]` | strtoll/strtoull 191 MB/s `[3-way TIE]` | std::from_chars 191 MB/s `[3-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 477 MB/s** (+22.0% over std::from_chars) | std::from_chars 391 MB/s | strtoll/strtoull 173 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 477 MB/s** (+10.0% over std::from_chars) | std::from_chars 433 MB/s | strtoll/strtoull 187 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 443 MB/s** (+9.7% over std::from_chars) | std::from_chars 404 MB/s | strtoll/strtoull 174 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 191 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | vn::from_chars 347 MB/s `[TIE]` | std::from_chars 347 MB/s `[TIE]` | strtoll/strtoull 182 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **std::from_chars 378 MB/s** (+6.0% over vn::from_chars) | vn::from_chars 357 MB/s | strtoll/strtoull 197 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **std::from_chars 379 MB/s** (+16.3% over vn::from_chars) | vn::from_chars 326 MB/s | strtoll/strtoull 183 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 191 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **std::from_chars 347 MB/s** (+6.2% over vn::from_chars) | vn::from_chars 327 MB/s | strtoll/strtoull 182 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | vn::from_chars 332 MB/s `[TIE]` | std::from_chars 322 MB/s `[TIE]` | strtoll/strtoull 197 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **std::from_chars 364 MB/s** (+9.3% over vn::from_chars) | vn::from_chars 333 MB/s | strtoll/strtoull 181 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 229 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 545 MB/s** (+14.3% over std::from_chars) | std::from_chars 477 MB/s | strtoll/strtoull 227 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 538 MB/s** (+16.8% over std::from_chars) | std::from_chars 461 MB/s | strtoll/strtoull 231 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | std::from_chars 451 MB/s `[TIE]` | vn::from_chars 427 MB/s `[TIE]` | strtoll/strtoull 191 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 763 MB/s** (+66.7% over std::from_chars) | std::from_chars 458 MB/s | strtoll/strtoull 254 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 545 MB/s** (+7.1% over std::from_chars) | std::from_chars 509 MB/s | strtoll/strtoull 263 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 545 MB/s** (+6.5% over std::from_chars) | std::from_chars 512 MB/s | strtoll/strtoull 264 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **std::from_chars 486 MB/s** (+23.1% over vn::from_chars) | vn::from_chars 395 MB/s | strtoll/strtoull 263 MB/s |
| int64-positive-mixed-lengths-test-size[100] | vn::from_chars 572 MB/s `[TIE]` | std::from_chars 496 MB/s `[TIE]` | strtoll/strtoull 254 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 587 MB/s** (+15.4% over std::from_chars) | std::from_chars 509 MB/s | strtoll/strtoull 265 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 570 MB/s** (+11.1% over std::from_chars) | std::from_chars 513 MB/s | strtoll/strtoull 265 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | std::from_chars 535 MB/s `[TIE]` | vn::from_chars 529 MB/s `[TIE]` | strtoll/strtoull 259 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 763 MB/s** (+42.9% over std::from_chars) | std::from_chars 534 MB/s `[TIE]` | strtoll/strtoull 292 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 587 MB/s** (+15.4% over std::from_chars) | std::from_chars 509 MB/s | strtoll/strtoull 293 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 591 MB/s** (+17.0% over std::from_chars) | std::from_chars 506 MB/s | strtoll/strtoull 294 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 533 MB/s** (+10.9% over std::from_chars) | std::from_chars 480 MB/s | strtoll/strtoull 265 MB/s |

