package stack

type Stack struct {
	data []int
}

func New() *Stack {
	return &Stack{}
}

func (s *Stack) Push(num int) {
	s.data = append(s.data, num)
}

func (s *Stack) Pop() int {
	num := s.data[len(s.data) - 1]
	s.data = s.data[:len(s.data) - 1]
	return num
}