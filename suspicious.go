package main

import (
    "fmt"
	  "math/rand"
	  "strings"
	  "time"
)

func main() {
	  dur := time.Duration(160)
	  fmt.Println("Suspciious bomginb. 😂")

	  for i := 0; i < 30; i++ {
        time.Sleep(dur * time.Millisecond)
        times := rand.Intn(10) + 1
        fmt.Println(strings.Repeat("💣", times))
    }
    fmt.Println("😂😂 bombed 😂😂")
}
