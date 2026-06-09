# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** Clang 23.0.0

---

## str-to-int

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **43** | - | 5 |
| std::from_chars | - | 43 | 5 |
| strtoll/strtoull | - | 5 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 160 MB/s `[TIE]` | std::from_chars 143 MB/s `[TIE]` | strtoll/strtoull 92 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 172 MB/s** (+17.7% over std::from_chars) | std::from_chars 146 MB/s | strtoll/strtoull 90 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 166 MB/s** (+12.9% over std::from_chars) | std::from_chars 147 MB/s | strtoll/strtoull 94 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 167 MB/s** (+20.5% over std::from_chars) | std::from_chars 139 MB/s | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 160 MB/s `[TIE]` | std::from_chars 145 MB/s `[TIE]` | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 170 MB/s** (+16.4% over std::from_chars) | std::from_chars 146 MB/s | strtoll/strtoull 92 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 167 MB/s** (+18.0% over std::from_chars) | std::from_chars 141 MB/s | strtoll/strtoull 90 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 168 MB/s** (+16.7% over std::from_chars) | std::from_chars 144 MB/s | strtoll/strtoull 91 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | std::from_chars 239 MB/s `[TIE]` | vn::from_chars 232 MB/s `[TIE]` | strtoll/strtoull 102 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | vn::from_chars 252 MB/s `[TIE]` | std::from_chars 240 MB/s `[TIE]` | strtoll/strtoull 123 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 247 MB/s** (+2.9% over std::from_chars) | std::from_chars 240 MB/s | strtoll/strtoull 115 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 250 MB/s** (+8.5% over std::from_chars) | std::from_chars 230 MB/s | strtoll/strtoull 109 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 271 MB/s** (+16.9% over std::from_chars) | std::from_chars 232 MB/s | strtoll/strtoull 156 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 282 MB/s** (+14.5% over std::from_chars) | std::from_chars 246 MB/s | strtoll/strtoull 154 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 275 MB/s** (+15.2% over std::from_chars) | std::from_chars 239 MB/s | strtoll/strtoull 155 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 271 MB/s** (+12.9% over std::from_chars) | std::from_chars 240 MB/s | strtoll/strtoull 153 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 267 MB/s** (+16.0% over std::from_chars) | std::from_chars 230 MB/s | strtoll/strtoull 156 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 278 MB/s** (+12.7% over std::from_chars) | std::from_chars 247 MB/s | strtoll/strtoull 154 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 263 MB/s** (+11.5% over std::from_chars) | std::from_chars 236 MB/s | strtoll/strtoull 156 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 275 MB/s** (+15.2% over std::from_chars) | std::from_chars 239 MB/s | strtoll/strtoull 155 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::from_chars 579 MB/s `[TIE]` | std::from_chars 528 MB/s `[TIE]` | strtoll/strtoull 202 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 627 MB/s** (+11.0% over std::from_chars) | std::from_chars 565 MB/s | strtoll/strtoull 208 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 608 MB/s** (+15.0% over std::from_chars) | std::from_chars 529 MB/s | strtoll/strtoull 207 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 616 MB/s** (+10.4% over std::from_chars) | std::from_chars 558 MB/s | strtoll/strtoull 201 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 416 MB/s** (+32.2% over std::from_chars) | std::from_chars 315 MB/s | strtoll/strtoull 240 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 412 MB/s** (+28.1% over std::from_chars) | std::from_chars 322 MB/s | strtoll/strtoull 242 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 415 MB/s** (+28.9% over std::from_chars) | std::from_chars 322 MB/s | strtoll/strtoull 249 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 405 MB/s** (+22.8% over std::from_chars) | std::from_chars 330 MB/s | strtoll/strtoull 251 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 419 MB/s** (+27.5% over std::from_chars) | std::from_chars 329 MB/s | strtoll/strtoull 236 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 422 MB/s** (+27.2% over std::from_chars) | std::from_chars 332 MB/s | strtoll/strtoull 256 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 409 MB/s** (+25.7% over std::from_chars) | std::from_chars 325 MB/s | strtoll/strtoull 249 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 412 MB/s** (+25.1% over std::from_chars) | std::from_chars 330 MB/s | strtoll/strtoull 251 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 719 MB/s** (+24.7% over std::from_chars) | std::from_chars 577 MB/s | strtoll/strtoull 227 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 754 MB/s** (+23.3% over std::from_chars) | std::from_chars 611 MB/s | strtoll/strtoull 229 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 707 MB/s** (+25.6% over std::from_chars) | std::from_chars 563 MB/s | strtoll/strtoull 232 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 746 MB/s** (+25.4% over std::from_chars) | std::from_chars 595 MB/s | strtoll/strtoull 231 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 727 MB/s** (+32.2% over std::from_chars) | std::from_chars 550 MB/s | strtoll/strtoull 418 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 769 MB/s** (+25.1% over std::from_chars) | std::from_chars 615 MB/s | strtoll/strtoull 337 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 735 MB/s** (+39.7% over std::from_chars) | std::from_chars 526 MB/s | strtoll/strtoull 408 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 744 MB/s** (+30.4% over std::from_chars) | std::from_chars 571 MB/s | strtoll/strtoull 415 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 750 MB/s** (+35.0% over std::from_chars) | std::from_chars 556 MB/s | strtoll/strtoull 404 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 757 MB/s** (+22.8% over std::from_chars) | std::from_chars 616 MB/s | strtoll/strtoull 367 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 730 MB/s** (+22.7% over std::from_chars) | std::from_chars 595 MB/s | strtoll/strtoull 413 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 737 MB/s** (+24.2% over std::from_chars) | std::from_chars 594 MB/s | strtoll/strtoull 419 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 753 MB/s** (+20.8% over std::from_chars) | std::from_chars 623 MB/s | strtoll/strtoull 354 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 756 MB/s** (+36.2% over std::from_chars) | std::from_chars 555 MB/s | strtoll/strtoull 351 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 719 MB/s** (+34.7% over std::from_chars) | std::from_chars 534 MB/s | strtoll/strtoull 333 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 745 MB/s** (+21.9% over std::from_chars) | std::from_chars 612 MB/s | strtoll/strtoull 342 MB/s |
