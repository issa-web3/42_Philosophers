FLAGS="-Wall -Wextra -Werror"
LEAKS="-g -fsanitize=address"
THREADS="-g -fsanitize=thread"
LEAKS=""
# FLAGS=""
cc $LEAKS *.c */*/*.c -o philo
