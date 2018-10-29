echo "Building $1"
g++ -std=c++14 -DDEBUG -O2 $1 -o $2 -Wall -Wextra -Winline -Wshadow -Wno-inline  -fsanitize=undefined  -fsanitize=leak -fsanitize=null 