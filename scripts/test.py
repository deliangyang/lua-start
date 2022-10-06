import gdb
from gdb.printing import PrettyPrinter, register_pretty_printer


class Test(object):

  def __init__(self, val) -> None:
    self.val = val
  
  def to_string(self):
    return "TODO: Implement"


class CustomTest(PrettyPrinter):
  
  def __init__(self) -> None:
    super(CustomTest, self).__init__(
            "my_pretty_printers", []
        )
  
  def __call__(self, val):
    typename = gdb.types.get_basic_type(val.type).tag
    if typename is None:
        typename = val.type.name
    print('-----------------------', typename)


register_pretty_printer(None, CustomTest(), replace=True)
