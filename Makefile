all: producer consumer

producer: producer.c
	gcc -o producer producer.c

clearproducer: producer
	rm producer

clearconsumer: consumer
	rm consumer

consumer: consumer.c
	gcc -o consumer consumer.c

clean: clearconsumer clearproducer