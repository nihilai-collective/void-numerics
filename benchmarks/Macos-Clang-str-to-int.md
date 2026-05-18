# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.6  

---

## str-to-int

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **41** | - | 6 |
| std::from_chars | 1 | 39 | 6 |
| strtoll/strtoull | - | 9 | - |

---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 123 MB/s** (+19.3% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 73 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 130 MB/s** (+20.7% over std::from_chars) | std::from_chars 108 MB/s | strtoll/strtoull 74 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 116 MB/s** (+7.3% over std::from_chars) | std::from_chars 108 MB/s | strtoll/strtoull 74 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 128 MB/s** (+26.3% over std::from_chars) | std::from_chars 102 MB/s | strtoll/strtoull 74 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 124 MB/s** (+16.8% over std::from_chars) | std::from_chars 106 MB/s | strtoll/strtoull 72 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 131 MB/s** (+78.7% over strtoll/strtoull) | strtoll/strtoull 73 MB/s | std::from_chars 54 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 132 MB/s** (+21.5% over std::from_chars) | std::from_chars 108 MB/s | strtoll/strtoull 74 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 131 MB/s** (+21.0% over std::from_chars) | std::from_chars 108 MB/s | strtoll/strtoull 74 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 179 MB/s** (+21.6% over std::from_chars) | std::from_chars 147 MB/s | strtoll/strtoull 88 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 192 MB/s** (+27.1% over std::from_chars) | std::from_chars 151 MB/s | strtoll/strtoull 90 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 195 MB/s** (+27.6% over std::from_chars) | std::from_chars 153 MB/s | strtoll/strtoull 92 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 166 MB/s** (+10.0% over std::from_chars) | std::from_chars 151 MB/s | strtoll/strtoull 89 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::from_chars 220 MB/s `[TIE]` | std::from_chars 212 MB/s `[TIE]` | strtoll/strtoull 116 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | vn::from_chars 222 MB/s `[TIE]` | std::from_chars 221 MB/s `[TIE]` | strtoll/strtoull 125 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | vn::from_chars 222 MB/s `[TIE]` | std::from_chars 221 MB/s `[TIE]` | strtoll/strtoull 125 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::from_chars 223 MB/s `[TIE]` | std::from_chars 219 MB/s `[TIE]` | strtoll/strtoull 121 MB/s |
| int16-positive-mixed-lengths-test-size[100] | std::from_chars 211 MB/s `[TIE]` | vn::from_chars 209 MB/s `[TIE]` | strtoll/strtoull 119 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | vn::from_chars 223 MB/s `[TIE]` | std::from_chars 219 MB/s `[TIE]` | strtoll/strtoull 124 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 225 MB/s** (+3.8% over std::from_chars) | std::from_chars 217 MB/s | strtoll/strtoull 124 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 226 MB/s** (+6.4% over std::from_chars) | std::from_chars 212 MB/s | strtoll/strtoull 125 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 463 MB/s** (+57.5% over std::from_chars) | std::from_chars 294 MB/s | strtoll/strtoull 165 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 492 MB/s** (+188.8% over strtoll/strtoull) | strtoll/strtoull 170 MB/s | std::from_chars 115 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 496 MB/s** (+54.2% over std::from_chars) | std::from_chars 322 MB/s | strtoll/strtoull 177 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 488 MB/s** (+51.9% over std::from_chars) | std::from_chars 321 MB/s | strtoll/strtoull 169 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 368 MB/s** (+66.2% over std::from_chars) | std::from_chars 221 MB/s | strtoll/strtoull 177 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 350 MB/s** (+52.4% over std::from_chars) | std::from_chars 230 MB/s | strtoll/strtoull 182 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 356 MB/s** (+56.0% over std::from_chars) | std::from_chars 228 MB/s | strtoll/strtoull 181 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 344 MB/s** (+50.7% over std::from_chars) | std::from_chars 228 MB/s | strtoll/strtoull 180 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 372 MB/s** (+65.5% over std::from_chars) | std::from_chars 225 MB/s | strtoll/strtoull 185 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 349 MB/s** (+52.1% over std::from_chars) | std::from_chars 229 MB/s | strtoll/strtoull 188 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 376 MB/s** (+53.7% over std::from_chars) | std::from_chars 245 MB/s | strtoll/strtoull 188 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 348 MB/s** (+54.0% over std::from_chars) | std::from_chars 226 MB/s | strtoll/strtoull 181 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 610 MB/s** (+77.3% over std::from_chars) | std::from_chars 344 MB/s | strtoll/strtoull 229 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **std::from_chars 355 MB/s** (+49.0% over strtoll/strtoull) | strtoll/strtoull 238 MB/s | vn::from_chars 231 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 601 MB/s** (+66.0% over std::from_chars) | std::from_chars 362 MB/s | strtoll/strtoull 227 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 622 MB/s** (+77.5% over std::from_chars) | std::from_chars 351 MB/s | strtoll/strtoull 238 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 578 MB/s** (+74.8% over std::from_chars) | std::from_chars 331 MB/s | strtoll/strtoull 264 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 615 MB/s** (+75.7% over std::from_chars) | std::from_chars 350 MB/s | strtoll/strtoull 276 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 616 MB/s** (+83.1% over std::from_chars) | std::from_chars 337 MB/s | strtoll/strtoull 276 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 493 MB/s** (+90.1% over std::from_chars) | std::from_chars 259 MB/s | strtoll/strtoull 251 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 592 MB/s** (+71.2% over std::from_chars) | std::from_chars 346 MB/s | strtoll/strtoull 267 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 616 MB/s** (+76.0% over std::from_chars) | std::from_chars 350 MB/s | strtoll/strtoull 276 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 536 MB/s** (+53.2% over std::from_chars) | std::from_chars 350 MB/s | strtoll/strtoull 275 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 507 MB/s** (+55.5% over std::from_chars) | std::from_chars 326 MB/s | strtoll/strtoull 257 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 576 MB/s** (+78.3% over std::from_chars) | std::from_chars 323 MB/s | strtoll/strtoull 278 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 599 MB/s** (+77.3% over std::from_chars) | std::from_chars 338 MB/s | strtoll/strtoull 281 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 600 MB/s** (+71.7% over std::from_chars) | std::from_chars 349 MB/s | strtoll/strtoull 270 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 604 MB/s** (+81.5% over std::from_chars) | std::from_chars 333 MB/s | strtoll/strtoull 279 MB/s |

