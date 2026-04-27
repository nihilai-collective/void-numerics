# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.4  

---
### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **47** | 1 | - |
| std::from_chars | 1 | 46 | - |
| strtoll/strtoull | - | 1 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 129 MB/s** (+27.7% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 74 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 131 MB/s** (+31.7% over std::from_chars) | std::from_chars 99 MB/s | strtoll/strtoull 77 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 132 MB/s** (+24.7% over std::from_chars) | std::from_chars 106 MB/s | strtoll/strtoull 72 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 138 MB/s** (+36.0% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 74 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 125 MB/s** (+18.6% over std::from_chars) | std::from_chars 105 MB/s | strtoll/strtoull 72 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 132 MB/s** (+24.4% over std::from_chars) | std::from_chars 106 MB/s | strtoll/strtoull 74 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 131 MB/s** (+28.0% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 74 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 129 MB/s** (+24.6% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 75 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 178 MB/s** (+21.7% over std::from_chars) | std::from_chars 146 MB/s | strtoll/strtoull 86 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 198 MB/s** (+32.5% over std::from_chars) | std::from_chars 150 MB/s | strtoll/strtoull 89 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 197 MB/s** (+28.4% over std::from_chars) | std::from_chars 153 MB/s | strtoll/strtoull 89 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 199 MB/s** (+30.4% over std::from_chars) | std::from_chars 152 MB/s | strtoll/strtoull 92 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 221 MB/s** (+17.9% over std::from_chars) | std::from_chars 188 MB/s | strtoll/strtoull 128 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 223 MB/s** (+5.9% over std::from_chars) | std::from_chars 211 MB/s | strtoll/strtoull 124 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 228 MB/s** (+8.6% over std::from_chars) | std::from_chars 210 MB/s | strtoll/strtoull 124 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 235 MB/s** (+11.0% over std::from_chars) | std::from_chars 212 MB/s | strtoll/strtoull 124 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 220 MB/s** (+79.8% over strtoll/strtoull) | strtoll/strtoull 122 MB/s | std::from_chars 85 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 224 MB/s** (+11.1% over std::from_chars) | std::from_chars 202 MB/s | strtoll/strtoull 122 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 222 MB/s** (+3.8% over std::from_chars) | std::from_chars 214 MB/s | strtoll/strtoull 123 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 223 MB/s** (+5.3% over std::from_chars) | std::from_chars 212 MB/s | strtoll/strtoull 129 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **std::from_chars 271 MB/s** (+56.8% over vn::from_chars) | vn::from_chars 173 MB/s | strtoll/strtoull 159 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 485 MB/s** (+73.3% over std::from_chars) | std::from_chars 280 MB/s | strtoll/strtoull 163 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 496 MB/s** (+71.5% over std::from_chars) | std::from_chars 289 MB/s | strtoll/strtoull 171 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 499 MB/s** (+79.3% over std::from_chars) | std::from_chars 278 MB/s | strtoll/strtoull 170 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 333 MB/s** (+54.2% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 178 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 357 MB/s** (+59.5% over std::from_chars) | std::from_chars 224 MB/s | strtoll/strtoull 176 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 358 MB/s** (+60.7% over std::from_chars) | std::from_chars 223 MB/s | strtoll/strtoull 179 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 376 MB/s** (+63.8% over std::from_chars) | std::from_chars 230 MB/s | strtoll/strtoull 176 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 343 MB/s** (+58.8% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 172 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 367 MB/s** (+66.1% over std::from_chars) | std::from_chars 221 MB/s | strtoll/strtoull 175 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 350 MB/s** (+58.3% over std::from_chars) | std::from_chars 221 MB/s | strtoll/strtoull 191 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 348 MB/s** (+44.6% over std::from_chars) | std::from_chars 240 MB/s | strtoll/strtoull 181 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 547 MB/s** (+58.8% over std::from_chars) | std::from_chars 344 MB/s | strtoll/strtoull 220 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 591 MB/s** (+66.1% over std::from_chars) | std::from_chars 356 MB/s | strtoll/strtoull 246 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 595 MB/s** (+73.2% over std::from_chars) | std::from_chars 343 MB/s | strtoll/strtoull 237 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 583 MB/s** (+65.3% over std::from_chars) | std::from_chars 353 MB/s | strtoll/strtoull 228 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 543 MB/s** (+67.0% over std::from_chars) | std::from_chars 325 MB/s | strtoll/strtoull 263 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 595 MB/s** (+79.9% over std::from_chars) | std::from_chars 331 MB/s | strtoll/strtoull 267 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 547 MB/s** (+71.3% over std::from_chars) | std::from_chars 319 MB/s | strtoll/strtoull 265 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 621 MB/s** (+102.1% over std::from_chars) | std::from_chars 307 MB/s | strtoll/strtoull 260 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 603 MB/s** (+77.1% over std::from_chars) | std::from_chars 340 MB/s | strtoll/strtoull 283 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 637 MB/s** (+79.8% over std::from_chars) | std::from_chars 354 MB/s | strtoll/strtoull 264 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 640 MB/s** (+94.7% over std::from_chars) | std::from_chars 328 MB/s | strtoll/strtoull 286 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 496 MB/s** (+54.3% over std::from_chars) | std::from_chars 322 MB/s | strtoll/strtoull 249 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 610 MB/s** (+78.6% over std::from_chars) | std::from_chars 342 MB/s | strtoll/strtoull 259 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 620 MB/s** (+84.9% over std::from_chars) | std::from_chars 335 MB/s | strtoll/strtoull 270 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 646 MB/s** (+82.1% over std::from_chars) | std::from_chars 355 MB/s | strtoll/strtoull 290 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 605 MB/s** (+67.8% over std::from_chars) | std::from_chars 361 MB/s | strtoll/strtoull 288 MB/s |
