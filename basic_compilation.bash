$FLAGS = -Wall -Wextra -Werror
cc $FLAGS *.c */*.c */*/*.c -g -fsanitize=address -o philo