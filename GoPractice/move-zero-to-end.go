package main

import "fmt"

func main() {

	arr := []int{6, 0, 8, 2, 3, 0, 4, 0, 1}
	cnt := -1
	arr1 := make([]int, 0)
	for _, value := range arr {
		if value == 0 {
			cnt++
		} else {
			arr1 = append(arr1, value)
		}
	}
	for ; cnt > 0; cnt-- {
		arr1 = append(arr1, 0)
	}

	fmt.Println(arr1)
}
