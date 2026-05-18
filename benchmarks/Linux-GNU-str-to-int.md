
# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** GNU 16.0.1

---

## str-to-int

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **33** | 8 | 7 |
| std::from_chars | 8 | 33 | 7 |
| strtoll/strtoull | - | 7 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 193 MB/s** (+23.8% over std::from_chars) | std::from_chars 156 MB/s | strtoll/strtoull 89 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 202 MB/s** (+20.6% over std::from_chars) | std::from_chars 168 MB/s | strtoll/strtoull 90 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 199 MB/s** (+18.8% over std::from_chars) | std::from_chars 168 MB/s | strtoll/strtoull 90 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 192 MB/s** (+16.6% over std::from_chars) | std::from_chars 165 MB/s | strtoll/strtoull 90 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 187 MB/s** (+16.9% over std::from_chars) | std::from_chars 160 MB/s | strtoll/strtoull 94 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 198 MB/s** (+16.6% over std::from_chars) | std::from_chars 169 MB/s | strtoll/strtoull 92 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 200 MB/s** (+18.0% over std::from_chars) | std::from_chars 170 MB/s | strtoll/strtoull 93 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 197 MB/s** (+22.8% over std::from_chars) | std::from_chars 161 MB/s | strtoll/strtoull 91 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 265 MB/s `[TIE]` | std::from_chars 233 MB/s `[TIE]` | strtoll/strtoull 111 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 285 MB/s** (+11.8% over std::from_chars) | std::from_chars 255 MB/s | strtoll/strtoull 112 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 282 MB/s** (+12.3% over std::from_chars) | std::from_chars 251 MB/s | strtoll/strtoull 106 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 275 MB/s** (+10.0% over std::from_chars) | std::from_chars 250 MB/s | strtoll/strtoull 109 MB/s |
| int16-negative-mixed-lengths-test-size[100] | std::from_chars 306 MB/s `[TIE]` | vn::from_chars 284 MB/s `[TIE]` | strtoll/strtoull 155 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | std::from_chars 302 MB/s `[TIE]` | vn::from_chars 294 MB/s `[TIE]` | strtoll/strtoull 157 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **std::from_chars 301 MB/s** (+5.3% over vn::from_chars) | vn::from_chars 286 MB/s | strtoll/strtoull 153 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | std::from_chars 300 MB/s `[TIE]` | vn::from_chars 283 MB/s `[TIE]` | strtoll/strtoull 148 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::from_chars 284 MB/s `[TIE]` | std::from_chars 281 MB/s `[TIE]` | strtoll/strtoull 154 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **std::from_chars 313 MB/s** (+7.2% over vn::from_chars) | vn::from_chars 292 MB/s | strtoll/strtoull 153 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **std::from_chars 295 MB/s** (+7.0% over vn::from_chars) | vn::from_chars 276 MB/s | strtoll/strtoull 150 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **std::from_chars 297 MB/s** (+6.8% over vn::from_chars) | vn::from_chars 278 MB/s | strtoll/strtoull 151 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **std::from_chars 591 MB/s** (+19.4% over vn::from_chars) | vn::from_chars 495 MB/s | strtoll/strtoull 203 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **std::from_chars 663 MB/s** (+24.8% over vn::from_chars) | vn::from_chars 531 MB/s | strtoll/strtoull 211 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **std::from_chars 598 MB/s** (+14.1% over vn::from_chars) | vn::from_chars 524 MB/s | strtoll/strtoull 204 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **std::from_chars 664 MB/s** (+30.2% over vn::from_chars) | vn::from_chars 510 MB/s | strtoll/strtoull 195 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 464 MB/s** (+16.7% over std::from_chars) | std::from_chars 398 MB/s | strtoll/strtoull 239 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 469 MB/s** (+11.4% over std::from_chars) | std::from_chars 421 MB/s | strtoll/strtoull 244 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 442 MB/s** (+13.7% over std::from_chars) | std::from_chars 389 MB/s | strtoll/strtoull 238 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 464 MB/s** (+14.1% over std::from_chars) | std::from_chars 407 MB/s | strtoll/strtoull 236 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 481 MB/s** (+13.5% over std::from_chars) | std::from_chars 424 MB/s | strtoll/strtoull 250 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 446 MB/s** (+7.5% over std::from_chars) | std::from_chars 414 MB/s | strtoll/strtoull 238 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 462 MB/s** (+9.5% over std::from_chars) | std::from_chars 422 MB/s | strtoll/strtoull 242 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 473 MB/s** (+15.0% over std::from_chars) | std::from_chars 412 MB/s | strtoll/strtoull 236 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 870 MB/s** (+31.2% over std::from_chars) | std::from_chars 663 MB/s | strtoll/strtoull 229 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 870 MB/s** (+17.9% over std::from_chars) | std::from_chars 738 MB/s | strtoll/strtoull 231 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 785 MB/s** (+17.0% over std::from_chars) | std::from_chars 670 MB/s | strtoll/strtoull 225 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | vn::from_chars 777 MB/s `[TIE]` | std::from_chars 726 MB/s `[TIE]` | strtoll/strtoull 229 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 831 MB/s** (+19.8% over std::from_chars) | std::from_chars 693 MB/s | strtoll/strtoull 313 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 846 MB/s** (+15.0% over std::from_chars) | std::from_chars 736 MB/s | strtoll/strtoull 231 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 783 MB/s** (+7.2% over std::from_chars) | std::from_chars 731 MB/s | strtoll/strtoull 327 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 805 MB/s** (+11.5% over std::from_chars) | std::from_chars 723 MB/s | strtoll/strtoull 328 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 805 MB/s** (+14.4% over std::from_chars) | std::from_chars 704 MB/s | strtoll/strtoull 359 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 839 MB/s** (+20.8% over std::from_chars) | std::from_chars 695 MB/s | strtoll/strtoull 399 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 817 MB/s** (+14.4% over std::from_chars) | std::from_chars 714 MB/s | strtoll/strtoull 327 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 810 MB/s** (+13.5% over std::from_chars) | std::from_chars 714 MB/s | strtoll/strtoull 330 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 857 MB/s** (+14.2% over std::from_chars) | std::from_chars 750 MB/s | strtoll/strtoull 338 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 866 MB/s** (+10.8% over std::from_chars) | std::from_chars 781 MB/s | strtoll/strtoull 342 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 849 MB/s** (+6.7% over std::from_chars) | std::from_chars 795 MB/s | strtoll/strtoull 348 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | vn::from_chars 814 MB/s `[TIE]` | std::from_chars 782 MB/s `[TIE]` | strtoll/strtoull 346 MB/s |

