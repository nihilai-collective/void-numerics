# void-numerics Benchmark Results
**Platform:** Intel(R) Core(TM) i9-14900KF
**OS:** Windows 10.0.26200
**Compiler:** MSVC 19.44.35227.0

---

## int-to-str

### int-to-str Statistical Summary

| Library | Outright Wins | 2nd Place | Statistical Ties for 1st |
|---|---|---|---|
| **vn::to_chars** | **41** | 3 | 3 |
| jeaiii::to_text | 3 | 36 | 4 |
| fmt::format_to | - | 8 | 1 |

---

## int-to-str

| Test | 1st | 2nd | 3rd | 4th |
|---|---|---|---|---|
| int8-negative-mixed-lengths-test-size[100] | **vn::to_chars 196 MB/s** (+2.5% over jeaiii::to_text) | jeaiii::to_text 191 MB/s | fmt::format_to 159 MB/s | std::to_chars 136 MB/s |
| int8-negative-mixed-lengths-test-size[1000] | **vn::to_chars 223 MB/s** (+8.9% over jeaiii::to_text) | jeaiii::to_text 205 MB/s | fmt::format_to 181 MB/s | std::to_chars 150 MB/s |
| int8-negative-mixed-lengths-test-size[10000] | **vn::to_chars 234 MB/s** (+8.6% over jeaiii::to_text) | jeaiii::to_text 215 MB/s | fmt::format_to 184 MB/s | std::to_chars 151 MB/s |
| int8-negative-mixed-lengths-test-size[100000] | **vn::to_chars 226 MB/s** (+6.5% over jeaiii::to_text) | jeaiii::to_text 212 MB/s | fmt::format_to 182 MB/s | std::to_chars 152 MB/s |
| int8-positive-mixed-lengths-test-size[100] | **vn::to_chars 196 MB/s** (+2.5% over jeaiii::to_text) | jeaiii::to_text 191 MB/s | fmt::format_to 159 MB/s | std::to_chars 95 MB/s |
| int8-positive-mixed-lengths-test-size[1000] | **vn::to_chars 230 MB/s** (+26.8% over fmt::format_to) | fmt::format_to 182 MB/s | jeaiii::to_text 158 MB/s | std::to_chars 98 MB/s |
| int8-positive-mixed-lengths-test-size[10000] | **vn::to_chars 233 MB/s** (+7.8% over jeaiii::to_text) | jeaiii::to_text 216 MB/s | fmt::format_to 184 MB/s | std::to_chars 154 MB/s |
| int8-positive-mixed-lengths-test-size[100000] | **jeaiii::to_text 207 MB/s** (+17.8% over vn::to_chars) | vn::to_chars 176 MB/s | std::to_chars 152 MB/s | fmt::format_to 131 MB/s |
| uint8-positive-mixed-lengths-test-size[100] | jeaiii::to_text 318 MB/s `[TIE]` | fmt::format_to 318 MB/s `[TIE]` | vn::to_chars 246 MB/s | std::to_chars 191 MB/s |
| uint8-positive-mixed-lengths-test-size[1000] | **vn::to_chars 355 MB/s** (+6.3% over jeaiii::to_text) | jeaiii::to_text 334 MB/s | fmt::format_to 313 MB/s | std::to_chars 196 MB/s |
| uint8-positive-mixed-lengths-test-size[10000] | vn::to_chars 352 MB/s `[TIE]` | jeaiii::to_text 340 MB/s `[TIE]` | fmt::format_to 316 MB/s | std::to_chars 118 MB/s |
| uint8-positive-mixed-lengths-test-size[100000] | **vn::to_chars 346 MB/s** (+12.7% over fmt::format_to) | fmt::format_to 307 MB/s | jeaiii::to_text 262 MB/s | std::to_chars 197 MB/s |
| int16-negative-mixed-lengths-test-size[100] | **vn::to_chars 381 MB/s** (+40.0% over fmt::format_to) | fmt::format_to 272 MB/s | jeaiii::to_text 238 MB/s | std::to_chars 215 MB/s |
| int16-negative-mixed-lengths-test-size[1000] | **vn::to_chars 409 MB/s** (+34.1% over fmt::format_to) | fmt::format_to 305 MB/s | jeaiii::to_text 249 MB/s | std::to_chars 234 MB/s |
| int16-negative-mixed-lengths-test-size[10000] | **vn::to_chars 422 MB/s** (+19.5% over jeaiii::to_text) | jeaiii::to_text 353 MB/s | fmt::format_to 312 MB/s | std::to_chars 236 MB/s |
| int16-negative-mixed-lengths-test-size[100000] | **vn::to_chars 408 MB/s** (+16.5% over jeaiii::to_text) | jeaiii::to_text 350 MB/s | fmt::format_to 304 MB/s | std::to_chars 233 MB/s |
| int16-positive-mixed-lengths-test-size[100] | **vn::to_chars 381 MB/s** (+20.0% over jeaiii::to_text) | jeaiii::to_text 318 MB/s | fmt::format_to 282 MB/s | std::to_chars 238 MB/s |
| int16-positive-mixed-lengths-test-size[1000] | **jeaiii::to_text 351 MB/s** (+13.3% over fmt::format_to) | fmt::format_to 310 MB/s `[TIE]` | vn::to_chars 307 MB/s `[TIE]` | std::to_chars 150 MB/s |
| int16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 421 MB/s** (+18.6% over jeaiii::to_text) | jeaiii::to_text 355 MB/s | fmt::format_to 309 MB/s | std::to_chars 237 MB/s |
| int16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 408 MB/s** (+18.5% over jeaiii::to_text) | jeaiii::to_text 344 MB/s | fmt::format_to 304 MB/s | std::to_chars 230 MB/s |
| uint16-positive-mixed-lengths-test-size[100] | jeaiii::to_text 636 MB/s `[TIE]` | vn::to_chars 636 MB/s `[TIE]` | fmt::format_to 477 MB/s | std::to_chars 238 MB/s |
| uint16-positive-mixed-lengths-test-size[1000] | **vn::to_chars 723 MB/s** (+27.8% over jeaiii::to_text) | jeaiii::to_text 566 MB/s | fmt::format_to 468 MB/s | std::to_chars 240 MB/s |
| uint16-positive-mixed-lengths-test-size[10000] | **vn::to_chars 715 MB/s** (+20.0% over jeaiii::to_text) | jeaiii::to_text 596 MB/s | fmt::format_to 469 MB/s | std::to_chars 237 MB/s |
| uint16-positive-mixed-lengths-test-size[100000] | **vn::to_chars 688 MB/s** (+19.1% over jeaiii::to_text) | jeaiii::to_text 578 MB/s | fmt::format_to 460 MB/s | std::to_chars 239 MB/s |
| int32-negative-mixed-lengths-test-size[100] | **vn::to_chars 429 MB/s** (+12.5% over jeaiii::to_text) | jeaiii::to_text 381 MB/s | fmt::format_to 318 MB/s | std::to_chars 183 MB/s |
| int32-negative-mixed-lengths-test-size[1000] | **vn::to_chars 447 MB/s** (+10.7% over jeaiii::to_text) | jeaiii::to_text 404 MB/s | fmt::format_to 323 MB/s | std::to_chars 190 MB/s |
| int32-negative-mixed-lengths-test-size[10000] | **vn::to_chars 449 MB/s** (+12.8% over jeaiii::to_text) | jeaiii::to_text 398 MB/s | fmt::format_to 313 MB/s | std::to_chars 187 MB/s |
| int32-negative-mixed-lengths-test-size[100000] | **vn::to_chars 437 MB/s** (+11.4% over jeaiii::to_text) | jeaiii::to_text 392 MB/s | fmt::format_to 315 MB/s | std::to_chars 182 MB/s |
| int32-positive-mixed-lengths-test-size[100] | **vn::to_chars 429 MB/s** (+12.5% over jeaiii::to_text) | jeaiii::to_text 381 MB/s | fmt::format_to 298 MB/s | std::to_chars 192 MB/s |
| int32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 441 MB/s** (+9.5% over jeaiii::to_text) | jeaiii::to_text 403 MB/s | fmt::format_to 322 MB/s | std::to_chars 189 MB/s |
| int32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 439 MB/s** (+9.3% over jeaiii::to_text) | jeaiii::to_text 402 MB/s | fmt::format_to 308 MB/s | std::to_chars 187 MB/s |
| int32-positive-mixed-lengths-test-size[100000] | vn::to_chars 585 MB/s `[TIE]` | jeaiii::to_text 558 MB/s `[TIE]` | fmt::format_to 401 MB/s | std::to_chars 289 MB/s |
| uint32-positive-mixed-lengths-test-size[100] | **vn::to_chars 1335 MB/s** (+5.0% over jeaiii::to_text) | jeaiii::to_text 1272 MB/s | fmt::format_to 545 MB/s | std::to_chars 386 MB/s |
| uint32-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1458 MB/s** (+15.7% over jeaiii::to_text) | jeaiii::to_text 1260 MB/s | fmt::format_to 839 MB/s | std::to_chars 257 MB/s |
| uint32-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1406 MB/s** (+12.7% over jeaiii::to_text) | jeaiii::to_text 1247 MB/s | fmt::format_to 864 MB/s | std::to_chars 433 MB/s |
| uint32-positive-mixed-lengths-test-size[100000] | **vn::to_chars 1396 MB/s** (+14.0% over jeaiii::to_text) | jeaiii::to_text 1224 MB/s | fmt::format_to 848 MB/s | std::to_chars 427 MB/s |
| int64-negative-mixed-lengths-test-size[100] | **jeaiii::to_text 954 MB/s** (+12.5% over vn::to_chars) | vn::to_chars 848 MB/s | fmt::format_to 701 MB/s | std::to_chars 480 MB/s |
| int64-negative-mixed-lengths-test-size[1000] | **vn::to_chars 1429 MB/s** (+112.2% over fmt::format_to) | fmt::format_to 673 MB/s | jeaiii::to_text 608 MB/s | std::to_chars 511 MB/s |
| int64-negative-mixed-lengths-test-size[10000] | **vn::to_chars 1378 MB/s** (+42.6% over jeaiii::to_text) | jeaiii::to_text 966 MB/s | fmt::format_to 679 MB/s | std::to_chars 210 MB/s |
| int64-negative-mixed-lengths-test-size[100000] | **vn::to_chars 1344 MB/s** (+32.9% over jeaiii::to_text) | jeaiii::to_text 1011 MB/s | fmt::format_to 673 MB/s | std::to_chars 501 MB/s |
| int64-positive-mixed-lengths-test-size[100] | **vn::to_chars 848 MB/s** (+32.1% over jeaiii::to_text) | jeaiii::to_text 642 MB/s | fmt::format_to 365 MB/s | std::to_chars 225 MB/s |
| int64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 876 MB/s** (+34.9% over jeaiii::to_text) | jeaiii::to_text 649 MB/s | fmt::format_to 372 MB/s | std::to_chars 229 MB/s |
| int64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 847 MB/s** (+33.1% over jeaiii::to_text) | jeaiii::to_text 636 MB/s | fmt::format_to 368 MB/s | std::to_chars 225 MB/s |
| int64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 841 MB/s** (+34.5% over jeaiii::to_text) | jeaiii::to_text 626 MB/s | fmt::format_to 359 MB/s | std::to_chars 202 MB/s |
| uint64-positive-mixed-lengths-test-size[100] | **vn::to_chars 967 MB/s** (+39.5% over jeaiii::to_text) | jeaiii::to_text 694 MB/s | fmt::format_to 321 MB/s | std::to_chars 219 MB/s |
| uint64-positive-mixed-lengths-test-size[1000] | **vn::to_chars 1005 MB/s** (+39.3% over jeaiii::to_text) | jeaiii::to_text 722 MB/s | fmt::format_to 328 MB/s | std::to_chars 220 MB/s |
| uint64-positive-mixed-lengths-test-size[10000] | **vn::to_chars 1006 MB/s** (+42.9% over jeaiii::to_text) | jeaiii::to_text 704 MB/s | fmt::format_to 323 MB/s | std::to_chars 216 MB/s |
| uint64-positive-mixed-lengths-test-size[100000] | **vn::to_chars 960 MB/s** (+36.1% over jeaiii::to_text) | jeaiii::to_text 705 MB/s | fmt::format_to 318 MB/s | std::to_chars 211 MB/s |

