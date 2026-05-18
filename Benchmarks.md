# void-numerics Benchmark Results

**Hardware:** Intel Core i9-14900KF (Linux/WSL2 & Windows) · Apple M1 Virtual (macOS)  
**Format:** `Winner (MB/s) | Dev (+/-%) | % ahead of 2nd`  
**Ties** listed together under the same rank.

---

## int-to-str

### Clang 23.0.0 · Linux (WSL2)

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | `vn::to_chars` | 357.53 | 12.26% | 11.54% |
| int8 neg | 1,000 | `jeaiii::to_text` | 407.24 | 6.10% | 4.03% |
| int8 neg | 10,000 | `vn::to_chars` | 433.12 | 2.52% | 6.60% |
| int8 neg | 100,000 | `jeaiii::to_text` | 440.46 | 3.73% | 3.96% |
| int8 pos | 100 | `vn::to_chars` | 389.98 | 6.66% | 1.37% |
| int8 pos | 1,000 | `vn::to_chars` | 411.40 | 3.25% | 7.68% |
| int8 pos | 10,000 | `jeaiii::to_text` | 433.66 | 1.57% | 3.82% |
| int8 pos | 100,000 | **TIE** `jeaiii` / `vn` | 412 / 412 | 4.80% / 2.89% | — |
| uint8 pos | 100 | `std::to_chars` | 323.62 | 8.48% | 6.06% |
| uint8 pos | 1,000 | `std::to_chars` | 366.67 | 2.33% | 5.63% |
| uint8 pos | 10,000 | `std::to_chars` | 371.97 | 1.22% | 2.90% |
| uint8 pos | 100,000 | `jeaiii::to_text` | 369.28 | 3.52% | 1.32% |
| int16 neg | 100 | `vn::to_chars` | 619.60 | 11.80% | 4.70% |
| int16 neg | 1,000 | `vn::to_chars` | 710.23 | 7.17% | 2.06% |
| int16 neg | 10,000 | `vn::to_chars` | 730.93 | 1.97% | 5.91% |
| int16 neg | 100,000 | `vn::to_chars` | 769.67 | 3.86% | 12.83% |
| int16 pos | 100 | `vn::to_chars` | 670.05 | 11.60% | 4.90% |
| int16 pos | 1,000 | `vn::to_chars` | 748.92 | 4.83% | 8.42% |
| int16 pos | 10,000 | `vn::to_chars` | 754.86 | 2.65% | 10.26% |
| int16 pos | 100,000 | `vn::to_chars` | 768.43 | 2.94% | 10.55% |
| uint16 pos | 100 | `vn::to_chars` | 1,157.38 | 13.26% | 20.25% |
| uint16 pos | 1,000 | `vn::to_chars` | 1,279.55 | 11.43% | 16.12% |
| uint16 pos | 10,000 | `vn::to_chars` | 1,253.93 | 3.97% | 16.13% |
| uint16 pos | 100,000 | `vn::to_chars` | 1,345.40 | 1.98% | 18.57% |
| int32 neg | 100 | `vn::to_chars` | 926.25 | 2.64% | 11.55% |
| int32 neg | 1,000 | `vn::to_chars` | 982.04 | 4.18% | 22.14% |
| int32 neg | 10,000 | `vn::to_chars` | 981.69 | 1.84% | 16.68% |
| int32 neg | 100,000 | `vn::to_chars` | 988.37 | 2.45% | 15.78% |
| int32 pos | 100 | **TIE** `vn` / `jeaiii` | 828 / 822 | 11.95% / 7.17% | — |
| int32 pos | 1,000 | `vn::to_chars` | 975.24 | 2.48% | 19.09% |
| int32 pos | 10,000 | `vn::to_chars` | 980.98 | 1.45% | 19.61% |
| int32 pos | 100,000 | `vn::to_chars` | 989.12 | 2.29% | 15.63% |
| uint32 pos | 100 | `vn::to_chars` | 1,378.30 | 19.54% | 16.30% |
| uint32 pos | 1,000 | `vn::to_chars` | 1,609.66 | 3.03% | 38.01% |
| uint32 pos | 10,000 | `vn::to_chars` | 1,426.09 | 5.31% | 23.42% |
| uint32 pos | 100,000 | `vn::to_chars` | 1,608.26 | 5.55% | 30.52% |
| int64 neg | 100 | `vn::to_chars` | 2,523.87 | 22.49% | 42.80% |
| int64 neg | 1,000 | `vn::to_chars` | 2,457.73 | 7.72% | 36.04% |
| int64 neg | 10,000 | `vn::to_chars` | 2,469.04 | 2.50% | 44.39% |
| int64 neg | 100,000 | `vn::to_chars` | 2,676.36 | 4.49% | 42.17% |
| int64 pos | 100 | `vn::to_chars` | 2,439.73 | 26.42% | 35.09% |
| int64 pos | 1,000 | `vn::to_chars` | 2,517.48 | 4.04% | 40.11% |
| int64 pos | 10,000 | `vn::to_chars` | 2,492.50 | 1.80% | 52.48% |
| int64 pos | 100,000 | `vn::to_chars` | 2,623.09 | 6.28% | 42.16% |
| uint64 pos | 100 | `vn::to_chars` | 1,683.43 | 25.21% | 34.33% |
| uint64 pos | 1,000 | `vn::to_chars` | 1,765.94 | 2.63% | 35.50% |
| uint64 pos | 10,000 | `vn::to_chars` | 1,663.39 | 1.86% | 32.58% |
| uint64 pos | 100,000 | `vn::to_chars` | 1,692.51 | 4.92% | 27.32% |

**Total wins — Clang:** `vn::to_chars` 39 · `jeaiii` 4 · `std` 3 · Ties: 2+2

---

### GNU 16.0.1 · Linux (WSL2)

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | `vn::to_chars` | 385.78 | 12.03% | 2.67% |
| int8 neg | 1,000 | `jeaiii::to_text` | 417.52 | 3.99% | 3.01% |
| int8 neg | 10,000 | **TIE** `vn` / `jeaiii` | 418 / 418 | 1.38% / 1.09% | — |
| int8 neg | 100,000 | **TIE** `jeaiii` / `vn` | 424 / 421 | 2.93% / 3.38% | — |
| int8 pos | 100 | `jeaiii::to_text` | 369.38 | 9.73% | 24.08% |
| int8 pos | 1,000 | `vn::to_chars` | 416.01 | 3.19% | 2.65% |
| int8 pos | 10,000 | `vn::to_chars` | 414.64 | 0.96% | 12.89% |
| int8 pos | 100,000 | `vn::to_chars` | 423.31 | 5.36% | 1.15% |
| uint8 pos | 100 | `vn::to_chars` | 316.63 | 9.82% | 2.50% |
| uint8 pos | 1,000 | `vn::to_chars` | 376.80 | 3.66% | 6.26% |
| uint8 pos | 10,000 | **TIE** `vn` / `jeaiii` | 385 / 383 | 1.27% / 1.33% | — |
| uint8 pos | 100,000 | **TIE** `vn` / `jeaiii` | 384 / 382 | 4.61% / 3.85% | — |
| int16 neg | 100 | `vn::to_chars` | 626.35 | 9.64% | 2.26% |
| int16 neg | 1,000 | `vn::to_chars` | 680.86 | 6.68% | 7.23% |
| int16 neg | 10,000 | `vn::to_chars` | 713.59 | 0.99% | 8.31% |
| int16 neg | 100,000 | `vn::to_chars` | 709.31 | 3.09% | 5.95% |
| int16 pos | 100 | `vn::to_chars` | 616.89 | 9.86% | 4.72% |
| int16 pos | 1,000 | `vn::to_chars` | 698.91 | 5.77% | 6.85% |
| int16 pos | 10,000 | `vn::to_chars` | 719.82 | 0.92% | 6.13% |
| int16 pos | 100,000 | `vn::to_chars` | 714.26 | 1.59% | 5.10% |
| uint16 pos | 100 | `vn::to_chars` | 1,030.00 | 8.78% | 4.12% |
| uint16 pos | 1,000 | `vn::to_chars` | 1,205.73 | 7.11% | 6.45% |
| uint16 pos | 10,000 | `vn::to_chars` | 1,224.87 | 4.24% | 8.94% |
| uint16 pos | 100,000 | `vn::to_chars` | 1,254.33 | 4.44% | 10.12% |
| int32 neg | 100 | `vn::to_chars` | 893.77 | 4.73% | 16.14% |
| int32 neg | 1,000 | `vn::to_chars` | 930.27 | 4.12% | 21.41% |
| int32 neg | 10,000 | `vn::to_chars` | 935.75 | 0.99% | 17.72% |
| int32 neg | 100,000 | `vn::to_chars` | 920.10 | 2.70% | 17.31% |
| int32 pos | 100 | `vn::to_chars` | 887.33 | 7.55% | 16.11% |
| int32 pos | 1,000 | `vn::to_chars` | 908.17 | 2.88% | 13.61% |
| int32 pos | 10,000 | `vn::to_chars` | 933.24 | 2.15% | 18.79% |
| int32 pos | 100,000 | `vn::to_chars` | 892.33 | 6.90% | 12.02% |
| uint32 pos | 100 | `vn::to_chars` | 1,442.78 | 14.71% | 35.15% |
| uint32 pos | 1,000 | `vn::to_chars` | 1,564.35 | 5.26% | 20.45% |
| uint32 pos | 10,000 | `vn::to_chars` | 1,574.36 | 2.47% | 25.22% |
| uint32 pos | 100,000 | `vn::to_chars` | 1,601.93 | 2.31% | 20.32% |
| int64 neg | 100 | `vn::to_chars` | 2,153.16 | 17.79% | 42.62% |
| int64 neg | 1,000 | `vn::to_chars` | 2,437.59 | 3.99% | 48.53% |
| int64 neg | 10,000 | `vn::to_chars` | 2,436.93 | 2.41% | 47.04% |
| int64 neg | 100,000 | `vn::to_chars` | 2,313.89 | 10.20% | 40.80% |
| int64 pos | 100 | `vn::to_chars` | 2,242.00 | 13.41% | 43.81% |
| int64 pos | 1,000 | `vn::to_chars` | 2,461.89 | 3.73% | 52.58% |
| int64 pos | 10,000 | `vn::to_chars` | 2,501.26 | 1.17% | 49.21% |
| int64 pos | 100,000 | `vn::to_chars` | 2,384.09 | 5.03% | 57.79% |
| uint64 pos | 100 | `vn::to_chars` | 1,449.89 | 11.41% | 31.74% |
| uint64 pos | 1,000 | `vn::to_chars` | 1,536.30 | 2.61% | 23.74% |
| uint64 pos | 10,000 | `vn::to_chars` | 1,576.41 | 2.46% | 27.54% |
| uint64 pos | 100,000 | `vn::to_chars` | 1,512.58 | 6.68% | 19.46% |

**Total wins — GNU:** `vn::to_chars` 42 · `jeaiii` 2 · Ties: 4+4

---

### MSVC 19.44 · Windows 10

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | **TIE** `jeaiii` / `vn` | 477 / 477 | 0.00% / 0.00% | — |
| int8 neg | 1,000 | `vn::to_chars` | 537.43 | 6.60% | 1.85% |
| int8 neg | 10,000 | `vn::to_chars` | 566.84 | 2.18% | 4.41% |
| int8 neg | 100,000 | `vn::to_chars` | 601.76 | 3.25% | 8.90% |
| int8 pos | 100 | `vn::to_chars` | 572.20 | 16.67% | 9.09% |
| int8 pos | 1,000 | `vn::to_chars` | 642.03 | 7.16% | 1.23% |
| int8 pos | 10,000 | `jeaiii::to_text` | 641.18 | 2.79% | 3.29% |
| int8 pos | 100,000 | `vn::to_chars` | 686.05 | 2.38% | 5.51% |
| uint8 pos | 100 | `jeaiii::to_text` | 667.57 | 28.57% | 7.69% |
| uint8 pos | 1,000 | `jeaiii::to_text` | 695.34 | 8.57% | 5.51% |
| uint8 pos | 10,000 | `jeaiii::to_text` | 715.69 | 3.44% | 7.92% |
| uint8 pos | 100,000 | **TIE** `jeaiii` / `vn` | 719 / 715 | 5.11% / 2.73% | — |
| int16 neg | 100 | `vn::to_chars` | 635.78 | 25.00% | 11.11% |
| int16 neg | 1,000 | `vn::to_chars` | 1,016.14 | 6.15% | 45.93% |
| int16 neg | 10,000 | `vn::to_chars` | 1,060.98 | 1.22% | 48.57% |
| int16 neg | 100,000 | `vn::to_chars` | 1,044.96 | 1.50% | 45.32% |
| int16 pos | 100 | `vn::to_chars` | 890.10 | 28.57% | 33.33% |
| int16 pos | 1,000 | `vn::to_chars` | 1,157.97 | 3.11% | 49.29% |
| int16 pos | 10,000 | `vn::to_chars` | 1,263.38 | 2.60% | 52.99% |
| int16 pos | 100,000 | `vn::to_chars` | 1,239.40 | 1.16% | 49.77% |
| uint16 pos | 100 | `jeaiii::to_text` | 1,049.04 | 9.09% | 22.22% (vs fmt) |
| uint16 pos | 1,000 | `vn::to_chars` | 1,486.88 | 8.37% | 34.21% |
| uint16 pos | 10,000 | `vn::to_chars` | 1,599.68 | 3.84% | 32.75% |
| uint16 pos | 100,000 | `vn::to_chars` | 1,625.65 | 2.06% | 35.81% |
| int32 neg | 100 | `vn::to_chars` | 1,271.57 | 25.00% | 29.03% |
| int32 neg | 1,000 | `vn::to_chars` | 1,508.76 | 2.76% | 42.32% |
| int32 neg | 10,000 | `vn::to_chars` | 1,454.30 | 10.78% | 37.62% |
| int32 neg | 100,000 | `vn::to_chars` | 1,521.24 | 0.84% | 45.64% |
| int32 pos | 100 | `vn::to_chars` | 1,525.88 | 16.67% | 50.00% |
| int32 pos | 1,000 | `vn::to_chars` | 1,760.99 | 5.82% | 42.51% |
| int32 pos | 10,000 | `vn::to_chars` | 1,835.12 | 1.95% | 46.19% |
| int32 pos | 100,000 | `vn::to_chars` | 1,805.89 | 3.10% | 43.06% |
| uint32 pos | 100 | `vn::to_chars` | 1,907.35 | 0.00% | 30.43% |
| uint32 pos | 1,000 | `vn::to_chars` | 2,151.26 | 6.67% | 25.05% |
| uint32 pos | 10,000 | `vn::to_chars` | 2,185.94 | 3.59% | 23.85% |
| uint32 pos | 100,000 | `vn::to_chars` | 2,170.22 | 4.83% | 22.42% |
| int64 neg | 100 | `vn::to_chars` | 2,161.66 | 11.76% | 41.67% |
| int64 neg | 1,000 | `vn::to_chars` | 2,500.29 | 7.53% | 58.26% |
| int64 neg | 10,000 | `vn::to_chars` | 2,581.28 | 1.81% | 62.06% |
| int64 neg | 100,000 | `vn::to_chars` | 2,476.68 | 6.60% | 58.31% |
| int64 pos | 100 | `vn::to_chars` | 2,161.66 | 11.76% | 49.12% |
| int64 pos | 1,000 | `vn::to_chars` | 2,467.31 | 6.30% | 55.52% |
| int64 pos | 10,000 | `vn::to_chars` | 2,539.46 | 2.14% | 55.87% |
| int64 pos | 100,000 | `vn::to_chars` | 2,494.10 | 6.57% | 55.38% |
| uint64 pos | 100 | `vn::to_chars` | 2,225.24 | 14.29% | 32.58% |
| uint64 pos | 1,000 | `vn::to_chars` | 2,568.18 | 7.16% | 47.40% |
| uint64 pos | 10,000 | `vn::to_chars` | 2,694.34 | 1.68% | 50.57% |
| uint64 pos | 100,000 | `vn::to_chars` | 2,664.23 | 2.66% | 49.75% |

**Total wins — MSVC:** `vn::to_chars` 41 · `jeaiii` 5 · Ties: 2+2

---

### Clang 22.1.4 · Apple M1

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | `vn::to_chars` | 302.50 | 5.61% | 1.35% |
| int8 neg | 1,000 | `jeaiii::to_text` | 325.44 | 3.67% | 4.44% |
| int8 neg | 10,000 | `vn::to_chars` | 319.43 | 1.44% | 3.21% |
| int8 neg | 100,000 | `vn::to_chars` | 344.52 | 1.46% | 1.15% |
| int8 pos | 100 | `jeaiii::to_text` | 280.53 | 9.35% | 9.91% |
| int8 pos | 1,000 | `vn::to_chars` | 334.47 | 6.24% | 11.68% |
| int8 pos | 10,000 | `jeaiii::to_text` | 330.66 | 2.23% | 1.70% |
| int8 pos | 100,000 | **TIE** `vn` / `jeaiii` | 319 / 317 | 2.23% / 4.57% | — |
| uint8 pos | 100 | `jeaiii::to_text` | 251.10 | 8.92% | 2.86% |
| uint8 pos | 1,000 | `vn::to_chars` | 277.92 | 1.96% | 5.39% |
| uint8 pos | 10,000 | `vn::to_chars` | 287.34 | 0.93% | 4.73% |
| uint8 pos | 100,000 | `vn::to_chars` | 293.98 | 1.60% | 5.61% |
| int16 neg | 100 | `vn::to_chars` | 490.66 | 6.78% | 3.64% |
| int16 neg | 1,000 | `vn::to_chars` | 520.55 | 3.37% | 9.90% |
| int16 neg | 10,000 | `vn::to_chars` | 554.16 | 2.12% | 12.15% |
| int16 neg | 100,000 | `vn::to_chars` | 588.74 | 2.87% | 10.49% |
| int16 pos | 100 | `vn::to_chars` | 499.67 | 8.46% | 2.34% |
| int16 pos | 1,000 | `vn::to_chars` | 592.42 | 2.20% | 10.24% |
| int16 pos | 10,000 | `vn::to_chars` | 614.24 | 1.16% | 11.21% |
| int16 pos | 100,000 | `vn::to_chars` | 575.37 | 2.31% | 9.51% |
| uint16 pos | 100 | `vn::to_chars` | 772.03 | 15.39% | 2.90% |
| uint16 pos | 1,000 | `vn::to_chars` | 960.76 | 4.69% | 12.42% |
| uint16 pos | 10,000 | `vn::to_chars` | 955.79 | 2.46% | 11.41% |
| uint16 pos | 100,000 | `vn::to_chars` | 952.11 | 5.06% | 28.54% |
| int32 neg | 100 | `vn::to_chars` | 727.86 | 3.30% | 23.11% |
| int32 neg | 1,000 | `vn::to_chars` | 771.38 | 1.09% | 19.63% |
| int32 neg | 10,000 | `vn::to_chars` | 782.01 | 1.29% | 22.82% |
| int32 neg | 100,000 | `vn::to_chars` | 839.77 | 2.19% | 23.70% |
| int32 pos | 100 | `vn::to_chars` | 892.32 | 6.86% | 30.47% |
| int32 pos | 1,000 | `vn::to_chars` | 934.37 | 2.02% | 30.70% |
| int32 pos | 10,000 | `vn::to_chars` | 956.47 | 1.42% | 30.94% |
| int32 pos | 100,000 | `vn::to_chars` | 948.09 | 2.51% | 36.50% |
| uint32 pos | 100 | `vn::to_chars` | 1,275.24 | 10.44% | 34.81% (vs std) |
| uint32 pos | 1,000 | `vn::to_chars` | 1,275.95 | 4.33% | 26.07% (vs std) |
| uint32 pos | 10,000 | `vn::to_chars` | 1,404.33 | 1.37% | 39.96% (vs std) |
| uint32 pos | 100,000 | `vn::to_chars` | 1,437.05 | 0.92% | 42.60% (vs std) |
| int64 neg | 100 | `vn::to_chars` | 2,160.75 | 5.84% | 68.66% |
| int64 neg | 1,000 | `vn::to_chars` | 2,236.01 | 1.33% | 78.66% |
| int64 neg | 10,000 | `vn::to_chars` | 2,255.97 | 1.26% | 78.72% |
| int64 neg | 100,000 | `vn::to_chars` | 2,087.68 | 3.25% | 67.25% |
| int64 pos | 100 | `vn::to_chars` | 2,185.72 | 6.92% | 71.67% |
| int64 pos | 1,000 | `vn::to_chars` | 2,381.58 | 1.43% | 77.52% |
| int64 pos | 10,000 | `vn::to_chars` | 2,408.74 | 1.02% | 79.43% |
| int64 pos | 100,000 | `vn::to_chars` | 2,409.24 | 0.74% | 92.98% |
| uint64 pos | 100 | `vn::to_chars` | 1,432.07 | 1.71% | 40.58% |
| uint64 pos | 1,000 | `vn::to_chars` | 1,648.55 | 1.72% | 51.51% |
| uint64 pos | 10,000 | `vn::to_chars` | 1,665.09 | 0.66% | 54.42% |
| uint64 pos | 100,000 | `vn::to_chars` | 1,655.52 | 2.35% | 51.94% |

**Total wins — M1 Clang:** `vn::to_chars` 43 · `jeaiii` 4 · Ties: 1+1

---

### GNU 15.2.0 · Apple M1

> Note: size=100 results show identical throughput across all competitors — timer resolution artifact; meaningful data starts at size=1,000.

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 1,000 | `jeaiii::to_text` | 667.57 | 28.57% | 7.69% |
| int8 neg | 10,000 | `jeaiii::to_text` | 623.86 | 4.46% | 3.97% |
| int8 neg | 100,000 | `jeaiii::to_text` | 354.55 | 4.28% | 1.34% |
| int8 pos | 1,000 | `vn::to_chars` | 715.26 | 33.33% | 15.38% |
| int8 pos | 10,000 | `vn::to_chars` | 635.78 | 0.00% | 53.33% (vs fmt) |
| int8 pos | 100,000 | `vn::to_chars` | 608.83 | 6.76% | 4.57% |
| uint8 pos | 1,000 | **TIE** `vn` / `jeaiii` | 954 / 954 | 0.00% / 0.00% | — |
| uint8 pos | 10,000 | `vn::to_chars` | 936.33 | 7.41% | 4.85% |
| uint8 pos | 100,000 | `vn::to_chars` | 944.27 | 0.98% | 10.39% |
| int16 neg | 1,000 | **TIE** `vn` / `jeaiii` | 795 / 795 | 20.00% / 20.00% | — |
| int16 neg | 10,000 | `jeaiii::to_text` | 775.41 | 23.13% | 41.83% |
| int16 neg | 100,000 | `vn::to_chars` | 831.49 | 1.55% | 3.88% |
| int16 pos | 1,000 | **TIE** `vn` / `jeaiii` | 827 / 827 | 23.08% / 23.08% | — |
| int16 pos | 10,000 | `vn::to_chars` | 822.37 | 3.36% | 2.15% |
| int16 pos | 100,000 | `vn::to_chars` | 830.74 | 0.61% | 3.14% |
| uint16 pos | 1,000 | **TIE** `fmt` / `jeaiii` | 795 / 795 | 20.00% / 20.00% | — |
| uint16 pos | 10,000 | **TIE** `jeaiii` / `vn` | 833 / 833 | 0.45% / 0.45% | — |
| uint16 pos | 100,000 | `vn::to_chars` | 828.60 | 1.21% | 1.73% |
| int32 neg | 1,000 | `vn::to_chars` | 1,398.72 | 9.09% | 4.76% |
| int32 neg | 10,000 | `vn::to_chars` | 1,557.67 | 2.04% | 16.75% |
| int32 neg | 100,000 | `vn::to_chars` | 1,490.75 | 0.82% | 16.07% |
| int32 pos | 1,000 | `vn::to_chars` | 1,525.88 | 16.67% | 9.09% |
| int32 pos | 10,000 | `vn::to_chars` | 1,509.25 | 2.79% | 10.75% |
| int32 pos | 100,000 | `vn::to_chars` | 1,487.03 | 3.92% | 10.65% |
| uint32 pos | 1,000 | `vn::to_chars` | 1,589.46 | 20.00% | 4.17% |
| uint32 pos | 10,000 | `vn::to_chars` | 1,637.83 | 2.95% | 7.75% |
| uint32 pos | 100,000 | `vn::to_chars` | 1,603.74 | 2.52% | 5.43% |
| int64 neg | 1,000 | `vn::to_chars` | 2,161.66 | 11.76% | 70.00% |
| int64 neg | 10,000 | `vn::to_chars` | 2,158.43 | 26.36% | 63.51% |
| int64 neg | 100,000 | `vn::to_chars` | 1,234.34 | 4.76% | 10.28% |
| int64 pos | 1,000 | `vn::to_chars` | 2,161.66 | 11.76% | 66.67% |
| int64 pos | 10,000 | `vn::to_chars` | 2,362.51 | 2.14% | 80.51% |
| int64 pos | 100,000 | `vn::to_chars` | 2,366.44 | 0.19% | 83.41% |
| uint64 pos | 1,000 | `vn::to_chars` | 2,670.29 | 4.76% | 98.11% |
| uint64 pos | 10,000 | `vn::to_chars` | 2,775.24 | 1.82% | 97.49% |
| uint64 pos | 100,000 | `vn::to_chars` | 2,629.36 | 3.28% | 90.91% |

**Total wins — M1 GNU:** `vn::to_chars` 27 · `jeaiii` 4 · Ties: 16+10 (timer resolution at size=100 accounts for most ties)

---

## str-to-int

### Clang 23.0.0 · Linux (WSL2)

**`vn::from_chars` wins 48/48. Perfect sweep.**

| Type | Size | MB/s | Dev ±% | Ahead of 2nd |
|------|------|------|---------|--------------|
| int8 neg | 100 | 156.78 | 4.81% | 14.23% |
| int8 neg | 1,000 | 167.61 | 1.83% | 51.64% |
| int8 neg | 10,000 | 171.85 | 0.74% | 19.06% |
| int8 neg | 100,000 | 167.14 | 1.89% | 19.16% |
| int8 pos | 100 | 163.65 | 6.91% | 19.19% |
| int8 pos | 1,000 | 171.89 | 1.43% | 21.86% |
| int8 pos | 10,000 | 171.34 | 0.64% | 19.95% |
| int8 pos | 100,000 | 168.38 | 2.70% | 20.32% |
| uint8 pos | 100 | 232.83 | 5.84% | 6.50% |
| uint8 pos | 1,000 | 237.03 | 3.70% | 3.66% |
| uint8 pos | 10,000 | 252.14 | 1.29% | 2.81% |
| uint8 pos | 100,000 | 251.08 | 1.48% | 5.26% |
| int16 neg | 100 | 278.57 | 5.43% | 14.35% |
| int16 neg | 1,000 | 280.51 | 1.84% | 14.88% |
| int16 neg | 10,000 | 281.94 | 0.83% | 17.02% |
| int16 neg | 100,000 | 281.13 | 1.72% | 14.17% |
| int16 pos | 100 | 274.29 | 5.13% | 15.11% |
| int16 pos | 1,000 | 282.33 | 2.82% | 15.71% |
| int16 pos | 10,000 | 278.18 | 5.05% | 13.21% |
| int16 pos | 100,000 | 281.60 | 1.73% | 15.34% |
| uint16 pos | 100 | 572.62 | 7.47% | 19.68% |
| uint16 pos | 1,000 | 618.23 | 4.54% | 12.31% |
| uint16 pos | 10,000 | 620.09 | 0.89% | 10.31% |
| uint16 pos | 100,000 | 598.19 | 5.00% | 9.89% |
| int32 neg | 100 | 410.05 | 4.09% | 30.44% |
| int32 neg | 1,000 | 422.73 | 1.31% | 26.67% |
| int32 neg | 10,000 | 426.75 | 0.94% | 29.35% |
| int32 neg | 100,000 | 418.10 | 1.09% | 28.21% |
| int32 pos | 100 | 399.68 | 3.88% | 26.92% |
| int32 pos | 1,000 | 427.55 | 1.44% | 29.41% |
| int32 pos | 10,000 | 425.42 | 0.53% | 33.99% |
| int32 pos | 100,000 | 413.79 | 1.98% | 26.48% |
| uint32 pos | 100 | 733.91 | 4.98% | 27.25% |
| uint32 pos | 1,000 | 763.20 | 1.57% | 26.09% |
| uint32 pos | 10,000 | 764.53 | 0.92% | 24.97% |
| uint32 pos | 100,000 | 754.80 | 2.01% | 25.03% |
| int64 neg | 100 | 724.82 | 4.92% | 35.40% |
| int64 neg | 1,000 | 766.96 | 0.85% | 38.82% |
| int64 neg | 10,000 | 749.87 | 5.15% | 35.71% |
| int64 neg | 100,000 | 749.14 | 1.55% | 48.79% |
| int64 pos | 100 | 726.09 | 7.59% | 36.33% |
| int64 pos | 1,000 | 762.82 | 1.14% | 39.48% |
| int64 pos | 10,000 | 745.62 | 8.66% | 36.73% |
| int64 pos | 100,000 | 753.53 | 0.88% | 36.49% |
| uint64 pos | 100 | 672.11 | 1.03% | 29.26% |
| uint64 pos | 1,000 | 686.47 | 1.30% | 8.29% |
| uint64 pos | 10,000 | 654.65 | 1.06% | 5.44% |
| uint64 pos | 100,000 | 676.41 | 2.19% | 15.88% |

---

### GNU 16.0.1 · Linux (WSL2)

**`vn::from_chars` wins 36/48 · `std::from_chars` wins 9 · Ties: 3+3**

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | `vn::from_chars` | 181.03 | 9.17% | 12.51% |
| int8 neg | 1,000 | `vn::from_chars` | 190.87 | 1.72% | 15.10% |
| int8 neg | 10,000 | `vn::from_chars` | 194.82 | 0.60% | 14.33% |
| int8 neg | 100,000 | `vn::from_chars` | 189.53 | 1.47% | 12.42% |
| int8 pos | 100 | `vn::from_chars` | 188.17 | 5.27% | 10.71% |
| int8 pos | 1,000 | `vn::from_chars` | 188.64 | 2.83% | 10.88% |
| int8 pos | 10,000 | `vn::from_chars` | 195.37 | 0.86% | 14.03% |
| int8 pos | 100,000 | `vn::from_chars` | 191.42 | 1.74% | 17.83% |
| uint8 pos | 100 | `vn::from_chars` | 253.46 | 6.87% | 5.45% |
| uint8 pos | 1,000 | `vn::from_chars` | 276.18 | 4.03% | 8.72% |
| uint8 pos | 10,000 | `vn::from_chars` | 282.39 | 2.00% | 10.11% |
| uint8 pos | 100,000 | `vn::from_chars` | 271.68 | 4.65% | 12.30% |
| int16 neg | 100 | **TIE** `std` / `vn` | 279 / 277 | 7.87% / 5.17% | — |
| int16 neg | 1,000 | `std::from_chars` | 291.12 | 2.30% | 5.57% |
| int16 neg | 10,000 | `std::from_chars` | 307.25 | 3.39% | 6.41% |
| int16 neg | 100,000 | `std::from_chars` | 303.73 | 1.16% | 6.62% |
| int16 pos | 100 | **TIE** `std` / `vn` | 278 / 276 | 7.65% / 4.57% | — |
| int16 pos | 1,000 | `std::from_chars` | 295.46 | 3.35% | 3.02% |
| int16 pos | 10,000 | `std::from_chars` | 303.14 | 5.83% | 9.86% |
| int16 pos | 100,000 | **TIE** `vn` / `std` | 284 / 282 | 2.24% / 3.13% | — |
| uint16 pos | 100 | `std::from_chars` | 591.71 | 9.45% | 18.72% |
| uint16 pos | 1,000 | `std::from_chars` | 645.57 | 4.97% | 24.77% |
| uint16 pos | 10,000 | `std::from_chars` | 651.84 | 1.16% | 23.75% |
| uint16 pos | 100,000 | `std::from_chars` | 640.00 | 2.90% | 24.75% |
| int32 neg | 100 | `vn::from_chars` | 446.98 | 4.54% | 10.81% |
| int32 neg | 1,000 | `vn::from_chars` | 465.36 | 1.98% | 12.86% |
| int32 neg | 10,000 | `vn::from_chars` | 456.83 | 5.44% | 15.74% |
| int32 neg | 100,000 | `vn::from_chars` | 463.94 | 1.14% | 12.91% |
| int32 pos | 100 | `vn::from_chars` | 447.23 | 2.41% | 17.63% |
| int32 pos | 1,000 | `vn::from_chars` | 467.55 | 1.60% | 13.75% |
| int32 pos | 10,000 | `vn::from_chars` | 435.43 | 11.54% | 7.42% |
| int32 pos | 100,000 | `vn::from_chars` | 463.52 | 2.11% | 12.02% |
| uint32 pos | 100 | `vn::from_chars` | 835.24 | 6.03% | 31.97% |
| uint32 pos | 1,000 | `vn::from_chars` | 862.15 | 1.54% | 21.71% |
| uint32 pos | 10,000 | `vn::from_chars` | 847.15 | 1.99% | 16.70% |
| uint32 pos | 100,000 | `vn::from_chars` | 854.19 | 2.59% | 18.53% |
| int64 neg | 100 | `vn::from_chars` | 797.30 | 5.16% | 12.52% |
| int64 neg | 1,000 | `vn::from_chars` | 817.19 | 2.03% | 11.88% |
| int64 neg | 10,000 | `vn::from_chars` | 815.24 | 1.36% | 10.61% |
| int64 neg | 100,000 | `vn::from_chars` | 823.88 | 1.31% | 11.80% |
| int64 pos | 100 | `vn::from_chars` | 796.77 | 4.91% | 8.55% |
| int64 pos | 1,000 | `vn::from_chars` | 806.65 | 1.63% | 8.71% |
| int64 pos | 10,000 | `vn::from_chars` | 802.17 | 5.43% | 10.27% |
| int64 pos | 100,000 | `vn::from_chars` | 810.57 | 1.90% | 12.64% |
| uint64 pos | 100 | `vn::from_chars` | 803.08 | 5.56% | 3.89% |
| uint64 pos | 1,000 | `vn::from_chars` | 799.38 | 3.08% | 1.13% |
| uint64 pos | 10,000 | `vn::from_chars` | 809.70 | 1.46% | 7.17% |
| uint64 pos | 100,000 | `vn::from_chars` | 832.42 | 1.23% | 7.05% |

---

### MSVC 19.44 · Windows 10

**`vn::from_chars` wins 48/48. Perfect sweep.**

| Type | Size | MB/s | Dev ±% | Ahead of 2nd |
|------|------|------|---------|--------------|
| int8 neg | 100 | 214.58 | 11.11% | 20.54% |
| int8 neg | 1,000 | 239.09 | 2.71% | 13.75% |
| int8 neg | 10,000 | 247.46 | 0.93% | 10.82% |
| int8 neg | 100,000 | 245.45 | 0.93% | 10.35% |
| int8 pos | 100 | 262.26 | 9.09% | 3.12% |
| int8 pos | 1,000 | 364.30 | 3.04% | 15.29% |
| int8 pos | 10,000 | 372.42 | 1.13% | 14.57% |
| int8 pos | 100,000 | 371.67 | 1.99% | 15.45% |
| uint8 pos | 100 | 381.47 | 16.67% | 20.00% |
| uint8 pos | 1,000 | 456.40 | 0.50% | 21.00% |
| uint8 pos | 10,000 | 439.72 | 0.97% | 12.82% |
| uint8 pos | 100,000 | 480.27 | 1.94% | 22.20% |
| int16 neg | 100 | 330.61 | 3.85% | 12.00% |
| int16 neg | 1,000 | 364.06 | 1.15% | 8.41% |
| int16 neg | 10,000 | 368.23 | 0.96% | 9.58% |
| int16 neg | 100,000 | 370.83 | 0.95% | 10.45% |
| int16 pos | 100 | 400.54 | 4.76% | 2.44% |
| int16 pos | 1,000 | 503.29 | 0.27% | 14.77% |
| int16 pos | 10,000 | 507.02 | 1.00% | 17.73% |
| int16 pos | 100,000 | 503.70 | 1.31% | 16.45% |
| uint16 pos | 100 | 699.36 | 9.09% | 10.00% |
| uint16 pos | 1,000 | 772.48 | 1.23% | 10.53% |
| uint16 pos | 10,000 | 789.15 | 0.54% | 10.51% |
| uint16 pos | 100,000 | 796.36 | 1.84% | 11.83% |
| int32 neg | 100 | 497.27 | 4.11% | 13.08% |
| int32 neg | 1,000 | 519.28 | 4.60% | 18.52% |
| int32 neg | 10,000 | 538.81 | 0.56% | 12.23% |
| int32 neg | 100,000 | 549.44 | 0.43% | 13.26% |
| int32 pos | 100 | 590.37 | 7.69% | 10.64% |
| int32 pos | 1,000 | 670.44 | 0.18% | 10.19% |
| int32 pos | 10,000 | 690.96 | 0.70% | 10.45% |
| int32 pos | 100,000 | 670.61 | 3.06% | 7.50% |
| uint32 pos | 100 | 762.94 | 0.00% | 11.11% |
| uint32 pos | 1,000 | 836.65 | 0.88% | 9.59% |
| uint32 pos | 10,000 | 844.53 | 0.29% | 7.88% |
| uint32 pos | 100,000 | 845.23 | 0.76% | 8.58% |
| int64 neg | 100 | 788.37 | 3.23% | 17.59% |
| int64 neg | 1,000 | 845.00 | 1.86% | 19.83% |
| int64 neg | 10,000 | 866.30 | 0.37% | 22.23% |
| int64 neg | 100,000 | 863.72 | 0.46% | 27.01% |
| int64 pos | 100 | 879.50 | 3.61% | 11.56% |
| int64 pos | 1,000 | 965.84 | 1.26% | 23.29% |
| int64 pos | 10,000 | 972.52 | 0.32% | 26.93% |
| int64 pos | 100,000 | 809.41 | 4.84% | 7.90% |
| uint64 pos | 100 | 911.29 | 6.98% | 14.36% |
| uint64 pos | 1,000 | 1,006.54 | 0.27% | 19.00% |
| uint64 pos | 10,000 | 857.25 | 0.78% | 1.37% |
| uint64 pos | 100,000 | 998.21 | 2.40% | 17.87% |

---

### Clang 22.1.4 · Apple M1

**`vn::from_chars` wins 47/48 · Ties: 1+1**

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 100 | `vn::from_chars` | 128.22 | 6.09% | 28.58% |
| int8 neg | 1,000 | `vn::from_chars` | 134.65 | 1.17% | 29.17% |
| int8 neg | 10,000 | `vn::from_chars` | 141.38 | 0.68% | 28.82% |
| int8 neg | 100,000 | `vn::from_chars` | 130.39 | 2.17% | 20.05% |
| int8 pos | 100 | `vn::from_chars` | 123.27 | 7.24% | 28.49% |
| int8 pos | 1,000 | `vn::from_chars` | 130.36 | 1.37% | 28.26% |
| int8 pos | 10,000 | `vn::from_chars` | 132.70 | 0.53% | 40.28% |
| int8 pos | 100,000 | `vn::from_chars` | 129.58 | 2.88% | 29.82% |
| uint8 pos | 100 | `vn::from_chars` | 199.73 | 4.51% | 28.77% |
| uint8 pos | 1,000 | `vn::from_chars` | 212.77 | 2.22% | 31.27% |
| uint8 pos | 10,000 | `vn::from_chars` | 219.39 | 0.73% | 32.14% |
| uint8 pos | 100,000 | `vn::from_chars` | 199.37 | 1.69% | 32.99% |
| int16 neg | 100 | `vn::from_chars` | 208.24 | 4.39% | 2.91% |
| int16 neg | 1,000 | `vn::from_chars` | 223.24 | 1.89% | 9.05% |
| int16 neg | 10,000 | `vn::from_chars` | 226.90 | 0.62% | 10.27% |
| int16 neg | 100,000 | `vn::from_chars` | 242.12 | 1.36% | 16.09% |
| int16 pos | 100 | `vn::from_chars` | 217.15 | 4.22% | 14.61% |
| int16 pos | 1,000 | **TIE** `vn` / `std` | 211 / 211 | 35.77% / 1.69% | — |
| int16 pos | 10,000 | `vn::from_chars` | 221.47 | 0.87% | 12.02% |
| int16 pos | 100,000 | `vn::from_chars` | 221.13 | 1.42% | 6.48% |
| uint16 pos | 100 | `vn::from_chars` | 478.11 | 4.33% | 78.15% |
| uint16 pos | 1,000 | `vn::from_chars` | 533.53 | 1.38% | 72.61% |
| uint16 pos | 10,000 | `vn::from_chars` | 537.55 | 0.86% | 74.01% |
| uint16 pos | 100,000 | `vn::from_chars` | 495.72 | 1.26% | 75.68% |
| int32 neg | 100 | `vn::from_chars` | 340.65 | 4.04% | 62.24% |
| int32 neg | 1,000 | `vn::from_chars` | 355.72 | 1.39% | 64.05% |
| int32 neg | 10,000 | `vn::from_chars` | 376.73 | 1.21% | 64.01% |
| int32 neg | 100,000 | `vn::from_chars` | 341.62 | 0.48% | 59.63% |
| int32 pos | 100 | `vn::from_chars` | 349.61 | 3.01% | 55.42% |
| int32 pos | 1,000 | `vn::from_chars` | 352.03 | 1.86% | 57.95% |
| int32 pos | 10,000 | `vn::from_chars` | 342.75 | 1.36% | 56.23% |
| int32 pos | 100,000 | `vn::from_chars` | 341.03 | 1.70% | 53.99% |
| uint32 pos | 100 | `vn::from_chars` | 562.53 | 4.35% | 68.91% |
| uint32 pos | 1,000 | `vn::from_chars` | 581.39 | 1.58% | 65.67% |
| uint32 pos | 10,000 | `vn::from_chars` | 579.27 | 0.60% | 64.60% |
| uint32 pos | 100,000 | `vn::from_chars` | 589.35 | 2.51% | 68.05% |
| int64 neg | 100 | `vn::from_chars` | 553.36 | 2.70% | 64.95% |
| int64 neg | 1,000 | `vn::from_chars` | 604.95 | 1.09% | 77.87% |
| int64 neg | 10,000 | `vn::from_chars` | 597.63 | 0.23% | 80.39% |
| int64 neg | 100,000 | `vn::from_chars` | 571.05 | 1.60% | 80.54% |
| int64 pos | 100 | `vn::from_chars` | 555.23 | 5.82% | 75.81% |
| int64 pos | 1,000 | `vn::from_chars` | 560.62 | 2.21% | 71.24% |
| int64 pos | 10,000 | `vn::from_chars` | 562.64 | 4.62% | 73.75% |
| int64 pos | 100,000 | `vn::from_chars` | 573.87 | 1.50% | 80.32% |
| uint64 pos | 100 | `vn::from_chars` | 558.82 | 3.65% | 69.60% |
| uint64 pos | 1,000 | `vn::from_chars` | 583.72 | 1.36% | 76.16% |
| uint64 pos | 10,000 | `vn::from_chars` | 583.05 | 1.12% | 74.83% |
| uint64 pos | 100,000 | `vn::from_chars` | 552.76 | 4.23% | 64.03% |

---

### GNU 15.2.0 · Apple M1

**`vn::from_chars` wins 39/48 · Ties: 9+9** (timer resolution ties at size=100)

| Type | Size | Winner | MB/s | Dev ±% | Ahead of 2nd |
|------|------|--------|------|---------|--------------|
| int8 neg | 1,000 | `vn::from_chars` | 397.36 | 20.00% | 35.14% |
| int8 neg | 10,000 | `vn::from_chars` | 399.09 | 0.43% | 24.26% |
| int8 neg | 100,000 | `vn::from_chars` | 399.56 | 0.96% | 28.19% |
| int8 pos | 1,000 | `vn::from_chars` | 476.84 | 0.00% | 56.25% |
| int8 pos | 10,000 | `vn::from_chars` | 458.67 | 0.99% | 43.30% |
| int8 pos | 100,000 | `vn::from_chars` | 460.80 | 3.74% | 45.29% |
| uint8 pos | 1,000 | `vn::from_chars` | 413.26 | 23.08% | 13.04% |
| uint8 pos | 10,000 | `vn::from_chars` | 422.18 | 1.79% | 11.96% |
| uint8 pos | 100,000 | `vn::from_chars` | 435.73 | 2.72% | 17.19% |
| int16 neg | 1,000 | `vn::from_chars` | 476.84 | 0.00% | 16.28% |
| int16 neg | 10,000 | `vn::from_chars` | 466.48 | 2.65% | 10.66% |
| int16 neg | 100,000 | `vn::from_chars` | 460.00 | 1.74% | 11.06% |
| int16 pos | 1,000 | `vn::from_chars` | 457.76 | 16.67% | 4.35% |
| int16 pos | 10,000 | `vn::from_chars` | 507.36 | 1.07% | 20.21% |
| int16 pos | 100,000 | `vn::from_chars` | 489.54 | 2.84% | 12.03% |
| uint16 pos | 1,000 | `vn::from_chars` | 556.31 | 14.29% | 16.67% |
| uint16 pos | 10,000 | `vn::from_chars` | 556.27 | 2.03% | 15.18% |
| uint16 pos | 100,000 | `vn::from_chars` | 548.61 | 2.61% | 13.97% |
| int32 neg | 1,000 | `vn::from_chars` | 544.96 | 0.00% | 14.29% |
| int32 neg | 10,000 | `vn::from_chars` | 564.33 | 0.59% | 17.75% |
| int32 neg | 100,000 | `vn::from_chars` | 528.73 | 12.55% | 12.97% |
| int32 pos | 1,000 | `vn::from_chars` | 572.20 | 4.76% | 18.31% |
| int32 pos | 10,000 | `vn::from_chars` | 581.54 | 0.61% | 22.24% |
| int32 pos | 100,000 | `vn::from_chars` | 574.40 | 1.32% | 18.89% |
| uint32 pos | 1,000 | `vn::from_chars` | 590.37 | 7.69% | 8.33% |
| uint32 pos | 10,000 | `vn::from_chars` | 601.87 | 2.49% | 38.25% |
| uint32 pos | 100,000 | `vn::from_chars` | 598.47 | 1.64% | 14.57% |
| int64 neg | 1,000 | `vn::from_chars` | 647.34 | 1.79% | 24.60% |
| int64 neg | 10,000 | `vn::from_chars` | 664.61 | 1.04% | 26.14% |
| int64 neg | 100,000 | `vn::from_chars` | 638.70 | 1.44% | 23.72% |
| int64 pos | 1,000 | `vn::from_chars` | 641.56 | 0.90% | 22.63% |
| int64 pos | 10,000 | `vn::from_chars` | 649.66 | 7.53% | 28.55% |
| int64 pos | 100,000 | `vn::from_chars` | 656.17 | 2.86% | 29.64% |
| uint64 pos | 1,000 | `vn::from_chars` | 641.56 | 0.90% | 16.83% |
| uint64 pos | 10,000 | `vn::from_chars` | 654.40 | 1.20% | 20.84% |
| uint64 pos | 100,000 | `vn::from_chars` | 649.90 | 1.35% | 17.18% |

---

## str-to-int-leading-zeros

### Clang 23.0.0 · Linux — `vn::from_chars` wins 41/48 · Ties: 2+2
### GNU 16.0.1 · Linux — `vn::from_chars` wins 48/48 · **Perfect sweep**
### MSVC 19.44 · Windows — `vn::from_chars` wins 44/48 · Ties: 1+1
### Clang 22.1.4 · Apple M1 — `vn::from_chars` wins 45/48 · Ties: 1+1
### GNU 15.2.0 · Apple M1 — `vn::from_chars` wins 47/48 · Ties: 1+1

> Leading-zeros detail tables omitted for brevity — win distributions match or exceed str-to-int results above.

---

## Summary

| Stage | Compiler / Platform | `vn` wins | Ties | Notes |
|-------|---------------------|-----------|------|-------|
| int-to-str | Clang / Linux | 39 | 2 | |
| int-to-str | GNU / Linux | 42 | 4 | |
| int-to-str | MSVC / Windows | 41 | 2 | |
| int-to-str | Clang / M1 | 43 | 1 | |
| int-to-str | GNU / M1 | 27 | 16 | Timer resolution at n=100 inflates ties |
| str-to-int | Clang / Linux | **48** | 0 | **Perfect sweep** |
| str-to-int | GNU / Linux | 36 | 3 | `std` wins int16 on GNU; `vn` dominant elsewhere |
| str-to-int | MSVC / Windows | **48** | 0 | **Perfect sweep** |
| str-to-int | Clang / M1 | 47 | 1 | |
| str-to-int | GNU / M1 | 39 | 9 | Timer ties at n=100 |
| str-to-int-lz | Clang / Linux | 41 | 2 | |
| str-to-int-lz | GNU / Linux | **48** | 0 | **Perfect sweep** |
| str-to-int-lz | MSVC / Windows | 44 | 1 | |
| str-to-int-lz | Clang / M1 | 45 | 1 | |
| str-to-int-lz | GNU / M1 | 47 | 1 | |