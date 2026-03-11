package none

func minWindow(s string, t string) string {
	tcnt := make(map[byte]int, 100)
	for i := 0; i < len(t); i++ {
		tcnt[t[i]]++
	}
	fin, need := len(tcnt), 0
	l, r, minl := 0, -1, int(1e9+7)
	cnt := make(map[byte]int, 100)
	ans := ""
	for r < len(s)-1 {
		r++
		v, e := tcnt[s[r]]
		if e {
			cnt[s[r]]++
			if cnt[s[r]] == v {
				need++
			}
			if need == fin {
				for l < r {
					vl, el := tcnt[s[l]]
					if el {
						if vl == cnt[s[l]] {
							break
						}
						cnt[s[l]]--
					}
					l++
				}
			}
		}
		if need == fin {
			le := r - l + 1
			if le < minl {
				minl = le
				ans = s[l : r+1]
			}
		}
	}
	return ans
}
