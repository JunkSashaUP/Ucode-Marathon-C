#include "create_agent.h"

t_agent *mx_create_agent(char *name, int power, int strength){
	if (name == NULL){
		return NULL;	
	}
	t_agent *new_agent = malloc(sizeof(t_agent *));
	new_agent->name = mx_strdup(name);
	new_agent->power = power;
	new_agent->strength = strength;
	return new_agent;
}
