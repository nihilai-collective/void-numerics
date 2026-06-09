# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.6  

---

## int-to-str

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **16** | 2 | 16 |
| std::to_chars | 8 | 6 | 15 |
| jeaiii::to_text | 6 | 7 | 18 |
| fmt::format_to | - | 2 | 13 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::to_chars 176 MB/s `[4-way TIE]` | jeaiii::to_text 169 MB/s `[4-way TIE]` | std::to_chars 156 MB/s `[4-way TIE]` | fmt::format_to 156 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[1000] | vn::to_chars 162 MB/s `[4-way TIE]` | std::to_chars 158 MB/s `[4-way TIE]` | jeaiii::to_text 151 MB/s `[4-way TIE]` | fmt::format_to 150 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[10000] | std::to_chars 156 MB/s `[4-way TIE]` | jeaiii::to_text 149 MB/s `[4-way TIE]` | fmt::format_to 136 MB/s `[4-way TIE]` | vn::to_chars 119 MB/s `[4-way TIE]` |
| int8-negative-mixed-lengths-test-size[100000] | jeaiii::to_text 90 MB/s `[4-way TIE]` | vn::to_chars 84 MB/s `[4-way TIE]` | std::to_chars 83 MB/s `[4-way TIE]` | fmt::format_to 82 MB/s `[4-way TIE]` |
| int8-positive-mixed-lengths-test-size[100] | vn::to_chars 167 MB/s `[4-way TIE]` | jeaiii::to_text 158 MB/s `[4-way TIE]` | std::to_chars 147 MB/s `[4-way TIE]` | fmt::format_to 147 MB/s `[4-way TIE]` |
| int8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 171 MB/s** (+9.1% over std::to_chars) | std::to_chars 157 MB/s `[TIE]` | fmt::format_to 157 MB/s `[TIE]` | vn::to_chars 125 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 175 MB/s** (+11.4% over std::to_chars) | std::to_chars 157 MB/s | fmt::format_to 113 MB/s | vn::to_chars 98 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | std::to_chars 102 MB/s `[4-way TIE]` | jeaiii::to_text 98 MB/s `[4-way TIE]` | vn::to_chars 85 MB/s `[4-way TIE]` | fmt::format_to 76 MB/s `[4-way TIE]` |
| uint8-positive-mixed-lengths-test-size[100] | vn::to_chars 268 MB/s `[TIE]` | jeaiii::to_text 261 MB/s `[TIE]` | std::to_chars 229 MB/s | fmt::format_to 214 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 291 MB/s** (+15.6% over fmt::format_to) | fmt::format_to 252 MB/s `[3-way TIE]` | vn::to_chars 232 MB/s `[3-way TIE]` | std::to_chars 225 MB/s `[3-way TIE]` |
| uint8-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 301 MB/s** (+8.2% over vn::to_chars) | vn::to_chars 279 MB/s | fmt::format_to 260 MB/s | std::to_chars 225 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | std::to_chars 122 MB/s `[4-way TIE]` | jeaiii::to_text 110 MB/s `[4-way TIE]` | fmt::format_to 99 MB/s `[4-way TIE]` | vn::to_chars 97 MB/s `[4-way TIE]` |
| int16-negative-mixed-lengths-test-size[100] | **vn::to_chars 314 MB/s** (+14.5% over jeaiii::to_text) | jeaiii::to_text 275 MB/s `[3-way TIE]` | std::to_chars 271 MB/s `[3-way TIE]` | fmt::format_to 249 MB/s `[3-way TIE]` |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 323 MB/s** (+10.2% over jeaiii::to_text) | jeaiii::to_text 293 MB/s | std::to_chars 273 MB/s | fmt::format_to 131 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **std::to_chars 292 MB/s** (+39.3% over fmt::format_to) | fmt::format_to 210 MB/s | vn::to_chars 185 MB/s | jeaiii::to_text 130 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::to_chars 156 MB/s `[4-way TIE]` | std::to_chars 149 MB/s `[4-way TIE]` | jeaiii::to_text 149 MB/s `[4-way TIE]` | fmt::format_to 90 MB/s `[4-way TIE]` |
| int16-positive-mixed-lengths-test-size[100] | vn::to_chars 307 MB/s `[TIE]` | jeaiii::to_text 292 MB/s `[TIE]` | std::to_chars 262 MB/s `[TIE]` | fmt::format_to 248 MB/s `[TIE]` |
| int16-positive-mixed-lengths-test-size[1000] | jeaiii::to_text 289 MB/s `[TIE]` | std::to_chars 279 MB/s `[TIE]` | fmt::format_to 266 MB/s | vn::to_chars 166 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | vn::to_chars 299 MB/s `[TIE]` | jeaiii::to_text 297 MB/s `[TIE]` | std::to_chars 273 MB/s | fmt::format_to 234 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **std::to_chars 236 MB/s** (+45.9% over jeaiii::to_text) | jeaiii::to_text 162 MB/s `[TIE]` | fmt::format_to 155 MB/s `[TIE]` | vn::to_chars 117 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | vn::to_chars 877 MB/s `[4-way TIE]` | jeaiii::to_text 793 MB/s `[4-way TIE]` | std::to_chars 664 MB/s `[4-way TIE]` | fmt::format_to 596 MB/s `[4-way TIE]` |
| uint16-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 861 MB/s** (+26.0% over std::to_chars) | std::to_chars 683 MB/s | vn::to_chars 347 MB/s | fmt::format_to 164 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **jeaiii::to_text 868 MB/s** (+25.2% over std::to_chars) | std::to_chars 693 MB/s | fmt::format_to 388 MB/s | vn::to_chars 298 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **std::to_chars 334 MB/s** (+87.1% over jeaiii::to_text) | jeaiii::to_text 179 MB/s `[TIE]` | vn::to_chars 155 MB/s `[TIE]` | fmt::format_to 67 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::to_chars 490 MB/s** (+10.7% over jeaiii::to_text) | jeaiii::to_text 442 MB/s `[TIE]` | std::to_chars 426 MB/s `[TIE]` | fmt::format_to 348 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 516 MB/s** (+14.8% over std::to_chars) | std::to_chars 450 MB/s `[TIE]` | jeaiii::to_text 440 MB/s `[TIE]` | fmt::format_to 337 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | jeaiii::to_text 448 MB/s `[TIE]` | std::to_chars 440 MB/s `[TIE]` | vn::to_chars 397 MB/s | fmt::format_to 359 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **std::to_chars 327 MB/s** (+51.3% over vn::to_chars) | vn::to_chars 216 MB/s `[3-way TIE]` | jeaiii::to_text 155 MB/s `[3-way TIE]` | fmt::format_to 107 MB/s `[3-way TIE]` |
| int32-positive-mixed-lengths-test-size[100] | **vn::to_chars 524 MB/s** (+18.3% over jeaiii::to_text) | jeaiii::to_text 443 MB/s `[TIE]` | std::to_chars 442 MB/s `[TIE]` | fmt::format_to 346 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 526 MB/s** (+18.0% over jeaiii::to_text) | jeaiii::to_text 445 MB/s `[TIE]` | std::to_chars 437 MB/s `[TIE]` | fmt::format_to 355 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 516 MB/s** (+16.7% over jeaiii::to_text) | jeaiii::to_text 442 MB/s `[TIE]` | std::to_chars 434 MB/s `[TIE]` | fmt::format_to 353 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | std::to_chars 215 MB/s `[4-way TIE]` | vn::to_chars 205 MB/s `[4-way TIE]` | fmt::format_to 185 MB/s `[4-way TIE]` | jeaiii::to_text 177 MB/s `[4-way TIE]` |
| uint32-positive-mixed-lengths-test-size[100] | **vn::to_chars 1178 MB/s** (+40.0% over std::to_chars) | std::to_chars 841 MB/s `[TIE]` | jeaiii::to_text 840 MB/s `[TIE]` | fmt::format_to 680 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1299 MB/s** (+46.8% over std::to_chars) | std::to_chars 885 MB/s `[TIE]` | jeaiii::to_text 876 MB/s `[TIE]` | fmt::format_to 724 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1327 MB/s** (+43.8% over std::to_chars) | std::to_chars 923 MB/s | fmt::format_to 746 MB/s | jeaiii::to_text 412 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **std::to_chars 494 MB/s** (+133.6% over fmt::format_to) | fmt::format_to 211 MB/s `[3-way TIE]` | jeaiii::to_text 150 MB/s `[3-way TIE]` | vn::to_chars 117 MB/s `[3-way TIE]` |
| int64-negative-mixed-lengths-test-size[100] | vn::to_chars 995 MB/s `[4-way TIE]` | jeaiii::to_text 865 MB/s `[4-way TIE]` | std::to_chars 807 MB/s `[4-way TIE]` | fmt::format_to 259 MB/s `[4-way TIE]` |
| int64-negative-mixed-lengths-test-size[1000] | **std::to_chars 845 MB/s** (+99.9% over fmt::format_to) | fmt::format_to 423 MB/s `[TIE]` | jeaiii::to_text 365 MB/s `[TIE]` | vn::to_chars 290 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1007 MB/s** (+18.5% over jeaiii::to_text) | jeaiii::to_text 850 MB/s `[TIE]` | std::to_chars 847 MB/s `[TIE]` | fmt::format_to 709 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | vn::to_chars 243 MB/s `[4-way TIE]` | fmt::format_to 242 MB/s `[4-way TIE]` | std::to_chars 183 MB/s `[4-way TIE]` | jeaiii::to_text 147 MB/s `[4-way TIE]` |
| int64-positive-mixed-lengths-test-size[100] | vn::to_chars 912 MB/s `[4-way TIE]` | jeaiii::to_text 822 MB/s `[4-way TIE]` | std::to_chars 319 MB/s `[4-way TIE]` | fmt::format_to 257 MB/s `[4-way TIE]` |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1219 MB/s** (+38.0% over jeaiii::to_text) | jeaiii::to_text 883 MB/s | std::to_chars 849 MB/s | fmt::format_to 773 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1218 MB/s** (+41.1% over jeaiii::to_text) | jeaiii::to_text 863 MB/s `[TIE]` | std::to_chars 859 MB/s `[TIE]` | fmt::format_to 717 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **std::to_chars 838 MB/s** (+70.2% over jeaiii::to_text) | jeaiii::to_text 493 MB/s | fmt::format_to 369 MB/s `[TIE]` | vn::to_chars 348 MB/s `[TIE]` |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 1257 MB/s** (+35.1% over jeaiii::to_text) | jeaiii::to_text 930 MB/s | std::to_chars 881 MB/s | fmt::format_to 461 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1422 MB/s** (+37.3% over jeaiii::to_text) | jeaiii::to_text 1036 MB/s | std::to_chars 880 MB/s | fmt::format_to 435 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1416 MB/s** (+48.1% over jeaiii::to_text) | jeaiii::to_text 956 MB/s | fmt::format_to 467 MB/s | std::to_chars 320 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **std::to_chars 837 MB/s** (+107.5% over jeaiii::to_text) | jeaiii::to_text 403 MB/s | vn::to_chars 298 MB/s `[TIE]` | fmt::format_to 257 MB/s `[TIE]` |
