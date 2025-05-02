FLAGS="-Wall -Wextra -Werror"
LEAKS="-g -fsanitize=address"
THREADS="-g -fsanitize=thread"
LEAKS=""
# FLAGS=""
cc $FLAGS *.c */*/*.c -o philo
