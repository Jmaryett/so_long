#include "so_long.h"

char	*comp_str(char *array)
{
	int		i;
	int		len;
	char	*comp;

	i = 0;
	
	if (!array)
		return (NULL);
	while (array[i] != '\n' && array[i] != '\0')
		i++;
	len = i;
	comp = (char *)malloc(sizeof(char) * (len + 1));
	if (!comp)
		return (NULL);
	i = -1;
	while (array[++i] && i < len)
		comp[i] = array[i];
	comp[i] = '\0';
	return (comp);
}