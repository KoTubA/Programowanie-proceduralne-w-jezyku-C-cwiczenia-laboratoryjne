#include <stdio.h>
#include <stdlib.h>

char labirynt[10][18] = {{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                         {'@','@','@','@','@','@','X','X','X','@','X','@','@','@','@','@','X','X'},
                         {'X','@','X','@','X','@','X','@','@','@','X','@','X','@','X','X','X','X'},
                         {'X','@','X','@','X','X','X','X','X','@','@','@','X','X','X','@','X','X'},
                         {'X','@','X','@','@','@','@','X','@','@','X','@','X','@','@','@','@','X'},
                         {'X','X','X','@','X','X','@','X','@','X','X','X','@','X','@','X','X','X'},
                         {'X','@','@','@','@','X','@','X','@','@','@','@','@','@','@','@','@','X'},
                         {'X','@','X','X','@','X','@','X','X','@','X','X','X','X','@','X','@','X'},
                         {'X','@','@','X','@','X','@','@','@','@','@','@','X','@','@','X','@','@'},
                         {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

int visited[10][18] = {0};

typedef enum {false, true} bool;

typedef struct Stack{
	int x;
	int y;
	struct Stack * next;
} Stack;

Stack *push(Stack * element, int xx, int yy);
Stack *pop(Stack *element);
bool wschod(Stack * element);
bool poludnie(Stack *element);
bool zachod(Stack * element);
bool polnoc(Stack * element);
void draw_path(Stack * element);
void draw_visited();
void draw_maze();
bool maze_out();

int main()
{

	Stack *first = NULL;

	first = push(first,1,0);


	while(maze_out())
	{
		if(wschod(first))
		{
			first = push(first,first->x, first->y+1);
			visited[first->x][first->y] = 1;
		}
		else if(poludnie(first))
		{
			first = push(first,first->x + 1, first->y);
			visited[first->x][first->y] = 1;
		}
		else if(zachod(first))
		{
			first = push(first,first->x, first->y-1);
			visited[first->x][first->y] = 1;
		}
		else if(polnoc(first))
		{
			first = push(first,first->x - 1, first->y);
			visited[first->x][first->y] = 1;
		}
		else
		{
			first = pop(first);

		}

	}
	printf("LABIRYNT:\n\n");
	draw_maze();

	printf("\nOdwiedzone miejsca:\n");
	printf("1-Odwiedzone\n0-Nieodwiedzone\n\n");
	draw_visited();

	printf("\n\nDroga do wyjscia:\n");
	draw_path(first);
}


Stack *push(Stack *element, int xx, int yy)
{
	if(element == NULL)
	{
		Stack *new_element = (Stack *) malloc(sizeof(Stack));

		new_element->x = xx;
		new_element->y = yy;
		new_element->next = NULL;

		visited[xx][yy] = 1;

		return new_element;
	}
	else
	{
		Stack *new_element = (Stack *) malloc(sizeof(Stack));

		new_element->x = xx;
		new_element->y = yy;
		new_element->next = element;

		return new_element;
	}
}

Stack *pop(Stack *element)
{
	if(element != NULL)
	{
		Stack * temp = element->next;
		free(element);
		element = temp;
	}

	return element;
}

bool wschod(Stack *element)
{
	if(labirynt[element->x][element->y + 1] != 'X' && visited[element->x][element->y + 1] != 1) return true;
	else return false;
}

bool poludnie(Stack *element)
{
	if(labirynt[element->x+1][element->y] != 'X' && visited[element->x+1][element->y] != 1) return true;
	else return false;
}

bool zachod(Stack *element)
{
	if(labirynt[element->x][element->y-1] != 'X' && visited[element->x][element->y-1] != 1) return true;
	else return false;
}

bool polnoc(Stack *element)
{
	if(labirynt[element->x-1][element->y] != 'X' && visited[element->x-1][element->y] != 1) return true;
	else return false;
}

bool maze_out()
{
	if(visited[8][17] != 1)return true;
	else return false;
}

void draw_path(Stack *element)
{
	Stack *q = element;
	while(q != NULL)
	{
		labirynt[q->x][q->y] = '.';

		q = q->next;
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			printf("%c ",labirynt[i][j]);
		}
		printf("\n");
	}
}

void draw_visited()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			printf("%d ",visited[i][j]);
		}
		printf("\n");
	}
}

void draw_maze()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			printf("%c ",labirynt[i][j]);
		}
		printf("\n");
	}
}
