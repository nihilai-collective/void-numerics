# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Linux 6.6.87.2-microsoft-standard-WSL2
**Compiler:** GNU 16.0.1

---

## int-to-str

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **27** | - | 19 |
| jeaiii::to_text | 1 | 15 | 20 |
| std::to_chars | - | 8 | 4 |
| fmt::format_to | - | 9 | 12 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | jeaiii::to_text 216 MB/s `[4-way TIE]` | vn::to_chars 206 MB/s `[4-way TIE]` | fmt::format_to 201 MB/s `[4-way TIE]` | std::to_chars 197 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | vn::to_chars 232 MB/s `[3-way TIE]` | jeaiii::to_text 222 MB/s `[3-way TIE]` | fmt::format_to 213 MB/s `[3-way TIE]` | std::to_chars 196 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | vn::to_chars 234 MB/s `[TIE]` | jeaiii::to_text 231 MB/s `[TIE]` | fmt::format_to 224 MB/s | std::to_chars 191 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 224 MB/s `[TIE]` | fmt::format_to 219 MB/s `[TIE]` | std::to_chars 193 MB/s `[TIE]` | vn::to_chars 189 MB/s `[TIE]` |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 222 MB/s `[4-way TIE]` | jeaiii::to_text 218 MB/s `[4-way TIE]` | fmt::format_to 205 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | vn::to_chars 232 MB/s `[3-way TIE]` | jeaiii::to_text 228 MB/s `[3-way TIE]` | fmt::format_to 223 MB/s `[3-way TIE]` | std::to_chars 202 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 231 MB/s `[TIE]` | vn::to_chars 229 MB/s `[TIE]` | fmt::format_to 222 MB/s | std::to_chars 200 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | vn::to_chars 229 MB/s `[3-way TIE]` | jeaiii::to_text 225 MB/s `[3-way TIE]` | fmt::format_to 218 MB/s `[3-way TIE]` | std::to_chars 198 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | jeaiii::to_text 354 MB/s `[4-way TIE]` | vn::to_chars 353 MB/s `[4-way TIE]` | fmt::format_to 293 MB/s `[4-way TIE]` | std::to_chars 290 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | vn::to_chars 383 MB/s `[3-way TIE]` | jeaiii::to_text 365 MB/s `[3-way TIE]` | fmt::format_to 351 MB/s `[3-way TIE]` | std::to_chars 310 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::to_chars 415 MB/s** (+7.1% over jeaiii::to_text) | jeaiii::to_text 388 MB/s | fmt::format_to 370 MB/s | std::to_chars 294 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::to_chars 410 MB/s** (+13.6% over fmt::format_to) | fmt::format_to 361 MB/s | jeaiii::to_text 298 MB/s `[TIE]` | std::to_chars 296 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[100] | **vn::to_chars 410 MB/s** (+20.2% over jeaiii::to_text) | jeaiii::to_text 341 MB/s `[3-way TIE]` | std::to_chars 306 MB/s `[3-way TIE]` | fmt::format_to 301 MB/s `[3-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 422 MB/s** (+16.6% over fmt::format_to) | fmt::format_to 362 MB/s `[TIE]` | jeaiii::to_text 360 MB/s `[TIE]` | std::to_chars 307 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 432 MB/s** (+20.1% over fmt::format_to) | fmt::format_to 360 MB/s `[TIE]` | jeaiii::to_text 355 MB/s `[TIE]` | std::to_chars 306 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 434 MB/s** (+21.1% over jeaiii::to_text) | jeaiii::to_text 358 MB/s `[TIE]` | fmt::format_to 357 MB/s `[TIE]` | std::to_chars 310 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 407 MB/s `[4-way TIE]` | fmt::format_to 353 MB/s `[4-way TIE]` | jeaiii::to_text 338 MB/s `[4-way TIE]` | std::to_chars 303 MB/s `[4-way TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 425 MB/s** (+17.9% over fmt::format_to) | fmt::format_to 360 MB/s `[TIE]` | jeaiii::to_text 355 MB/s `[TIE]` | std::to_chars 312 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 441 MB/s** (+21.3% over jeaiii::to_text) | jeaiii::to_text 364 MB/s `[TIE]` | fmt::format_to 360 MB/s `[TIE]` | std::to_chars 313 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 427 MB/s** (+19.8% over jeaiii::to_text) | jeaiii::to_text 357 MB/s `[TIE]` | fmt::format_to 345 MB/s `[TIE]` | std::to_chars 311 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 1294 MB/s `[TIE]` | jeaiii::to_text 964 MB/s `[TIE]` | std::to_chars 650 MB/s | fmt::format_to 335 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1390 MB/s** (+51.3% over jeaiii::to_text) | jeaiii::to_text 918 MB/s `[TIE]` | fmt::format_to 843 MB/s `[TIE]` | std::to_chars 647 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1328 MB/s** (+41.5% over jeaiii::to_text) | jeaiii::to_text 938 MB/s | fmt::format_to 828 MB/s | std::to_chars 631 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1312 MB/s** (+40.9% over jeaiii::to_text) | jeaiii::to_text 931 MB/s `[TIE]` | fmt::format_to 819 MB/s `[TIE]` | std::to_chars 633 MB/s |
| int32-negative-mixed-lengths-test-size[100] | jeaiii::to_text 574 MB/s `[3-way TIE]` | vn::to_chars 562 MB/s `[3-way TIE]` | fmt::format_to 494 MB/s `[3-way TIE]` | std::to_chars 378 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | vn::to_chars 587 MB/s `[TIE]` | jeaiii::to_text 587 MB/s `[TIE]` | fmt::format_to 493 MB/s | std::to_chars 393 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | vn::to_chars 593 MB/s `[3-way TIE]` | jeaiii::to_text 550 MB/s `[3-way TIE]` | fmt::format_to 493 MB/s `[3-way TIE]` | std::to_chars 371 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 591 MB/s** (+12.8% over jeaiii::to_text) | jeaiii::to_text 524 MB/s `[TIE]` | fmt::format_to 490 MB/s `[TIE]` | std::to_chars 357 MB/s |
| int32-positive-mixed-lengths-test-size[100] | jeaiii::to_text 575 MB/s `[TIE]` | vn::to_chars 571 MB/s `[TIE]` | fmt::format_to 494 MB/s | std::to_chars 368 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | vn::to_chars 587 MB/s `[TIE]` | jeaiii::to_text 579 MB/s `[TIE]` | fmt::format_to 504 MB/s | std::to_chars 396 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 592 MB/s** (+2.8% over jeaiii::to_text) | jeaiii::to_text 576 MB/s | fmt::format_to 497 MB/s | std::to_chars 386 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | vn::to_chars 578 MB/s `[TIE]` | jeaiii::to_text 571 MB/s `[TIE]` | fmt::format_to 493 MB/s | std::to_chars 395 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | vn::to_chars 1218 MB/s `[3-way TIE]` | jeaiii::to_text 1039 MB/s `[3-way TIE]` | fmt::format_to 925 MB/s `[3-way TIE]` | std::to_chars 679 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1344 MB/s** (+18.3% over jeaiii::to_text) | jeaiii::to_text 1136 MB/s | fmt::format_to 975 MB/s | std::to_chars 704 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1315 MB/s** (+15.8% over jeaiii::to_text) | jeaiii::to_text 1135 MB/s | fmt::format_to 973 MB/s | std::to_chars 696 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1310 MB/s** (+12.0% over jeaiii::to_text) | jeaiii::to_text 1170 MB/s | fmt::format_to 964 MB/s | std::to_chars 627 MB/s |
| int64-negative-mixed-lengths-test-size[100] | vn::to_chars 1237 MB/s `[TIE]` | jeaiii::to_text 1031 MB/s `[TIE]` | fmt::format_to 860 MB/s | std::to_chars 648 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1334 MB/s** (+25.9% over jeaiii::to_text) | jeaiii::to_text 1059 MB/s | fmt::format_to 888 MB/s | std::to_chars 645 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1343 MB/s** (+31.4% over jeaiii::to_text) | jeaiii::to_text 1022 MB/s | fmt::format_to 871 MB/s | std::to_chars 640 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **jeaiii::to_text 971 MB/s** (+18.9% over fmt::format_to) | fmt::format_to 817 MB/s | std::to_chars 603 MB/s | vn::to_chars 378 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1304 MB/s** (+27.3% over jeaiii::to_text) | jeaiii::to_text 1024 MB/s | fmt::format_to 878 MB/s | std::to_chars 650 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1355 MB/s** (+44.5% over jeaiii::to_text) | jeaiii::to_text 938 MB/s `[TIE]` | fmt::format_to 885 MB/s `[TIE]` | std::to_chars 654 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1292 MB/s** (+27.7% over jeaiii::to_text) | jeaiii::to_text 1011 MB/s | fmt::format_to 872 MB/s | std::to_chars 625 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1261 MB/s** (+24.1% over jeaiii::to_text) | jeaiii::to_text 1016 MB/s | fmt::format_to 848 MB/s | std::to_chars 639 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1564 MB/s** (+24.8% over jeaiii::to_text) | jeaiii::to_text 1253 MB/s | fmt::format_to 723 MB/s | std::to_chars 631 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1580 MB/s** (+25.6% over jeaiii::to_text) | jeaiii::to_text 1258 MB/s | fmt::format_to 748 MB/s | std::to_chars 652 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1522 MB/s** (+20.6% over jeaiii::to_text) | jeaiii::to_text 1262 MB/s | fmt::format_to 735 MB/s | std::to_chars 623 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1509 MB/s** (+21.6% over jeaiii::to_text) | jeaiii::to_text 1241 MB/s | fmt::format_to 728 MB/s | std::to_chars 633 MB/s |