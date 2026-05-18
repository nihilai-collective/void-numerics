# void-numerics Benchmark Results  
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Windows 10.0.26200  
**Compiler:** MSVC 19.44.35227.0  

---

### str-to-int Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **39** | - | 9 |
| std::from_chars | - | 39 | 9 |
| strtoll/strtoull | - | 9 | - |


---

## str-to-int

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 123 MB/s `[TIE]` | std::from_chars 121 MB/s `[TIE]` | strtoll/strtoull 50 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::from_chars 135 MB/s** (+9.9% over std::from_chars) | std::from_chars 123 MB/s | strtoll/strtoull 51 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 136 MB/s** (+8.5% over std::from_chars) | std::from_chars 125 MB/s | strtoll/strtoull 50 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 136 MB/s** (+9.2% over std::from_chars) | std::from_chars 124 MB/s | strtoll/strtoull 49 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 191 MB/s** (+20.0% over std::from_chars) | std::from_chars 159 MB/s | strtoll/strtoull 60 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 210 MB/s** (+24.5% over std::from_chars) | std::from_chars 169 MB/s | strtoll/strtoull 57 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 214 MB/s** (+15.3% over std::from_chars) | std::from_chars 186 MB/s | strtoll/strtoull 59 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 214 MB/s** (+14.1% over std::from_chars) | std::from_chars 188 MB/s | strtoll/strtoull 58 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 238 MB/s** (+25.0% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 64 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 266 MB/s** (+28.2% over std::from_chars) | std::from_chars 208 MB/s | strtoll/strtoull 64 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 271 MB/s** (+32.5% over std::from_chars) | std::from_chars 204 MB/s | strtoll/strtoull 64 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 272 MB/s** (+29.4% over std::from_chars) | std::from_chars 210 MB/s | strtoll/strtoull 63 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 193 MB/s** (+1.1% over std::from_chars) | std::from_chars 191 MB/s | strtoll/strtoull 91 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | vn::from_chars 197 MB/s `[TIE]` | std::from_chars 196 MB/s `[TIE]` | strtoll/strtoull 85 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | std::from_chars 201 MB/s `[TIE]` | vn::from_chars 201 MB/s `[TIE]` | strtoll/strtoull 86 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::from_chars 200 MB/s `[TIE]` | std::from_chars 200 MB/s `[TIE]` | strtoll/strtoull 86 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 272 MB/s** (+14.3% over std::from_chars) | std::from_chars 238 MB/s | strtoll/strtoull 95 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 274 MB/s** (+3.2% over std::from_chars) | std::from_chars 266 MB/s | strtoll/strtoull 96 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 274 MB/s** (+3.1% over std::from_chars) | std::from_chars 265 MB/s | strtoll/strtoull 96 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 276 MB/s** (+4.2% over std::from_chars) | std::from_chars 265 MB/s | strtoll/strtoull 97 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+20.0% over std::from_chars) | std::from_chars 318 MB/s | strtoll/strtoull 106 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 382 MB/s** (+19.8% over std::from_chars) | std::from_chars 319 MB/s | strtoll/strtoull 108 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 389 MB/s** (+21.4% over std::from_chars) | std::from_chars 321 MB/s | strtoll/strtoull 108 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 387 MB/s** (+22.1% over std::from_chars) | std::from_chars 317 MB/s | strtoll/strtoull 107 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 296 MB/s** (+16.3% over std::from_chars) | std::from_chars 254 MB/s | strtoll/strtoull 120 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 305 MB/s** (+21.0% over std::from_chars) | std::from_chars 252 MB/s | strtoll/strtoull 119 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 309 MB/s** (+22.4% over std::from_chars) | std::from_chars 252 MB/s | strtoll/strtoull 117 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 301 MB/s** (+22.6% over std::from_chars) | std::from_chars 246 MB/s | strtoll/strtoull 120 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 381 MB/s** (+30.0% over std::from_chars) | std::from_chars 293 MB/s | strtoll/strtoull 132 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 390 MB/s** (+30.9% over std::from_chars) | std::from_chars 298 MB/s | strtoll/strtoull 133 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 389 MB/s** (+32.9% over std::from_chars) | std::from_chars 293 MB/s | strtoll/strtoull 135 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 389 MB/s** (+32.0% over std::from_chars) | std::from_chars 294 MB/s | strtoll/strtoull 133 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | std::from_chars 477 MB/s `[TIE]` | vn::from_chars 477 MB/s `[TIE]` | strtoll/strtoull 147 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | std::from_chars 496 MB/s `[TIE]` | vn::from_chars 492 MB/s `[TIE]` | strtoll/strtoull 149 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | std::from_chars 495 MB/s `[TIE]` | vn::from_chars 493 MB/s `[TIE]` | strtoll/strtoull 147 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | std::from_chars 492 MB/s `[TIE]` | vn::from_chars 484 MB/s `[TIE]` | strtoll/strtoull 148 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 449 MB/s** (+11.1% over std::from_chars) | std::from_chars 404 MB/s | strtoll/strtoull 177 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 451 MB/s** (+9.3% over std::from_chars) | std::from_chars 412 MB/s | strtoll/strtoull 177 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 456 MB/s** (+10.9% over std::from_chars) | std::from_chars 411 MB/s | strtoll/strtoull 169 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | vn::from_chars 443 MB/s `[TIE]` | std::from_chars 388 MB/s `[TIE]` | strtoll/strtoull 175 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 477 MB/s** (+18.1% over std::from_chars) | std::from_chars 404 MB/s | strtoll/strtoull 182 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 484 MB/s** (+10.9% over std::from_chars) | std::from_chars 437 MB/s | strtoll/strtoull 183 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 489 MB/s** (+11.9% over std::from_chars) | std::from_chars 437 MB/s | strtoll/strtoull 174 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 481 MB/s** (+12.5% over std::from_chars) | std::from_chars 428 MB/s | strtoll/strtoull 180 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 480 MB/s** (+13.2% over std::from_chars) | std::from_chars 424 MB/s | strtoll/strtoull 177 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 504 MB/s** (+17.9% over std::from_chars) | std::from_chars 427 MB/s | strtoll/strtoull 179 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 503 MB/s** (+17.5% over std::from_chars) | std::from_chars 428 MB/s | strtoll/strtoull 180 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 508 MB/s** (+20.5% over std::from_chars) | std::from_chars 421 MB/s | strtoll/strtoull 174 MB/s |
