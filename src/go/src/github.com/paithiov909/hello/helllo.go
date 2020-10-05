package hello

import (
	"strings"
)

func Hello(x string) string {
	s := "hello " + x + "!"
	return (strings.Title(s))
}
