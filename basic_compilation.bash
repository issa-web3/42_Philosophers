FLAGS="-Wall -Wextra -Werror"
LEAKS="-g -fsanitize=address"
FLAGS=""
cc $FLAGS $LEAKS *.c */*.c */*/*.c -o philo
