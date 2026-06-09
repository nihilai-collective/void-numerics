# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** GNU 15.2.0  

---

## int-to-str

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **14** | 5 | 18 |
| jeaiii::to_text | 11 | 10 | 20 |
| std::to_chars | 2 | 6 | 12 |
| fmt::format_to | 1 | 7 | 14 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | **jeaiii::to_text 159 MB/s** (+33.3% over vn::to_chars) | vn::to_chars 119 MB/s | std::to_chars 106 MB/s | fmt::format_to 95 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **jeaiii::to_text 166 MB/s** (+17.2% over vn::to_chars) | vn::to_chars 141 MB/s `[3-way TIE]` | fmt::format_to 124 MB/s `[3-way TIE]` | std::to_chars 108 MB/s `[3-way TIE]` |
| int8-negative-mixed-lengths-test-size[100000] | **std::to_chars 97 MB/s** (+21.6% over vn::to_chars) | vn::to_chars 80 MB/s `[3-way TIE]` | jeaiii::to_text 78 MB/s `[3-way TIE]` | fmt::format_to 53 MB/s `[3-way TIE]` |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | **vn::to_chars 168 MB/s** (+6.0% over fmt::format_to) | fmt::format_to 159 MB/s `[TIE]` | jeaiii::to_text 159 MB/s `[TIE]` | std::to_chars 60 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 168 MB/s** (+36.7% over vn::to_chars) | vn::to_chars 123 MB/s | std::to_chars 106 MB/s | fmt::format_to 95 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 169 MB/s** (+20.1% over fmt::format_to) | fmt::format_to 141 MB/s | std::to_chars 107 MB/s | vn::to_chars 80 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::to_chars 95 MB/s `[4-way TIE]` | fmt::format_to 95 MB/s `[4-way TIE]` | jeaiii::to_text 95 MB/s `[4-way TIE]` | std::to_chars 95 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 318 MB/s** (+33.3% over fmt::format_to) | fmt::format_to 238 MB/s | vn::to_chars 162 MB/s | std::to_chars 159 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | vn::to_chars 281 MB/s `[TIE]` | jeaiii::to_text 281 MB/s `[TIE]` | fmt::format_to 246 MB/s | std::to_chars 155 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **std::to_chars 147 MB/s** (+22.2% over jeaiii::to_text) | jeaiii::to_text 120 MB/s `[3-way TIE]` | fmt::format_to 111 MB/s `[3-way TIE]` | vn::to_chars 108 MB/s `[3-way TIE]` |
| int16-negative-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **fmt::format_to 272 MB/s** (+28.6% over std::to_chars) | std::to_chars 212 MB/s | vn::to_chars 191 MB/s | jeaiii::to_text 159 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 318 MB/s** (+9.7% over jeaiii::to_text) | jeaiii::to_text 290 MB/s | fmt::format_to 278 MB/s | std::to_chars 214 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 236 MB/s `[TIE]` | std::to_chars 218 MB/s `[TIE]` | fmt::format_to 149 MB/s `[TIE]` | vn::to_chars 143 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 318 MB/s** (+11.1% over jeaiii::to_text) | jeaiii::to_text 286 MB/s | std::to_chars 212 MB/s | fmt::format_to 147 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 301 MB/s** (+7.0% over fmt::format_to) | fmt::format_to 281 MB/s | std::to_chars 220 MB/s | jeaiii::to_text 162 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 276 MB/s `[3-way TIE]` | fmt::format_to 271 MB/s `[3-way TIE]` | vn::to_chars 256 MB/s `[3-way TIE]` | std::to_chars 161 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 191 MB/s `[4-way TIE]` | fmt::format_to 191 MB/s `[4-way TIE]` | jeaiii::to_text 191 MB/s `[4-way TIE]` | std::to_chars 191 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 954 MB/s** (+50.0% over fmt::format_to) | fmt::format_to 636 MB/s | jeaiii::to_text 401 MB/s | std::to_chars 381 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1060 MB/s** (+11.1% over jeaiii::to_text) | jeaiii::to_text 954 MB/s | fmt::format_to 617 MB/s | std::to_chars 382 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 596 MB/s** (+68.5% over std::to_chars) | std::to_chars 354 MB/s `[TIE]` | fmt::format_to 322 MB/s `[TIE]` | vn::to_chars 267 MB/s |
| int32-negative-mixed-lengths-test-size[100] | vn::to_chars 381 MB/s `[TIE]` | jeaiii::to_text 381 MB/s `[TIE]` | std::to_chars 286 MB/s | fmt::format_to 191 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | jeaiii::to_text 445 MB/s `[TIE]` | vn::to_chars 394 MB/s `[TIE]` | fmt::format_to 350 MB/s | std::to_chars 272 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 463 MB/s** (+1.9% over jeaiii::to_text) | jeaiii::to_text 454 MB/s | fmt::format_to 341 MB/s | std::to_chars 275 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | std::to_chars 236 MB/s `[4-way TIE]` | jeaiii::to_text 220 MB/s `[4-way TIE]` | vn::to_chars 151 MB/s `[4-way TIE]` | fmt::format_to 147 MB/s `[4-way TIE]` |
| int32-positive-mixed-lengths-test-size[100] | vn::to_chars 381 MB/s `[3-way TIE]` | fmt::format_to 381 MB/s `[3-way TIE]` | jeaiii::to_text 381 MB/s `[3-way TIE]` | std::to_chars 267 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | vn::to_chars 437 MB/s `[3-way TIE]` | jeaiii::to_text 434 MB/s `[3-way TIE]` | fmt::format_to 327 MB/s `[3-way TIE]` | std::to_chars 127 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 471 MB/s** (+6.7% over jeaiii::to_text) | jeaiii::to_text 442 MB/s | fmt::format_to 342 MB/s | std::to_chars 275 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 161 MB/s `[4-way TIE]` | fmt::format_to 156 MB/s `[4-way TIE]` | std::to_chars 127 MB/s `[4-way TIE]` | vn::to_chars 85 MB/s `[4-way TIE]` |
| uint32-positive-mixed-lengths-test-size[100] | fmt::format_to 381 MB/s `[3-way TIE]` | jeaiii::to_text 381 MB/s `[3-way TIE]` | std::to_chars 381 MB/s `[3-way TIE]` | vn::to_chars 212 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1272 MB/s** (+33.3% over jeaiii::to_text) | jeaiii::to_text 954 MB/s | fmt::format_to 636 MB/s | std::to_chars 424 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1032 MB/s** (+64.2% over fmt::format_to) | fmt::format_to 628 MB/s | jeaiii::to_text 456 MB/s | std::to_chars 439 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | jeaiii::to_text 317 MB/s `[4-way TIE]` | fmt::format_to 246 MB/s `[4-way TIE]` | std::to_chars 179 MB/s `[4-way TIE]` | vn::to_chars 137 MB/s `[4-way TIE]` |
| int64-negative-mixed-lengths-test-size[100] | **jeaiii::to_text 763 MB/s** (+57.1% over fmt::format_to) | fmt::format_to 486 MB/s `[TIE]` | vn::to_chars 458 MB/s `[TIE]` | std::to_chars 153 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1126 MB/s** (+47.6% over jeaiii::to_text) | jeaiii::to_text 763 MB/s | fmt::format_to 545 MB/s | std::to_chars 426 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1179 MB/s** (+52.4% over jeaiii::to_text) | jeaiii::to_text 774 MB/s | fmt::format_to 541 MB/s | std::to_chars 433 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | vn::to_chars 156 MB/s `[4-way TIE]` | fmt::format_to 151 MB/s `[4-way TIE]` | std::to_chars 136 MB/s `[4-way TIE]` | jeaiii::to_text 118 MB/s `[4-way TIE]` |
| int64-positive-mixed-lengths-test-size[100] | vn::to_chars 763 MB/s `[TIE]` | jeaiii::to_text 763 MB/s `[TIE]` | fmt::format_to 572 MB/s `[TIE]` | std::to_chars 420 MB/s `[TIE]` |
| int64-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 763 MB/s** (+25.8% over vn::to_chars) | vn::to_chars 606 MB/s | fmt::format_to 545 MB/s | std::to_chars 424 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1183 MB/s** (+74.0% over jeaiii::to_text) | jeaiii::to_text 680 MB/s | fmt::format_to 554 MB/s | std::to_chars 443 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 453 MB/s** (+39.9% over std::to_chars) | std::to_chars 324 MB/s `[3-way TIE]` | vn::to_chars 267 MB/s `[3-way TIE]` | fmt::format_to 143 MB/s `[3-way TIE]` |
| uint64-positive-mixed-lengths-test-size[100] | vn::to_chars 763 MB/s `[TIE]` | jeaiii::to_text 763 MB/s `[TIE]` | fmt::format_to 381 MB/s `[TIE]` | std::to_chars 381 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 848 MB/s** (+11.1% over vn::to_chars) | vn::to_chars 763 MB/s | fmt::format_to 402 MB/s `[TIE]` | std::to_chars 402 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1470 MB/s** (+69.4% over jeaiii::to_text) | jeaiii::to_text 868 MB/s | fmt::format_to 396 MB/s | std::to_chars 379 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 660 MB/s** (+72.8% over std::to_chars) | std::to_chars 382 MB/s | vn::to_chars 257 MB/s `[TIE]` | fmt::format_to 199 MB/s `[TIE]` |
