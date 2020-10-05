package main

import "C"
import (
	hello "github.com/paithiov909/hello"
)

//export Hi
func Hi(x string) *C.char {
	s := C.CString(hello.Hello(x))
	return s
}

func main() {}
