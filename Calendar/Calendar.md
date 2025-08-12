# 日历计算常用算法公式

## 计算星期几

---

### 1. Zeller’s 公式

```c++
// 返回值：0=Saturday, 1=Sunday, …, 6=Friday
int zeller(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return h;
}
```

---

### 2. Gauss 公式

```c++
// 返回值：0=Sunday, 1=Monday, …, 6=Saturday
int gauss(int year, int month, int day) {
    if (month < 3) {
        year--;
        month += 12;
    }
    int q = day;
    int m = month;
    int Y = year;
    int W = (q + Y + Y/4 - Y/100 + Y/400 + (31 * (m - 1)) / 12) % 7;
    return W;
}
```

---

### 3. Doomsday 算法

```c++
// 返回值：0=Sunday, 1=Monday, …, 6=Saturday
int doomsday(int year, int month, int day) {
    static int cc[] = {2, 0, 5, 3};      // 世纪码(按 century%4)
    int century = year / 100;
    int anchor = cc[century % 4];
    int y = year % 100;
    int A = y / 12;
    int B = y % 12;
    int C = B / 4;
    int d = (A + B + C + anchor) % 7;
    static int md[] = {0,3,0,28,14,4,9,6,11,8,5,10,7};
    if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && (month == 1 || month == 2))
        md[month] = (month == 1 ? 4 : 1);
    int offset = day - md[month];
    return (d + offset % 7 + 7) % 7;
}
```

---

### 4. Sakamoto 算法

```c++
// 返回值：0=Sunday, 1=Monday, …, 6=Saturday
int sakamoto(int year, int month, int day) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) --year;
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}
```

---

## 日序映射

把 0001-01-01 映射为 0 (改变映射起始位置直接改最后一位常数项即可,可参考下面):

$$
\text{idx}
= 365Y+\Big\lfloor\frac{Y}{4}\Big\rfloor-\Big\lfloor\frac{Y}{100}\Big\rfloor+\Big\lfloor\frac{Y}{400}\Big\rfloor
+\Big\lfloor\frac{153\,(M-3)+2}{5}\Big\rfloor + D\;-\;307
$$

对于前一天后一天可直接+1/-1

```c++ 
// 0001-01-01 -> 0
long long base_0001(int Y, int M, int D) { 
    if (M <= 2) { Y--; M += 12; }
    return 365LL*Y + Y/4 - Y/100 + Y/400
         + (153LL*(M-3)+2)/5 + D - 307;
}

//计算日序差
long long day_dis(int y, int m, int d, int Y, int M, int D) {
    return base_0001(y, m, d) - base_0001(Y, M, D);
}

// 1970-01-01 -> 0
long long day_index(int Y, int M, int D) {
    if (M <= 2) { Y--; M += 12; }
    return 365LL*Y + Y/4 - Y/100 + Y/400
         + (153LL*(M-3)+2)/5 + D - 719468; 
}
```

