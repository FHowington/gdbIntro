#include <string>
#include <memory>
#include <iostream>

struct Foo {
  int* intArr;
  std::string name;
  size_t howManyBytes;
  std::unique_ptr<Foo> nextFoo;
};


void coolFunction(const Foo foo) {
  std::cout << "Got struct " << foo.name << std::endl;
  return;
}

void anotherFunction(const Foo& foo) {
  std::cout << "foo's child is " << foo.nextFoo->name << std::endl;
}

int main() {
  Foo* nestedFoo = new Foo{nullptr, "NestedPlumbus", 4, nullptr};

  Foo foo{nullptr, "Plumbus", 8, std::move(std::unique_ptr<Foo>(nestedFoo))};

  coolFunction(std::move(foo));

  anotherFunction(foo);

}
