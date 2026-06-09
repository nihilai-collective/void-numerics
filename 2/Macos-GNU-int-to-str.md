# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

---

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **14** | 2 | 22 |
| jeaiii::to_text | 11 | 14 | 20 |
| std::to_chars | 1 | 6 | 9 |
| fmt::format_to | - | 9 | 16 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 954 MB/s** (+42.9% over vn::to_chars) | vn::to_chars 668 MB/s | fmt::format_to 477 MB/s | std::to_chars 210 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | vn::to_chars 681 MB/s `[TIE]` | jeaiii::to_text 681 MB/s `[TIE]` | fmt::format_to 438 MB/s | std::to_chars 223 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **std::to_chars 196 MB/s** (+54.5% over vn::to_chars) | vn::to_chars 127 MB/s `[3-way TIE]` | fmt::format_to 116 MB/s `[3-way TIE]` | jeaiii::to_text 109 MB/s `[3-way TIE]` |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | vn::to_chars 715 MB/s `[TIE]` | jeaiii::to_text 715 MB/s `[TIE]` | fmt::format_to 477 MB/s | std::to_chars 238 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | vn::to_chars 681 MB/s `[TIE]` | jeaiii::to_text 681 MB/s `[TIE]` | fmt::format_to 438 MB/s | std::to_chars 252 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 680 MB/s** (+54.5% over fmt::format_to) | fmt::format_to 440 MB/s | vn::to_chars 402 MB/s | std::to_chars 251 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | vn::to_chars 954 MB/s `[TIE]` | jeaiii::to_text 954 MB/s `[TIE]` | fmt::format_to 477 MB/s | std::to_chars 254 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | vn::to_chars 1007 MB/s `[TIE]` | jeaiii::to_text 975 MB/s `[TIE]` | fmt::format_to 438 MB/s | std::to_chars 265 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 986 MB/s** (+111.6% over vn::to_chars) | vn::to_chars 466 MB/s | fmt::format_to 440 MB/s | std::to_chars 263 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 954 MB/s** (+15.4% over jeaiii::to_text) | jeaiii::to_text 827 MB/s `[3-way TIE]` | fmt::format_to 668 MB/s `[3-way TIE]` | std::to_chars 420 MB/s `[3-way TIE]` |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 888 MB/s** (+2.4% over jeaiii::to_text) | jeaiii::to_text 867 MB/s | fmt::format_to 795 MB/s | std::to_chars 436 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **jeaiii::to_text 867 MB/s** (+9.1% over fmt::format_to) | fmt::format_to 794 MB/s | vn::to_chars 639 MB/s | std::to_chars 436 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | vn::to_chars 954 MB/s `[TIE]` | fmt::format_to 954 MB/s `[TIE]` | jeaiii::to_text 858 MB/s | std::to_chars 477 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 888 MB/s** (+2.4% over jeaiii::to_text) | jeaiii::to_text 867 MB/s | fmt::format_to 802 MB/s | std::to_chars 454 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 868 MB/s `[3-way TIE]` | fmt::format_to 769 MB/s `[3-way TIE]` | vn::to_chars 614 MB/s `[3-way TIE]` | std::to_chars 451 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | vn::to_chars 954 MB/s `[TIE]` | fmt::format_to 954 MB/s `[TIE]` | jeaiii::to_text 858 MB/s | std::to_chars 477 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 883 MB/s `[TIE]` | vn::to_chars 879 MB/s `[TIE]` | fmt::format_to 867 MB/s | std::to_chars 465 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 891 MB/s** (+10.8% over fmt::format_to) | fmt::format_to 804 MB/s | vn::to_chars 641 MB/s | std::to_chars 463 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::to_chars 381 MB/s `[4-way TIE]` | fmt::format_to 381 MB/s `[4-way TIE]` | jeaiii::to_text 381 MB/s `[4-way TIE]` | std::to_chars 381 MB/s `[4-way TIE]` |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1907 MB/s** (+36.4% over jeaiii::to_text) | jeaiii::to_text 1399 MB/s | fmt::format_to 954 MB/s | std::to_chars 545 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1666 MB/s** (+13.6% over jeaiii::to_text) | jeaiii::to_text 1467 MB/s | fmt::format_to 1004 MB/s | std::to_chars 512 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **jeaiii::to_text 702 MB/s** (+34.8% over std::to_chars) | std::to_chars 521 MB/s | vn::to_chars 367 MB/s `[TIE]` | fmt::format_to 313 MB/s `[TIE]` |
| int32-positive-mixed-lengths-test-size[100] | vn::to_chars 381 MB/s `[4-way TIE]` | fmt::format_to 381 MB/s `[4-way TIE]` | jeaiii::to_text 381 MB/s `[4-way TIE]` | std::to_chars 381 MB/s `[4-way TIE]` |
| int32-positive-mixed-lengths-test-size[1000] | vn::to_chars 1653 MB/s `[3-way TIE]` | jeaiii::to_text 1462 MB/s `[3-way TIE]` | fmt::format_to 1049 MB/s `[3-way TIE]` | std::to_chars 554 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1689 MB/s** (+13.7% over jeaiii::to_text) | jeaiii::to_text 1485 MB/s | fmt::format_to 1090 MB/s | std::to_chars 569 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 1470 MB/s** (+37.6% over fmt::format_to) | fmt::format_to 1068 MB/s `[TIE]` | vn::to_chars 1037 MB/s `[TIE]` | std::to_chars 564 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::to_chars 381 MB/s `[4-way TIE]` | fmt::format_to 381 MB/s `[4-way TIE]` | jeaiii::to_text 381 MB/s `[4-way TIE]` | std::to_chars 381 MB/s `[4-way TIE]` |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1907 MB/s** (+20.0% over jeaiii::to_text) | jeaiii::to_text 1589 MB/s `[TIE]` | fmt::format_to 1017 MB/s `[TIE]` | std::to_chars 599 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1742 MB/s** (+5.0% over jeaiii::to_text) | jeaiii::to_text 1659 MB/s | fmt::format_to 1060 MB/s | std::to_chars 607 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 1647 MB/s** (+109.3% over vn::to_chars) | vn::to_chars 787 MB/s `[3-way TIE]` | std::to_chars 609 MB/s `[3-way TIE]` | fmt::format_to 602 MB/s `[3-way TIE]` |
| int64-negative-mixed-lengths-test-size[100] | vn::to_chars 763 MB/s `[3-way TIE]` | fmt::format_to 763 MB/s `[3-way TIE]` | jeaiii::to_text 763 MB/s `[3-way TIE]` | std::to_chars 572 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 2543 MB/s** (+100.0% over jeaiii::to_text) | jeaiii::to_text 1272 MB/s | fmt::format_to 707 MB/s | std::to_chars 558 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 2502 MB/s** (+76.1% over jeaiii::to_text) | jeaiii::to_text 1421 MB/s | fmt::format_to 715 MB/s | std::to_chars 561 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **jeaiii::to_text 918 MB/s** (+36.8% over vn::to_chars) | vn::to_chars 671 MB/s `[TIE]` | std::to_chars 559 MB/s `[TIE]` | fmt::format_to 333 MB/s |
| int64-positive-mixed-lengths-test-size[100] | vn::to_chars 763 MB/s `[3-way TIE]` | fmt::format_to 763 MB/s `[3-way TIE]` | jeaiii::to_text 763 MB/s `[3-way TIE]` | std::to_chars 572 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2543 MB/s** (+96.1% over jeaiii::to_text) | jeaiii::to_text 1297 MB/s | fmt::format_to 714 MB/s | std::to_chars 545 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2543 MB/s** (+76.7% over jeaiii::to_text) | jeaiii::to_text 1440 MB/s | fmt::format_to 722 MB/s | std::to_chars 566 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 1416 MB/s** (+151.0% over fmt::format_to) | fmt::format_to 564 MB/s `[3-way TIE]` | std::to_chars 563 MB/s `[3-way TIE]` | vn::to_chars 555 MB/s `[3-way TIE]` |
| uint64-positive-mixed-lengths-test-size[100] | vn::to_chars 763 MB/s `[3-way TIE]` | fmt::format_to 763 MB/s `[3-way TIE]` | jeaiii::to_text 763 MB/s `[3-way TIE]` | std::to_chars 572 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2925 MB/s** (+91.7% over jeaiii::to_text) | jeaiii::to_text 1526 MB/s | fmt::format_to 763 MB/s | std::to_chars 553 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2946 MB/s** (+93.1% over jeaiii::to_text) | jeaiii::to_text 1526 MB/s | fmt::format_to 750 MB/s | std::to_chars 558 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 1510 MB/s** (+150.7% over vn::to_chars) | vn::to_chars 602 MB/s `[3-way TIE]` | fmt::format_to 562 MB/s `[3-way TIE]` | std::to_chars 557 MB/s `[3-way TIE]` |
