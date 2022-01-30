package downcase

import (
	"unicode"
)

func Downcase(s string) (string, error) {
	var output[]byte
	for _, v := range s {
		if unicode.IsUpper(v) {
			output = append(output, byte(unicode.ToLower(v))) 
		} else {
			output = append(output, byte(v)) 
		}
	}
	return string(output), nil
}
