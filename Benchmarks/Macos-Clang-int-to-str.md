# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.4  

---
### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **13** | 4 | 24 |
| jeaiii::to_text | 8 | 10 | 25 |
| std::to_chars | 2 | 6 | 11 |
| fmt::format_to | - | 6 | 6 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::to_chars 299 MB/s `[TIE]` | jeaiii::to_text 294 MB/s `[TIE]` | fmt::format_to 157 MB/s `[TIE]` | std::to_chars 148 MB/s `[TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 348 MB/s** (+9.9% over vn::to_chars) | vn::to_chars 317 MB/s | fmt::format_to 159 MB/s | std::to_chars 152 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **jeaiii::to_text 339 MB/s** (+33.2% over vn::to_chars) | vn::to_chars 255 MB/s | fmt::format_to 159 MB/s `[TIE]` | std::to_chars 156 MB/s `[TIE]` |
| int8-negative-mixed-lengths-test-size[100000] | **vn::to_chars 321 MB/s** (+46.8% over jeaiii::to_text) | jeaiii::to_text 219 MB/s | fmt::format_to 162 MB/s `[TIE]` | std::to_chars 153 MB/s `[TIE]` |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 299 MB/s `[TIE]` | jeaiii::to_text 294 MB/s `[TIE]` | fmt::format_to 167 MB/s | std::to_chars 154 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 319 MB/s** (+29.0% over vn::to_chars) | vn::to_chars 248 MB/s | std::to_chars 166 MB/s | fmt::format_to 157 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 343 MB/s `[TIE]` | vn::to_chars 334 MB/s `[TIE]` | std::to_chars 163 MB/s `[TIE]` | fmt::format_to 161 MB/s `[TIE]` |
| int8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 234 MB/s `[TIE]` | vn::to_chars 229 MB/s `[TIE]` | fmt::format_to 126 MB/s `[TIE]` | std::to_chars 121 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[100] | **std::to_chars 254 MB/s** (+-3.6% over vn::to_chars) | vn::to_chars 264 MB/s `[3-way TIE]` | jeaiii::to_text 239 MB/s `[3-way TIE]` | fmt::format_to 236 MB/s `[3-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | vn::to_chars 279 MB/s `[TIE]` | jeaiii::to_text 270 MB/s `[TIE]` | fmt::format_to 253 MB/s `[TIE]` | std::to_chars 250 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[10000] | vn::to_chars 294 MB/s `[TIE]` | jeaiii::to_text 287 MB/s `[TIE]` | fmt::format_to 259 MB/s `[TIE]` | std::to_chars 258 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 230 MB/s `[3-way TIE]` | std::to_chars 228 MB/s `[3-way TIE]` | vn::to_chars 199 MB/s `[3-way TIE]` | fmt::format_to 175 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 515 MB/s `[TIE]` | jeaiii::to_text 473 MB/s `[TIE]` | std::to_chars 276 MB/s `[TIE]` | fmt::format_to 249 MB/s `[TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | vn::to_chars 358 MB/s `[TIE]` | jeaiii::to_text 347 MB/s `[TIE]` | std::to_chars 280 MB/s | fmt::format_to 223 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | vn::to_chars 513 MB/s `[TIE]` | jeaiii::to_text 483 MB/s `[TIE]` | fmt::format_to 283 MB/s | std::to_chars 270 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::to_chars 401 MB/s `[TIE]` | jeaiii::to_text 389 MB/s `[TIE]` | fmt::format_to 243 MB/s `[TIE]` | std::to_chars 242 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[100] | **vn::to_chars 542 MB/s** (+17.1% over jeaiii::to_text) | jeaiii::to_text 463 MB/s | std::to_chars 276 MB/s `[TIE]` | fmt::format_to 265 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | vn::to_chars 539 MB/s `[TIE]` | jeaiii::to_text 533 MB/s `[TIE]` | std::to_chars 303 MB/s `[TIE]` | fmt::format_to 290 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[10000] | vn::to_chars 565 MB/s `[TIE]` | jeaiii::to_text 535 MB/s `[TIE]` | std::to_chars 285 MB/s `[TIE]` | fmt::format_to 283 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 329 MB/s `[3-way TIE]` | vn::to_chars 323 MB/s `[3-way TIE]` | std::to_chars 299 MB/s `[3-way TIE]` | fmt::format_to 226 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 916 MB/s `[4-way TIE]` | jeaiii::to_text 756 MB/s `[4-way TIE]` | std::to_chars 673 MB/s `[4-way TIE]` | fmt::format_to 553 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | vn::to_chars 977 MB/s `[TIE]` | jeaiii::to_text 920 MB/s `[TIE]` | fmt::format_to 663 MB/s `[TIE]` | std::to_chars 663 MB/s `[TIE]` |
| uint16-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 795 MB/s `[4-way TIE]` | std::to_chars 677 MB/s `[4-way TIE]` | fmt::format_to 635 MB/s `[4-way TIE]` | vn::to_chars 595 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 769 MB/s `[4-way TIE]` | std::to_chars 560 MB/s `[4-way TIE]` | vn::to_chars 469 MB/s `[4-way TIE]` | fmt::format_to 468 MB/s `[4-way TIE]` |
| int32-negative-mixed-lengths-test-size[100] | **vn::to_chars 716 MB/s** (+8.7% over jeaiii::to_text) | jeaiii::to_text 659 MB/s | std::to_chars 407 MB/s | fmt::format_to 348 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | jeaiii::to_text 632 MB/s `[TIE]` | vn::to_chars 618 MB/s `[TIE]` | std::to_chars 436 MB/s | fmt::format_to 335 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **jeaiii::to_text 629 MB/s** (+33.1% over std::to_chars) | std::to_chars 473 MB/s | fmt::format_to 346 MB/s | vn::to_chars 276 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | std::to_chars 321 MB/s `[4-way TIE]` | jeaiii::to_text 278 MB/s `[4-way TIE]` | vn::to_chars 202 MB/s `[4-way TIE]` | fmt::format_to 172 MB/s `[4-way TIE]` |
| int32-positive-mixed-lengths-test-size[100] | **vn::to_chars 792 MB/s** (+28.0% over jeaiii::to_text) | jeaiii::to_text 619 MB/s | std::to_chars 445 MB/s | fmt::format_to 371 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 810 MB/s** (+25.7% over jeaiii::to_text) | jeaiii::to_text 644 MB/s | std::to_chars 454 MB/s | fmt::format_to 376 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 821 MB/s** (+24.5% over jeaiii::to_text) | jeaiii::to_text 660 MB/s | std::to_chars 465 MB/s | fmt::format_to 384 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 633 MB/s** (+47.1% over std::to_chars) | std::to_chars 430 MB/s | vn::to_chars 286 MB/s `[TIE]` | fmt::format_to 199 MB/s `[TIE]` |
| uint32-positive-mixed-lengths-test-size[100] | **vn::to_chars 1194 MB/s** (+40.5% over std::to_chars) | std::to_chars 850 MB/s `[3-way TIE]` | jeaiii::to_text 791 MB/s `[3-way TIE]` | fmt::format_to 685 MB/s `[3-way TIE]` |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1290 MB/s** (+46.9% over jeaiii::to_text) | jeaiii::to_text 878 MB/s `[TIE]` | std::to_chars 877 MB/s `[TIE]` | fmt::format_to 718 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1317 MB/s** (+42.1% over std::to_chars) | std::to_chars 927 MB/s | jeaiii::to_text 852 MB/s | fmt::format_to 710 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 826 MB/s `[3-way TIE]` | std::to_chars 814 MB/s `[3-way TIE]` | vn::to_chars 793 MB/s `[3-way TIE]` | fmt::format_to 407 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::to_chars 1913 MB/s** (+56.7% over jeaiii::to_text) | jeaiii::to_text 1221 MB/s | std::to_chars 840 MB/s | fmt::format_to 694 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 1188 MB/s** (+40.4% over std::to_chars) | std::to_chars 846 MB/s `[3-way TIE]` | vn::to_chars 777 MB/s `[3-way TIE]` | fmt::format_to 683 MB/s `[3-way TIE]` |
| int64-negative-mixed-lengths-test-size[10000] | **jeaiii::to_text 1233 MB/s** (+75.2% over fmt::format_to) | fmt::format_to 704 MB/s `[TIE]` | std::to_chars 633 MB/s `[TIE]` | vn::to_chars 450 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | vn::to_chars 324 MB/s `[4-way TIE]` | std::to_chars 291 MB/s `[4-way TIE]` | fmt::format_to 197 MB/s `[4-way TIE]` | jeaiii::to_text 171 MB/s `[4-way TIE]` |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 2111 MB/s** (+71.7% over jeaiii::to_text) | jeaiii::to_text 1229 MB/s | std::to_chars 872 MB/s | fmt::format_to 298 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 1226 MB/s** (+45.5% over std::to_chars) | std::to_chars 842 MB/s | fmt::format_to 701 MB/s | vn::to_chars 480 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 2186 MB/s** (+73.3% over jeaiii::to_text) | jeaiii::to_text 1262 MB/s | std::to_chars 757 MB/s | fmt::format_to 716 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 496 MB/s `[3-way TIE]` | vn::to_chars 479 MB/s `[3-way TIE]` | std::to_chars 454 MB/s `[3-way TIE]` | fmt::format_to 338 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1408 MB/s** (+50.7% over jeaiii::to_text) | jeaiii::to_text 934 MB/s | std::to_chars 876 MB/s | fmt::format_to 482 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **std::to_chars 918 MB/s** (+35.0% over jeaiii::to_text) | jeaiii::to_text 680 MB/s `[TIE]` | vn::to_chars 589 MB/s `[TIE]` | fmt::format_to 374 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | jeaiii::to_text 898 MB/s `[TIE]` | std::to_chars 792 MB/s `[TIE]` | vn::to_chars 661 MB/s | fmt::format_to 438 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 190 MB/s `[4-way TIE]` | vn::to_chars 153 MB/s `[4-way TIE]` | std::to_chars 134 MB/s `[4-way TIE]` | fmt::format_to 105 MB/s `[4-way TIE]` |
