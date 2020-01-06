cp /Users/tlucille/42cursus/gnl/gnl_42cursus/get_next_line.c /Users/tlucille/42cursus/gnl/gnl_42cursus/get_next_line.h /Users/tlucille/42cursus/gnl/gnl_42cursus/get_next_line_utils.c .;
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main_test.c get_next_line.c get_next_line_utils.c -L. -lft;
rm log_test1;
touch log_test1;
