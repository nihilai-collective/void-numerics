
# void-numerics Benchmark Results  
**Platform:** Apple M1 (Virtual)  
**OS:** Darwin 24.6.0  
**Compiler:** Clang 22.1.6  

---

## str-to-int-leading-zeros

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **35** | 1 | 9 |
| std::from_chars | 4 | 31 | 9 |
| strtoll/strtoull | - | 12 | 2 |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::from_chars 48 MB/s** (+4.2% over std::from_chars) | std::from_chars 46 MB/s | strtoll/strtoull 35 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **std::from_chars 51 MB/s** (+3.8% over vn::from_chars) | vn::from_chars 49 MB/s | strtoll/strtoull 35 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::from_chars 49 MB/s** (+3.0% over std::from_chars) | std::from_chars 47 MB/s | strtoll/strtoull 35 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::from_chars 49 MB/s** (+4.0% over std::from_chars) | std::from_chars 47 MB/s | strtoll/strtoull 34 MB/s |
| int8-positive-mixed-lengths-test-size[100] | vn::from_chars 48 MB/s `[TIE]` | std::from_chars 46 MB/s `[TIE]` | strtoll/strtoull 34 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 49 MB/s** (+5.3% over std::from_chars) | std::from_chars 47 MB/s | strtoll/strtoull 34 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 49 MB/s** (+3.5% over std::from_chars) | std::from_chars 47 MB/s | strtoll/strtoull 36 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **std::from_chars 47 MB/s** (+15.0% over vn::from_chars) | vn::from_chars 41 MB/s `[TIE]` | strtoll/strtoull 33 MB/s `[TIE]` |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 56 MB/s** (+13.5% over std::from_chars) | std::from_chars 49 MB/s | strtoll/strtoull 36 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **std::from_chars 53 MB/s** (+35.3% over strtoll/strtoull) | strtoll/strtoull 39 MB/s | vn::from_chars 33 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 56 MB/s** (+6.7% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 38 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 56 MB/s** (+8.0% over std::from_chars) | std::from_chars 52 MB/s | strtoll/strtoull 38 MB/s |
| int16-negative-mixed-lengths-test-size[100] | std::from_chars 92 MB/s `[TIE]` | vn::from_chars 92 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | vn::from_chars 100 MB/s `[TIE]` | std::from_chars 97 MB/s `[TIE]` | strtoll/strtoull 64 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | vn::from_chars 99 MB/s `[TIE]` | std::from_chars 98 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::from_chars 97 MB/s `[TIE]` | std::from_chars 96 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 95 MB/s** (+52.4% over strtoll/strtoull) | strtoll/strtoull 62 MB/s | std::from_chars 46 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 100 MB/s** (+3.7% over std::from_chars) | std::from_chars 97 MB/s | strtoll/strtoull 65 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | vn::from_chars 97 MB/s `[TIE]` | std::from_chars 97 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | vn::from_chars 86 MB/s `[TIE]` | std::from_chars 80 MB/s `[TIE]` | strtoll/strtoull 62 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 122 MB/s** (+19.0% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 68 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 126 MB/s** (+19.0% over std::from_chars) | std::from_chars 106 MB/s | strtoll/strtoull 72 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 126 MB/s** (+22.4% over std::from_chars) | std::from_chars 103 MB/s | strtoll/strtoull 69 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | std::from_chars 100 MB/s `[3-way TIE]` | vn::from_chars 90 MB/s `[3-way TIE]` | strtoll/strtoull 59 MB/s `[3-way TIE]` |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 179 MB/s** (+65.9% over strtoll/strtoull) | strtoll/strtoull 108 MB/s | std::from_chars 68 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 179 MB/s** (+29.5% over std::from_chars) | std::from_chars 138 MB/s | strtoll/strtoull 107 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 180 MB/s** (+27.3% over std::from_chars) | std::from_chars 141 MB/s | strtoll/strtoull 106 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 176 MB/s** (+29.6% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 101 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 178 MB/s** (+29.2% over std::from_chars) | std::from_chars 138 MB/s `[TIE]` | strtoll/strtoull 89 MB/s `[TIE]` |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 178 MB/s** (+25.5% over std::from_chars) | std::from_chars 142 MB/s | strtoll/strtoull 106 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 182 MB/s** (+29.9% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 107 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 182 MB/s** (+28.0% over std::from_chars) | std::from_chars 142 MB/s | strtoll/strtoull 109 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 233 MB/s** (+56.0% over std::from_chars) | std::from_chars 149 MB/s | strtoll/strtoull 119 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 235 MB/s** (+54.0% over std::from_chars) | std::from_chars 152 MB/s | strtoll/strtoull 120 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 236 MB/s** (+56.3% over std::from_chars) | std::from_chars 151 MB/s | strtoll/strtoull 121 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 229 MB/s** (+59.6% over std::from_chars) | std::from_chars 143 MB/s | strtoll/strtoull 118 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 314 MB/s** (+52.9% over std::from_chars) | std::from_chars 205 MB/s | strtoll/strtoull 168 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **std::from_chars 213 MB/s** (+27.6% over strtoll/strtoull) | strtoll/strtoull 167 MB/s | vn::from_chars 128 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 308 MB/s** (+47.1% over std::from_chars) | std::from_chars 210 MB/s | strtoll/strtoull 153 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 245 MB/s** (+51.0% over strtoll/strtoull) | strtoll/strtoull 162 MB/s | std::from_chars 110 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 316 MB/s** (+49.3% over std::from_chars) | std::from_chars 211 MB/s | strtoll/strtoull 166 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 304 MB/s** (+53.5% over std::from_chars) | std::from_chars 198 MB/s | strtoll/strtoull 166 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 308 MB/s** (+53.1% over std::from_chars) | std::from_chars 201 MB/s | strtoll/strtoull 165 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 262 MB/s** (+38.7% over std::from_chars) | std::from_chars 189 MB/s | strtoll/strtoull 151 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::from_chars 319 MB/s** (+52.6% over std::from_chars) | std::from_chars 209 MB/s | strtoll/strtoull 179 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 324 MB/s** (+57.1% over std::from_chars) | std::from_chars 206 MB/s | strtoll/strtoull 180 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 325 MB/s** (+55.6% over std::from_chars) | std::from_chars 209 MB/s | strtoll/strtoull 175 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | std::from_chars 172 MB/s `[3-way TIE]` | vn::from_chars 164 MB/s `[3-way TIE]` | strtoll/strtoull 149 MB/s `[3-way TIE]` |

