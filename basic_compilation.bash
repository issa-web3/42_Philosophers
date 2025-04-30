$FLAGS = -Wall -Wextra -Werror
$LEAKS = -g -fsanitize=address
$LEAKS = 
cc $FLAGS *.c */*.c */*/*.c $LEAKS -o philo