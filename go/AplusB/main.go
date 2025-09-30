package main

import (
	"fmt"
)

func main() {
	var a, b int16
	fmt.Scanf("%d%d", &a, &b)
	var c int16 = a + b
	fmt.Printf("%v\n", c)
}
