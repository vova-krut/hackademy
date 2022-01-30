package letter

import (
	"sync"
)

func Frequency(text string) map[string]int {
	frequency := make(map[string]int)
	for _, symbol := range text {
		frequency[string(symbol)]++
	}	
	return frequency
}

func ConcurrentFrequency(texts []string) map[string]int {
	var sync sync.WaitGroup
	frequencies := make([]map[string]int, len(texts) * 2)
	counter := 0
	for _, text := range texts {
		sync.Add(2)
		f := func(i int, text string) {
			frequencies[i] = Frequency(text)
			sync.Done()
		} 
		go f(counter, text[:len(text)/2])
		go f(counter+1, text[len(text)/2:])
		counter += 2
	}
	sync.Wait()
	frequency := make(map[string]int)
	for _, text := range frequencies {
		for symbol, count := range text {
			frequency[symbol] += count
		}
	}
	return frequency
}