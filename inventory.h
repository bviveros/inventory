/*
 * inventory.h
 * author: Braulio Viveros
 * date: August 6th, 2024
*/

#ifndef _INVENTORY_H_
#define _INVENTORY_H_

struct Item
{
  float weight;
  float cost;
  char* name;
};

void init();
void add_item(struct Item* new_item);
void remove_item(struct Item* consumable_item);
void display_inventory();

#endif