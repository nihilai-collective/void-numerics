# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2  
**Compiler:** GNU 16.0.1  

---

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **28** | 1 | 17 |
| jeaiii::to_text | 2 | 26 | 18 |
| fmt::format_to | - | 12 | 2 |
| std::to_chars | - | 4 | - |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 352 MB/s `[TIE]` | vn::to_chars 351 MB/s `[TIE]` | fmt::format_to 187 MB/s `[TIE]` | std::to_chars 173 MB/s `[TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | **vn::to_chars 416 MB/s** (+51.3% over jeaiii::to_text) | jeaiii::to_text 275 MB/s | fmt::format_to 211 MB/s | std::to_chars 201 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | jeaiii::to_text 432 MB/s `[TIE]` | vn::to_chars 422 MB/s `[TIE]` | std::to_chars 198 MB/s | fmt::format_to 158 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | vn::to_chars 421 MB/s `[TIE]` | jeaiii::to_text 410 MB/s `[TIE]` | fmt::format_to 213 MB/s | std::to_chars 199 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 392 MB/s `[TIE]` | jeaiii::to_text 367 MB/s `[TIE]` | fmt::format_to 198 MB/s `[TIE]` | std::to_chars 181 MB/s `[TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 421 MB/s `[TIE]` | vn::to_chars 394 MB/s `[TIE]` | fmt::format_to 211 MB/s | std::to_chars 199 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 429 MB/s `[TIE]` | vn::to_chars 419 MB/s `[TIE]` | std::to_chars 188 MB/s | fmt::format_to 157 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::to_chars 420 MB/s** (+32.7% over jeaiii::to_text) | jeaiii::to_text 317 MB/s | fmt::format_to 209 MB/s | std::to_chars 194 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | jeaiii::to_text 343 MB/s `[TIE]` | fmt::format_to 331 MB/s `[TIE]` | vn::to_chars 282 MB/s `[TIE]` | std::to_chars 272 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 389 MB/s** (+9.0% over vn::to_chars) | vn::to_chars 356 MB/s `[TIE]` | fmt::format_to 332 MB/s `[TIE]` | std::to_chars 185 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::to_chars 375 MB/s** (+7.7% over fmt::format_to) | fmt::format_to 349 MB/s | jeaiii::to_text 336 MB/s | std::to_chars 254 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 385 MB/s `[3-way TIE]` | vn::to_chars 377 MB/s `[3-way TIE]` | fmt::format_to 360 MB/s `[3-way TIE]` | std::to_chars 311 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 675 MB/s `[TIE]` | jeaiii::to_text 585 MB/s `[TIE]` | fmt::format_to 312 MB/s `[TIE]` | std::to_chars 298 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | vn::to_chars 663 MB/s `[TIE]` | jeaiii::to_text 661 MB/s `[TIE]` | fmt::format_to 345 MB/s | std::to_chars 310 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 742 MB/s** (+9.1% over jeaiii::to_text) | jeaiii::to_text 680 MB/s | fmt::format_to 357 MB/s | std::to_chars 309 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::to_chars 737 MB/s `[TIE]` | jeaiii::to_text 669 MB/s `[TIE]` | fmt::format_to 349 MB/s | std::to_chars 304 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **jeaiii::to_text 628 MB/s** (+35.3% over vn::to_chars) | vn::to_chars 464 MB/s | fmt::format_to 331 MB/s `[TIE]` | std::to_chars 298 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | vn::to_chars 703 MB/s `[TIE]` | jeaiii::to_text 660 MB/s `[TIE]` | fmt::format_to 347 MB/s | std::to_chars 294 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 743 MB/s** (+7.6% over jeaiii::to_text) | jeaiii::to_text 691 MB/s | fmt::format_to 356 MB/s | std::to_chars 307 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | vn::to_chars 726 MB/s `[TIE]` | jeaiii::to_text 679 MB/s `[TIE]` | fmt::format_to 349 MB/s | std::to_chars 306 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 1161 MB/s `[TIE]` | jeaiii::to_text 1071 MB/s `[TIE]` | fmt::format_to 709 MB/s | std::to_chars 560 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | vn::to_chars 1234 MB/s `[TIE]` | jeaiii::to_text 1134 MB/s `[TIE]` | fmt::format_to 793 MB/s | std::to_chars 560 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1344 MB/s** (+20.0% over jeaiii::to_text) | jeaiii::to_text 1119 MB/s | fmt::format_to 797 MB/s | std::to_chars 568 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1343 MB/s** (+13.4% over jeaiii::to_text) | jeaiii::to_text 1184 MB/s | fmt::format_to 790 MB/s | std::to_chars 636 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::to_chars 872 MB/s `[TIE]` | jeaiii::to_text 822 MB/s `[TIE]` | fmt::format_to 485 MB/s | std::to_chars 395 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 930 MB/s** (+8.0% over jeaiii::to_text) | jeaiii::to_text 862 MB/s | fmt::format_to 500 MB/s | std::to_chars 408 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 944 MB/s** (+11.0% over jeaiii::to_text) | jeaiii::to_text 851 MB/s | fmt::format_to 497 MB/s | std::to_chars 403 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 912 MB/s** (+7.3% over jeaiii::to_text) | jeaiii::to_text 850 MB/s | fmt::format_to 489 MB/s | std::to_chars 402 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::to_chars 882 MB/s `[TIE]` | jeaiii::to_text 813 MB/s `[TIE]` | fmt::format_to 495 MB/s | std::to_chars 394 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 927 MB/s** (+11.7% over jeaiii::to_text) | jeaiii::to_text 829 MB/s | fmt::format_to 484 MB/s | std::to_chars 403 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 928 MB/s** (+7.9% over jeaiii::to_text) | jeaiii::to_text 861 MB/s | fmt::format_to 502 MB/s | std::to_chars 403 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 919 MB/s** (+8.5% over jeaiii::to_text) | jeaiii::to_text 848 MB/s | fmt::format_to 491 MB/s | std::to_chars 401 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::to_chars 1544 MB/s `[TIE]` | jeaiii::to_text 1353 MB/s `[TIE]` | std::to_chars 677 MB/s | fmt::format_to 556 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1607 MB/s** (+14.1% over jeaiii::to_text) | jeaiii::to_text 1408 MB/s | fmt::format_to 951 MB/s | std::to_chars 348 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1500 MB/s** (+6.9% over jeaiii::to_text) | jeaiii::to_text 1403 MB/s | fmt::format_to 951 MB/s | std::to_chars 703 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1598 MB/s** (+13.8% over jeaiii::to_text) | jeaiii::to_text 1405 MB/s | fmt::format_to 933 MB/s | std::to_chars 699 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::to_chars 2424 MB/s** (+53.1% over jeaiii::to_text) | jeaiii::to_text 1583 MB/s | fmt::format_to 912 MB/s | std::to_chars 681 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 2451 MB/s** (+54.7% over jeaiii::to_text) | jeaiii::to_text 1585 MB/s | fmt::format_to 901 MB/s | std::to_chars 684 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 2419 MB/s** (+50.0% over jeaiii::to_text) | jeaiii::to_text 1613 MB/s | fmt::format_to 895 MB/s | std::to_chars 659 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 2496 MB/s** (+53.0% over jeaiii::to_text) | jeaiii::to_text 1631 MB/s | fmt::format_to 908 MB/s | std::to_chars 674 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 2350 MB/s** (+47.9% over jeaiii::to_text) | jeaiii::to_text 1589 MB/s | fmt::format_to 908 MB/s | std::to_chars 657 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2574 MB/s** (+59.5% over jeaiii::to_text) | jeaiii::to_text 1613 MB/s | fmt::format_to 905 MB/s | std::to_chars 680 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1325 MB/s** (+46.6% over fmt::format_to) | fmt::format_to 904 MB/s | jeaiii::to_text 719 MB/s | std::to_chars 669 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 2403 MB/s** (+47.0% over jeaiii::to_text) | jeaiii::to_text 1635 MB/s | fmt::format_to 897 MB/s | std::to_chars 680 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1582 MB/s** (+30.6% over jeaiii::to_text) | jeaiii::to_text 1211 MB/s | fmt::format_to 720 MB/s | std::to_chars 643 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1618 MB/s** (+25.4% over jeaiii::to_text) | jeaiii::to_text 1290 MB/s | fmt::format_to 704 MB/s | std::to_chars 654 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1612 MB/s** (+28.9% over jeaiii::to_text) | jeaiii::to_text 1251 MB/s | fmt::format_to 737 MB/s | std::to_chars 623 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1575 MB/s** (+24.7% over jeaiii::to_text) | jeaiii::to_text 1263 MB/s | fmt::format_to 731 MB/s | std::to_chars 642 MB/s |

