#include <stdio.h>
#include <stdlib.h>

struct graph_t{
	unsigned int city_number, neighbours_count;
	struct graph_t **nodes;
};

struct queue{
	struct queue* next;
	struct graph_t* city;
};

struct graph_t* init_graph(unsigned int city_number){
	struct graph_t* new_graph = (struct graph_t*)malloc(sizeof(struct graph_t));
	if (new_graph == NULL) return 0;

	new_graph->city_number = city_number, new_graph->neighbours_count = 0;
	new_graph->nodes = (struct graph_t**)malloc(sizeof(struct graph_t *));
	//new_graph->nodes = 0;
	if(new_graph->nodes == NULL) return 0;

	return new_graph;
}

struct graph_t* find_city(struct graph_t* graph, unsigned int city_number){
	struct graph_t* temp = 0;
	if (graph->city_number == city_number) return graph;

	for (unsigned int i = 0; i < graph->neighbours_count; i++){
		if (graph->nodes == NULL) return 0;
		if(temp == find_city(graph->nodes[i], city_number)) return temp;
	}
	return 0;
}

void add_connections(struct graph_t **cities, unsigned int from, unsigned int to){
	struct graph_t* from_city = cities[from - 1], * to_city = cities[to - 1];

	from_city->nodes = realloc(from_city->nodes, sizeof(struct graph_t*) * from_city->neighbours_count + 1);
	if (from_city->nodes == NULL) return;
	to_city->nodes = realloc(to_city->nodes, sizeof(struct graph_t*) * to_city->neighbours_count + 1);
	if (to_city->nodes == NULL) return;

	from_city->nodes[from_city->neighbours_count++] = to_city;
	to_city->nodes[to_city->neighbours_count++] = from_city;
}

unsigned int get_shortest_rout_count(struct graph_t* start, struct graph_t* end, unsigned int *best, int temp){
	if (start == NULL || end == NULL) return NULL;

	if (start == end){
		if (temp < *best){
			*best = temp;
            return temp;
		}
	};

	for (unsigned int i = 0; i < start->neighbours_count; i++){
		get_shortest_rout_count(start->nodes[i], end, best, temp+1);
	}
}

void get_cities(struct graph_t** available_cities, struct graph_t* city_map, struct graph_t* home_city, unsigned int *available_cities_count, double cost_between_two_cities, double *available_money)
{
	if (city_map == NULL) return;
	unsigned int best = 1 << 31;
	get_shortest_rout_count(city_map, home_city, &best, 0);

	if (*available_money - ((best+1) * cost_between_two_cities) < 0) return;

	available_cities[*available_cities_count++] = city_map;

	for (unsigned int i = 0; i < city_map->neighbours_count; i++){
		get_cities(available_cities, city_map->nodes[i], home_city, available_cities_count, cost_between_two_cities, available_money);
	}

}

int compar(struct graph_t* first, struct graph_t* second)
{
	return first->city_number - second->city_number;
}

struct graph_t** sort_cities(struct graph_t** available_citties, unsigned int available_cities_count)
{
	qsort(available_citties, available_cities_count, sizeof(struct graph_t*), compar);
	return available_citties;
}

void print_cities(struct graph_t** available_cities, unsigned int available_cities_count)
{
	for (unsigned int i = 0; i < available_cities_count; i++)
	{
		printf("\n%d ", available_cities[i]->city_number);
	}
}

double get_cost_between_two_cities(double oil_price, double car_cost)
{
	return 33.5 / 100 * car_cost * oil_price;
}

void main()
{
	unsigned int city_count = 0, roads_count = 0, murder_city = 0, home_city = 0, node_from = 0, node_to = 0;
	double oil_price = 0, car_cost = 0, available_money = 0;


	printf("city_count: ");
	scanf(" %u", &city_count);

	struct graph_t** cities = (struct graph_t**)malloc(sizeof(struct graph_t*) * city_count);
	if (cities == NULL) return;

	for (unsigned int i = 0; i < city_count; i++)
	{
		cities[i] = init_graph(i);
	}

	printf("roads_count: ");
	scanf(" %u", &roads_count);

	for (unsigned int i = 0; i < roads_count; i++)
	{
		scanf(" %d", &node_from);
		scanf(" %d", &node_to);
		add_connections(cities, node_from, node_to);
	}

	printf("murder_city: ");
	scanf(" %u", &murder_city);

	struct graph_t* city_map = cities[murder_city-1];

	printf("oil_price: ");
	scanf(" %lf", &oil_price);

	printf("car_cost: ");
	scanf(" %lf", &car_cost);

	printf("available_money: ");
	scanf(" %lf", &available_money);

	printf("home_city: ");
	scanf(" %u", &home_city);

	struct graph_t** available_citties = 0;
	unsigned int available_cities_count = 0;
	get_cities(available_citties, city_map, cities[home_city - 1], &available_cities_count, get_cost_between_two_cities(oil_price, car_cost), &available_money);

	available_citties = sort_cities(available_citties, available_cities_count);
	print_cities(available_citties, available_cities_count);
}
/*
8
10
1 2
1 3
3 5
3 4
4 6
6 7
7 2
7 8
2 8
4 5
1
1
10
120
2
*/
