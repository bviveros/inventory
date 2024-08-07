/*
 * item.c
 * author: Braulio Viveros
 * date: August 6th, 2024
*/

/* included libraries */
#include <stdio.h>
#include <stdlib.h>

/* included user defined libraries */
#include "inventory.h"

int main()
{
  /* initialize an empty inventory(backpack) */
  init();

  /* declare objects of type Item */
  struct Item* weapon = (struct Item*) malloc(sizeof(struct Item*));
  struct Item* shield = (struct Item*) malloc(sizeof(struct Item*));
  struct Item* potion = (struct Item*) malloc(sizeof(struct Item*));

  /* initialize all the objects' properties */
  weapon->name = "broad";
  weapon->weight = 10.00;
  weapon->cost = 100.00;

  shield->name = "buckler";
  shield->weight = 15.00;
  shield->cost = 50.00;

  potion->name = "health";
  potion->weight = 2.50;
  potion->cost = 10.50;


  /* add the object to inventory */
  add_item(weapon);
  add_item(shield);
  add_item(potion);

  /* display inventory */
  display_inventory();

  /* remove the object from inventory */
  remove_item(shield);
  remove_item(potion);
  remove_item(weapon);

  /* display inventory */
  display_inventory();

  printf("About to free allocated memory for all items in inventory!\n");

  /* free all allocated memory */
  free(weapon);
  free(shield);
  free(potion);

  /* indicates successful execution */
  return 0;
}