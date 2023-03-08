#include "create_new_agents.h"
t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count){
	if (!name || counter < 1 || !counter){
		return NULL;
	}
	t_agent **new_agents = malloc(sizeof(t_agent *) * counter + 1);
	for (int i = 0; i < counter; i++){
		new_agents[i] = mx_create_agent(name[i], power[i], strength[i]);
	}
	new_agents[counter] = NULL;
	return new_agents;
}
