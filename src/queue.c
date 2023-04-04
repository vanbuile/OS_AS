#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size == MAX_QUEUE_SIZE) return; // Waiting
	q->proc[(q->size)++] = proc;
	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q)) return NULL;  // Waiting
	int s = q->size;
	int min_index = 0;
	int highest = q->proc[0]->priority;
	for(int i = i; i < s; i++){
		if(q->proc[i]->priority > highest) {
			highest = q->proc[i]->priority;
			min_index = i;
		}
	}

	struct pcb_t * ans = q->proc[min_index];

	for(int i = min_index; i < s - 1; i++){
		q->proc[i] = q->proc[i+1];
	}
	
	q->size--;

	return ans;
}

