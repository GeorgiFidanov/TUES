#include <stdlib.h>
#include <stdio.h>

#define MAX_NODE 6

// ========= arraylist =============

struct arraylist_t {
	int count;
	int capacity;
	int* arr;
};

struct arraylist_t* init_arraylist(int capacity) {
	struct arraylist_t* new_list = malloc(sizeof(struct arraylist_t));

	new_list->capacity = capacity;
	new_list->count = 0;
	new_list->arr = malloc(sizeof(int) * capacity);
}

void list_add_element(struct arraylist_t* list, int value) {
	if (list->capacity == list->count) {
		list->capacity *= 2;
		list->arr = realloc(list->arr, sizeof(int) * list->capacity);
	}

	list->arr[list->count] = value;
	list->count++;
}

int list_contains(struct arraylist_t* list, int value) {
	for (int i = 0; i < list->count; i++) {
		if (list->arr[i] == value) {
			return 1;
		}
	}

	return 0;
}

// ========= end arraylist =============

// ========= graph and queue ===========

struct queue_t {
	struct queue_node_t* head;
	struct queue_node_t* tail;
};

struct queue_node_t {
	struct graph_node_t* value;
	struct queue_node_t* next;
};

struct connection_t {
	struct  graph_node_t* to;
	struct  graph_node_t* from;
};

struct  graph_node_t {
	int value;
	int connections_count;
	struct connection_t** connections;
};

struct queue_t* queue_init() {
	struct queue_t* new_queue = malloc(sizeof(struct queue_t));

	new_queue->head = NULL;
	new_queue->tail = NULL;

	return new_queue;
}

struct queue_node_t* queue_node_init(struct graph_node_t* value) {
	struct queue_node_t* new_node = malloc(sizeof(struct queue_node_t));

	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}

struct graph_node_t* graph_node_init(int value) {
	struct graph_node_t* new_node = malloc(sizeof(struct graph_node_t));

	new_node->value = value;
	new_node->connections_count = 0;
	new_node->connections = NULL;

	return new_node;
}

int queue_is_empty(struct queue_t* queue) {
	return queue->head == NULL;
}

// add to back of queue
void enqueue(struct queue_t* queue, struct graph_node_t* value) {
	struct queue_node_t* new_node = queue_node_init(value);

	if (queue_is_empty(queue)) {
		queue->head = new_node;
		queue->tail = new_node;
	} else {
		queue->tail->next = new_node;
		queue->tail = new_node;
	}
}


// remove first element from queue
struct graph_node_t* dequeue(struct queue_t* queue) {
	if (queue_is_empty(queue)) {
		return NULL;
	}
	struct graph_node_t* result = queue->head->value;
	if (queue->head == queue->tail) {
		queue->head = queue->tail = NULL;
	} else {
		queue->head = queue->head->next;
	}

	return result;
}

struct connection_t* init_connection(struct graph_node_t* to) {
	struct connection_t* new_conn = malloc(sizeof(struct connection_t));
	new_conn->to = to;

	return new_conn;
}

void add_neighbour(struct graph_node_t* node, struct graph_node_t* neighbour) {
	node->connections = realloc(node->connections, sizeof(struct graph_node_t*) * (node->connections_count + 1));
	node->connections[node->connections_count] = init_connection(neighbour);
	node->connections_count++;
}

// ========= end graph and queue ===========

void shortest_distance(struct graph_node_t* start, struct graph_node_t* end) {
	int* passed = malloc(sizeof(int) * (MAX_NODE + 1));
	int* distance = malloc(sizeof(int) * (MAX_NODE + 1));
	for (int i = 1; i <= MAX_NODE; i++) {
		passed[i] = -1;
		distance[i] = -1;
	}
	passed[start->value] = start->value;
	distance[start->value] = 0;

	struct queue_t* to_visit = queue_init();

	enqueue(to_visit, start);


	while (!queue_is_empty(to_visit)) {
		struct graph_node_t* current = dequeue(to_visit);

		for (int i = 0; i < current->connections_count; i++) {
			struct graph_node_t* neighbour = current->connections[i]->to;

			// check if node is not visited
			if (passed[neighbour->value] == -1) {
				passed[neighbour->value] = current->value;
				distance[neighbour->value] = distance[current->value] + 1;
				enqueue(to_visit, neighbour);
			}
		}
	}

	printf("%d\n", distance[end->value]);
}

int main () {
	struct graph_node_t* one = graph_node_init(1);
	struct graph_node_t* two = graph_node_init(2);
	struct graph_node_t* three = graph_node_init(3);
	struct graph_node_t* four = graph_node_init(4);
	struct graph_node_t* five = graph_node_init(5);
	struct graph_node_t* six = graph_node_init(6);

	add_neighbour(one, two);
	add_neighbour(one, five);
	add_neighbour(five, six);
	add_neighbour(six, one);
	add_neighbour(two, four);
	add_neighbour(two, five);
	add_neighbour(five, two);
	add_neighbour(five, four);
	add_neighbour(four, three);
	add_neighbour(three, four);
	add_neighbour(three, two);

	shortest_distance(one, three);
}
