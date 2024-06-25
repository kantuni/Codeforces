g++ -std=c++20 generator.cpp -o generator
g++ -std=c++20 binary-deque.cpp -o original
g++ -std=c++20 naive.cpp -o naive

for ((i = 0; i < 10000; i++)); do
  echo "Test: " $i
  ./generator $i >sin
  ./original <sin >souto
  ./naive <sin >soutn
  diff -w souto soutn || break
done
