#include <string>
#include <memory>
#include <iostream>

struct Foo {
  int* intArr[5];
  std::string name;
  size_t howManyBytes;
  std::unique_ptr<Foo> nextFoo;
};


void allocator(Foo& foo, int maxSize) {
  for (unsigned idx = 0; idx < maxSize; ++idx) {
    if (idx > 1) {
      for (unsigned ii = 0; ii < idx - 1; ++ii)
        delete[] foo.nextFoo->intArr[ii];
    }
    for (unsigned ii = 0; ii < idx; ++ii) {
      foo.nextFoo->intArr[ii] = new int[idx];
    }
    for (unsigned ii = 0; ii < idx; ++ii) {
      for (unsigned jj = 0; jj < idx; ++jj) {
        foo.nextFoo->intArr[ii][jj]=ii * jj;
        std::cout << foo.nextFoo->intArr[ii][jj] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

void anotherFunction(Foo& foo) {
  std::cout << "foo's child is " << foo.nextFoo->name << std::endl;
  allocator(foo, 7);
  std::cout << "Nice! " << foo.nextFoo->name << std::endl;
}


void coolFunction(Foo foo) {
  std::cout << "Got struct " << foo.name << std::endl;
  anotherFunction(std::ref(foo));
  return;
}


int main() {
  Foo* nestedFoo = new Foo{{nullptr,nullptr,nullptr,nullptr,nullptr}, "NestedPlumbus", 4, nullptr};

  Foo foo{{nullptr,nullptr,nullptr,nullptr,nullptr}, "Plumbus", 8, std::move(std::unique_ptr<Foo>(nestedFoo))};

  coolFunction(std::move(foo));

}
