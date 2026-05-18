# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** Clang 23.0.0

---

## int-to-str

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **22** | 2 | 24 |
| jeaiii::to_text | 1 | 22 | 25 |
| std::to_chars | - | 5 | 7 |
| fmt::format_to | - | 11 | 12 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 226 MB/s `[4-way TIE]` | vn::to_chars 216 MB/s `[4-way TIE]` | fmt::format_to 198 MB/s `[4-way TIE]` | std::to_chars 163 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | jeaiii::to_text 239 MB/s `[3-way TIE]` | vn::to_chars 237 MB/s `[3-way TIE]` | fmt::format_to 224 MB/s `[3-way TIE]` | std::to_chars 188 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | vn::to_chars 240 MB/s `[TIE]` | jeaiii::to_text 240 MB/s `[TIE]` | fmt::format_to 230 MB/s | std::to_chars 185 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | fmt::format_to 232 MB/s `[3-way TIE]` | jeaiii::to_text 231 MB/s `[3-way TIE]` | vn::to_chars 231 MB/s `[3-way TIE]` | std::to_chars 185 MB/s |
| int8-positive-mixed-lengths-test-size[100] | fmt::format_to 224 MB/s `[3-way TIE]` | jeaiii::to_text 223 MB/s `[3-way TIE]` | vn::to_chars 221 MB/s `[3-way TIE]` | std::to_chars 180 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 243 MB/s `[3-way TIE]` | vn::to_chars 237 MB/s `[3-way TIE]` | fmt::format_to 229 MB/s `[3-way TIE]` | std::to_chars 188 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 238 MB/s `[TIE]` | fmt::format_to 237 MB/s `[TIE]` | vn::to_chars 228 MB/s | std::to_chars 172 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | vn::to_chars 238 MB/s `[3-way TIE]` | jeaiii::to_text 236 MB/s `[3-way TIE]` | fmt::format_to 232 MB/s `[3-way TIE]` | std::to_chars 182 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | std::to_chars 337 MB/s `[4-way TIE]` | jeaiii::to_text 332 MB/s `[4-way TIE]` | vn::to_chars 325 MB/s `[4-way TIE]` | fmt::format_to 306 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | vn::to_chars 378 MB/s `[3-way TIE]` | jeaiii::to_text 377 MB/s `[3-way TIE]` | std::to_chars 373 MB/s `[3-way TIE]` | fmt::format_to 335 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 406 MB/s** (+4.2% over vn::to_chars) | vn::to_chars 389 MB/s | std::to_chars 351 MB/s `[TIE]` | fmt::format_to 349 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 395 MB/s `[4-way TIE]` | vn::to_chars 383 MB/s `[4-way TIE]` | std::to_chars 363 MB/s `[4-way TIE]` | fmt::format_to 339 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 407 MB/s `[4-way TIE]` | jeaiii::to_text 378 MB/s `[4-way TIE]` | fmt::format_to 332 MB/s `[4-way TIE]` | std::to_chars 309 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | vn::to_chars 410 MB/s `[TIE]` | jeaiii::to_text 397 MB/s `[TIE]` | fmt::format_to 351 MB/s | std::to_chars 318 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 419 MB/s** (+5.8% over jeaiii::to_text) | jeaiii::to_text 396 MB/s | fmt::format_to 357 MB/s | std::to_chars 321 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 413 MB/s** (+10.2% over jeaiii::to_text) | jeaiii::to_text 375 MB/s | fmt::format_to 349 MB/s | std::to_chars 321 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 399 MB/s `[4-way TIE]` | jeaiii::to_text 376 MB/s `[4-way TIE]` | fmt::format_to 338 MB/s `[4-way TIE]` | std::to_chars 301 MB/s `[4-way TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | vn::to_chars 399 MB/s `[TIE]` | jeaiii::to_text 396 MB/s `[TIE]` | fmt::format_to 358 MB/s | std::to_chars 324 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 417 MB/s** (+4.4% over jeaiii::to_text) | jeaiii::to_text 399 MB/s | fmt::format_to 357 MB/s | std::to_chars 320 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | vn::to_chars 414 MB/s `[TIE]` | jeaiii::to_text 396 MB/s `[TIE]` | fmt::format_to 354 MB/s | std::to_chars 312 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | jeaiii::to_text 1011 MB/s `[4-way TIE]` | vn::to_chars 935 MB/s `[4-way TIE]` | std::to_chars 740 MB/s `[4-way TIE]` | fmt::format_to 707 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 1084 MB/s `[TIE]` | vn::to_chars 1005 MB/s `[TIE]` | fmt::format_to 833 MB/s `[TIE]` | std::to_chars 811 MB/s `[TIE]` |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1209 MB/s** (+11.2% over jeaiii::to_text) | jeaiii::to_text 1088 MB/s | fmt::format_to 873 MB/s | std::to_chars 763 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1192 MB/s** (+11.7% over jeaiii::to_text) | jeaiii::to_text 1067 MB/s | fmt::format_to 877 MB/s | std::to_chars 767 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::to_chars 603 MB/s `[TIE]` | jeaiii::to_text 589 MB/s `[TIE]` | fmt::format_to 498 MB/s | std::to_chars 413 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 637 MB/s** (+6.5% over jeaiii::to_text) | jeaiii::to_text 598 MB/s | fmt::format_to 490 MB/s | std::to_chars 426 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 636 MB/s** (+7.6% over jeaiii::to_text) | jeaiii::to_text 591 MB/s | fmt::format_to 522 MB/s | std::to_chars 403 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | vn::to_chars 619 MB/s `[TIE]` | jeaiii::to_text 585 MB/s `[TIE]` | fmt::format_to 508 MB/s | std::to_chars 417 MB/s |
| int32-positive-mixed-lengths-test-size[100] | vn::to_chars 613 MB/s `[TIE]` | jeaiii::to_text 598 MB/s `[TIE]` | fmt::format_to 493 MB/s | std::to_chars 424 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 631 MB/s** (+7.7% over jeaiii::to_text) | jeaiii::to_text 586 MB/s | fmt::format_to 514 MB/s | std::to_chars 425 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 629 MB/s** (+7.2% over jeaiii::to_text) | jeaiii::to_text 587 MB/s | fmt::format_to 503 MB/s | std::to_chars 416 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 618 MB/s** (+6.5% over jeaiii::to_text) | jeaiii::to_text 580 MB/s | fmt::format_to 506 MB/s | std::to_chars 406 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::to_chars 1467 MB/s `[TIE]` | jeaiii::to_text 1282 MB/s `[TIE]` | fmt::format_to 959 MB/s | std::to_chars 745 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1464 MB/s** (+18.2% over jeaiii::to_text) | jeaiii::to_text 1239 MB/s | fmt::format_to 993 MB/s | std::to_chars 769 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1529 MB/s** (+20.8% over jeaiii::to_text) | jeaiii::to_text 1266 MB/s | fmt::format_to 1016 MB/s | std::to_chars 775 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1460 MB/s** (+22.0% over jeaiii::to_text) | jeaiii::to_text 1197 MB/s | fmt::format_to 991 MB/s | std::to_chars 743 MB/s |
| int64-negative-mixed-lengths-test-size[100] | vn::to_chars 1414 MB/s `[TIE]` | jeaiii::to_text 1157 MB/s `[TIE]` | fmt::format_to 883 MB/s | std::to_chars 693 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1496 MB/s** (+31.9% over jeaiii::to_text) | jeaiii::to_text 1133 MB/s | fmt::format_to 884 MB/s | std::to_chars 701 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1497 MB/s** (+31.3% over jeaiii::to_text) | jeaiii::to_text 1140 MB/s | fmt::format_to 887 MB/s | std::to_chars 693 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 1452 MB/s** (+29.3% over jeaiii::to_text) | jeaiii::to_text 1123 MB/s | fmt::format_to 831 MB/s | std::to_chars 688 MB/s |
| int64-positive-mixed-lengths-test-size[100] | vn::to_chars 1426 MB/s `[TIE]` | jeaiii::to_text 1128 MB/s `[TIE]` | fmt::format_to 854 MB/s | std::to_chars 666 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1549 MB/s** (+34.8% over jeaiii::to_text) | jeaiii::to_text 1149 MB/s | fmt::format_to 839 MB/s | std::to_chars 684 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1471 MB/s** (+32.0% over jeaiii::to_text) | jeaiii::to_text 1114 MB/s | fmt::format_to 840 MB/s | std::to_chars 690 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1432 MB/s** (+31.7% over jeaiii::to_text) | jeaiii::to_text 1088 MB/s | fmt::format_to 823 MB/s | std::to_chars 628 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | vn::to_chars 1646 MB/s `[TIE]` | jeaiii::to_text 1375 MB/s `[TIE]` | fmt::format_to 715 MB/s `[TIE]` | std::to_chars 665 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1744 MB/s** (+33.4% over jeaiii::to_text) | jeaiii::to_text 1307 MB/s | fmt::format_to 743 MB/s | std::to_chars 689 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1657 MB/s** (+25.9% over jeaiii::to_text) | jeaiii::to_text 1316 MB/s | fmt::format_to 748 MB/s | std::to_chars 661 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1702 MB/s** (+27.2% over jeaiii::to_text) | jeaiii::to_text 1338 MB/s | fmt::format_to 743 MB/s | std::to_chars 662 MB/s |

