# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

----
### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **38** | - | 10 |
| std::from_chars | - | 36 | 10 |
| strtoll/strtoull | - | 3 | 7 |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[3-way TIE]` | strtoll/strtoull 95 MB/s `[3-way TIE]` | std::from_chars 95 MB/s `[3-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 477 MB/s** (+42.9% over std::from_chars) | std::from_chars 334 MB/s | strtoll/strtoull 126 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 456 MB/s** (+33.0% over std::from_chars) | std::from_chars 343 MB/s | strtoll/strtoull 122 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 448 MB/s** (+30.0% over std::from_chars) | std::from_chars 345 MB/s | strtoll/strtoull 129 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[3-way TIE]` | strtoll/strtoull 95 MB/s `[3-way TIE]` | std::from_chars 95 MB/s `[3-way TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 477 MB/s** (+42.9% over std::from_chars) | std::from_chars 334 MB/s | strtoll/strtoull 119 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 502 MB/s** (+42.1% over std::from_chars) | std::from_chars 353 MB/s | strtoll/strtoull 134 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 511 MB/s** (+44.1% over std::from_chars) | std::from_chars 355 MB/s | strtoll/strtoull 134 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 95 MB/s `[3-way TIE]` | strtoll/strtoull 95 MB/s `[3-way TIE]` | std::from_chars 95 MB/s `[3-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 477 MB/s** (+20.0% over std::from_chars) | std::from_chars 397 MB/s | strtoll/strtoull 128 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 477 MB/s** (+17.4% over std::from_chars) | std::from_chars 406 MB/s | strtoll/strtoull 131 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 449 MB/s** (+9.1% over std::from_chars) | std::from_chars 411 MB/s | strtoll/strtoull 131 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[3-way TIE]` | strtoll/strtoull 191 MB/s `[3-way TIE]` | std::from_chars 191 MB/s `[3-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 493 MB/s** (+3.3% over std::from_chars) | std::from_chars 477 MB/s | strtoll/strtoull 193 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 515 MB/s** (+10.8% over std::from_chars) | std::from_chars 465 MB/s | strtoll/strtoull 197 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 518 MB/s** (+12.2% over std::from_chars) | std::from_chars 462 MB/s | strtoll/strtoull 197 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[3-way TIE]` | strtoll/strtoull 191 MB/s `[3-way TIE]` | std::from_chars 191 MB/s `[3-way TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 540 MB/s** (+13.3% over std::from_chars) | std::from_chars 477 MB/s | strtoll/strtoull 201 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 551 MB/s** (+21.1% over std::from_chars) | std::from_chars 455 MB/s | strtoll/strtoull 204 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 557 MB/s** (+18.4% over std::from_chars) | std::from_chars 470 MB/s | strtoll/strtoull 204 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::from_chars 191 MB/s `[3-way TIE]` | strtoll/strtoull 191 MB/s `[3-way TIE]` | std::from_chars 191 MB/s `[3-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 636 MB/s** (+33.3% over std::from_chars) | std::from_chars 477 MB/s | strtoll/strtoull 201 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 604 MB/s** (+13.0% over std::from_chars) | std::from_chars 534 MB/s | strtoll/strtoull 204 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 608 MB/s** (+13.2% over std::from_chars) | std::from_chars 537 MB/s | strtoll/strtoull 204 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 267 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 581 MB/s** (+6.7% over std::from_chars) | std::from_chars 545 MB/s | strtoll/strtoull 265 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 608 MB/s** (+16.4% over std::from_chars) | std::from_chars 523 MB/s | strtoll/strtoull 268 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 610 MB/s** (+23.9% over std::from_chars) | std::from_chars 493 MB/s | strtoll/strtoull 268 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[3-way TIE]` | strtoll/strtoull 381 MB/s `[3-way TIE]` | std::from_chars 381 MB/s `[3-way TIE]` |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 636 MB/s** (+26.1% over std::from_chars) | std::from_chars 504 MB/s | strtoll/strtoull 272 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 636 MB/s** (+21.0% over std::from_chars) | std::from_chars 525 MB/s | strtoll/strtoull 273 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 633 MB/s** (+20.2% over std::from_chars) | std::from_chars 526 MB/s | strtoll/strtoull 274 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::from_chars 381 MB/s `[TIE]` | std::from_chars 381 MB/s `[TIE]` | strtoll/strtoull 267 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 636 MB/s** (+16.7% over std::from_chars) | std::from_chars 545 MB/s | strtoll/strtoull 272 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 658 MB/s** (+13.8% over std::from_chars) | std::from_chars 578 MB/s | strtoll/strtoull 273 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 658 MB/s** (+13.8% over std::from_chars) | std::from_chars 579 MB/s | strtoll/strtoull 272 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 763 MB/s** (+42.9% over std::from_chars) | std::from_chars 534 MB/s `[TIE]` | strtoll/strtoull 318 MB/s `[TIE]` |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 694 MB/s** (+23.5% over std::from_chars) | std::from_chars 562 MB/s | strtoll/strtoull 322 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 706 MB/s** (+24.6% over std::from_chars) | std::from_chars 567 MB/s | strtoll/strtoull 324 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 680 MB/s** (+21.8% over std::from_chars) | std::from_chars 559 MB/s | strtoll/strtoull 322 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 763 MB/s** (+42.9% over std::from_chars) | std::from_chars 534 MB/s `[TIE]` | strtoll/strtoull 318 MB/s `[TIE]` |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 707 MB/s** (+20.5% over std::from_chars) | std::from_chars 587 MB/s | strtoll/strtoull 319 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 720 MB/s** (+26.8% over std::from_chars) | std::from_chars 568 MB/s | strtoll/strtoull 326 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 690 MB/s** (+22.5% over std::from_chars) | std::from_chars 563 MB/s | strtoll/strtoull 324 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | vn::from_chars 763 MB/s `[TIE]` | std::from_chars 763 MB/s `[TIE]` | strtoll/strtoull 292 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 707 MB/s** (+16.7% over std::from_chars) | std::from_chars 606 MB/s | strtoll/strtoull 305 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 720 MB/s** (+17.3% over std::from_chars) | std::from_chars 614 MB/s | strtoll/strtoull 305 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 689 MB/s** (+13.6% over std::from_chars) | std::from_chars 607 MB/s | strtoll/strtoull 302 MB/s |
