/*
 * inventory.c
 * author: Braulio Viveros
 * date: August 6th, 2024
*/

/* included standard libraries */
#include <stdio.h>
#include <stdlib.h>

/* included user defined libraries */
#include "inventory.h"

/* struct to chain all the items together */
struct Node
{
  struct Item* item;
  struct Node* next;
};

/* global variable */
struct Node* head;

/* creates an empty backpack */
void init()
{
  head = NULL;
}

/* adds item to backpack */
void add_item(struct Item* new_item)
{
  /* if head is empty */
  if( !head ) {
    /* allocate enough memory for a new node */
    head = malloc(sizeof(struct Node*));
    /* assign the new item to the head of the inventory */
    head->item = new_item;
    /* next space in inventory is empty */
    head->next = NULL;
    printf("first item in inventory: %s\n", head->item->name);
  }
  else {
    /* create a new node(space) to add to the inventory */
    struct Node* new_node = malloc(sizeof(struct Node*));
    /* assign new item to the space and it is next to nothing */
    new_node->item = new_item;
    new_node->next = NULL;

    /* create a node to traverse the inventory and assign it to the top of the list */
    struct Node* cur_node = head;

    /* loop while there exists a next node in the list */
    while(cur_node->next){
      /* move down to the next node */
      cur_node = cur_node->next;
    }
    /* add new node with item to the end of the list */
    cur_node->next = new_node;
    printf("new item in inventory: %s\n", cur_node->next->item->name);
  }
}

/* removes item from backpack */
void remove_item(struct Item* consumable_item)
{
  /* allocate memory for a node */
  struct Node* remove_node = head;
  struct Node* trav_node = head;

  /* if item is found at the top of list */
  if(head && head->item == consumable_item){
    head = head->next;
    printf("removing item %s from inventory\n", remove_node->item->name);
    free(remove_node);
  }

  /* while traversal node isn't NULL and item not yet found */
  while(remove_node && remove_node->item != consumable_item){
    /* keeps track of previous node */
    trav_node = remove_node;
    /* move down the list */
    remove_node = remove_node->next;
  }

  /* if item was found in list */
  if(remove_node && remove_node->item == consumable_item){
    /* previous node connects to the next next node */
    trav_node->next = remove_node->next;
    /* remove node with item from the list */
    printf("removing item %s from inventory\n", remove_node->item->name);
    free(remove_node);
  }
}

/* displays all the items in the inventory */
void display_inventory()
{
  /* assign traversal node to the head of the inventory */
  struct Node* traversal_node = head;

  unsigned int i = 1;

  /* traverse while traversal node isn't null(end of list) */
  while(traversal_node){
    /* print the current contents of the node */
    printf("item %u name: %s\n", i, traversal_node->item->name);
    /* move down the list */
    traversal_node = traversal_node->next;
    i+=1;
  }
  printf("\n");
}