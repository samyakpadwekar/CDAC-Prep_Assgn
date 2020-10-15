/*A CSV file contains movies data in given form. 
Read the file and load data into a singly linked list of movie objects. 
Also give facility to find movies by name and by genre.

movieid,title,genres (data in csv file)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOVIE_DB	"movies.csv"

typedef struct movie {
	int id;
	char name[80];
	char genres[220];
}Movie;

void movie_display(Movie *m) {
	printf("Id=%d Name=%s Genres=%s\n", m->id, m->name, m->genres);
}

typedef struct node {
	Movie data;
	struct node *next;
}Node;

Node *head = NULL; 

Node* create_node(Movie val) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

void add_last(Movie val) {
	Node *newnode = create_node(val);
	if(head == NULL)
		head = newnode;
	else {
		Node *temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display_list() {
	Node *temp = head;
	while(temp != NULL) {
		movie_display(&temp->data);
		temp = temp->next;
	}
}

int parse_movie(char line[], Movie *m) {
	int success = 0;
	char *id, *name, *genres;
	id = strtok(line, ",\n");
	name = strtok(NULL, ",\n");
	genres = strtok(NULL, ",\n");
	if(id == NULL || name == NULL || genres == NULL)
		success = 0; 
	else {
		success = 1;
		m->id = atoi(id);	// "10" (string) --> 10 (int)
		strcpy(m->name, name);
		strcpy(m->genres, genres);
	}
	return success;
}

void find_movie_by_name() {
	char name[80];
	Node *temp = head;
	int found = 0;
	printf("\nEnter movie name to be searched: ");
	gets(name);
    printf("\n");

	temp = head;
	while(temp != NULL) {
		if(strcmp(name, temp->data.name) == 0) {
			movie_display(&temp->data);
			found = 1;
			break;
		}
		temp = temp->next;
	}

	if(!found)
		printf("movie not found.\n");
}

void find_movie_by_genre() {
	char genre[80];
	Node *temp = head;
	int found = 0;
	printf("\nEnter movie genre to be searched: ");
	gets(genre);
    printf("\n");

	temp = head;
	while(temp != NULL) {
		if(strstr(temp->data.genres, genre) != NULL) {
			movie_display(&temp->data);
			found = 1;
		}
		temp = temp->next;
	}

	if(!found)
		printf("movie not found.\n");
}

int main() {
	FILE *fp;
	char line[1024];
	Movie m;
	fp = fopen(MOVIE_DB, "r");
	if(fp == NULL) {
		perror("failed to open movies file");
		exit(1);
	}

	while(fgets(line, sizeof(line), fp) != NULL) {
		//printf("%s\n", line);
		parse_movie(line, &m);
		//movie_display(&m);
		add_last(m); 
	}

	fclose(fp);

    display_list(); // diplay movie linked list
    find_movie_by_name();
	find_movie_by_genre();

	return 0;
}


	
