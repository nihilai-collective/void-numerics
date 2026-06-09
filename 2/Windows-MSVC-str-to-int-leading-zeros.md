# void-numerics Benchmark Results  
**Platform:** Intel(R) Core(TM) i9-14900KF  
**OS:** Windows 10.0.26200  
**Compiler:** MSVC 19.44.35227.0  

---

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **35** | 10 | 3 |
| std::from_chars | 10 | 35 | 3 |
| strtoll/strtoull | - | 3 | - |


---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **std::from_chars 48 MB/s** (+12.5% over vn::from_chars) | vn::from_chars 43 MB/s | strtoll/strtoull 24 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **std::from_chars 48 MB/s** (+11.7% over vn::from_chars) | vn::from_chars 43 MB/s | strtoll/strtoull 24 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **std::from_chars 48 MB/s** (+8.7% over vn::from_chars) | vn::from_chars 44 MB/s | strtoll/strtoull 23 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **std::from_chars 47 MB/s** (+7.9% over vn::from_chars) | vn::from_chars 44 MB/s | strtoll/strtoull 23 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **std::from_chars 48 MB/s** (+7.4% over vn::from_chars) | vn::from_chars 44 MB/s | strtoll/strtoull 23 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **std::from_chars 49 MB/s** (+3.8% over vn::from_chars) | vn::from_chars 47 MB/s | strtoll/strtoull 25 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **std::from_chars 49 MB/s** (+3.7% over vn::from_chars) | vn::from_chars 47 MB/s | strtoll/strtoull 24 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **std::from_chars 49 MB/s** (+4.1% over vn::from_chars) | vn::from_chars 47 MB/s | strtoll/strtoull 24 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | **vn::from_chars 61 MB/s** (+19.3% over std::from_chars) | std::from_chars 51 MB/s | strtoll/strtoull 24 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 60 MB/s** (+12.7% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 24 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | **vn::from_chars 63 MB/s** (+18.5% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 26 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::from_chars 61 MB/s** (+15.8% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 25 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::from_chars 88 MB/s** (+6.1% over std::from_chars) | std::from_chars 83 MB/s | strtoll/strtoull 45 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 89 MB/s** (+8.4% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 43 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::from_chars 89 MB/s** (+8.5% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 40 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::from_chars 90 MB/s** (+9.6% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 42 MB/s |
| int16-positive-mixed-lengths-test-size[100] | std::from_chars 139 MB/s `[TIE]` | vn::from_chars 131 MB/s `[TIE]` | strtoll/strtoull 74 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 181 MB/s** (+26.1% over std::from_chars) | std::from_chars 144 MB/s | strtoll/strtoull 80 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 183 MB/s** (+25.5% over std::from_chars) | std::from_chars 146 MB/s | strtoll/strtoull 47 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 181 MB/s** (+28.0% over std::from_chars) | std::from_chars 141 MB/s | strtoll/strtoull 73 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 131 MB/s** (+43.3% over std::from_chars) | std::from_chars 91 MB/s | strtoll/strtoull 43 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 134 MB/s** (+43.0% over std::from_chars) | std::from_chars 94 MB/s | strtoll/strtoull 44 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 137 MB/s** (+46.5% over std::from_chars) | std::from_chars 93 MB/s | strtoll/strtoull 48 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 135 MB/s** (+50.6% over std::from_chars) | std::from_chars 90 MB/s | strtoll/strtoull 48 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 175 MB/s** (+27.1% over std::from_chars) | std::from_chars 138 MB/s | strtoll/strtoull 66 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 178 MB/s** (+27.5% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 75 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 176 MB/s** (+26.0% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 73 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 176 MB/s** (+33.4% over std::from_chars) | std::from_chars 132 MB/s | strtoll/strtoull 66 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 161 MB/s** (+12.2% over std::from_chars) | std::from_chars 144 MB/s | strtoll/strtoull 73 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 184 MB/s** (+31.3% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 67 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 183 MB/s** (+34.0% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 65 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 183 MB/s** (+34.3% over std::from_chars) | std::from_chars 136 MB/s | strtoll/strtoull 74 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 227 MB/s** (+42.3% over std::from_chars) | std::from_chars 160 MB/s | strtoll/strtoull 80 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 232 MB/s** (+44.2% over std::from_chars) | std::from_chars 161 MB/s | strtoll/strtoull 81 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 236 MB/s** (+51.1% over std::from_chars) | std::from_chars 156 MB/s | strtoll/strtoull 81 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 231 MB/s** (+46.8% over std::from_chars) | std::from_chars 157 MB/s | strtoll/strtoull 73 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 285 MB/s** (+15.3% over std::from_chars) | std::from_chars 247 MB/s | strtoll/strtoull 105 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 291 MB/s** (+17.2% over std::from_chars) | std::from_chars 248 MB/s | strtoll/strtoull 115 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 289 MB/s** (+17.9% over std::from_chars) | std::from_chars 245 MB/s | strtoll/strtoull 117 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 285 MB/s** (+17.9% over std::from_chars) | std::from_chars 242 MB/s | strtoll/strtoull 115 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 295 MB/s** (+18.9% over std::from_chars) | std::from_chars 248 MB/s | strtoll/strtoull 104 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 286 MB/s** (+15.6% over std::from_chars) | std::from_chars 248 MB/s | strtoll/strtoull 117 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 289 MB/s** (+20.0% over std::from_chars) | std::from_chars 241 MB/s | strtoll/strtoull 105 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 286 MB/s** (+18.2% over std::from_chars) | std::from_chars 242 MB/s | strtoll/strtoull 107 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **std::from_chars 318 MB/s** (+7.9% over vn::from_chars) | vn::from_chars 295 MB/s | strtoll/strtoull 124 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **std::from_chars 317 MB/s** (+4.9% over vn::from_chars) | vn::from_chars 302 MB/s | strtoll/strtoull 111 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | std::from_chars 317 MB/s `[TIE]` | vn::from_chars 301 MB/s `[TIE]` | strtoll/strtoull 125 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | std::from_chars 307 MB/s `[TIE]` | vn::from_chars 302 MB/s `[TIE]` | strtoll/strtoull 120 MB/s |
