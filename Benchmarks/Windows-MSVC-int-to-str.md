# void-numerics Benchmark Results  
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Windows 10.0.26200  
**Compiler:** MSVC 19.44.35227.0  

---
### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **34** | 3 | 11 |
| jeaiii::to_text | 3 | 30 | 11 |
| fmt::format_to | - | 12 | - |


---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 477 MB/s `[TIE]` | vn::to_chars 477 MB/s `[TIE]` | fmt::format_to 238 MB/s | std::to_chars 191 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | jeaiii::to_text 564 MB/s `[TIE]` | vn::to_chars 549 MB/s `[TIE]` | fmt::format_to 276 MB/s | std::to_chars 205 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | vn::to_chars 586 MB/s `[TIE]` | jeaiii::to_text 564 MB/s `[TIE]` | fmt::format_to 280 MB/s | std::to_chars 206 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 588 MB/s `[TIE]` | vn::to_chars 584 MB/s `[TIE]` | fmt::format_to 277 MB/s | std::to_chars 206 MB/s |
| int8-positive-mixed-lengths-test-size[100] | jeaiii::to_text 477 MB/s `[TIE]` | vn::to_chars 477 MB/s `[TIE]` | fmt::format_to 318 MB/s | std::to_chars 238 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | vn::to_chars 718 MB/s `[TIE]` | jeaiii::to_text 658 MB/s `[TIE]` | fmt::format_to 368 MB/s | std::to_chars 245 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | vn::to_chars 682 MB/s `[TIE]` | jeaiii::to_text 657 MB/s `[TIE]` | fmt::format_to 384 MB/s | std::to_chars 246 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 669 MB/s `[TIE]` | vn::to_chars 661 MB/s `[TIE]` | fmt::format_to 379 MB/s | std::to_chars 241 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::to_chars 525 MB/s** (+10.0% over jeaiii::to_text) | jeaiii::to_text 477 MB/s `[TIE]` | fmt::format_to 477 MB/s `[TIE]` | std::to_chars 238 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 707 MB/s `[TIE]` | vn::to_chars 645 MB/s `[TIE]` | fmt::format_to 575 MB/s | std::to_chars 245 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | vn::to_chars 734 MB/s `[TIE]` | jeaiii::to_text 724 MB/s `[TIE]` | fmt::format_to 573 MB/s | std::to_chars 246 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 721 MB/s** (+18.3% over vn::to_chars) | vn::to_chars 610 MB/s | fmt::format_to 572 MB/s | std::to_chars 246 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::to_chars 954 MB/s** (+50.0% over jeaiii::to_text) | jeaiii::to_text 636 MB/s | fmt::format_to 381 MB/s | std::to_chars 272 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1021 MB/s** (+39.1% over jeaiii::to_text) | jeaiii::to_text 734 MB/s | fmt::format_to 457 MB/s | std::to_chars 300 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 892 MB/s** (+17.8% over jeaiii::to_text) | jeaiii::to_text 757 MB/s | fmt::format_to 466 MB/s | std::to_chars 310 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 968 MB/s** (+32.2% over jeaiii::to_text) | jeaiii::to_text 732 MB/s | fmt::format_to 463 MB/s | std::to_chars 307 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::to_chars 954 MB/s** (+36.4% over jeaiii::to_text) | jeaiii::to_text 699 MB/s `[TIE]` | fmt::format_to 525 MB/s `[TIE]` | std::to_chars 324 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1216 MB/s** (+43.2% over jeaiii::to_text) | jeaiii::to_text 849 MB/s | fmt::format_to 617 MB/s | std::to_chars 383 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 857 MB/s** (+12.2% over vn::to_chars) | vn::to_chars 764 MB/s | std::to_chars 373 MB/s | fmt::format_to 359 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1239 MB/s** (+47.1% over jeaiii::to_text) | jeaiii::to_text 842 MB/s | fmt::format_to 616 MB/s | std::to_chars 382 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::to_chars 1907 MB/s** (+100.0% over fmt::format_to) | fmt::format_to 954 MB/s `[TIE]` | jeaiii::to_text 954 MB/s `[TIE]` | std::to_chars 381 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1518 MB/s** (+24.1% over jeaiii::to_text) | jeaiii::to_text 1224 MB/s | fmt::format_to 1015 MB/s | std::to_chars 362 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1609 MB/s** (+32.6% over jeaiii::to_text) | jeaiii::to_text 1213 MB/s | fmt::format_to 569 MB/s | std::to_chars 412 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 1217 MB/s** (+14.0% over vn::to_chars) | vn::to_chars 1067 MB/s | fmt::format_to 536 MB/s | std::to_chars 412 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::to_chars 1272 MB/s** (+33.3% over jeaiii::to_text) | jeaiii::to_text 954 MB/s | fmt::format_to 636 MB/s | std::to_chars 381 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 930 MB/s** (+47.8% over jeaiii::to_text) | jeaiii::to_text 630 MB/s | fmt::format_to 437 MB/s | std::to_chars 247 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 807 MB/s** (+40.9% over jeaiii::to_text) | jeaiii::to_text 573 MB/s | fmt::format_to 380 MB/s | std::to_chars 223 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 794 MB/s** (+37.2% over jeaiii::to_text) | jeaiii::to_text 579 MB/s | fmt::format_to 378 MB/s | std::to_chars 217 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::to_chars 954 MB/s** (+50.0% over jeaiii::to_text) | jeaiii::to_text 636 MB/s | fmt::format_to 477 MB/s | std::to_chars 272 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 994 MB/s** (+41.9% over jeaiii::to_text) | jeaiii::to_text 700 MB/s | fmt::format_to 496 MB/s | std::to_chars 271 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1002 MB/s** (+43.3% over jeaiii::to_text) | jeaiii::to_text 699 MB/s | fmt::format_to 506 MB/s | std::to_chars 271 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1621 MB/s** (+104.8% over fmt::format_to) | fmt::format_to 792 MB/s | jeaiii::to_text 694 MB/s | std::to_chars 270 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | jeaiii::to_text 1907 MB/s `[TIE]` | vn::to_chars 1907 MB/s `[TIE]` | fmt::format_to 1272 MB/s | std::to_chars 545 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2169 MB/s** (+23.3% over jeaiii::to_text) | jeaiii::to_text 1760 MB/s | fmt::format_to 1207 MB/s | std::to_chars 292 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1987 MB/s** (+15.2% over jeaiii::to_text) | jeaiii::to_text 1726 MB/s | fmt::format_to 1194 MB/s | std::to_chars 526 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1205 MB/s** (+21.6% over jeaiii::to_text) | jeaiii::to_text 992 MB/s | fmt::format_to 749 MB/s | std::to_chars 287 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::to_chars 1272 MB/s** (+66.7% over jeaiii::to_text) | jeaiii::to_text 763 MB/s | fmt::format_to 381 MB/s | std::to_chars 231 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1282 MB/s** (+59.7% over jeaiii::to_text) | jeaiii::to_text 803 MB/s | fmt::format_to 390 MB/s | std::to_chars 233 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1310 MB/s** (+65.8% over jeaiii::to_text) | jeaiii::to_text 790 MB/s | fmt::format_to 391 MB/s | std::to_chars 233 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 1298 MB/s** (+63.5% over jeaiii::to_text) | jeaiii::to_text 794 MB/s | fmt::format_to 389 MB/s | std::to_chars 231 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1297 MB/s** (+70.0% over jeaiii::to_text) | jeaiii::to_text 763 MB/s | fmt::format_to 424 MB/s | std::to_chars 246 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1375 MB/s** (+65.4% over jeaiii::to_text) | jeaiii::to_text 831 MB/s | fmt::format_to 432 MB/s | std::to_chars 246 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1371 MB/s** (+65.1% over jeaiii::to_text) | jeaiii::to_text 831 MB/s | fmt::format_to 435 MB/s | std::to_chars 246 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1353 MB/s** (+63.4% over jeaiii::to_text) | jeaiii::to_text 828 MB/s | fmt::format_to 433 MB/s | std::to_chars 245 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1272 MB/s** (+50.0% over jeaiii::to_text) | jeaiii::to_text 848 MB/s | fmt::format_to 426 MB/s | std::to_chars 238 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1332 MB/s** (+46.3% over jeaiii::to_text) | jeaiii::to_text 910 MB/s | fmt::format_to 429 MB/s | std::to_chars 237 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1342 MB/s** (+46.3% over jeaiii::to_text) | jeaiii::to_text 917 MB/s | fmt::format_to 433 MB/s | std::to_chars 237 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1334 MB/s** (+46.4% over jeaiii::to_text) | jeaiii::to_text 912 MB/s | fmt::format_to 431 MB/s | std::to_chars 236 MB/s |
