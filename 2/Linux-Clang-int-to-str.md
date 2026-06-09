# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** Clang 23.0.0  

---

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **28** | 3 | 17 |
| jeaiii::to_text | 3 | 27 | 17 |
| std::to_chars | - | 1 | 3 |
| fmt::format_to | - | 9 | 4 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 395 MB/s `[TIE]` | vn::to_chars 321 MB/s `[TIE]` | fmt::format_to 223 MB/s | std::to_chars 170 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 451 MB/s** (+18.8% over vn::to_chars) | vn::to_chars 380 MB/s | fmt::format_to 230 MB/s | std::to_chars 182 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **jeaiii::to_text 427 MB/s** (+6.9% over vn::to_chars) | vn::to_chars 399 MB/s | fmt::format_to 233 MB/s | std::to_chars 182 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 426 MB/s `[TIE]` | vn::to_chars 392 MB/s `[TIE]` | fmt::format_to 231 MB/s | std::to_chars 177 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 358 MB/s `[TIE]` | jeaiii::to_text 328 MB/s `[TIE]` | fmt::format_to 219 MB/s | std::to_chars 172 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 442 MB/s** (+17.3% over vn::to_chars) | vn::to_chars 376 MB/s | fmt::format_to 236 MB/s | std::to_chars 182 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 416 MB/s `[TIE]` | vn::to_chars 400 MB/s `[TIE]` | fmt::format_to 231 MB/s | std::to_chars 183 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 415 MB/s `[TIE]` | vn::to_chars 396 MB/s `[TIE]` | fmt::format_to 234 MB/s | std::to_chars 178 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | fmt::format_to 311 MB/s `[3-way TIE]` | jeaiii::to_text 311 MB/s `[3-way TIE]` | vn::to_chars 307 MB/s `[3-way TIE]` | std::to_chars 216 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | std::to_chars 362 MB/s `[4-way TIE]` | jeaiii::to_text 358 MB/s `[4-way TIE]` | vn::to_chars 351 MB/s `[4-way TIE]` | fmt::format_to 333 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::to_chars 385 MB/s** (+4.6% over jeaiii::to_text) | jeaiii::to_text 368 MB/s | fmt::format_to 348 MB/s | std::to_chars 231 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | vn::to_chars 375 MB/s `[4-way TIE]` | std::to_chars 367 MB/s `[4-way TIE]` | jeaiii::to_text 362 MB/s `[4-way TIE]` | fmt::format_to 338 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 686 MB/s `[TIE]` | jeaiii::to_text 576 MB/s `[TIE]` | fmt::format_to 325 MB/s `[TIE]` | std::to_chars 308 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | vn::to_chars 760 MB/s `[TIE]` | jeaiii::to_text 709 MB/s `[TIE]` | fmt::format_to 326 MB/s `[TIE]` | std::to_chars 316 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[10000] | vn::to_chars 675 MB/s `[TIE]` | jeaiii::to_text 665 MB/s `[TIE]` | fmt::format_to 342 MB/s | std::to_chars 321 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 771 MB/s** (+9.5% over jeaiii::to_text) | jeaiii::to_text 704 MB/s | fmt::format_to 338 MB/s | std::to_chars 312 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 697 MB/s `[TIE]` | jeaiii::to_text 601 MB/s `[TIE]` | fmt::format_to 309 MB/s `[TIE]` | std::to_chars 304 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 795 MB/s** (+18.3% over jeaiii::to_text) | jeaiii::to_text 672 MB/s | fmt::format_to 340 MB/s | std::to_chars 318 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 793 MB/s** (+9.1% over jeaiii::to_text) | jeaiii::to_text 727 MB/s | fmt::format_to 342 MB/s | std::to_chars 318 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 774 MB/s** (+9.1% over jeaiii::to_text) | jeaiii::to_text 710 MB/s | fmt::format_to 340 MB/s | std::to_chars 316 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 1224 MB/s `[TIE]` | jeaiii::to_text 1078 MB/s `[TIE]` | std::to_chars 719 MB/s `[TIE]` | fmt::format_to 709 MB/s `[TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1247 MB/s** (+55.8% over fmt::format_to) | fmt::format_to 801 MB/s `[3-way TIE]` | jeaiii::to_text 768 MB/s `[3-way TIE]` | std::to_chars 758 MB/s `[3-way TIE]` |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1311 MB/s** (+14.4% over jeaiii::to_text) | jeaiii::to_text 1146 MB/s | fmt::format_to 801 MB/s | std::to_chars 737 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1317 MB/s** (+13.2% over jeaiii::to_text) | jeaiii::to_text 1164 MB/s | fmt::format_to 783 MB/s `[TIE]` | std::to_chars 731 MB/s `[TIE]` |
| int32-negative-mixed-lengths-test-size[100] | vn::to_chars 937 MB/s `[TIE]` | jeaiii::to_text 810 MB/s `[TIE]` | fmt::format_to 485 MB/s | std::to_chars 397 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1012 MB/s** (+18.6% over jeaiii::to_text) | jeaiii::to_text 853 MB/s | fmt::format_to 486 MB/s | std::to_chars 290 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1033 MB/s** (+18.9% over jeaiii::to_text) | jeaiii::to_text 869 MB/s | fmt::format_to 495 MB/s | std::to_chars 415 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 993 MB/s** (+18.9% over jeaiii::to_text) | jeaiii::to_text 835 MB/s | fmt::format_to 486 MB/s | std::to_chars 411 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::to_chars 965 MB/s `[TIE]` | jeaiii::to_text 837 MB/s `[TIE]` | fmt::format_to 464 MB/s | std::to_chars 418 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1004 MB/s** (+16.4% over jeaiii::to_text) | jeaiii::to_text 863 MB/s | fmt::format_to 489 MB/s | std::to_chars 413 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1004 MB/s** (+15.4% over jeaiii::to_text) | jeaiii::to_text 870 MB/s | fmt::format_to 498 MB/s | std::to_chars 401 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1016 MB/s** (+18.8% over jeaiii::to_text) | jeaiii::to_text 855 MB/s | fmt::format_to 488 MB/s | std::to_chars 411 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::to_chars 1409 MB/s `[4-way TIE]` | jeaiii::to_text 1010 MB/s `[4-way TIE]` | fmt::format_to 898 MB/s `[4-way TIE]` | std::to_chars 657 MB/s `[4-way TIE]` |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1459 MB/s** (+19.3% over jeaiii::to_text) | jeaiii::to_text 1223 MB/s | fmt::format_to 944 MB/s | std::to_chars 742 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1533 MB/s** (+17.8% over jeaiii::to_text) | jeaiii::to_text 1301 MB/s | fmt::format_to 937 MB/s | std::to_chars 727 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1662 MB/s** (+29.6% over jeaiii::to_text) | jeaiii::to_text 1283 MB/s | fmt::format_to 958 MB/s | std::to_chars 730 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::to_chars 2714 MB/s** (+66.0% over jeaiii::to_text) | jeaiii::to_text 1636 MB/s | fmt::format_to 792 MB/s | std::to_chars 696 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 2790 MB/s** (+68.7% over jeaiii::to_text) | jeaiii::to_text 1653 MB/s | fmt::format_to 866 MB/s | std::to_chars 709 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 2753 MB/s** (+42.1% over jeaiii::to_text) | jeaiii::to_text 1938 MB/s | fmt::format_to 900 MB/s | std::to_chars 695 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 2836 MB/s** (+48.4% over jeaiii::to_text) | jeaiii::to_text 1911 MB/s | fmt::format_to 847 MB/s | std::to_chars 696 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 2701 MB/s** (+45.4% over jeaiii::to_text) | jeaiii::to_text 1858 MB/s | fmt::format_to 837 MB/s | std::to_chars 639 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2857 MB/s** (+49.2% over jeaiii::to_text) | jeaiii::to_text 1914 MB/s | fmt::format_to 852 MB/s | std::to_chars 696 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2733 MB/s** (+42.6% over jeaiii::to_text) | jeaiii::to_text 1916 MB/s | fmt::format_to 835 MB/s | std::to_chars 698 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 2817 MB/s** (+46.6% over jeaiii::to_text) | jeaiii::to_text 1922 MB/s | fmt::format_to 875 MB/s | std::to_chars 706 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | vn::to_chars 1652 MB/s `[TIE]` | jeaiii::to_text 1333 MB/s `[TIE]` | fmt::format_to 738 MB/s | std::to_chars 634 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1717 MB/s** (+24.9% over jeaiii::to_text) | jeaiii::to_text 1375 MB/s | fmt::format_to 738 MB/s | std::to_chars 682 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1692 MB/s** (+22.4% over jeaiii::to_text) | jeaiii::to_text 1383 MB/s | fmt::format_to 728 MB/s | std::to_chars 678 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1675 MB/s** (+27.3% over jeaiii::to_text) | jeaiii::to_text 1316 MB/s | fmt::format_to 726 MB/s | std::to_chars 658 MB/s |
