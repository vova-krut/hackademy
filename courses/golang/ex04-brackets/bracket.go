package brackets

type Stack struct {
	data []rune
}

func New() *Stack {
	return &Stack{}
}

func (s *Stack) Push(num rune) {
	s.data = append(s.data, num)
}

func (s *Stack) Pop() rune {
	if len(s.data) == 0 {
		var r rune
		return r
	}
	num := s.data[len(s.data) - 1]
	s.data = s.data[:len(s.data) - 1]
	return num
}

func verify(symb1, symb2 string) bool {
	switch symb1 + symb2 {
	case "{}", "()", "[]":
		return true
	default:
		return false
	}
}

func Bracket(text string) (bool, error) {
	Stack := New()
	for _, v := range text {
		switch v {
		case '{', '(', '[' :
			Stack.Push(v)
		case '}', ')', ']' :
			symb := Stack.Pop()
			if !verify(string(symb), string(v)) {
				return false, nil
			}
		}
	}
	return len(Stack.data) == 0, nil
}