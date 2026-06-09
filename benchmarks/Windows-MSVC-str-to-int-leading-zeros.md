# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Windows 10.0.26200
**Compiler:** MSVC 19.44.35227.0

---

## str-to-int-leading-zeros

### str-to-int-leading-zeros Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::from_chars** | **28** | 6 | 14 |
| std::from_chars | 6 | 28 | 14 |
| strtoll/strtoull | - | 14 | - |

---

## str-to-int-leading-zeros

| Test | 1st | 2nd | 3rd |
|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **std::from_chars 48 MB/s** (+10.1% over vn::from_chars) | vn::from_chars 44 MB/s | strtoll/strtoull 22 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **std::from_chars 48 MB/s** (+8.2% over vn::from_chars) | vn::from_chars 44 MB/s | strtoll/strtoull 22 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | std::from_chars 47 MB/s `[TIE]` | vn::from_chars 42 MB/s `[TIE]` | strtoll/strtoull 23 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | std::from_chars 46 MB/s `[TIE]` | vn::from_chars 43 MB/s `[TIE]` | strtoll/strtoull 22 MB/s |
| int8-positive-mixed-lengths-test-size[100] | std::from_chars 46 MB/s `[TIE]` | vn::from_chars 43 MB/s `[TIE]` | strtoll/strtoull 22 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **std::from_chars 48 MB/s** (+10.6% over vn::from_chars) | vn::from_chars 43 MB/s | strtoll/strtoull 24 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **std::from_chars 46 MB/s** (+20.8% over vn::from_chars) | vn::from_chars 38 MB/s | strtoll/strtoull 21 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **std::from_chars 46 MB/s** (+9.8% over vn::from_chars) | vn::from_chars 42 MB/s | strtoll/strtoull 22 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | vn::from_chars 54 MB/s `[TIE]` | std::from_chars 53 MB/s `[TIE]` | strtoll/strtoull 24 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::from_chars 57 MB/s** (+7.1% over std::from_chars) | std::from_chars 53 MB/s | strtoll/strtoull 24 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | vn::from_chars 56 MB/s `[TIE]` | std::from_chars 51 MB/s `[TIE]` | strtoll/strtoull 26 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | vn::from_chars 54 MB/s `[TIE]` | std::from_chars 52 MB/s `[TIE]` | strtoll/strtoull 23 MB/s |
| int16-negative-mixed-lengths-test-size[100] | vn::from_chars 85 MB/s `[TIE]` | std::from_chars 81 MB/s `[TIE]` | strtoll/strtoull 44 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::from_chars 87 MB/s** (+5.5% over std::from_chars) | std::from_chars 83 MB/s | strtoll/strtoull 39 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | vn::from_chars 88 MB/s `[TIE]` | std::from_chars 81 MB/s `[TIE]` | strtoll/strtoull 42 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | vn::from_chars 86 MB/s `[TIE]` | std::from_chars 81 MB/s `[TIE]` | strtoll/strtoull 40 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::from_chars 88 MB/s** (+9.3% over std::from_chars) | std::from_chars 81 MB/s | strtoll/strtoull 43 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 86 MB/s** (+4.8% over std::from_chars) | std::from_chars 82 MB/s | strtoll/strtoull 43 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | vn::from_chars 87 MB/s `[TIE]` | std::from_chars 81 MB/s `[TIE]` | strtoll/strtoull 43 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | vn::from_chars 84 MB/s `[TIE]` | std::from_chars 80 MB/s `[TIE]` | strtoll/strtoull 38 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | **vn::from_chars 129 MB/s** (+39.9% over std::from_chars) | std::from_chars 92 MB/s | strtoll/strtoull 48 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::from_chars 127 MB/s** (+35.4% over std::from_chars) | std::from_chars 94 MB/s | strtoll/strtoull 48 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::from_chars 126 MB/s** (+41.9% over std::from_chars) | std::from_chars 89 MB/s | strtoll/strtoull 48 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::from_chars 125 MB/s** (+39.3% over std::from_chars) | std::from_chars 90 MB/s | strtoll/strtoull 43 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::from_chars 177 MB/s** (+28.3% over std::from_chars) | std::from_chars 138 MB/s | strtoll/strtoull 74 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::from_chars 177 MB/s** (+26.4% over std::from_chars) | std::from_chars 140 MB/s | strtoll/strtoull 73 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::from_chars 175 MB/s** (+26.9% over std::from_chars) | std::from_chars 138 MB/s | strtoll/strtoull 70 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::from_chars 168 MB/s** (+32.2% over std::from_chars) | std::from_chars 127 MB/s | strtoll/strtoull 68 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::from_chars 175 MB/s** (+30.7% over std::from_chars) | std::from_chars 134 MB/s | strtoll/strtoull 74 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 248 MB/s** (+77.9% over std::from_chars) | std::from_chars 139 MB/s | strtoll/strtoull 67 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 172 MB/s** (+25.2% over std::from_chars) | std::from_chars 137 MB/s | strtoll/strtoull 65 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 169 MB/s** (+26.0% over std::from_chars) | std::from_chars 134 MB/s | strtoll/strtoull 67 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::from_chars 227 MB/s** (+42.3% over std::from_chars) | std::from_chars 160 MB/s | strtoll/strtoull 80 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::from_chars 225 MB/s** (+39.2% over std::from_chars) | std::from_chars 162 MB/s | strtoll/strtoull 81 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::from_chars 222 MB/s** (+42.7% over std::from_chars) | std::from_chars 155 MB/s | strtoll/strtoull 81 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::from_chars 210 MB/s** (+42.5% over std::from_chars) | std::from_chars 147 MB/s | strtoll/strtoull 76 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **vn::from_chars 285 MB/s** (+18.3% over std::from_chars) | std::from_chars 241 MB/s | strtoll/strtoull 116 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::from_chars 285 MB/s** (+15.7% over std::from_chars) | std::from_chars 247 MB/s | strtoll/strtoull 116 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::from_chars 278 MB/s** (+14.1% over std::from_chars) | std::from_chars 244 MB/s | strtoll/strtoull 116 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::from_chars 272 MB/s** (+14.6% over std::from_chars) | std::from_chars 237 MB/s | strtoll/strtoull 103 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::from_chars 280 MB/s** (+13.6% over std::from_chars) | std::from_chars 246 MB/s | strtoll/strtoull 116 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::from_chars 281 MB/s** (+14.1% over std::from_chars) | std::from_chars 246 MB/s | strtoll/strtoull 103 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::from_chars 276 MB/s** (+14.0% over std::from_chars) | std::from_chars 242 MB/s | strtoll/strtoull 104 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::from_chars 278 MB/s** (+17.6% over std::from_chars) | std::from_chars 236 MB/s | strtoll/strtoull 102 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **std::from_chars 321 MB/s** (+8.4% over vn::from_chars) | vn::from_chars 296 MB/s | strtoll/strtoull 111 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | vn::from_chars 301 MB/s `[TIE]` | std::from_chars 295 MB/s `[TIE]` | strtoll/strtoull 111 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | std::from_chars 313 MB/s `[TIE]` | vn::from_chars 296 MB/s `[TIE]` | strtoll/strtoull 124 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | std::from_chars 307 MB/s `[TIE]` | vn::from_chars 294 MB/s `[TIE]` | strtoll/strtoull 119 MB/s |

