#abstract base class
import collections.abc as abc
print(issubclass(list,abc.Container))
print(isinstance('',abc.Generator))