#include <iostream>
#include "driver.h"
#include "ast.h"
#include "printer.h"

int main(int argc, char *argv[])
{
  int result;
  ebpf::bpftrace::Driver driver;
  if (argc == 1) {
    result = driver.parse();
  }
  else {
    result = driver.parse(argv[1]);
  }

  if (!result) {
    ebpf::bpftrace::ast::Printer p = ebpf::bpftrace::ast::Printer(std::cout);
    driver.root_->accept(p);
  }

  return result;
}
