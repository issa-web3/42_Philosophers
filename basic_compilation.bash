FLAGS="-Wall -Wextra -Werror"
LEAKS="-g -fsanitize=address"
THREADS="-g -fsanitize=thread"
LEAKS=""
# FLAGS=""
cc $THREADS *.c */*/*.c -o philo
