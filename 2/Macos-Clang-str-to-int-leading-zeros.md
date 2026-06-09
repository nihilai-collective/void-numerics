# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.4  

---

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **38** | 1 | 8 |
| std::from_chars | 2 | 38 | 8 |
| strtoll/strtoull | - | 9 | - |


---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | vn::from_chars 48 MB/s `[TIE]` | std::from_chars 45 MB/s `[TIE]` | strtoll/strtoull 33 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **std::from_chars 45 MB/s** (+30.6% over strtoll/strtoull) | strtoll/strtoull 35 MB/s | vn::from_chars 29 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 49 MB/s** (+8.8% over std::from_chars) | std::from_chars 45 MB/s | strtoll/strtoull 35 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **std::from_chars 45 MB/s** (+10.1% over vn::from_chars) | vn::from_chars 41 MB/s | strtoll/strtoull 34 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::from_chars 49 MB/s** (+8.4% over std::from_chars) | std::from_chars 45 MB/s | strtoll/strtoull 35 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 49 MB/s** (+6.8% over std::from_chars) | std::from_chars 45 MB/s | strtoll/strtoull 35 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 50 MB/s** (+7.6% over std::from_chars) | std::from_chars 46 MB/s | strtoll/strtoull 35 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 49 MB/s** (+7.7% over std::from_chars) | std::from_chars 46 MB/s | strtoll/strtoull 34 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 54 MB/s** (+10.0% over std::from_chars) | std::from_chars 49 MB/s | strtoll/strtoull 38 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 56 MB/s** (+6.8% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 38 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 55 MB/s** (+7.4% over std::from_chars) | std::from_chars 51 MB/s | strtoll/strtoull 39 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 56 MB/s** (+5.7% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 38 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::from_chars 99 MB/s `[TIE]` | std::from_chars 96 MB/s `[TIE]` | strtoll/strtoull 63 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | vn::from_chars 99 MB/s `[TIE]` | std::from_chars 98 MB/s `[TIE]` | strtoll/strtoull 63 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | vn::from_chars 98 MB/s `[TIE]` | std::from_chars 97 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::from_chars 97 MB/s `[TIE]` | std::from_chars 96 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| int16-positive-mixed-lengths-test-size[100] | vn::from_chars 99 MB/s `[TIE]` | std::from_chars 97 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | vn::from_chars 100 MB/s `[TIE]` | std::from_chars 98 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | std::from_chars 98 MB/s `[TIE]` | vn::from_chars 98 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 94 MB/s** (+7.0% over std::from_chars) | std::from_chars 87 MB/s | strtoll/strtoull 59 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 129 MB/s** (+25.1% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 71 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 128 MB/s** (+21.5% over std::from_chars) | std::from_chars 106 MB/s | strtoll/strtoull 73 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 128 MB/s** (+22.6% over std::from_chars) | std::from_chars 105 MB/s | strtoll/strtoull 72 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 124 MB/s** (+23.2% over std::from_chars) | std::from_chars 101 MB/s | strtoll/strtoull 69 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 170 MB/s** (+24.7% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 110 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 182 MB/s** (+30.9% over std::from_chars) | std::from_chars 139 MB/s | strtoll/strtoull 103 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 176 MB/s** (+35.9% over std::from_chars) | std::from_chars 129 MB/s | strtoll/strtoull 108 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 186 MB/s** (+36.9% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 107 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 179 MB/s** (+30.0% over std::from_chars) | std::from_chars 138 MB/s | strtoll/strtoull 109 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 190 MB/s** (+31.5% over std::from_chars) | std::from_chars 144 MB/s | strtoll/strtoull 114 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 196 MB/s** (+37.2% over std::from_chars) | std::from_chars 143 MB/s | strtoll/strtoull 118 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 194 MB/s** (+36.5% over std::from_chars) | std::from_chars 142 MB/s | strtoll/strtoull 115 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 230 MB/s** (+47.6% over std::from_chars) | std::from_chars 156 MB/s | strtoll/strtoull 130 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 250 MB/s** (+67.4% over std::from_chars) | std::from_chars 149 MB/s | strtoll/strtoull 130 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 253 MB/s** (+54.1% over std::from_chars) | std::from_chars 164 MB/s | strtoll/strtoull 130 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 224 MB/s** (+41.6% over std::from_chars) | std::from_chars 158 MB/s | strtoll/strtoull 125 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 331 MB/s** (+60.3% over std::from_chars) | std::from_chars 206 MB/s | strtoll/strtoull 174 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 334 MB/s** (+61.3% over std::from_chars) | std::from_chars 207 MB/s | strtoll/strtoull 173 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 332 MB/s** (+66.7% over std::from_chars) | std::from_chars 199 MB/s | strtoll/strtoull 172 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 246 MB/s** (+38.2% over std::from_chars) | std::from_chars 178 MB/s | strtoll/strtoull 119 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 317 MB/s** (+56.0% over std::from_chars) | std::from_chars 203 MB/s | strtoll/strtoull 66 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 334 MB/s** (+60.5% over std::from_chars) | std::from_chars 208 MB/s | strtoll/strtoull 166 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 334 MB/s** (+55.1% over std::from_chars) | std::from_chars 216 MB/s | strtoll/strtoull 167 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 323 MB/s** (+50.2% over std::from_chars) | std::from_chars 215 MB/s | strtoll/strtoull 173 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 325 MB/s** (+57.3% over std::from_chars) | std::from_chars 206 MB/s | strtoll/strtoull 179 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 337 MB/s** (+60.1% over std::from_chars) | std::from_chars 211 MB/s | strtoll/strtoull 179 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 339 MB/s** (+55.1% over std::from_chars) | std::from_chars 219 MB/s | strtoll/strtoull 186 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 324 MB/s** (+49.7% over std::from_chars) | std::from_chars 217 MB/s | strtoll/strtoull 167 MB/s |
