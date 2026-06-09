# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** GNU 16.0.1  

---
### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **32** | 9 | 7 |
| std::from_chars | 9 | 32 | 7 |
| strtoll/strtoull | - | 7 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 187 MB/s** (+18.7% over std::from_chars) | std::from_chars 157 MB/s | strtoll/strtoull 90 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 193 MB/s** (+12.6% over std::from_chars) | std::from_chars 171 MB/s | strtoll/strtoull 90 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 196 MB/s** (+12.8% over std::from_chars) | std::from_chars 174 MB/s | strtoll/strtoull 89 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 197 MB/s** (+17.1% over std::from_chars) | std::from_chars 169 MB/s | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 185 MB/s** (+20.2% over std::from_chars) | std::from_chars 154 MB/s | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 199 MB/s** (+16.8% over std::from_chars) | std::from_chars 170 MB/s | strtoll/strtoull 91 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 200 MB/s** (+16.5% over std::from_chars) | std::from_chars 172 MB/s | strtoll/strtoull 92 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 197 MB/s** (+14.8% over std::from_chars) | std::from_chars 171 MB/s | strtoll/strtoull 91 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 249 MB/s `[TIE]` | std::from_chars 244 MB/s `[TIE]` | strtoll/strtoull 112 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | vn::from_chars 269 MB/s `[TIE]` | std::from_chars 255 MB/s `[TIE]` | strtoll/strtoull 114 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 288 MB/s** (+11.8% over std::from_chars) | std::from_chars 257 MB/s | strtoll/strtoull 111 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 282 MB/s** (+14.2% over std::from_chars) | std::from_chars 247 MB/s | strtoll/strtoull 111 MB/s |
| int16-negative-mixed-lengths-test-size[100] | std::from_chars 301 MB/s `[TIE]` | vn::from_chars 268 MB/s `[TIE]` | strtoll/strtoull 157 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **std::from_chars 308 MB/s** (+5.8% over vn::from_chars) | vn::from_chars 291 MB/s | strtoll/strtoull 155 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **std::from_chars 312 MB/s** (+11.1% over vn::from_chars) | vn::from_chars 281 MB/s | strtoll/strtoull 158 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **std::from_chars 304 MB/s** (+6.1% over vn::from_chars) | vn::from_chars 286 MB/s | strtoll/strtoull 151 MB/s |
| int16-positive-mixed-lengths-test-size[100] | std::from_chars 302 MB/s `[TIE]` | vn::from_chars 278 MB/s `[TIE]` | strtoll/strtoull 153 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | std::from_chars 297 MB/s `[TIE]` | vn::from_chars 286 MB/s `[TIE]` | strtoll/strtoull 157 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **std::from_chars 311 MB/s** (+8.0% over vn::from_chars) | vn::from_chars 288 MB/s | strtoll/strtoull 153 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **std::from_chars 308 MB/s** (+8.5% over vn::from_chars) | vn::from_chars 284 MB/s | strtoll/strtoull 153 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **std::from_chars 622 MB/s** (+24.9% over vn::from_chars) | vn::from_chars 498 MB/s | strtoll/strtoull 198 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **std::from_chars 658 MB/s** (+22.4% over vn::from_chars) | vn::from_chars 537 MB/s | strtoll/strtoull 206 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **std::from_chars 663 MB/s** (+23.5% over vn::from_chars) | vn::from_chars 536 MB/s | strtoll/strtoull 214 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **std::from_chars 658 MB/s** (+22.7% over vn::from_chars) | vn::from_chars 536 MB/s | strtoll/strtoull 202 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 461 MB/s** (+20.9% over std::from_chars) | std::from_chars 382 MB/s | strtoll/strtoull 239 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 475 MB/s** (+12.9% over std::from_chars) | std::from_chars 420 MB/s | strtoll/strtoull 249 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 465 MB/s** (+11.1% over std::from_chars) | std::from_chars 418 MB/s | strtoll/strtoull 249 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 467 MB/s** (+11.8% over std::from_chars) | std::from_chars 418 MB/s | strtoll/strtoull 240 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::from_chars 442 MB/s `[TIE]` | std::from_chars 397 MB/s `[TIE]` | strtoll/strtoull 234 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 472 MB/s** (+11.5% over std::from_chars) | std::from_chars 424 MB/s | strtoll/strtoull 248 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 467 MB/s** (+11.4% over std::from_chars) | std::from_chars 419 MB/s | strtoll/strtoull 240 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 466 MB/s** (+10.8% over std::from_chars) | std::from_chars 420 MB/s | strtoll/strtoull 240 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 789 MB/s** (+14.5% over std::from_chars) | std::from_chars 689 MB/s | strtoll/strtoull 226 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 875 MB/s** (+16.7% over std::from_chars) | std::from_chars 749 MB/s | strtoll/strtoull 232 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 851 MB/s** (+21.4% over std::from_chars) | std::from_chars 701 MB/s | strtoll/strtoull 230 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 870 MB/s** (+18.2% over std::from_chars) | std::from_chars 736 MB/s | strtoll/strtoull 229 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 816 MB/s** (+9.6% over std::from_chars) | std::from_chars 744 MB/s | strtoll/strtoull 363 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 830 MB/s** (+10.1% over std::from_chars) | std::from_chars 754 MB/s | strtoll/strtoull 422 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 822 MB/s** (+10.3% over std::from_chars) | std::from_chars 745 MB/s | strtoll/strtoull 404 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 816 MB/s** (+7.5% over std::from_chars) | std::from_chars 759 MB/s | strtoll/strtoull 336 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 804 MB/s** (+9.5% over std::from_chars) | std::from_chars 734 MB/s | strtoll/strtoull 334 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 834 MB/s** (+8.6% over std::from_chars) | std::from_chars 768 MB/s | strtoll/strtoull 340 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 811 MB/s** (+7.7% over std::from_chars) | std::from_chars 753 MB/s | strtoll/strtoull 337 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 818 MB/s** (+9.5% over std::from_chars) | std::from_chars 747 MB/s | strtoll/strtoull 397 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | vn::from_chars 818 MB/s `[TIE]` | std::from_chars 766 MB/s `[TIE]` | strtoll/strtoull 332 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 837 MB/s** (+4.5% over std::from_chars) | std::from_chars 801 MB/s | strtoll/strtoull 353 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 835 MB/s** (+4.1% over std::from_chars) | std::from_chars 803 MB/s | strtoll/strtoull 337 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 836 MB/s** (+6.2% over std::from_chars) | std::from_chars 787 MB/s | strtoll/strtoull 341 MB/s |
