package main

import (
	"fmt"
	"time"
)

func getSeats() int {
	var seats int
	fmt.Printf("Enter the amount of places at waiting room: ")
	fmt.Scanf("%d", &seats)
	return seats
}

func getCustomers() int {
	var customers int
	fmt.Printf("Enter the amount of customers: ")
	fmt.Scanf("%d", &customers)
	return customers
}

func barber(seats chan int, customer_served chan int, going_home chan bool, customer_amount int) {
	customer_id := -1
	customers_served := 0
	for customers_served != customer_amount {
		select {
		case customer_id = <- seats:
		default:
			fmt.Printf("Barber is currently sleeping\n")
			customer_id = <- seats
			fmt.Printf("Barber was woken up by customer %d\n", customer_id)
		}
		serve_customer(customer_id, customer_served)
		customers_served++
	}
	fmt.Printf("Barber is closing his shop\n")
	going_home <- true
}

func serve_customer(customer_id int, customer_served chan int) {
	time.Sleep(20 * time.Millisecond)
	customer_served <- customer_id
	fmt.Printf("Barber served client %d\n", customer_id)
}

func customer(id int, waiting_room chan int, customer_served chan int) {
	serviced := false
	for serviced != true {
		select {
		case waiting_room <- id:
			fmt.Printf("Customer %d entering barbershop, %d places at waiting room\n", id, len(waiting_room))
			finished_customer := -1
			for finished_customer != id {
				finished_customer = <- customer_served
			}
			fmt.Printf("Customer %d leaving barber shop with a new cut\n", id)
			serviced = true
		default:
			fmt.Printf("Customer %d didn't enter barber shop cuz it is full\n", id)
			time.Sleep(25 * time.Millisecond)
		}
	}
}

func main() {
	seats := getSeats()
	customers := getCustomers()
	waiting_room := make(chan int, seats)
	customer_served := make(chan int)
	barber_going_home := make(chan bool)
	go barber(waiting_room, customer_served, barber_going_home, customers)
	for id := 0; id < customers; id++ {
		go customer(id, waiting_room, customer_served)
		time.Sleep(10 * time.Millisecond)
	}
	<-barber_going_home
}