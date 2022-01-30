package cipher

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

type Caesar struct {
	key int
}

type Vigenere struct {
	key string
}

func NewCaesar() *Caesar {
	return &Caesar{3}
}

func NewShift(shift int) *Caesar {
	if shift > 25 || shift < -25 || shift == 0 {
		return nil
	}
	return &Caesar{key: shift}
}

func NewVigenere(key string) *Vigenere {
	valid, a_check := true, true
	for _, symb := range key {
		if symb < 'a' || symb > 'z' {
			valid = false
		}
		if symb != 'a' {
			a_check = false
		}
	}

	if !valid || a_check || key == "" {
		return nil
	}
	return &Vigenere{key}
}

func stringify(str string) string {
	output := ""
	for _, v := range str {
		if v >= 'A' && v <= 'Z' || v >= 'a' && v <= 'z' {
			output += string(v)
		}
	}
	return output
}

func (v Vigenere) codify(length int) string {
	currCode := v.key
	oneCodeLen := len(v.key)
	codeLen := oneCodeLen
	for length > codeLen {
		currCode += v.key
		codeLen += oneCodeLen
	}
	return currCode[:length]
}

func (c Caesar) Encode(plain string) (coded string) {
	for _, v := range plain {
		if v >= 'A' && v <= 'Z' {
			v += 32
		}
		if v >= 'a' && v <= 'z' {
			v += rune(c.key)
			if v > 'z' {
				v -= 26
			}
			if v < 'a' {
				v += 26
			}
			coded += string(v)
		}
	}

	return coded
}

func (c Caesar) Decode(coded string) (plain string) {
	for _, v := range coded {
		v -= rune(c.key)
		if v > 'z' {
			v -= 26
		}
		if v < 'a' {
			v += 26
		}
		plain += string(v)
	}
	return plain
}

func (v Vigenere) Encode(plain string) (coded string) {
	plain = stringify(plain)
	currCode := v.codify(len(plain))

	for index, v := range plain {
		if v >= 'A' && v <= 'Z' {
			v += rune(32)
		}
		if v >= 'a' && v <= 'z' {
			v += rune(currCode[index] - 'a')

			if v > 'z' {
				v -= rune(26)
			}

			coded += string(v)
		}
	}

	return coded
}

func (v Vigenere) Decode(coded string) (plain string) {
	currCode := v.codify(len(coded))
	for index, v := range coded {
		v -= rune(currCode[index] - 'a')

		if v < 'a' {
			v += rune(26)
		}

		plain += string(v)
	}

	return plain
}