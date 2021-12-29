import types
def gen():yield 1
f=gen()
print(isinstance(gen,types.FunctionType))
print(isinstance(gen,types.GeneratorType))
print(isinstance(f,types.FunctionType))
print(isinstance(f,types.GeneratorType))