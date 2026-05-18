# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Windows 10.0.26200  
**Compiler:** MSVC 19.44.35227.0

---
### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **36** | 3 | 9 |
| jeaiii::to_text | 3 | 31 | 9 |
| fmt::format_to | - | 11 | 1 |
| std::to_chars | - | 1 | - |


---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 477 MB/s `[TIE]` | vn::to_chars 477 MB/s `[TIE]` | fmt::format_to 238 MB/s | std::to_chars 191 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | vn::to_chars 579 MB/s `[TIE]` | jeaiii::to_text 542 MB/s `[TIE]` | fmt::format_to 266 MB/s | std::to_chars 200 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::to_chars 603 MB/s** (+8.7% over jeaiii::to_text) | jeaiii::to_text 555 MB/s | fmt::format_to 274 MB/s | std::to_chars 208 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 574 MB/s `[TIE]` | vn::to_chars 571 MB/s `[TIE]` | fmt::format_to 275 MB/s | std::to_chars 205 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::to_chars 525 MB/s** (+10.0% over jeaiii::to_text) | jeaiii::to_text 477 MB/s | fmt::format_to 318 MB/s | std::to_chars 238 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 702 MB/s `[TIE]` | vn::to_chars 702 MB/s `[TIE]` | fmt::format_to 368 MB/s | std::to_chars 245 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 669 MB/s** (+14.0% over vn::to_chars) | vn::to_chars 587 MB/s | fmt::format_to 371 MB/s | std::to_chars 245 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 661 MB/s `[TIE]` | vn::to_chars 657 MB/s `[TIE]` | fmt::format_to 374 MB/s | std::to_chars 244 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | jeaiii::to_text 477 MB/s `[3-way TIE]` | fmt::format_to 477 MB/s `[3-way TIE]` | vn::to_chars 477 MB/s `[3-way TIE]` | std::to_chars 238 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 708 MB/s `[TIE]` | vn::to_chars 702 MB/s `[TIE]` | fmt::format_to 596 MB/s | std::to_chars 245 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 743 MB/s `[TIE]` | vn::to_chars 699 MB/s `[TIE]` | fmt::format_to 572 MB/s | std::to_chars 248 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | vn::to_chars 715 MB/s `[TIE]` | jeaiii::to_text 701 MB/s `[TIE]` | fmt::format_to 494 MB/s | std::to_chars 241 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::to_chars 636 MB/s** (+33.3% over jeaiii::to_text) | jeaiii::to_text 477 MB/s | fmt::format_to 318 MB/s | std::to_chars 238 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 979 MB/s** (+31.8% over jeaiii::to_text) | jeaiii::to_text 742 MB/s | fmt::format_to 457 MB/s | std::to_chars 301 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1007 MB/s** (+34.2% over jeaiii::to_text) | jeaiii::to_text 750 MB/s | fmt::format_to 456 MB/s | std::to_chars 311 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 1001 MB/s** (+33.2% over jeaiii::to_text) | jeaiii::to_text 751 MB/s | fmt::format_to 449 MB/s | std::to_chars 304 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::to_chars 954 MB/s** (+36.4% over jeaiii::to_text) | jeaiii::to_text 699 MB/s | fmt::format_to 477 MB/s | std::to_chars 318 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1208 MB/s** (+101.4% over fmt::format_to) | fmt::format_to 600 MB/s | jeaiii::to_text 505 MB/s | std::to_chars 375 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1224 MB/s** (+39.5% over jeaiii::to_text) | jeaiii::to_text 877 MB/s | fmt::format_to 608 MB/s | std::to_chars 380 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1056 MB/s** (+23.6% over jeaiii::to_text) | jeaiii::to_text 854 MB/s | fmt::format_to 617 MB/s | std::to_chars 372 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::to_chars 1907 MB/s** (+100.0% over fmt::format_to) | fmt::format_to 954 MB/s `[TIE]` | jeaiii::to_text 954 MB/s `[TIE]` | std::to_chars 381 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1504 MB/s** (+29.9% over jeaiii::to_text) | jeaiii::to_text 1158 MB/s | fmt::format_to 1021 MB/s | std::to_chars 266 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1569 MB/s** (+43.9% over jeaiii::to_text) | jeaiii::to_text 1090 MB/s | fmt::format_to 1012 MB/s | std::to_chars 412 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1589 MB/s** (+34.3% over jeaiii::to_text) | jeaiii::to_text 1183 MB/s | fmt::format_to 975 MB/s | std::to_chars 395 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::to_chars 1272 MB/s** (+100.0% over fmt::format_to) | fmt::format_to 636 MB/s | jeaiii::to_text 563 MB/s | std::to_chars 386 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 1037 MB/s** (+10.8% over vn::to_chars) | vn::to_chars 935 MB/s | fmt::format_to 685 MB/s | std::to_chars 421 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1581 MB/s** (+49.9% over jeaiii::to_text) | jeaiii::to_text 1054 MB/s | fmt::format_to 693 MB/s | std::to_chars 426 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 1533 MB/s** (+49.4% over jeaiii::to_text) | jeaiii::to_text 1026 MB/s | fmt::format_to 665 MB/s | std::to_chars 421 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::to_chars 1907 MB/s** (+50.0% over jeaiii::to_text) | jeaiii::to_text 1272 MB/s | fmt::format_to 763 MB/s | std::to_chars 275 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1900 MB/s** (+52.4% over jeaiii::to_text) | jeaiii::to_text 1247 MB/s | fmt::format_to 893 MB/s | std::to_chars 492 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1897 MB/s** (+51.2% over jeaiii::to_text) | jeaiii::to_text 1254 MB/s | fmt::format_to 900 MB/s | std::to_chars 494 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1879 MB/s** (+56.3% over jeaiii::to_text) | jeaiii::to_text 1202 MB/s | fmt::format_to 877 MB/s | std::to_chars 482 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::to_chars 1907 MB/s** (+36.4% over jeaiii::to_text) | jeaiii::to_text 1399 MB/s | fmt::format_to 985 MB/s | std::to_chars 477 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2126 MB/s** (+19.8% over jeaiii::to_text) | jeaiii::to_text 1775 MB/s | fmt::format_to 1243 MB/s | std::to_chars 505 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2234 MB/s** (+30.4% over jeaiii::to_text) | jeaiii::to_text 1713 MB/s | fmt::format_to 758 MB/s | std::to_chars 522 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 2145 MB/s** (+24.9% over jeaiii::to_text) | jeaiii::to_text 1717 MB/s | fmt::format_to 1188 MB/s | std::to_chars 522 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::to_chars 2543 MB/s** (+233.3% over jeaiii::to_text) | jeaiii::to_text 763 MB/s `[TIE]` | fmt::format_to 763 MB/s `[TIE]` | std::to_chars 549 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 2009 MB/s** (+28.5% over jeaiii::to_text) | jeaiii::to_text 1564 MB/s | fmt::format_to 805 MB/s | std::to_chars 501 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 2539 MB/s** (+61.2% over jeaiii::to_text) | jeaiii::to_text 1575 MB/s | fmt::format_to 713 MB/s | std::to_chars 574 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 2464 MB/s** (+62.6% over jeaiii::to_text) | jeaiii::to_text 1516 MB/s | fmt::format_to 801 MB/s | std::to_chars 550 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 2543 MB/s** (+200.0% over fmt::format_to) | fmt::format_to 848 MB/s | jeaiii::to_text 763 MB/s | std::to_chars 587 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 1596 MB/s** (+13.8% over vn::to_chars) | vn::to_chars 1403 MB/s | fmt::format_to 899 MB/s | std::to_chars 250 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2533 MB/s** (+56.5% over jeaiii::to_text) | jeaiii::to_text 1618 MB/s | fmt::format_to 853 MB/s | std::to_chars 614 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 2562 MB/s** (+68.2% over jeaiii::to_text) | jeaiii::to_text 1523 MB/s | fmt::format_to 842 MB/s | std::to_chars 588 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 2543 MB/s** (+66.7% over jeaiii::to_text) | jeaiii::to_text 1526 MB/s | std::to_chars 549 MB/s | fmt::format_to 452 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 2698 MB/s** (+51.0% over jeaiii::to_text) | jeaiii::to_text 1787 MB/s | fmt::format_to 783 MB/s | std::to_chars 557 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2641 MB/s** (+47.3% over jeaiii::to_text) | jeaiii::to_text 1793 MB/s | fmt::format_to 824 MB/s | std::to_chars 538 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 2586 MB/s** (+51.2% over jeaiii::to_text) | jeaiii::to_text 1710 MB/s | fmt::format_to 793 MB/s | std::to_chars 557 MB/s |