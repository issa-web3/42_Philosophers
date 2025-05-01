FLAGS="-Wall -Wextra -Werror"
LEAKS="-g -fsanitize=address"
LEAKS=""
FLAGS=""
cc  *.c */*/*.c -g -fsanitize=thread -o philo
