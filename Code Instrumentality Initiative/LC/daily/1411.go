package main

func numOfWays(n int) int {
	const MOD = 1e9 + 7
	var a, b int64 = 6, 6
	for i := 1; i < n; i++ {
		na := 3*a + 2*b
		nb := 2*a + 2*b
		a, b = na%MOD, nb%MOD
	}
	return int((a + b) % MOD)
}

/*
A: 123
B: 121

A(123) -> {
	212, ->B
	231, ->A
	232, ->B
	312, ->A
	313  ->B
}

B(121) ->{
	212, ->B
	213, ->A
	312, ->A
	313, ->B
}

ans=A+B

A(n)=2A(n-1)+2B(n-1)
B(n)=3A(n-1)+2B(n-1)
*/
