package main

import (
	"fmt"
)

// rotate ...
func rotate(arr [][]int) {
	// vert
	var top int
	_ = top
	lenArr := len(arr)
	horz := 0
	_ = horz
	vertLayer := 2
	_ = vertLayer
	for i := 0; i < lenArr/2; i++ {
		for j := i; j < lenArr-i-1; j++ {
			fmt.Println("------------------------------------")
			// store current cell in temp variable
			temp := arr[i][j]
			fmt.Println("temp", "<==", "[", i, "]", "[", j, "]")

			// move values from right to top
			arr[i][j] = arr[j][lenArr-1-i]
			fmt.Println("right <--- top")
			fmt.Println("[", i, "]", "[", j, "]", "<==", "[", j, "]", "[", lenArr-1-i, "]")

			// move values from bottom to right
			arr[j][lenArr-1-i] = arr[lenArr-1-i][lenArr-1-j]
			fmt.Println("")
			fmt.Println("bottom <--- right")
			fmt.Println("[", j, "]", "[", lenArr-1-i, "]", "<==", "[", lenArr-1-i, "]", "[", lenArr-1-j, "]")

			// move values from left to bottom
			arr[lenArr-1-i][lenArr-1-j] = arr[lenArr-1-j][i]
			fmt.Println("")
			fmt.Println("left <--- bottom")
			fmt.Println("[", lenArr-1-i, "]", "[", lenArr-1-j, "]", "<==", "[", lenArr-1-j, "]", "[", i, "]")

			// assign temp to left
			arr[lenArr-1-j][i] = temp
			fmt.Println("[", lenArr-1-j, "]", "[", i, "]", "<-----", "temp")

			fmt.Println("------------------------------------")
		}
	}

	display(arr)
}

// display ...
func display(arr [][]int) {
	for _, value := range arr {
		for _, value := range value {
			fmt.Print(value, " ")
		}
		fmt.Println("")
	}
}

func main() {
	arr := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	rotate(arr)

}
