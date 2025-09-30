package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &x[i])
	}
	var (
		minvar int = x[0]
		maxvar int = x[0]
	)
	if len(x) > 1 {

		for i := 1; i < n; i++ {
			if minvar > x[i] {
				minvar = x[i]
			}
			if maxvar < x[i] {
				maxvar = x[i]
			}
		}
	}
	fmt.Printf("%v %v\n", minvar, maxvar)
}
